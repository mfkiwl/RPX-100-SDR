///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2020 Bernhard Isemann, oe3bia                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include <QMessageBox>

#include "feature/featureuiset.h"
#include "dsp/spectrumvis.h"
#include "gui/basicfeaturesettingsdialog.h"
#include "gui/glspectrum.h"
#include "gui/glscope.h"
#include "device/deviceset.h"
#include "util/db.h"
#include "maincore.h"

#include "ui_demodanalyzergui.h"
#include "demodanalyzer.h"
#include "demodanalyzergui.h"

DemodAnalyzerGUI* DemodAnalyzerGUI::create(PluginAPI* pluginAPI, FeatureUISet *featureUISet, Feature *feature)
{
	DemodAnalyzerGUI* gui = new DemodAnalyzerGUI(pluginAPI, featureUISet, feature);
	return gui;
}

void DemodAnalyzerGUI::destroy()
{
	delete this;
}

void DemodAnalyzerGUI::resetToDefaults()
{
    m_settings.resetToDefaults();
    displaySettings();
	applySettings(true);
}

QByteArray DemodAnalyzerGUI::serialize() const
{
    return m_settings.serialize();
}

bool DemodAnalyzerGUI::deserialize(const QByteArray& data)
{
    if (m_settings.deserialize(data))
    {
        displaySettings();
        applySettings(true);
        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}

bool DemodAnalyzerGUI::handleMessage(const Message& message)
{
    if (DemodAnalyzer::MsgConfigureDemodAnalyzer::match(message))
    {
        qDebug("DemodAnalyzerGUI::handleMessage: DemodAnalyzer::MsgConfigureDemodAnalyzer");
        const DemodAnalyzer::MsgConfigureDemodAnalyzer& cfg = (DemodAnalyzer::MsgConfigureDemodAnalyzer&) message;
        m_settings = cfg.getSettings();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);

        return true;
    }
    else if (DemodAnalyzer::MsgReportChannels::match(message))
    {
        qDebug("DemodAnalyzerGUI::handleMessage: DemodAnalyzer::MsgReportChannels");
        DemodAnalyzer::MsgReportChannels& report = (DemodAnalyzer::MsgReportChannels&) message;
        m_availableChannels = report.getAvailableChannels();
        updateChannelList();

        return true;
    }
    else if (DemodAnalyzer::MsgReportSampleRate::match(message))
    {
        DemodAnalyzer::MsgReportSampleRate& report = (DemodAnalyzer::MsgReportSampleRate&) message;
        int sampleRate = report.getSampleRate();
        qDebug("DemodAnalyzerGUI::handleMessage: DemodAnalyzer::MsgReportSampleRate: %d", sampleRate);
        ui->glSpectrum->setSampleRate(sampleRate/(1<<m_settings.m_log2Decim));
        m_scopeVis->setLiveRate(sampleRate/(1<<m_settings.m_log2Decim));
        displaySampleRate(sampleRate/(1<<m_settings.m_log2Decim));
        m_sampleRate = sampleRate;

        return true;
    }

	return false;
}

void DemodAnalyzerGUI::handleInputMessages()
{
    Message* message;

    while ((message = getInputMessageQueue()->pop()))
    {
        if (handleMessage(*message)) {
            delete message;
        }
    }
}

void DemodAnalyzerGUI::onWidgetRolled(QWidget* widget, bool rollDown)
{
    (void) widget;
    (void) rollDown;
}

DemodAnalyzerGUI::DemodAnalyzerGUI(PluginAPI* pluginAPI, FeatureUISet *featureUISet, Feature *feature, QWidget* parent) :
	FeatureGUI(parent),
	ui(new Ui::DemodAnalyzerGUI),
	m_pluginAPI(pluginAPI),
    m_featureUISet(featureUISet),
    m_sampleRate(48000),
	m_doApplySettings(true),
    m_lastFeatureState(0),
    m_selectedChannel(nullptr)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose, true);
    setChannelWidget(false);
	connect(this, SIGNAL(widgetRolled(QWidget*,bool)), this, SLOT(onWidgetRolled(QWidget*,bool)));

    m_demodAnalyzer = reinterpret_cast<DemodAnalyzer*>(feature);
    m_demodAnalyzer->setMessageQueueToGUI(&m_inputMessageQueue);
    m_scopeVis = m_demodAnalyzer->getScopeVis();
    m_scopeVis->setGLScope(ui->glScope);
    m_spectrumVis = m_demodAnalyzer->getSpectrumVis();
	m_spectrumVis->setGLSpectrum(ui->glSpectrum);
    m_scopeVis->setSpectrumVis(m_spectrumVis);

	m_featureUISet->addRollupWidget(this);

    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onMenuDialogCalled(const QPoint &)));
    connect(getInputMessageQueue(), SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()));

	connect(&m_statusTimer, SIGNAL(timeout()), this, SLOT(updateStatus()));
	m_statusTimer.start(1000);

	ui->spectrumGUI->setBuddies(m_spectrumVis, ui->glSpectrum);
	ui->scopeGUI->setBuddies(m_scopeVis->getInputMessageQueue(), m_scopeVis, ui->glScope);
    ui->glSpectrum->setCenterFrequency(0);
    ui->glSpectrum->setSampleRate(m_sampleRate/(1<<m_settings.m_log2Decim));
    m_scopeVis->setLiveRate(m_sampleRate/(1<<m_settings.m_log2Decim));
    displaySampleRate(m_sampleRate/(1<<m_settings.m_log2Decim));

	ui->glScope->connectTimer(MainCore::instance()->getMasterTimer());
	connect(&MainCore::instance()->getMasterTimer(), SIGNAL(timeout()), this, SLOT(tick()));

    m_settings.setSpectrumGUI(ui->spectrumGUI);
    m_settings.setScopeGUI(ui->scopeGUI);

    displaySettings();
	applySettings(true);
}

DemodAnalyzerGUI::~DemodAnalyzerGUI()
{
	delete ui;
}

void DemodAnalyzerGUI::blockApplySettings(bool block)
{
    m_doApplySettings = !block;
}

void DemodAnalyzerGUI::displaySettings()
{
    setTitleColor(m_settings.m_rgbColor);
    setWindowTitle(m_settings.m_title);
    blockApplySettings(true);
    ui->log2Decim->setCurrentIndex(m_settings.m_log2Decim);
    blockApplySettings(false);
}

void DemodAnalyzerGUI::displaySampleRate(int sampleRate)
{
	QString s = QString::number(sampleRate/1000.0, 'f', 1);
	ui->sinkSampleRateText->setText(tr("%1 kS/s").arg(s));
}

void DemodAnalyzerGUI::updateChannelList()
{
    ui->channels->blockSignals(true);
    ui->channels->clear();

    QList<DemodAnalyzerSettings::AvailableChannel>::const_iterator it = m_availableChannels.begin();
    int selectedItem = -1;

    for (int i = 0; it != m_availableChannels.end(); ++it, i++)
    {
        ui->channels->addItem(tr("%1%2:%3 %4")
            .arg(it->m_tx ? "T" : "R")
            .arg(it->m_deviceSetIndex)
            .arg(it->m_channelIndex)
            .arg(it->m_id)
        );

        if (it->m_channelAPI == m_selectedChannel) {
            selectedItem = i;
        }
    }

    ui->channels->blockSignals(false);

    if (m_availableChannels.size() > 0)
    {
        if (selectedItem >= 0) {
            ui->channels->setCurrentIndex(selectedItem);
        } else {
            ui->channels->setCurrentIndex(0);
        }
    }
}

void DemodAnalyzerGUI::leaveEvent(QEvent*)
{
}

void DemodAnalyzerGUI::enterEvent(QEvent*)
{
}

void DemodAnalyzerGUI::onMenuDialogCalled(const QPoint &p)
{
    if (m_contextMenuType == ContextMenuChannelSettings)
    {
        BasicFeatureSettingsDialog dialog(this);
        dialog.setTitle(m_settings.m_title);
        dialog.setColor(m_settings.m_rgbColor);
        dialog.setUseReverseAPI(m_settings.m_useReverseAPI);
        dialog.setReverseAPIAddress(m_settings.m_reverseAPIAddress);
        dialog.setReverseAPIPort(m_settings.m_reverseAPIPort);
        dialog.setReverseAPIFeatureSetIndex(m_settings.m_reverseAPIFeatureSetIndex);
        dialog.setReverseAPIFeatureIndex(m_settings.m_reverseAPIFeatureIndex);

        dialog.move(p);
        dialog.exec();

        m_settings.m_rgbColor = dialog.getColor().rgb();
        m_settings.m_title = dialog.getTitle();
        m_settings.m_useReverseAPI = dialog.useReverseAPI();
        m_settings.m_reverseAPIAddress = dialog.getReverseAPIAddress();
        m_settings.m_reverseAPIPort = dialog.getReverseAPIPort();
        m_settings.m_reverseAPIFeatureSetIndex = dialog.getReverseAPIFeatureSetIndex();
        m_settings.m_reverseAPIFeatureIndex = dialog.getReverseAPIFeatureIndex();

        setWindowTitle(m_settings.m_title);
        setTitleColor(m_settings.m_rgbColor);

        applySettings();
    }

    resetContextMenuType();
}

void DemodAnalyzerGUI::on_startStop_toggled(bool checked)
{
    if (m_doApplySettings)
    {
        DemodAnalyzer::MsgStartStop *message = DemodAnalyzer::MsgStartStop::create(checked);
        m_demodAnalyzer->getInputMessageQueue()->push(message);
    }
}

void DemodAnalyzerGUI::on_devicesRefresh_clicked()
{
    DemodAnalyzer::MsgRefreshChannels *msg = DemodAnalyzer::MsgRefreshChannels::create();
    m_demodAnalyzer->getInputMessageQueue()->push(msg);
}

void DemodAnalyzerGUI::on_channels_currentIndexChanged(int index)
{
    if ((index >= 0) && (index < m_availableChannels.size()))
    {
        m_selectedChannel = m_availableChannels[index].m_channelAPI;
        DemodAnalyzer::MsgSelectChannel *msg = DemodAnalyzer::MsgSelectChannel::create(m_selectedChannel);
        m_demodAnalyzer->getInputMessageQueue()->push(msg);
    }
}

void DemodAnalyzerGUI::on_channelApply_clicked()
{
    if (ui->channels->count() > 0) {
        on_channels_currentIndexChanged(ui->channels->currentIndex());
    }
}

void DemodAnalyzerGUI::on_log2Decim_currentIndexChanged(int index)
{
    if ((index < 0) || (index > 6)) {
        return;
    }

    m_settings.m_log2Decim = index;
    ui->glSpectrum->setSampleRate(m_sampleRate/(1<<m_settings.m_log2Decim));
    m_scopeVis->setLiveRate(m_sampleRate/(1<<m_settings.m_log2Decim));
    displaySampleRate(m_sampleRate/(1<<m_settings.m_log2Decim));
    applySettings();
}

void DemodAnalyzerGUI::tick()
{
	m_channelPowerAvg(m_demodAnalyzer->getMagSqAvg());
	double powDb = CalcDb::dbPower((double) m_channelPowerAvg);
	ui->channelPower->setText(tr("%1 dB").arg(powDb, 0, 'f', 1));
}

void DemodAnalyzerGUI::updateStatus()
{
    int state = m_demodAnalyzer->getState();

    if (m_lastFeatureState != state)
    {
        switch (state)
        {
            case Feature::StNotStarted:
                ui->startStop->setStyleSheet("QToolButton { background:rgb(79,79,79); }");
                break;
            case Feature::StIdle:
                ui->startStop->setStyleSheet("QToolButton { background-color : blue; }");
                break;
            case Feature::StRunning:
                ui->startStop->setStyleSheet("QToolButton { background-color : green; }");
                break;
            case Feature::StError:
                ui->startStop->setStyleSheet("QToolButton { background-color : red; }");
                QMessageBox::information(this, tr("Message"), m_demodAnalyzer->getErrorMessage());
                break;
            default:
                break;
        }

        m_lastFeatureState = state;
    }
}

void DemodAnalyzerGUI::applySettings(bool force)
{
	if (m_doApplySettings)
	{
	    DemodAnalyzer::MsgConfigureDemodAnalyzer* message = DemodAnalyzer::MsgConfigureDemodAnalyzer::create( m_settings, force);
	    m_demodAnalyzer->getInputMessageQueue()->push(message);
	}
}

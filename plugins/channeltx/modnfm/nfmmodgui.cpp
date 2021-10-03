///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2016 Bernhard Isemann, oe3bia                                   //
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

#include <QDockWidget>
#include <QMainWindow>
#include <QFileDialog>
#include <QTime>
#include <QDebug>
#include <QRegExp>

#include "device/deviceuiset.h"
#include "plugin/pluginapi.h"
#include "util/simpleserializer.h"
#include "util/db.h"
#include "dsp/dspengine.h"
#include "dsp/cwkeyer.h"
#include "gui/crightclickenabler.h"
#include "gui/audioselectdialog.h"
#include "gui/basicchannelsettingsdialog.h"
#include "gui/devicestreamselectiondialog.h"
#include "maincore.h"

#include "ui_nfmmodgui.h"
#include "nfmmodgui.h"


NFMModGUI* NFMModGUI::create(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSource *channelTx)
{
    NFMModGUI* gui = new NFMModGUI(pluginAPI, deviceUISet, channelTx);
	return gui;
}

void NFMModGUI::destroy()
{
    delete this;
}

void NFMModGUI::resetToDefaults()
{
    m_settings.resetToDefaults();
    displaySettings();
    applySettings(true);
}

QByteArray NFMModGUI::serialize() const
{
    return m_settings.serialize();
}

bool NFMModGUI::deserialize(const QByteArray& data)
{
    if(m_settings.deserialize(data)) {
        displaySettings();
        applySettings(true);
        return true;
    } else {
        resetToDefaults();
        return false;
    }
}

bool NFMModGUI::handleMessage(const Message& message)
{
    if (NFMMod::MsgReportFileSourceStreamData::match(message))
    {
        m_recordSampleRate = ((NFMMod::MsgReportFileSourceStreamData&)message).getSampleRate();
        m_recordLength = ((NFMMod::MsgReportFileSourceStreamData&)message).getRecordLength();
        m_samplesCount = 0;
        updateWithStreamData();
        return true;
    }
    else if (NFMMod::MsgReportFileSourceStreamTiming::match(message))
    {
        m_samplesCount = ((NFMMod::MsgReportFileSourceStreamTiming&)message).getSamplesCount();
        updateWithStreamTime();
        return true;
    }
    else if (NFMMod::MsgConfigureNFMMod::match(message))
    {
        const NFMMod::MsgConfigureNFMMod& cfg = (NFMMod::MsgConfigureNFMMod&) message;
        m_settings = cfg.getSettings();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);
        return true;
    }
    else if (CWKeyer::MsgConfigureCWKeyer::match(message))
    {
        const CWKeyer::MsgConfigureCWKeyer& cfg = (CWKeyer::MsgConfigureCWKeyer&) message;
        ui->cwKeyerGUI->setSettings(cfg.getSettings());
        ui->cwKeyerGUI->displaySettings();
        return true;
    }
    else
    {
        return false;
    }
}

void NFMModGUI::channelMarkerChangedByCursor()
{
    ui->deltaFrequency->setValue(m_channelMarker.getCenterFrequency());
    m_settings.m_inputFrequencyOffset = m_channelMarker.getCenterFrequency();
	applySettings();
}

void NFMModGUI::handleSourceMessages()
{
    Message* message;

    while ((message = getInputMessageQueue()->pop()) != 0)
    {
        if (handleMessage(*message))
        {
            delete message;
        }
    }
}

void NFMModGUI::on_deltaFrequency_changed(qint64 value)
{
    m_channelMarker.setCenterFrequency(value);
    m_settings.m_inputFrequencyOffset = m_channelMarker.getCenterFrequency();
    applySettings();
}

void NFMModGUI::on_channelSpacingApply_clicked()
{
    int index = ui->channelSpacing->currentIndex();
	m_settings.m_rfBandwidth = NFMModSettings::getRFBW(index);
    m_settings.m_afBandwidth = NFMModSettings::getAFBW(index);
    m_settings.m_fmDeviation = 2.0 * NFMModSettings::getFMDev(index);
    m_channelMarker.setBandwidth(m_settings.m_rfBandwidth);
    ui->rfBW->blockSignals(true);
    ui->afBW->blockSignals(true);
    ui->fmDev->blockSignals(true);
    ui->rfBWText->setText(QString("%1k").arg(m_settings.m_rfBandwidth / 1000.0, 0, 'f', 1));
    ui->rfBW->setValue(m_settings.m_rfBandwidth / 100.0);
    ui->afBWText->setText(QString("%1k").arg(m_settings.m_afBandwidth / 1000.0, 0, 'f', 1));
    ui->afBW->setValue(m_settings.m_afBandwidth / 100.0);
    ui->fmDevText->setText(QString("%1%2k").arg(QChar(0xB1, 0x00)).arg(m_settings.m_fmDeviation / 2000.0, 0, 'f', 1));
    ui->fmDev->setValue(m_settings.m_fmDeviation / 200.0);
    ui->rfBW->blockSignals(false);
    ui->afBW->blockSignals(false);
    ui->fmDev->blockSignals(false);
	applySettings();
}

void NFMModGUI::on_rfBW_valueChanged(int value)
{
	ui->rfBWText->setText(QString("%1k").arg(value / 10.0, 0, 'f', 1));
	m_settings.m_rfBandwidth = value * 100.0;
	m_channelMarker.setBandwidth(m_settings.m_rfBandwidth);

    ui->channelSpacing->blockSignals(true);
    ui->channelSpacing->setCurrentIndex(NFMModSettings::getChannelSpacingIndex(m_settings.m_rfBandwidth));
    ui->channelSpacing->blockSignals(false);

    applySettings();
}

void NFMModGUI::on_afBW_valueChanged(int value)
{
	ui->afBWText->setText(QString("%1k").arg(value / 10.0, 0, 'f', 1));
	m_settings.m_afBandwidth = value * 100.0;
	applySettings();
}

void NFMModGUI::on_fmDev_valueChanged(int value)
{
	ui->fmDevText->setText(QString("%1%2k").arg(QChar(0xB1, 0x00)).arg(value / 10.0, 0, 'f', 1));
	m_settings.m_fmDeviation = value * 200.0;
	applySettings();
}

void NFMModGUI::on_volume_valueChanged(int value)
{
	ui->volumeText->setText(QString("%1").arg(value / 10.0, 0, 'f', 1));
	m_settings.m_volumeFactor = value / 10.0;
	applySettings();
}

void NFMModGUI::on_toneFrequency_valueChanged(int value)
{
    ui->toneFrequencyText->setText(QString("%1k").arg(value / 100.0, 0, 'f', 2));
    m_settings.m_toneFrequency = value * 10.0;
    applySettings();
}

void NFMModGUI::on_channelMute_toggled(bool checked)
{
    m_settings.m_channelMute = checked;
	applySettings();
}

void NFMModGUI::on_playLoop_toggled(bool checked)
{
    m_settings.m_playLoop = checked;
	applySettings();
}

void NFMModGUI::on_play_toggled(bool checked)
{
    ui->tone->setEnabled(!checked); // release other source inputs
    ui->mic->setEnabled(!checked);
    ui->morseKeyer->setEnabled(!checked);
    m_settings.m_modAFInput = checked ? NFMModSettings::NFMModInputFile : NFMModSettings::NFMModInputNone;
    applySettings();
    ui->navTimeSlider->setEnabled(!checked);
    m_enableNavTime = !checked;
}

void NFMModGUI::on_tone_toggled(bool checked)
{
    ui->play->setEnabled(!checked); // release other source inputs
    ui->mic->setEnabled(!checked);
    ui->morseKeyer->setEnabled(!checked);
    m_settings.m_modAFInput = checked ? NFMModSettings::NFMModInputTone : NFMModSettings::NFMModInputNone;
    applySettings();
}

void NFMModGUI::on_morseKeyer_toggled(bool checked)
{
    ui->tone->setEnabled(!checked); // release other source inputs
    ui->mic->setEnabled(!checked);
    ui->play->setEnabled(!checked);
    m_settings.m_modAFInput = checked ? NFMModSettings::NFMModInputCWTone : NFMModSettings::NFMModInputNone;
    applySettings();
}

void NFMModGUI::on_mic_toggled(bool checked)
{
    ui->play->setEnabled(!checked); // release other source inputs
    ui->tone->setEnabled(!checked); // release other source inputs
    ui->morseKeyer->setEnabled(!checked);
    m_settings.m_modAFInput = checked ? NFMModSettings::NFMModInputAudio : NFMModSettings::NFMModInputNone;
    applySettings();
}

void NFMModGUI::on_feedbackEnable_toggled(bool checked)
{
    m_settings.m_feedbackAudioEnable = checked;
    applySettings();
}

void NFMModGUI::on_feedbackVolume_valueChanged(int value)
{
    ui->feedbackVolumeText->setText(QString("%1").arg(value / 100.0, 0, 'f', 2));
    m_settings.m_feedbackVolumeFactor = value / 100.0;
    applySettings();
}

void NFMModGUI::on_navTimeSlider_valueChanged(int value)
{
    if (m_enableNavTime && ((value >= 0) && (value <= 100)))
    {
        int t_sec = (m_recordLength * value) / 100;
        QTime t(0, 0, 0, 0);
        t = t.addSecs(t_sec);

        NFMMod::MsgConfigureFileSourceSeek* message = NFMMod::MsgConfigureFileSourceSeek::create(value);
        m_nfmMod->getInputMessageQueue()->push(message);
    }
}

void NFMModGUI::on_showFileDialog_clicked(bool checked)
{
    (void) checked;
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open raw audio file"), ".", tr("Raw audio Files (*.raw)"), 0, QFileDialog::DontUseNativeDialog);

    if (fileName != "")
    {
        m_fileName = fileName;
        ui->recordFileText->setText(m_fileName);
        ui->play->setEnabled(true);
        configureFileName();
    }
}

void NFMModGUI::on_ctcss_currentIndexChanged(int index)
{
    m_settings.m_ctcssIndex = index;
    applySettings();
}

void NFMModGUI::on_ctcssOn_toggled(bool checked)
{
    ui->dcsOn->setEnabled(!checked);
    m_settings.m_ctcssOn = checked;
    applySettings();
}

void NFMModGUI::on_dcsOn_toggled(bool checked)
{
    ui->ctcssOn->setEnabled(!checked);
    m_settings.m_dcsOn = checked;
    applySettings();
}

void NFMModGUI::on_dcsCode_editingFinished()
{
    bool ok;
    int dcsCode = ui->dcsCode->text().toInt(&ok, 8);

    if (ok)
    {
        m_settings.m_dcsCode = dcsCode;
        applySettings();
    }
}

void NFMModGUI::on_dcsPositive_toggled(bool checked)
{
    m_settings.m_dcsPositive = checked;
    applySettings();
}

void NFMModGUI::configureFileName()
{
    qDebug() << "FileSourceGui::configureFileName: " << m_fileName.toStdString().c_str();
    NFMMod::MsgConfigureFileSourceName* message = NFMMod::MsgConfigureFileSourceName::create(m_fileName);
    m_nfmMod->getInputMessageQueue()->push(message);
}

void NFMModGUI::onWidgetRolled(QWidget* widget, bool rollDown)
{
    (void) widget;
    (void) rollDown;
}

void NFMModGUI::onMenuDialogCalled(const QPoint &p)
{
    if (m_contextMenuType == ContextMenuChannelSettings)
    {
        BasicChannelSettingsDialog dialog(&m_channelMarker, this);
        dialog.setUseReverseAPI(m_settings.m_useReverseAPI);
        dialog.setReverseAPIAddress(m_settings.m_reverseAPIAddress);
        dialog.setReverseAPIPort(m_settings.m_reverseAPIPort);
        dialog.setReverseAPIDeviceIndex(m_settings.m_reverseAPIDeviceIndex);
        dialog.setReverseAPIChannelIndex(m_settings.m_reverseAPIChannelIndex);
        dialog.move(p);
        dialog.exec();

        m_settings.m_inputFrequencyOffset = m_channelMarker.getCenterFrequency();
        m_settings.m_rgbColor = m_channelMarker.getColor().rgb();
        m_settings.m_title = m_channelMarker.getTitle();
        m_settings.m_useReverseAPI = dialog.useReverseAPI();
        m_settings.m_reverseAPIAddress = dialog.getReverseAPIAddress();
        m_settings.m_reverseAPIPort = dialog.getReverseAPIPort();
        m_settings.m_reverseAPIDeviceIndex = dialog.getReverseAPIDeviceIndex();
        m_settings.m_reverseAPIChannelIndex = dialog.getReverseAPIChannelIndex();

        setWindowTitle(m_settings.m_title);
        setTitleColor(m_settings.m_rgbColor);

        applySettings();
    }
    else if ((m_contextMenuType == ContextMenuStreamSettings) && (m_deviceUISet->m_deviceMIMOEngine))
    {
        DeviceStreamSelectionDialog dialog(this);
        dialog.setNumberOfStreams(m_nfmMod->getNumberOfDeviceStreams());
        dialog.setStreamIndex(m_settings.m_streamIndex);
        dialog.move(p);
        dialog.exec();

        m_settings.m_streamIndex = dialog.getSelectedStreamIndex();
        m_channelMarker.clearStreamIndexes();
        m_channelMarker.addStreamIndex(m_settings.m_streamIndex);
        displayStreamIndex();
        applySettings();
    }

    resetContextMenuType();
}

NFMModGUI::NFMModGUI(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSource *channelTx, QWidget* parent) :
	ChannelGUI(parent),
	ui(new Ui::NFMModGUI),
	m_pluginAPI(pluginAPI),
	m_deviceUISet(deviceUISet),
	m_channelMarker(this),
	m_doApplySettings(true),
    m_recordLength(0),
    m_recordSampleRate(48000),
    m_samplesCount(0),
    m_audioSampleRate(-1),
    m_feedbackAudioSampleRate(-1),
    m_tickCount(0),
    m_enableNavTime(false),
    m_dcsCodeValidator(QRegExp("[0-7]{1,3}"))
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose, true);

    ui->channelSpacing->blockSignals(true);
    ui->channelSpacing->clear();

    for (int i = 0; i < NFMModSettings::m_nbChannelSpacings; i++) {
        ui->channelSpacing->addItem(QString("%1").arg(NFMModSettings::getChannelSpacing(i) / 1000.0, 0, 'f', 2));
    }

    ui->channelSpacing->setCurrentIndex(NFMModSettings::getChannelSpacingIndex(25000));
    ui->channelSpacing->blockSignals(false);

	connect(this, SIGNAL(widgetRolled(QWidget*,bool)), this, SLOT(onWidgetRolled(QWidget*,bool)));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onMenuDialogCalled(const QPoint &)));

	m_nfmMod = (NFMMod*) channelTx;
	m_nfmMod->setMessageQueueToGUI(getInputMessageQueue());

	connect(&MainCore::instance()->getMasterTimer(), SIGNAL(timeout()), this, SLOT(tick()));

    CRightClickEnabler *audioMuteRightClickEnabler = new CRightClickEnabler(ui->mic);
    connect(audioMuteRightClickEnabler, SIGNAL(rightClick(const QPoint &)), this, SLOT(audioSelect()));

    CRightClickEnabler *feedbackRightClickEnabler = new CRightClickEnabler(ui->feedbackEnable);
    connect(feedbackRightClickEnabler, SIGNAL(rightClick(const QPoint &)), this, SLOT(audioFeedbackSelect()));

    ui->deltaFrequencyLabel->setText(QString("%1f").arg(QChar(0x94, 0x03)));
    ui->deltaFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
    ui->deltaFrequency->setValueRange(false, 7, -9999999, 9999999);

    m_channelMarker.blockSignals(true);
    m_channelMarker.setColor(Qt::red);
    m_channelMarker.setBandwidth(12500);
    m_channelMarker.setCenterFrequency(0);
    m_channelMarker.setTitle("NFM Modulator");
    m_channelMarker.setSourceOrSinkStream(false);
    m_channelMarker.blockSignals(false);
	m_channelMarker.setVisible(true); // activate signal on the last setting only

	m_deviceUISet->addChannelMarker(&m_channelMarker);
	m_deviceUISet->addRollupWidget(this);

	connect(&m_channelMarker, SIGNAL(changedByCursor()), this, SLOT(channelMarkerChangedByCursor()));

    ui->play->setEnabled(false);
    ui->play->setChecked(false);
    ui->tone->setChecked(false);
    ui->mic->setChecked(false);

    for (int i=0; i< NFMModSettings::getNbCTCSSFreq(); i++) {
        ui->ctcss->addItem(QString("%1").arg((double) NFMModSettings::getCTCSSFreq(i), 0, 'f', 1));
    }

    ui->dcsCode->setValidator(&m_dcsCodeValidator);
    ui->cwKeyerGUI->setCWKeyer(m_nfmMod->getCWKeyer());

	connect(getInputMessageQueue(), SIGNAL(messageEnqueued()), this, SLOT(handleSourceMessages()));
    m_nfmMod->setLevelMeter(ui->volumeMeter);

    m_settings.setChannelMarker(&m_channelMarker);
    m_settings.setCWKeyerGUI(ui->cwKeyerGUI);

    displaySettings();
    applySettings();
}

NFMModGUI::~NFMModGUI()
{
	delete ui;
}

void NFMModGUI::blockApplySettings(bool block)
{
    m_doApplySettings = !block;
}

void NFMModGUI::applySettings(bool force)
{
	if (m_doApplySettings)
	{
		NFMMod::MsgConfigureNFMMod *msg = NFMMod::MsgConfigureNFMMod::create(m_settings, force);
		m_nfmMod->getInputMessageQueue()->push(msg);
	}
}

void NFMModGUI::displaySettings()
{
    m_channelMarker.blockSignals(true);
    m_channelMarker.setCenterFrequency(m_settings.m_inputFrequencyOffset);
    m_channelMarker.setTitle(m_settings.m_title);
    m_channelMarker.blockSignals(false);
    m_channelMarker.setColor(m_settings.m_rgbColor); // activate signal on the last setting only

    setTitleColor(m_settings.m_rgbColor);
    setWindowTitle(m_channelMarker.getTitle());
    displayStreamIndex();

    blockApplySettings(true);

    ui->deltaFrequency->setValue(m_channelMarker.getCenterFrequency());

    ui->rfBWText->setText(QString("%1k").arg(m_settings.m_rfBandwidth / 1000.0, 0, 'f', 1));
    ui->rfBW->setValue(m_settings.m_rfBandwidth / 100.0);

    ui->afBWText->setText(QString("%1k").arg(m_settings.m_afBandwidth / 1000.0, 0, 'f', 1));
    ui->afBW->setValue(m_settings.m_afBandwidth / 100.0);

    ui->fmDevText->setText(QString("%1%2k").arg(QChar(0xB1, 0x00)).arg(m_settings.m_fmDeviation / 2000.0, 0, 'f', 1));
    ui->fmDev->setValue(m_settings.m_fmDeviation / 200.0);

    ui->channelSpacing->blockSignals(true);
    ui->channelSpacing->setCurrentIndex(NFMModSettings::getChannelSpacingIndex(m_settings.m_rfBandwidth));
    ui->channelSpacing->blockSignals(false);

    ui->volumeText->setText(QString("%1").arg(m_settings.m_volumeFactor, 0, 'f', 1));
    ui->volume->setValue(m_settings.m_volumeFactor * 10.0);

    ui->toneFrequencyText->setText(QString("%1k").arg(m_settings.m_toneFrequency / 1000.0, 0, 'f', 2));
    ui->toneFrequency->setValue(m_settings.m_toneFrequency / 10.0);

    ui->ctcssOn->setChecked(m_settings.m_ctcssOn);
    ui->ctcss->setCurrentIndex(m_settings.m_ctcssIndex);

    ui->dcsOn->setChecked(m_settings.m_dcsOn);
    ui->dcsOn->setEnabled(!m_settings.m_ctcssOn);
    ui->dcsCode->setText(tr("%1").arg(m_settings.m_dcsCode, 3, 8, QLatin1Char('0')));
    ui->dcsPositive->setChecked(m_settings.m_dcsPositive);

    ui->channelMute->setChecked(m_settings.m_channelMute);
    ui->playLoop->setChecked(m_settings.m_playLoop);

    ui->tone->setEnabled((m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputTone) || (m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputNone));
    ui->mic->setEnabled((m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputAudio) || (m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputNone));
    ui->play->setEnabled((m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputFile) || (m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputNone));
    ui->morseKeyer->setEnabled((m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputCWTone) || (m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputNone));

    ui->tone->setChecked(m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputTone);
    ui->mic->setChecked(m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputAudio);
    ui->play->setChecked(m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputFile);
    ui->morseKeyer->setChecked(m_settings.m_modAFInput == NFMModSettings::NFMModInputAF::NFMModInputCWTone);

    ui->feedbackEnable->setChecked(m_settings.m_feedbackAudioEnable);
    ui->feedbackVolume->setValue(roundf(m_settings.m_feedbackVolumeFactor * 100.0));
    ui->feedbackVolumeText->setText(QString("%1").arg(m_settings.m_feedbackVolumeFactor, 0, 'f', 2));

    blockApplySettings(false);
}

void NFMModGUI::displayStreamIndex()
{
    if (m_deviceUISet->m_deviceMIMOEngine) {
        setStreamIndicator(tr("%1").arg(m_settings.m_streamIndex));
    } else {
        setStreamIndicator("S"); // single channel indicator
    }
}

void NFMModGUI::leaveEvent(QEvent*)
{
	m_channelMarker.setHighlighted(false);
}

void NFMModGUI::enterEvent(QEvent*)
{
	m_channelMarker.setHighlighted(true);
}

void NFMModGUI::audioSelect()
{
    qDebug("NFMModGUI::audioSelect");
    AudioSelectDialog audioSelect(DSPEngine::instance()->getAudioDeviceManager(), m_settings.m_audioDeviceName, true); // true for input
    audioSelect.exec();

    if (audioSelect.m_selected)
    {
        m_settings.m_audioDeviceName = audioSelect.m_audioDeviceName;
        applySettings();
    }
}

void NFMModGUI::audioFeedbackSelect()
{
    qDebug("NFMModGUI::audioFeedbackSelect");
    AudioSelectDialog audioSelect(DSPEngine::instance()->getAudioDeviceManager(), m_settings.m_audioDeviceName, false); // false for output
    audioSelect.exec();

    if (audioSelect.m_selected)
    {
        m_settings.m_feedbackAudioDeviceName = audioSelect.m_audioDeviceName;
        applySettings();
    }
}

void NFMModGUI::tick()
{
    double powDb = CalcDb::dbPower(m_nfmMod->getMagSq());
	m_channelPowerDbAvg(powDb);
	ui->channelPower->setText(tr("%1 dB").arg(m_channelPowerDbAvg.asDouble(), 0, 'f', 1));

    int audioSampleRate = m_nfmMod->getAudioSampleRate();

    if (audioSampleRate != m_audioSampleRate)
    {
        if (audioSampleRate < 0) {
            ui->mic->setColor(QColor("red"));
        } else {
            ui->mic->resetColor();
        }

        m_audioSampleRate = audioSampleRate;
    }

    int feedbackAudioSampleRate = m_nfmMod->getFeedbackAudioSampleRate();

    if (feedbackAudioSampleRate != m_feedbackAudioSampleRate)
    {
        if (feedbackAudioSampleRate < 0) {
            ui->feedbackEnable->setStyleSheet("QToolButton { background-color : red; }");
        } else {
            ui->feedbackEnable->setStyleSheet("QToolButton { background:rgb(79,79,79); }");
        }

        m_feedbackAudioSampleRate = feedbackAudioSampleRate;
    }

    if (((++m_tickCount & 0xf) == 0) && (m_settings.m_modAFInput == NFMModSettings::NFMModInputFile))
    {
        NFMMod::MsgConfigureFileSourceStreamTiming* message = NFMMod::MsgConfigureFileSourceStreamTiming::create();
        m_nfmMod->getInputMessageQueue()->push(message);
    }
}

void NFMModGUI::updateWithStreamData()
{
    QTime recordLength(0, 0, 0, 0);
    recordLength = recordLength.addSecs(m_recordLength);
    QString s_time = recordLength.toString("HH:mm:ss");
    ui->recordLengthText->setText(s_time);
    updateWithStreamTime();
}

void NFMModGUI::updateWithStreamTime()
{
    int t_sec = 0;
    int t_msec = 0;

    if (m_recordSampleRate > 0)
    {
        t_msec = ((m_samplesCount * 1000) / m_recordSampleRate) % 1000;
        t_sec = m_samplesCount / m_recordSampleRate;
    }

    QTime t(0, 0, 0, 0);
    t = t.addSecs(t_sec);
    t = t.addMSecs(t_msec);
    QString s_timems = t.toString("HH:mm:ss.zzz");
    QString s_time = t.toString("HH:mm:ss");
    ui->relTimeText->setText(s_timems);

    if (!m_enableNavTime)
    {
        float posRatio = (float) t_sec / (float) m_recordLength;
        ui->navTimeSlider->setValue((int) (posRatio * 100.0));
    }
}

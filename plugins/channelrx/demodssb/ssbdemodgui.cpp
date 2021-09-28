#include <QPixmap>

#include "ssbdemodgui.h"

#include "device/deviceuiset.h"

#include "ui_ssbdemodgui.h"
#include "dsp/spectrumvis.h"
#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "gui/glspectrum.h"
#include "gui/basicchannelsettingsdialog.h"
#include "gui/devicestreamselectiondialog.h"
#include "plugin/pluginapi.h"
#include "util/simpleserializer.h"
#include "util/db.h"
#include "gui/crightclickenabler.h"
#include "gui/audioselectdialog.h"
#include "maincore.h"
#include "ssbdemod.h"

SSBDemodGUI* SSBDemodGUI::create(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel)
{
	SSBDemodGUI* gui = new SSBDemodGUI(pluginAPI, deviceUISet, rxChannel);
	return gui;
}

void SSBDemodGUI::destroy()
{
	delete this;
}

void SSBDemodGUI::resetToDefaults()
{
	m_settings.resetToDefaults();
}

QByteArray SSBDemodGUI::serialize() const
{
    return m_settings.serialize();
}

bool SSBDemodGUI::deserialize(const QByteArray& data)
{
    if(m_settings.deserialize(data))
    {
        ui->BW->setMaximum(480);
        ui->lowCut->setMaximum(480);
        displaySettings();
        applyBandwidths(m_settings.m_spanLog2, true); // does applySettings(true)
        return true;
    }
    else
    {
        m_settings.resetToDefaults();
        ui->BW->setMaximum(480);
        ui->lowCut->setMaximum(480);
        displaySettings();
        applyBandwidths(m_settings.m_spanLog2, true); // does applySettings(true)
        return false;
    }
}

bool SSBDemodGUI::handleMessage(const Message& message)
{
    if (SSBDemod::MsgConfigureSSBDemod::match(message))
    {
        qDebug("SSBDemodGUI::handleMessage: SSBDemod::MsgConfigureSSBDemod");
        const SSBDemod::MsgConfigureSSBDemod& cfg = (SSBDemod::MsgConfigureSSBDemod&) message;
        m_settings = cfg.getSettings();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);
        return true;
    }
    else if (DSPConfigureAudio::match(message))
    {
        qDebug("SSBDemodGUI::handleMessage: DSPConfigureAudio: %d", m_ssbDemod->getAudioSampleRate());
        applyBandwidths(1 + ui->spanLog2->maximum() - ui->spanLog2->value()); // will update spectrum details with new sample rate
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);
        return true;
    }
    else
    {
        return false;
    }
}

void SSBDemodGUI::handleInputMessages()
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

void SSBDemodGUI::channelMarkerChangedByCursor()
{
    ui->deltaFrequency->setValue(m_channelMarker.getCenterFrequency());
    m_settings.m_inputFrequencyOffset = m_channelMarker.getCenterFrequency();
    applySettings();
}

void SSBDemodGUI::channelMarkerHighlightedByCursor()
{
    setHighlighted(m_channelMarker.getHighlighted());
}

void SSBDemodGUI::on_audioBinaural_toggled(bool binaural)
{
	m_audioBinaural = binaural;
	m_settings.m_audioBinaural = binaural;
	applySettings();
}

void SSBDemodGUI::on_audioFlipChannels_toggled(bool flip)
{
	m_audioFlipChannels = flip;
	m_settings.m_audioFlipChannels = flip;
	applySettings();
}

void SSBDemodGUI::on_dsb_toggled(bool dsb)
{
    ui->flipSidebands->setEnabled(!dsb);
    applyBandwidths(1 + ui->spanLog2->maximum() - ui->spanLog2->value());
}

void SSBDemodGUI::on_deltaFrequency_changed(qint64 value)
{
    m_channelMarker.setCenterFrequency(value);
    m_settings.m_inputFrequencyOffset = m_channelMarker.getCenterFrequency();
    applySettings();
}

void SSBDemodGUI::on_BW_valueChanged(int value)
{
    (void) value;
    qDebug("SSBDemodGUI::on_BW_valueChanged: ui->spanLog2: %d", ui->spanLog2->value());
    applyBandwidths(1 + ui->spanLog2->maximum() - ui->spanLog2->value());
}

void SSBDemodGUI::on_lowCut_valueChanged(int value)
{
    (void) value;
    applyBandwidths(1 + ui->spanLog2->maximum() - ui->spanLog2->value());
}

void SSBDemodGUI::on_volume_valueChanged(int value)
{
	ui->volumeText->setText(QString("%1").arg(value));
	m_settings.m_volume = CalcDb::powerFromdB(value);
	applySettings();
}

void SSBDemodGUI::on_agc_toggled(bool checked)
{
    m_settings.m_agc = checked;
    applySettings();
}

void SSBDemodGUI::on_agcClamping_toggled(bool checked)
{
    m_settings.m_agcClamping = checked;
    applySettings();
}

void SSBDemodGUI::on_agcTimeLog2_valueChanged(int value)
{
    QString s = QString::number((1<<value), 'f', 0);
    ui->agcTimeText->setText(s);
    m_settings.m_agcTimeLog2 = value;
    applySettings();
}

void SSBDemodGUI::on_agcPowerThreshold_valueChanged(int value)
{
    displayAGCPowerThreshold(value);
    m_settings.m_agcPowerThreshold = value;
    applySettings();
}

void SSBDemodGUI::on_agcThresholdGate_valueChanged(int value)
{
    int agcThresholdGate = value < 20 ? value : ((value - 20) * 10) + 20;
    QString s = QString::number(agcThresholdGate, 'f', 0);
    ui->agcThresholdGateText->setText(s);
    m_settings.m_agcThresholdGate = agcThresholdGate;
    applySettings();
}

void SSBDemodGUI::on_audioMute_toggled(bool checked)
{
	m_audioMute = checked;
	m_settings.m_audioMute = checked;
	applySettings();
}

void SSBDemodGUI::on_spanLog2_valueChanged(int value)
{
    int s2max = spanLog2Max();

    if ((value < 0) || (value > s2max-1)) {
        return;
    }

    applyBandwidths(s2max - ui->spanLog2->value());
}

void SSBDemodGUI::on_flipSidebands_clicked(bool checked)
{
    (void) checked;
    int bwValue = ui->BW->value();
    int lcValue = ui->lowCut->value();
    ui->BW->setValue(-bwValue);
    ui->lowCut->setValue(-lcValue);
}

void SSBDemodGUI::onMenuDialogCalled(const QPoint &p)
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
        dialog.setNumberOfStreams(m_ssbDemod->getNumberOfDeviceStreams());
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

void SSBDemodGUI::onWidgetRolled(QWidget* widget, bool rollDown)
{
    (void) widget;
    (void) rollDown;
}

SSBDemodGUI::SSBDemodGUI(PluginAPI* pluginAPI, DeviceUISet *deviceUISet, BasebandSampleSink *rxChannel, QWidget* parent) :
	ChannelGUI(parent),
	ui(new Ui::SSBDemodGUI),
	m_pluginAPI(pluginAPI),
	m_deviceUISet(deviceUISet),
	m_channelMarker(this),
	m_doApplySettings(true),
    m_spectrumRate(6000),
	m_audioBinaural(false),
	m_audioFlipChannels(false),
    m_audioMute(false),
	m_squelchOpen(false),
    m_audioSampleRate(-1)
{
	ui->setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose, true);
	connect(this, SIGNAL(widgetRolled(QWidget*,bool)), this, SLOT(onWidgetRolled(QWidget*,bool)));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onMenuDialogCalled(const QPoint &)));

	m_ssbDemod = (SSBDemod*) rxChannel;
    m_spectrumVis = m_ssbDemod->getSpectrumVis();
	m_spectrumVis->setGLSpectrum(ui->glSpectrum);
	m_ssbDemod->setMessageQueueToGUI(getInputMessageQueue());

    CRightClickEnabler *audioMuteRightClickEnabler = new CRightClickEnabler(ui->audioMute);
    connect(audioMuteRightClickEnabler, SIGNAL(rightClick(const QPoint &)), this, SLOT(audioSelect()));

    ui->deltaFrequencyLabel->setText(QString("%1f").arg(QChar(0x94, 0x03)));
    ui->deltaFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
    ui->deltaFrequency->setValueRange(false, 7, -9999999, 9999999);
	ui->channelPowerMeter->setColorTheme(LevelMeterSignalDB::ColorGreenAndBlue);

    ui->glSpectrum->setCenterFrequency(m_spectrumRate/2);
    ui->glSpectrum->setSampleRate(m_spectrumRate);
	ui->glSpectrum->setDisplayWaterfall(true);
	ui->glSpectrum->setDisplayMaxHold(true);
    ui->glSpectrum->setSsbSpectrum(true);

	connect(&MainCore::instance()->getMasterTimer(), SIGNAL(timeout()), this, SLOT(tick()));

	m_channelMarker.blockSignals(true);
	m_channelMarker.setColor(Qt::green);
    m_channelMarker.setBandwidth(6000);
    m_channelMarker.setCenterFrequency(0);
    m_channelMarker.setTitle("SSB Demodulator");
    m_channelMarker.blockSignals(false);
    m_channelMarker.setVisible(true); // activate signal on the last setting only

    setTitleColor(m_channelMarker.getColor());

    m_settings.setChannelMarker(&m_channelMarker);
    m_settings.setSpectrumGUI(ui->spectrumGUI);

	m_deviceUISet->addChannelMarker(&m_channelMarker);
	m_deviceUISet->addRollupWidget(this);

	connect(&m_channelMarker, SIGNAL(changedByCursor()), this, SLOT(channelMarkerChangedByCursor()));
    connect(&m_channelMarker, SIGNAL(highlightedByCursor()), this, SLOT(channelMarkerHighlightedByCursor()));
    connect(getInputMessageQueue(), SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()));

	ui->spectrumGUI->setBuddies(m_spectrumVis, ui->glSpectrum);

	m_iconDSBUSB.addPixmap(QPixmap("://dsb.png"), QIcon::Normal, QIcon::On);
    m_iconDSBUSB.addPixmap(QPixmap("://usb.png"), QIcon::Normal, QIcon::Off);
	m_iconDSBLSB.addPixmap(QPixmap("://dsb.png"), QIcon::Normal, QIcon::On);
    m_iconDSBLSB.addPixmap(QPixmap("://lsb.png"), QIcon::Normal, QIcon::Off);

    ui->BW->setMaximum(480);
    ui->lowCut->setMaximum(480);
	displaySettings();
	applyBandwidths(m_settings.m_spanLog2, true); // does applySettings(true)
}

SSBDemodGUI::~SSBDemodGUI()
{
	delete ui;
}

bool SSBDemodGUI::blockApplySettings(bool block)
{
    bool ret = !m_doApplySettings;
    m_doApplySettings = !block;
    return ret;
}

void SSBDemodGUI::applySettings(bool force)
{
	if (m_doApplySettings)
	{
        SSBDemod::MsgConfigureSSBDemod* message = SSBDemod::MsgConfigureSSBDemod::create( m_settings, force);
        m_ssbDemod->getInputMessageQueue()->push(message);
	}
}

unsigned int SSBDemodGUI::spanLog2Max()
{
    unsigned int spanLog2 = 0;
    for (; m_ssbDemod->getAudioSampleRate() / (1<<spanLog2) >= 1000; spanLog2++);
    return spanLog2 == 0 ? 0 : spanLog2-1;
}

void SSBDemodGUI::applyBandwidths(unsigned int spanLog2, bool force)
{
    unsigned int s2max = spanLog2Max();
    spanLog2 = spanLog2 > s2max ? s2max : spanLog2;
    unsigned int limit = s2max < 1 ? 0 : s2max - 1;
    ui->spanLog2->setMaximum(limit);
    bool dsb = ui->dsb->isChecked();
    //int spanLog2 = ui->spanLog2->value();
    m_spectrumRate = m_ssbDemod->getAudioSampleRate() / (1<<spanLog2);
    int bw = ui->BW->value();
    int lw = ui->lowCut->value();
    int bwMax = m_ssbDemod->getAudioSampleRate() / (100*(1<<spanLog2));
    int tickInterval = m_spectrumRate / 1200;
    tickInterval = tickInterval == 0 ? 1 : tickInterval;

    qDebug() << "SSBDemodGUI::applyBandwidths:"
            << " s2max:" << s2max
            << " dsb: " << dsb
            << " spanLog2: " << spanLog2
            << " m_spectrumRate: " << m_spectrumRate
            << " bw: " << bw
            << " lw: " << lw
            << " bwMax: " << bwMax
            << " tickInterval: " << tickInterval;

    ui->BW->setTickInterval(tickInterval);
    ui->lowCut->setTickInterval(tickInterval);

    bw = bw < -bwMax ? -bwMax : bw > bwMax ? bwMax : bw;

    if (bw < 0) {
        lw = lw < bw+1 ? bw+1 : lw < 0 ? lw : 0;
    } else if (bw > 0) {
        lw = lw > bw-1 ? bw-1 : lw < 0 ? 0 : lw;
    } else {
        lw = 0;
    }

    if (dsb)
    {
        bw = bw < 0 ? -bw : bw;
        lw = 0;
    }

    QString spanStr = QString::number(bwMax/10.0, 'f', 1);
    QString bwStr   = QString::number(bw/10.0, 'f', 1);
    QString lwStr   = QString::number(lw/10.0, 'f', 1);

    if (dsb)
    {
        ui->BWText->setText(tr("%1%2k").arg(QChar(0xB1, 0x00)).arg(bwStr));
        ui->spanText->setText(tr("%1%2k").arg(QChar(0xB1, 0x00)).arg(spanStr));
        ui->scaleMinus->setText("0");
        ui->scaleCenter->setText("");
        ui->scalePlus->setText(tr("%1").arg(QChar(0xB1, 0x00)));
        ui->lsbLabel->setText("");
        ui->usbLabel->setText("");
        ui->glSpectrum->setCenterFrequency(0);
        ui->glSpectrum->setSampleRate(2*m_spectrumRate);
        ui->glSpectrum->setSsbSpectrum(false);
        ui->glSpectrum->setLsbDisplay(false);
    }
    else
    {
        ui->BWText->setText(tr("%1k").arg(bwStr));
        ui->spanText->setText(tr("%1k").arg(spanStr));
        ui->scaleMinus->setText("-");
        ui->scaleCenter->setText("0");
        ui->scalePlus->setText("+");
        ui->lsbLabel->setText("LSB");
        ui->usbLabel->setText("USB");
        ui->glSpectrum->setCenterFrequency(m_spectrumRate/2);
        ui->glSpectrum->setSampleRate(m_spectrumRate);
        ui->glSpectrum->setSsbSpectrum(true);
        ui->glSpectrum->setLsbDisplay(bw < 0);
    }

    ui->lowCutText->setText(tr("%1k").arg(lwStr));

    ui->BW->blockSignals(true);
    ui->lowCut->blockSignals(true);

    ui->BW->setMaximum(bwMax);
    ui->BW->setMinimum(dsb ? 0 : -bwMax);
    ui->BW->setValue(bw);

    ui->lowCut->setMaximum(dsb ? 0 :  bwMax);
    ui->lowCut->setMinimum(dsb ? 0 : -bwMax);
    ui->lowCut->setValue(lw);

    ui->lowCut->blockSignals(false);
    ui->BW->blockSignals(false);

    ui->channelPowerMeter->setRange(SSBDemodSettings::m_minPowerThresholdDB, 0);

    m_settings.m_dsb = dsb;
    m_settings.m_spanLog2 = spanLog2;
    m_settings.m_rfBandwidth = bw * 100;
    m_settings.m_lowCutoff = lw * 100;

    applySettings(force);

    bool wasBlocked = blockApplySettings(true);
    m_channelMarker.setBandwidth(bw * 200);
    m_channelMarker.setSidebands(dsb ? ChannelMarker::dsb : bw < 0 ? ChannelMarker::lsb : ChannelMarker::usb);
    ui->dsb->setIcon(bw < 0 ? m_iconDSBLSB: m_iconDSBUSB);
    if (!dsb) { m_channelMarker.setLowCutoff(lw * 100); }
    blockApplySettings(wasBlocked);
}

void SSBDemodGUI::displaySettings()
{
    m_channelMarker.blockSignals(true);
    m_channelMarker.setCenterFrequency(m_settings.m_inputFrequencyOffset);
    m_channelMarker.setBandwidth(m_settings.m_rfBandwidth * 2);
    m_channelMarker.setTitle(m_settings.m_title);
    m_channelMarker.setLowCutoff(m_settings.m_lowCutoff);

    ui->flipSidebands->setEnabled(!m_settings.m_dsb);

    if (m_settings.m_dsb) {
        m_channelMarker.setSidebands(ChannelMarker::dsb);
    } else {
        if (m_settings.m_rfBandwidth < 0) {
            m_channelMarker.setSidebands(ChannelMarker::lsb);
            ui->dsb->setIcon(m_iconDSBLSB);
        } else {
            m_channelMarker.setSidebands(ChannelMarker::usb);
            ui->dsb->setIcon(m_iconDSBUSB);
        }
    }

    m_channelMarker.blockSignals(false);
    m_channelMarker.setColor(m_settings.m_rgbColor); // activate signal on the last setting only

    setTitleColor(m_settings.m_rgbColor);
    setWindowTitle(m_channelMarker.getTitle());

    blockApplySettings(true);

    ui->deltaFrequency->setValue(m_channelMarker.getCenterFrequency());

    ui->agc->setChecked(m_settings.m_agc);
    ui->agcClamping->setChecked(m_settings.m_agcClamping);
    ui->audioBinaural->setChecked(m_settings.m_audioBinaural);
    ui->audioFlipChannels->setChecked(m_settings.m_audioFlipChannels);
    ui->audioMute->setChecked(m_settings.m_audioMute);
    ui->deltaFrequency->setValue(m_channelMarker.getCenterFrequency());

    // Prevent uncontrolled triggering of applyBandwidths
    ui->spanLog2->blockSignals(true);
    ui->dsb->blockSignals(true);
    ui->BW->blockSignals(true);

    ui->dsb->setChecked(m_settings.m_dsb);
    ui->spanLog2->setValue(1 + ui->spanLog2->maximum() - m_settings.m_spanLog2);

    ui->BW->setValue(m_settings.m_rfBandwidth / 100.0);
    QString s = QString::number(m_settings.m_rfBandwidth/1000.0, 'f', 1);

    if (m_settings.m_dsb)
    {
        ui->BWText->setText(tr("%1%2k").arg(QChar(0xB1, 0x00)).arg(s));
    }
    else
    {
        ui->BWText->setText(tr("%1k").arg(s));
    }

    ui->spanLog2->blockSignals(false);
    ui->dsb->blockSignals(false);
    ui->BW->blockSignals(false);

    // The only one of the four signals triggering applyBandwidths will trigger it once only with all other values
    // set correctly and therefore validate the settings and apply them to dependent widgets
    ui->lowCut->setValue(m_settings.m_lowCutoff / 100.0);
    ui->lowCutText->setText(tr("%1k").arg(m_settings.m_lowCutoff / 1000.0));

    int volume = CalcDb::dbPower(m_settings.m_volume);
    ui->volume->setValue(volume);
    ui->volumeText->setText(QString("%1").arg(volume));

    ui->agcTimeLog2->setValue(m_settings.m_agcTimeLog2);
    s = QString::number((1<<ui->agcTimeLog2->value()), 'f', 0);
    ui->agcTimeText->setText(s);

    ui->agcPowerThreshold->setValue(m_settings.m_agcPowerThreshold);
    displayAGCPowerThreshold(ui->agcPowerThreshold->value());
    displayAGCThresholdGate(m_settings.m_agcThresholdGate);

    displayStreamIndex();

    blockApplySettings(false);
}

void SSBDemodGUI::displayStreamIndex()
{
    if (m_deviceUISet->m_deviceMIMOEngine) {
        setStreamIndicator(tr("%1").arg(m_settings.m_streamIndex));
    } else {
        setStreamIndicator("S"); // single channel indicator
    }
}

void SSBDemodGUI::displayAGCPowerThreshold(int value)
{
    if (value == SSBDemodSettings::m_minPowerThresholdDB)
    {
        ui->agcPowerThresholdText->setText("---");
    }
    else
    {
        QString s = QString::number(value, 'f', 0);
        ui->agcPowerThresholdText->setText(s);
    }
}

void SSBDemodGUI::displayAGCThresholdGate(int value)
{
    QString s = QString::number(value, 'f', 0);
    ui->agcThresholdGateText->setText(s);
    int dialValue = value;

    if (value > 20) {
        dialValue = ((value - 20) / 10) + 20;
    }

    ui->agcThresholdGate->setValue(dialValue);
}

void SSBDemodGUI::leaveEvent(QEvent*)
{
	m_channelMarker.setHighlighted(false);
}

void SSBDemodGUI::enterEvent(QEvent*)
{
	m_channelMarker.setHighlighted(true);
}

void SSBDemodGUI::audioSelect()
{
    qDebug("SSBDemodGUI::audioSelect");
    AudioSelectDialog audioSelect(DSPEngine::instance()->getAudioDeviceManager(), m_settings.m_audioDeviceName);
    audioSelect.exec();

    if (audioSelect.m_selected)
    {
        m_settings.m_audioDeviceName = audioSelect.m_audioDeviceName;
        applySettings();
    }
}

void SSBDemodGUI::tick()
{
    double magsqAvg, magsqPeak;
    int nbMagsqSamples;
    m_ssbDemod->getMagSqLevels(magsqAvg, magsqPeak, nbMagsqSamples);
    double powDbAvg = CalcDb::dbPower(magsqAvg);
    double powDbPeak = CalcDb::dbPower(magsqPeak);

    ui->channelPowerMeter->levelChanged(
            (SSBDemodSettings::m_mminPowerThresholdDBf + powDbAvg) / SSBDemodSettings::m_mminPowerThresholdDBf,
            (SSBDemodSettings::m_mminPowerThresholdDBf + powDbPeak) / SSBDemodSettings::m_mminPowerThresholdDBf,
            nbMagsqSamples);

    if (m_tickCount % 4 == 0) {
        ui->channelPower->setText(tr("%1 dB").arg(powDbAvg, 0, 'f', 1));
    }

    int audioSampleRate = m_ssbDemod->getAudioSampleRate();
    bool squelchOpen = m_ssbDemod->getAudioActive();

    if ((audioSampleRate != m_audioSampleRate) || (squelchOpen != m_squelchOpen))
    {
        if (audioSampleRate < 0) {
            ui->audioMute->setStyleSheet("QToolButton { background-color : red; }");
        } else if (squelchOpen) {
            ui->audioMute->setStyleSheet("QToolButton { background-color : green; }");
        } else {
            ui->audioMute->setStyleSheet("QToolButton { background:rgb(79,79,79); }");
        }

        m_audioSampleRate = audioSampleRate;
		m_squelchOpen = squelchOpen;
    }

    m_tickCount++;
}

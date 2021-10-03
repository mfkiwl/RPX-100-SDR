///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2015 Bernhard Isemann, oe3bia                                   //
// Copyright (C) 2020 Jon Beniston, M7RCE                                        //
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
#include <QFileDialog>

#include "ui_audioinputgui.h"
#include "gui/colormapper.h"
#include "gui/glspectrum.h"
#include "gui/crightclickenabler.h"
#include "gui/basicdevicesettingsdialog.h"
#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "audioinputgui.h"

#include "device/deviceapi.h"
#include "device/deviceuiset.h"

AudioInputGui::AudioInputGui(DeviceUISet *deviceUISet, QWidget* parent) :
    DeviceGUI(parent),
    ui(new Ui::AudioInputGui),
    m_deviceUISet(deviceUISet),
    m_forceSettings(true),
    m_settings(),
    m_sampleSource(nullptr),
    m_centerFrequency(0)
{
    m_sampleSource = (AudioInput*) m_deviceUISet->m_deviceAPI->getSampleSource();

    ui->setupUi(this);

    connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(updateHardware()));

    CRightClickEnabler *startStopRightClickEnabler = new CRightClickEnabler(ui->startStop);
    connect(startStopRightClickEnabler, SIGNAL(rightClick(const QPoint &)), this, SLOT(openDeviceSettingsDialog(const QPoint &)));

    displaySettings();

    connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()), Qt::QueuedConnection);
    m_sampleSource->setMessageQueueToGUI(&m_inputMessageQueue);
}

AudioInputGui::~AudioInputGui()
{
    delete ui;
}

void AudioInputGui::destroy()
{
    delete this;
}

void AudioInputGui::resetToDefaults()
{
    m_settings.resetToDefaults();
    displaySettings();
    sendSettings();
}

QByteArray AudioInputGui::serialize() const
{
    return m_settings.serialize();
}

bool AudioInputGui::deserialize(const QByteArray& data)
{
    if(m_settings.deserialize(data))
    {
        displaySettings();
        m_forceSettings = true;
        sendSettings();
        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}

bool AudioInputGui::handleMessage(const Message& message)
{
    if (AudioInput::MsgConfigureAudioInput::match(message))
    {
        const AudioInput::MsgConfigureAudioInput& cfg = (AudioInput::MsgConfigureAudioInput&) message;
        m_settings = cfg.getSettings();
        blockApplySettings(true);
        displaySettings();
        blockApplySettings(false);
        return true;
    }
    else if (AudioInput::MsgStartStop::match(message))
    {
        AudioInput::MsgStartStop& notif = (AudioInput::MsgStartStop&) message;
        blockApplySettings(true);
        ui->startStop->setChecked(notif.getStartStop());
        blockApplySettings(false);

        return true;
    }
    else
    {
        return false;
    }
}

void AudioInputGui::handleInputMessages()
{
    Message* message;

    while ((message = m_inputMessageQueue.pop()) != 0)
    {
        qDebug("AudioInputGui::handleInputMessages: message: %s", message->getIdentifier());

        if (DSPSignalNotification::match(*message))
        {
            DSPSignalNotification* notif = (DSPSignalNotification*) message;
            m_sampleRate = notif->getSampleRate();
            m_centerFrequency = notif->getCenterFrequency();
            qDebug("AudioInputGui::handleInputMessages: DSPSignalNotification: SampleRate: %d", notif->getSampleRate());
            updateSampleRateAndFrequency();

            delete message;
        }
        else
        {
            if (handleMessage(*message))
            {
                delete message;
            }
        }
    }
}

void AudioInputGui::updateSampleRateAndFrequency()
{
/*
    // Can't seem to get main spectrum to only display real part for mono/I-channel only
    if (m_settings.m_iqMapping <= AudioInputSettings::IQMapping::R)
    {
        m_deviceUISet->getSpectrum()->setSampleRate(m_sampleRate / 2);
        m_deviceUISet->getSpectrum()->setCenterFrequency(m_sampleRate / 4);
        m_deviceUISet->getSpectrum()->setSsbSpectrum(true);
        m_deviceUISet->getSpectrum()->setLsbDisplay(false);
    }
    else
*/
    {
        m_deviceUISet->getSpectrum()->setSampleRate(m_sampleRate);
        m_deviceUISet->getSpectrum()->setCenterFrequency(m_centerFrequency);
        m_deviceUISet->getSpectrum()->setSsbSpectrum(false);
        m_deviceUISet->getSpectrum()->setLsbDisplay(false);
    }
    ui->deviceRateText->setText(tr("%1k").arg((float)m_sampleRate / 1000));
}

void AudioInputGui::refreshDeviceList()
{
    ui->device->blockSignals(true);
    AudioDeviceManager *audioDeviceManager = DSPEngine::instance()->getAudioDeviceManager();
    const QList<QAudioDeviceInfo>& audioList = audioDeviceManager->getInputDevices();

    ui->device->clear();
    for (const auto &itAudio : audioList)
    {
        ui->device->addItem(AudioInputSettings::getFullDeviceName(itAudio));
    }
    ui->device->blockSignals(false);
}

void AudioInputGui::refreshSampleRates(QString deviceName)
{
    ui->sampleRate->blockSignals(true);
    ui->sampleRate->clear();
    const auto deviceInfos = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    for (const QAudioDeviceInfo &deviceInfo : deviceInfos)
    {
        if (deviceName == AudioInputSettings::getFullDeviceName(deviceInfo))
        {
            QList<int> sampleRates = deviceInfo.supportedSampleRates();
            for(int i = 0; i < sampleRates.size(); ++i)
            {
                ui->sampleRate->addItem(QString("%1").arg(sampleRates[i]));
            }
        }
    }
    ui->sampleRate->blockSignals(false);

    int index = ui->sampleRate->findText(QString("%1").arg(m_settings.m_sampleRate));
    if (index >= 0)
        ui->sampleRate->setCurrentIndex(index);
    else
        ui->sampleRate->setCurrentIndex(0);
}

void AudioInputGui::displaySettings()
{
    refreshDeviceList();
    int index = ui->device->findText(m_settings.m_deviceName);
    if (index >= 0)
        ui->device->setCurrentIndex(index);
    else
        ui->device->setCurrentIndex(0);
    ui->decim->setCurrentIndex(m_settings.m_log2Decim);
    ui->volume->setValue((int)(m_settings.m_volume*10.0f));
    ui->volumeText->setText(QString("%1").arg(m_settings.m_volume, 3, 'f', 1));
    ui->channels->setCurrentIndex((int)m_settings.m_iqMapping);
    refreshSampleRates(ui->device->currentText());
}

void AudioInputGui::on_device_currentIndexChanged(int index)
{
    (void) index;
    m_settings.m_deviceName = ui->device->currentText();
    refreshSampleRates(m_settings.m_deviceName);
    sendSettings();
}

void AudioInputGui::on_sampleRate_currentIndexChanged(int index)
{
    (void) index;
    m_settings.m_sampleRate = ui->sampleRate->currentText().toInt();
    sendSettings();
}

void AudioInputGui::on_decim_currentIndexChanged(int index)
{
    if ((index < 0) || (index > 6)) {
        return;
    }

    m_settings.m_log2Decim = index;
    sendSettings();
}

void AudioInputGui::on_volume_valueChanged(int value)
{
    m_settings.m_volume = value/10.0f;
    ui->volumeText->setText(QString("%1").arg(m_settings.m_volume, 3, 'f', 1));
    sendSettings();
}

void AudioInputGui::on_channels_currentIndexChanged(int index)
{
    m_settings.m_iqMapping = (AudioInputSettings::IQMapping)index;
    updateSampleRateAndFrequency();
    sendSettings();
}

void AudioInputGui::on_startStop_toggled(bool checked)
{
    if (m_doApplySettings)
    {
        AudioInput::MsgStartStop *message = AudioInput::MsgStartStop::create(checked);
        m_sampleSource->getInputMessageQueue()->push(message);
    }
}

void AudioInputGui::sendSettings()
{
    if(!m_updateTimer.isActive())
        m_updateTimer.start(100);
}

void AudioInputGui::updateHardware()
{
    if (m_doApplySettings)
    {
        AudioInput::MsgConfigureAudioInput* message = AudioInput::MsgConfigureAudioInput::create(m_settings, m_forceSettings);
        m_sampleSource->getInputMessageQueue()->push(message);
        m_forceSettings = false;
        m_updateTimer.stop();
    }
}

void AudioInputGui::openDeviceSettingsDialog(const QPoint& p)
{
    BasicDeviceSettingsDialog dialog(this);
    dialog.setUseReverseAPI(m_settings.m_useReverseAPI);
    dialog.setReverseAPIAddress(m_settings.m_reverseAPIAddress);
    dialog.setReverseAPIPort(m_settings.m_reverseAPIPort);
    dialog.setReverseAPIDeviceIndex(m_settings.m_reverseAPIDeviceIndex);

    dialog.move(p);
    dialog.exec();

    m_settings.m_useReverseAPI = dialog.useReverseAPI();
    m_settings.m_reverseAPIAddress = dialog.getReverseAPIAddress();
    m_settings.m_reverseAPIPort = dialog.getReverseAPIPort();
    m_settings.m_reverseAPIDeviceIndex = dialog.getReverseAPIDeviceIndex();

    sendSettings();
}

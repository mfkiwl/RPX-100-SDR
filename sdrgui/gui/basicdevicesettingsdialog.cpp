#include "basicdevicesettingsdialog.h"
#include "ui_basicdevicesettingsdialog.h"

BasicDeviceSettingsDialog::BasicDeviceSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BasicDeviceSettingsDialog),
    m_hasChanged(false)
{
    ui->setupUi(this);
    setUseReverseAPI(false);
    setReverseAPIAddress("127.0.0.1");
    setReverseAPIPort(8888);
    setReverseAPIDeviceIndex(0);
}

BasicDeviceSettingsDialog::~BasicDeviceSettingsDialog()
{
    delete ui;
}

void BasicDeviceSettingsDialog::setUseReverseAPI(bool useReverseAPI)
{
    m_useReverseAPI = useReverseAPI;
    ui->reverseAPI->setChecked(m_useReverseAPI);
}

void BasicDeviceSettingsDialog::setReverseAPIAddress(const QString& address)
{
    m_reverseAPIAddress = address;
    ui->reverseAPIAddress->setText(m_reverseAPIAddress);
}

void BasicDeviceSettingsDialog::setReverseAPIPort(uint16_t port)
{
    if (port < 1024) {
        return;
    } else {
        m_reverseAPIPort = port;
    }

    ui->reverseAPIPort->setText(tr("%1").arg(m_reverseAPIPort));
}

void BasicDeviceSettingsDialog::setReverseAPIDeviceIndex(uint16_t deviceIndex)
{
    m_reverseAPIDeviceIndex = deviceIndex > 99 ? 99 : deviceIndex;
    ui->reverseAPIDeviceIndex->setText(tr("%1").arg(m_reverseAPIDeviceIndex));
}

void BasicDeviceSettingsDialog::on_reverseAPI_toggled(bool checked)
{
    m_useReverseAPI = checked;
}

void BasicDeviceSettingsDialog::on_reverseAPIAddress_editingFinished()
{
    m_reverseAPIAddress = ui->reverseAPIAddress->text();
}

void BasicDeviceSettingsDialog::on_reverseAPIPort_editingFinished()
{
    bool dataOk;
    int reverseAPIPort = ui->reverseAPIPort->text().toInt(&dataOk);

    if((!dataOk) || (reverseAPIPort < 1024) || (reverseAPIPort > 65535)) {
        return;
    } else {
        m_reverseAPIPort = reverseAPIPort;
    }
}

void BasicDeviceSettingsDialog::on_reverseAPIDeviceIndex_editingFinished()
{
    bool dataOk;
    int reverseAPIDeviceIndex = ui->reverseAPIDeviceIndex->text().toInt(&dataOk);

    if ((!dataOk) || (reverseAPIDeviceIndex < 0)) {
        return;
    } else {
        m_reverseAPIDeviceIndex = reverseAPIDeviceIndex;
    }
}

void BasicDeviceSettingsDialog::accept()
{
    m_hasChanged = true;
    QDialog::accept();
}

#include <QColorDialog>

#include "basicfeaturesettingsdialog.h"
#include "ui_basicfeaturesettingsdialog.h"

BasicFeatureSettingsDialog::BasicFeatureSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BasicFeatureSettingsDialog),
    m_hasChanged(false)
{
    ui->setupUi(this);
    ui->title->setText(m_title);
    m_color =m_color;
    paintColor();
}

BasicFeatureSettingsDialog::~BasicFeatureSettingsDialog()
{
    delete ui;
}

void BasicFeatureSettingsDialog::setTitle(const QString& title)
{
    ui->title->blockSignals(true);
    ui->title->setText(title);
    m_title = title;
    ui->title->blockSignals(false);
}

void BasicFeatureSettingsDialog::setColor(const QColor& color)
{
    m_color = color;
    paintColor();
}

void BasicFeatureSettingsDialog::paintColor()
{
    QPixmap pm(24, 24);
    pm.fill(m_color);
    ui->colorBtn->setIcon(pm);
    ui->colorText->setText(tr("#%1%2%3")
        .arg(m_color.red(), 2, 16, QChar('0'))
        .arg(m_color.green(), 2, 16, QChar('0'))
        .arg(m_color.blue(), 2, 16, QChar('0')));
}

void BasicFeatureSettingsDialog::on_colorBtn_clicked()
{
    QColor c = m_color;
    c = QColorDialog::getColor(c, this, tr("Select Color for Channel"), QColorDialog::DontUseNativeDialog);

    if (c.isValid())
    {
        m_color = c;
        paintColor();
    }
}

void BasicFeatureSettingsDialog::on_title_editingFinished()
{
    m_title = ui->title->text();
}

void BasicFeatureSettingsDialog::on_reverseAPI_toggled(bool checked)
{
    m_useReverseAPI = checked;
}

void BasicFeatureSettingsDialog::on_reverseAPIAddress_editingFinished()
{
    m_reverseAPIAddress = ui->reverseAPIAddress->text();
}

void BasicFeatureSettingsDialog::on_reverseAPIPort_editingFinished()
{
    bool dataOk;
    int reverseAPIPort = ui->reverseAPIPort->text().toInt(&dataOk);

    if((!dataOk) || (reverseAPIPort < 1024) || (reverseAPIPort > 65535)) {
        return;
    } else {
        m_reverseAPIPort = reverseAPIPort;
    }
}

void BasicFeatureSettingsDialog::on_reverseAPIFeatureSetIndex_editingFinished()
{
    bool dataOk;
    int reverseAPIFeatureSetIndex = ui->reverseAPIFeatureSetIndex->text().toInt(&dataOk);

    if ((!dataOk) || (reverseAPIFeatureSetIndex < 0)) {
        return;
    } else {
        m_reverseAPIFeatureSetIndex = reverseAPIFeatureSetIndex;
    }
}

void BasicFeatureSettingsDialog::on_reverseAPIFeatureIndex_editingFinished()
{
    bool dataOk;
    int reverseAPIFeatureIndex = ui->reverseAPIFeatureIndex->text().toInt(&dataOk);

    if ((!dataOk) || (reverseAPIFeatureIndex < 0)) {
        return;
    } else {
        m_reverseAPIFeatureIndex = reverseAPIFeatureIndex;
    }
}

void BasicFeatureSettingsDialog::accept()
{
    m_hasChanged = true;
    QDialog::accept();
}

void BasicFeatureSettingsDialog::setUseReverseAPI(bool useReverseAPI)
{
    m_useReverseAPI = useReverseAPI;
    ui->reverseAPI->setChecked(m_useReverseAPI);
}

void BasicFeatureSettingsDialog::setReverseAPIAddress(const QString& address)
{
    m_reverseAPIAddress = address;
    ui->reverseAPIAddress->setText(m_reverseAPIAddress);
}

void BasicFeatureSettingsDialog::setReverseAPIPort(uint16_t port)
{
    if (port < 1024) {
        return;
    } else {
        m_reverseAPIPort = port;
    }

    ui->reverseAPIPort->setText(tr("%1").arg(m_reverseAPIPort));
}

void BasicFeatureSettingsDialog::setReverseAPIFeatureSetIndex(uint16_t featureSetIndex)
{
    m_reverseAPIFeatureSetIndex = featureSetIndex > 99 ? 99 : featureSetIndex;
    ui->reverseAPIFeatureSetIndex->setText(tr("%1").arg(m_reverseAPIFeatureSetIndex));
}

void BasicFeatureSettingsDialog::setReverseAPIFeatureIndex(uint16_t featureIndex)
{
    m_reverseAPIFeatureIndex = featureIndex > 99 ? 99 : featureIndex;
    ui->reverseAPIFeatureIndex->setText(tr("%1").arg(m_reverseAPIFeatureIndex));
}

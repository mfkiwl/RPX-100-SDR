///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 oe3bia                                                      //
// written by Bernhard Isemann                                                  //
//                                                                               //
// OpenGL interface modernization.                                               //
// See: http://doc.qt.io/qt-5/qopenglshaderprogram.html                          //
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

#include <QDebug>

#include "transverterdialog.h"

#include "ui_transverterdialog.h"


TransverterDialog::TransverterDialog(qint64& deltaFrequency, bool& deltaFrequencyActive, bool& iqOrder, QWidget* parent) :
    QDialog(parent),
    ui(new Ui::TransverterDialog),
    m_deltaFrequency(deltaFrequency),
    m_deltaFrequencyActive(deltaFrequencyActive),
    m_iqOrder(iqOrder)
{
    qDebug() << "TransverterDialog::TransverterDialog: " << m_iqOrder;
    ui->setupUi(this);
    ui->deltaFrequencyLabel->setText(QString("%1f").arg(QChar(0x94, 0x03)));
    ui->deltaFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
    ui->deltaFrequency->setValueRange(false, 10, -9999999999L, 9999999999L);
    ui->deltaFrequency->setValue(m_deltaFrequency);
    ui->deltaFrequencyActive->setChecked(m_deltaFrequencyActive);
    ui->iqOrder->setEnabled(true);
    ui->iqOrder->setChecked(m_iqOrder);
    ui->iqOrder->setText(m_iqOrder ? "IQ" : "QI");
}

TransverterDialog::~TransverterDialog()
{
    delete ui;
}

void TransverterDialog::accept()
{
    m_deltaFrequency = ui->deltaFrequency->getValueNew();
    m_deltaFrequencyActive = ui->deltaFrequencyActive->isChecked();
    m_iqOrder = ui->iqOrder->isChecked();
    QDialog::accept();
}

void TransverterDialog::on_iqOrder_toggled(bool checked)
{
    ui->iqOrder->setText(checked ? "IQ" : "QI");
}

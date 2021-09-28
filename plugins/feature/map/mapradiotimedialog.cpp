///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2021 Jon Beniston, M7RCE                                        //
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

#include "mapradiotimedialog.h"

#include <QDebug>

#include "channel/channelwebapiutils.h"
#include "mapgui.h"

MapRadioTimeDialog::MapRadioTimeDialog(MapGUI *gui, QWidget* parent) :
    QDialog(parent),
    m_gui(gui),
    ui(new Ui::MapRadioTimeDialog)
{
    ui->setupUi(this);
    // Don't call updateTable until m_gui->getAzEl() will return valid location
}

MapRadioTimeDialog::~MapRadioTimeDialog()
{
    delete ui;
}

void MapRadioTimeDialog::updateTable()
{
    AzEl azEl = *m_gui->getAzEl();
    ui->transmitters->setSortingEnabled(false);
    const QList<RadioTimeTransmitter> transmitters = m_gui->getRadioTimeTransmitters();
    ui->transmitters->setRowCount(0);
    ui->transmitters->setRowCount(transmitters.size());
    QListIterator<RadioTimeTransmitter> i(transmitters);
    int row = 0;
    for (int i = 0; i < transmitters.size(); i++)
    {
        ui->transmitters->setItem(row, TRANSMITTER_COL_CALLSIGN, new QTableWidgetItem(transmitters[i].m_callsign));
        QTableWidgetItem *freq = new QTableWidgetItem();
        freq->setText(QString("%1").arg(transmitters[i].m_frequency/1000.0));
        freq->setData(Qt::UserRole, transmitters[i].m_frequency);
        ui->transmitters->setItem(row, TRANSMITTER_COL_FREQUENCY, freq);
        ui->transmitters->setItem(row, TRANSMITTER_COL_LOCATION, new QTableWidgetItem(QString("%1,%2").arg(transmitters[i].m_latitude).arg(transmitters[i].m_longitude)));
        ui->transmitters->setItem(row, TRANSMITTER_COL_POWER, new QTableWidgetItem(QString("%1").arg(transmitters[i].m_power)));
        azEl.setTarget(transmitters[i].m_latitude, transmitters[i].m_longitude, 1.0);
        azEl.calculate();
        ui->transmitters->setItem(row, TRANSMITTER_COL_AZIMUTH, new QTableWidgetItem(QString("%1").arg(round(azEl.getAzimuth()))));
        ui->transmitters->setItem(row, TRANSMITTER_COL_ELEVATION, new QTableWidgetItem(QString("%1").arg(round(azEl.getElevation()))));
        int km = round(azEl.getDistance()/1000);
        QTableWidgetItem *dist = new QTableWidgetItem();
        dist->setData(Qt::DisplayRole, km);
        ui->transmitters->setItem(row, TRANSMITTER_COL_DISTANCE, dist);
        row++;
    }
    ui->transmitters->setSortingEnabled(true);
    ui->transmitters->resizeColumnsToContents();
}

void MapRadioTimeDialog::accept()
{
    QDialog::accept();
}

void MapRadioTimeDialog::on_transmitters_cellDoubleClicked(int row, int column)
{
    if ((column == TRANSMITTER_COL_CALLSIGN) || (column ==TRANSMITTER_COL_LOCATION))
    {
        // Find transmitter on map
        QString location = ui->transmitters->item(row, column)->text();
        m_gui->find(location);
    }
    else if (column == TRANSMITTER_COL_FREQUENCY)
    {
        // Tune to transmitter freq
        ChannelWebAPIUtils::setCenterFrequency(0, ui->transmitters->item(row, column)->data(Qt::UserRole).toDouble());
    }
}

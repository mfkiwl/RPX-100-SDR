///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Edouard Griffiths, F4EXB                                   //
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

#include "dynamicitemsettinggui.h"

DynamicItemSettingGUI::DynamicItemSettingGUI(ItemSettingGUI *itemSettingGUI, const QString& name, QObject *parent) :
    QObject(parent),
    m_itemSettingGUI(itemSettingGUI),
    m_name(name)
{
    connect(m_itemSettingGUI, SIGNAL(valueChanged(double)), this, SLOT(processValueChanged(double)));
}

DynamicItemSettingGUI::~DynamicItemSettingGUI()
{
    disconnect(m_itemSettingGUI, SIGNAL(valueChanged(double)), this, SLOT(processValueChanged(double)));
}

void DynamicItemSettingGUI::processValueChanged(double value) {
    emit valueChanged(m_name, value);
}

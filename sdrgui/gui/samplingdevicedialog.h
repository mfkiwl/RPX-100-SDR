///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 F4EXB                                                      //
// written by Edouard Griffiths                                                  //
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

#ifndef SDRGUI_GUI_SAMPLINGDEVICEDIALOG_H_
#define SDRGUI_GUI_SAMPLINGDEVICEDIALOG_H_

#include <QDialog>
#include <vector>

#include "export.h"

namespace Ui {
    class SamplingDeviceDialog;
}

class SDRGUI_API SamplingDeviceDialog : public QDialog {
    Q_OBJECT

public:
    explicit SamplingDeviceDialog(int deviceType, int deviceTabIndex, QWidget* parent = nullptr);
    ~SamplingDeviceDialog();
    int getSelectedDeviceIndex() const { return m_selectedDeviceIndex; }
    void setSelectedDeviceIndex(int deviceIndex);
    void setTabIndex(int deviceTabIndex) { m_deviceTabIndex = deviceTabIndex; }
    void getDeviceId(QString& id) const;
    int exec();
    bool hasChanged() const { return m_hasChanged; }

private:
    Ui::SamplingDeviceDialog* ui;
    int m_deviceType;
    int m_deviceTabIndex;
    int m_selectedDeviceIndex;
    std::vector<int> m_deviceIndexes;
    bool m_hasChanged;

private slots:
    void on_deviceSelect_currentIndexChanged(int index);
    void accept();
    void reject();
};

#endif /* SDRGUI_GUI_SAMPLINGDEVICEDIALOG_H_ */

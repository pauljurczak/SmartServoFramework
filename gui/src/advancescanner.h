/*!
 * This file is part of SmartServoFramework.
 * Copyright (c) 2014, INRIA, All rights reserved.
 *
 * SmartServoFramework is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software. If not, see <http://www.gnu.org/licenses/lgpl-3.0.txt>.
 *
 * \file AdvanceScanner.h
 * \date 5/09/2014
 * \author Emeric Grange <emeric.grange@inria.fr>
 */

#ifndef ADVANCESCANNER_H
#define ADVANCESCANNER_H

#include <QMainWindow>
#include <QTreeWidgetItem>

#include "../../src/DynamixelSimpleAPI.h"
#include "../../src/HerkuleXSimpleAPI.h"

namespace Ui {
class AdvanceScanner;
}

/*!
 * \brief The AdvanceScanner is a highly configurable GUI tool to scan for Dynamixel and HerkuleX device.
 *
 * It is built using the 'Simple API' and support every scanning scenario possible.
 * You can configure every combination of ports, protocols, speeds, ID range.
 */
class AdvanceScanner : public QMainWindow
{
    Q_OBJECT

    Ui::AdvanceScanner *ui;
    QWidget *parent;

    bool exit_programmed;

    bool scan_running;
    int scans_rounds;
    int scans_id_interval;
    double progress_global;
    double progress_current;

    void setProfil(int profile);
    int servoscan_dxl(DynamixelSimpleAPI *dxl, QTreeWidgetItem *port, int baudrate);
    int servoscan_hkx(HerkuleXSimpleAPI *hkx, QTreeWidgetItem *port, int baudrate);
    void progressbar();
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);

signals:
     void exiting();

public slots:
    void fillWidgets_ports();
    void fillWidgets_speeds();
    void startScan();
    void stopScan();
    void exitScan();
    void quickProfile();
    void fullProfile();

public:
    explicit AdvanceScanner(QMainWindow *main, QWidget *parent = 0);
    ~AdvanceScanner();
    void resizeTables();
};

#endif // ADVANCESCANNER_H

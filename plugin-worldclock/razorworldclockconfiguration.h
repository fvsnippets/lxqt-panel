/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * Razor - a lightweight, Qt based, desktop toolset
 * http://razor-qt.org
 *
 * Copyright: 2012 Razor team
 * Authors:
 *   Kuzma Shapran <kuzma.shapran@gmail.com>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */


#ifndef RAZORWORLDCLOCKCONFIGURATION_H
#define RAZORWORLDCLOCKCONFIGURATION_H

#include <lxqt/lxqtsettings.h>

#include <QtGui/QDialog>
#include <QtGui/QAbstractButton>
#include <QtGui/QFont>
#include <QtCore/QMap>


namespace Ui {
    class RazorWorldClockConfiguration;
}

class RazorWorldClockConfigurationTimeZones;
class QListWidgetItem;

class RazorWorldClockConfiguration : public QDialog
{
    Q_OBJECT

public:
    explicit RazorWorldClockConfiguration(QSettings *settings, QWidget *parent = NULL);
    ~RazorWorldClockConfiguration();

public slots:
    void saveSettings();

private:
    Ui::RazorWorldClockConfiguration *ui;
    QSettings *mSettings;
    LxQt::SettingsCache mOldSettings;

    /*
      Read settings from conf file and put data into controls.
    */
    void loadSettings();

private slots:
    /*
      Saves settings in conf file.
    */
    void dialogButtonsAction(QAbstractButton *);

    void updateTimeZoneButtons();
    void addTimeZone();
    void removeTimeZone();
    void setTimeZoneAsDefault();
    void moveTimeZoneUp();
    void moveTimeZoneDown();

private:
    QString mDefaultTimeZone;

    bool mLockCascadeSettingChanges;

    RazorWorldClockConfigurationTimeZones *mConfigurationTimeZones;

    void setDefault(QListWidgetItem *);
    void setBold(QListWidgetItem *, bool);
};

#endif // RAZORWORLDCLOCKCONFIGURATION_H

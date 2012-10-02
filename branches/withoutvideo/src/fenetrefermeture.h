/**
Copyright Frederic volleyclubstats ,2011
fred@volleyclubstats.com

This file is part of volleyclubstats.

volleyclubstats is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

volleyclubstats is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Volleyclubstats.  If not, see <http://www.gnu.org/licenses/>.
**/

#ifndef FENETREFERMETURE_H
#define FENETREFERMETURE_H

#include <QDialog>
#include "QFile"
#include "QDateTime"
#include "QMessageBox"

namespace Ui {
class FenetreFermeture;
}

class FenetreFermeture : public QDialog
{
    Q_OBJECT
    
public:
    explicit FenetreFermeture(QWidget *parent = 0);
    ~FenetreFermeture();
    
private:
    Ui::FenetreFermeture *ui;

public slots:
    void slot_Sauvegarde();
    void slot_Plustard();
    void slot_Supprimer();
};

#endif // FENETREFERMETURE_H

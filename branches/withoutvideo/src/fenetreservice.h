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

#ifndef FENETRESERVICE_H
#define FENETRESERVICE_H

#include <QDialog>

namespace Ui {
    class FenetreService;
}

class FenetreService : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreService(QString team1,QString team2,bool Tmort=false,QWidget *parent = 0);
    ~FenetreService();

private:
    Ui::FenetreService *ui;

public:
   bool isUS();
};

#endif // FENETRESERVICE_H

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


#ifndef TABLEMATCH_H
#define TABLEMATCH_H

#include <QTableWidget>
#include <QWidget>

class TableMatch : public QTableWidget
{
    Q_OBJECT
    private:
QStringList _listColonne;
public:
    explicit TableMatch(QWidget *parent = 0);
    void Vider();

void AjusterColonnes();

void ActualiserLigne(int num_ligne,QStringList Valeur);

signals:

public slots:

};

#endif // TABLEMATCH_H

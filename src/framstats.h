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

#ifndef FRAMSTATS_H
#define FRAMSTATS_H

#include <QFrame>
#include "QTableWidget"
#include "QLayout"
#include "Equipe.h"

namespace Ui {
class FramStats;
}

class TableStat: public QTableWidget
{

public:

    TableStat(QWidget * parent,Equipe* team,int Action,QStringList ListValeur);
};



class FramStats : public QFrame
{
    Q_OBJECT
    
public:
    explicit FramStats(int action,Equipe* team,QWidget *parent = 0);
    ~FramStats();
    void Init();
    void clean();
    Joueur* PlayerfromNum(QString num);

    
private:
    Ui::FramStats *ui;
    TableStat* _tabStat;
    QStringList _listvaleur;
    QList <Joueur*>_listJoueur;
    int _Action;
    Equipe * _team;

public slots:
    void SlotMiseAJour(bool isSet=false,int numSet=0);
};

#endif // FRAMSTATS_H

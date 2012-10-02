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

#ifndef TWSTATJOUEUR_H
#define TWSTATJOUEUR_H

#include <QTabWidget>
#include "QTableWidget"
#include "QVector"
#include "Joueur.h"
#include "Equipe.h"

namespace Ui {
class TwStatJoueur;
}


class TableState: public QTableWidget
{

public:

   TableState(QWidget * parent,QStringList action,QStringList valeur);
   void Resize();
};



class TwStat : public QTabWidget
{
    Q_OBJECT
    
public:
    explicit TwStat(Joueur * player,Equipe* team,QWidget *parent = 0);

    ~TwStat();
    void Initialisation();
    void InitJoueur();
    void InitEquipe();
private:
    Ui::TwStatJoueur *ui;
    Joueur* _currentJoueur;
    Equipe* _currentTeam;
    QStringList _ListAction;
    QStringList _ListValeur;
    int _NbSet;
    void Connection();
    QVector <TableState*> _VectorStatSet;
    TableState* _statMatch;

public slots:
    void Slot_fermer();
};

#endif // TWSTATJOUEUR_H

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

#ifndef FENETREJOUEURSTAT_H
#define FENETREJOUEURSTAT_H

#include <QDialog>
#include "twstatjoueur.h"
#include "Joueur.h"
#include "Equipe.h"


namespace Ui {
class FenetreJoueurStat;
}

class FenetreJoueurStat : public QDialog
{
    Q_OBJECT
    
public:
   explicit FenetreJoueurStat(Joueur* player,Equipe* team=0,QWidget *parent = 0);



    ~FenetreJoueurStat();
    
private:
    Ui::FenetreJoueurStat *ui;
     TwStat* _tabWidget;
};

#endif // FENETREJOUEURSTAT_H

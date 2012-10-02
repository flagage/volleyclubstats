/**
Copyright Frederic volleyclubstats ,2011
fred@volleyclubstats.com

This file is part of volleyclubstats.

volleyclubstats is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Volleyclubstats.  If not, see <http://www.gnu.org/licenses/>.
**/

#include "fenetrejoueurstat.h"
#include "ui_fenetrejoueurstat.h"


FenetreJoueurStat::FenetreJoueurStat(Joueur* player,Equipe* team,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreJoueurStat)
{
    ui->setupUi(this);

    _tabWidget = new TwStat(player,team,this);

    _tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    ui->gridLayout->addWidget(_tabWidget, 0, 0, 1, 1);
    if (player!=0)
    {
    this->setWindowTitle(player->get_Prenom()+"_"+QString::number(player->get_NumMaillot()));
    }
    else if(team!=0)
    {
        this->setWindowTitle(team->GetNom());
    }
    this->show();
}





FenetreJoueurStat::~FenetreJoueurStat()
{
    if(_tabWidget!=0)
        delete _tabWidget;

delete ui;
}

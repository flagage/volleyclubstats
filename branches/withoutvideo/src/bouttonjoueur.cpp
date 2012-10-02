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

#include "bouttonjoueur.h"
#include "QAction"
#include "QMenu"

BouttonJoueur::BouttonJoueur(QString text, QWidget *parent):
    QPushButton(text,parent)
{

}

void BouttonJoueur::mousePressEvent (QMouseEvent * event)
{

    if(event->button ()==Qt::LeftButton)
    {
        emit lclicked();
    }
    else
    {

        emit rclicked();
    }

}
void BouttonJoueur::SlotMenuJoueur(QAction * action)
{
    if(action->text()=="Modifier Joueur")
    {
        emit ModifJoueur();
    }
    else if(action->text()=="Ajouter Joueur")
    {
        emit AddJoueur();
    }
    else if(action->text()=="Supprimer Joueur")
    {
        emit SupJoueur();
    }
    else if(action->text()=="Statistiques")
    {
        emit AfficheStat();
    }
}

void BouttonJoueur::AjouterMenuBanc()
{
    QMenu * menu=new QMenu(this);
    menu->addAction("Ajouter Joueur");
    menu->addAction("Modifier Joueur");
    menu->addAction("Supprimer Joueur");
    menu->addSeparator();
    menu->addAction("Statistiques");
    this->setMenu(menu);
    connect(menu,SIGNAL(triggered(QAction *)), this, SLOT(SlotMenuJoueur(QAction *)));
}

/*void BouttonJoueur::mousePressEvent (QMouseEvent Qt::RightButton)
{};*/

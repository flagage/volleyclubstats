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

#ifndef FBJOUEUR_H
#define FBJOUEUR_H

#include <QtGui>
#include <QWidget>

#include "ui_dialog.h"
#include "ecran.h"

class fbjoueur : public QDialog
{
    Q_OBJECT
public:
     fbjoueur(Equipe* Team,Joueur *play=0 ,QWidget *parent = 0);
     void Init();
     void Enregistrer();
     void SetjoueurfromIHM(Joueur* play);
     bool isNumeroOk();
     Joueur* GetCurrentJoueur();

signals:

public slots:
     void SlotEnregistrer();
private:
     Ui::FenetreJoueur ui;
     Equipe* _Team;
     Joueur* _curentJoueur;
     bool _modif;

};

#endif // FBJOUEUR_H

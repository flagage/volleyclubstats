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

#ifndef FENETREEQUIPE_H
#define FENETREEQUIPE_H

#include <QDialog>
#include "ecran.h"

namespace Ui {
    class Fenetreequipe;
}

class Fenetreequipe : public QDialog
{
    Q_OBJECT

public:
    explicit Fenetreequipe(Ecran* ecran,QWidget *parent = 0,bool supp=false);
    ~Fenetreequipe();
    void RemplitTableauJoueur(Joueur* player,int row);
    void RaffraichirList();

private:
    Ui::Fenetreequipe *ui;
    Ecran* _ecran;
    QStringList _listColumn;
    Equipe* _currentTeam;
    void Connexion();

public slots:
    void Enregistrer();
    void InitListEquipe();
    void ListChange();
    void Ajouter();
    void Modifier();
    void Supprimer();
    void GestionEquipe();
    //void slot_Export();
    //void slot_Import();
};

#endif // FENETREEQUIPE_H

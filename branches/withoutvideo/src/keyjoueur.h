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

#ifndef KEYJOUEUR_H
#define KEYJOUEUR_H

#include <QWidget>
#include "bouttonjoueur.h"
#include <QLineEdit>
#include "QLabel"
#include "QGridLayout"
#include "Joueur.h"

class KeyJoueur : public QWidget
{
    Q_OBJECT
private :
        BouttonJoueur * buttons[100];
QLineEdit * line[100];
int _nbJoueur;
QLabel* _labelPosition;
QGridLayout*_layout;
bool _Islibero;
int _pos;
QWidget * _parent;
QList <Joueur*> _listjoueur;
int _nbjoueurEnPlace;

public:
explicit KeyJoueur(QWidget *parent = 0,int nbjoueur=0,bool libero=true);
~KeyJoueur();
void createLayout(int pos);
void InitListJoueur(QList <Joueur*> joueur);
void Initialisation();
void Stat();
void Start();
void Rotation(int &joueur);
void RotationM(int &joueur);
QString ChercherJoueur(int &currentposition);
QString ChercherPasseur();
QString ChercherPasseurPosition();
QString GetServeur();
Joueur *RechercheJoueur(int numero);
bool SetLineEdit(QDropEvent * e);
void InitLineEditSize();
void SetAdv(QString nom);
void SetListJoueur(QStringList list);
QString UpdateJoueur(Joueur* player);
QList<Joueur *> GetJoueurTerrain();
void Reinitialisation();
void UpdatePosition();
void Placement(QList<Joueur*> joueur);
signals:
    void Changement(QPushButton *button);
    void JoueurStat(QPushButton *button);
    //void ModifPoste(QPushButton *button);
    void Tlm_en_place();
public slots:
void bouttonLClicked();
void bouttonRClicked();


};

#endif // KEYJOUEUR_H

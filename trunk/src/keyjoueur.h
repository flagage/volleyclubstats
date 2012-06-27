/**
Copyright LAGAGE Frédéric ,2011
flagage@gmail.com

Ce logiciel est un programme informatique servant à capturer en direct des statistiques des joueurs de volley-ball.

Ce logiciel est régi par la licence CeCILLsoumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe à
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL et que vous en avez accepté les
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
void createLayout(int pos);
void InitListJoueur(QList <Joueur*> joueur);
void Initialisation();
void Stat();
void Start();
void Rotation(int &joueur);
void RotationM(int &joueur);
QString ChercherJoueur(int &currentposition);
QString ChercherPasseur();
QString GetServeur();
Joueur *RechercheJoueur(int numero);
bool SetLineEdit(QDropEvent * e);
void InitLineEditSize();
void SetAdv(QString nom);
void SetListJoueur(QStringList list);
QString UpdateJoueur(Joueur* player);
QList<Joueur *> GetJoueurTerrain();
void Reinitialisation();

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

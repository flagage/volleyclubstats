/**
Copyright LAGAGE Fr�d�ric ,2011
flagage@gmail.com

Ce logiciel est un programme informatique servant � capturer en direct des statistiques des joueurs de volley-ball.

Ce logiciel est r�gi par la licence CeCILLsoumise au droit fran�ais et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL telle que diffus�e par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilit� au code source et des droits de copie,
de modification et de redistribution accord�s par cette licence, il n'est
offert aux utilisateurs qu'une garantie limit�e.  Pour les m�mes raisons,
seule une responsabilit� restreinte p�se sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les conc�dants successifs.

A cet �gard  l'attention de l'utilisateur est attir�e sur les risques
associ�s au chargement,  � l'utilisation,  � la modification et/ou au
d�veloppement et � la reproduction du logiciel par l'utilisateur �tant
donn� sa sp�cificit� de logiciel libre, qui peut le rendre complexe �
manipuler et qui le r�serve donc � des d�veloppeurs et des professionnels
avertis poss�dant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invit�s � charger  et  tester  l'ad�quation  du
logiciel � leurs besoins dans des conditions permettant d'assurer la
s�curit� de leurs syst�mes et ou de leurs donn�es et, plus g�n�ralement,
� l'utiliser et l'exploiter dans les m�mes conditions de s�curit�.

Le fait que vous puissiez acc�der � cet en-t�te signifie que vous avez
pris connaissance de la licence CeCILL et que vous en avez accept� les
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

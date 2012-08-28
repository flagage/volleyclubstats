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
#ifndef JOUEUR_H
#define JOUEUR_H

#include <QString>
#include <QDomDocument>
#include <QVector>

#include "stat.h"


class Joueur
{
public:


private:
    QString _Nom;
    QString _Prenom;
    QString _Age;
    int _NLisence;
    int _Tel;
    int _NumMaillot;
    int _Position;
    QString _Email;
    QString _Addresse;
    QString _poste;
    int _num;
    int _nbSet;
    statFinal statMatch;
    statFinal statSet;
    QVector<statFinal*> _listStat;
    QStringList _ListValeur;
    QStringList _ListAction;

public:
    /// constructeur
    Joueur();
    ~Joueur();
    /// acceseur
    QString get_Prenom();
    void set_Prenom(QString prenon);
    QString get_Age();
    void set_Age(QString age);
    int get_NLisence();
    void set_NLisence(int lisence);
    void set_Tel(int tel);
    int get_Tel();
    void set_Email(QString email);
    QString get_Email();
    void set_Addresse(QString add);
    QString get_Addresse();
    void set_poste(QString poste);
    QString get_poste();
    QString get_Nom();
    int get_num();
    void set_Nom(QString nom);
    void set_NumMaillot(int numMaillot);
    int get_NumMaillot();
    /// Enregistrement
    void EnregistrerXML(QDomDocument doc,  QDomElement Equipe);
    void RestaurerXML(QDomNode noeud);
    void EnregistrerStatXML(QDomDocument doc,  QDomElement Equipe);
    void RestaurerStatXML(QDomNode noeud);
    /// Enregistrement Action
   // void Attaque(int position,StatValeur valeur);
  //  void Reception(int position,StatValeur valeur);
  //  void Service(int position,StatValeur valeur);;
    //int GetAction(Action action,StatValeur valeur,int position);

    /// stat
    void addStatMatch(int action,int pos);
    void setStatMatch(int action,int pos,double valeur);
    double getStatMatch(int action,int pos);
    void addStatSet(int action,int pos);
    void setStatSet(int action,int pos,double valeur);
    double getStatSet(int action,int pos);
    void initSet();
    void supStatMatch(int action,int pos);
    void supStatSet(int action,int pos);

    void SetPosition(int numpos);
    int GetPosition();
    void InitialisationStat(int NbSet,QStringList Action,QStringList Valeur);
    QStringList GetListAction();
    QStringList GetListValeur();
    //void SetListAction(QStringList list);

};

#endif // JOUEUR_H

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
#ifndef JOUEUR_H
#define JOUEUR_H

#include <QString>
#include <QDomDocument>


#include "stat.h"


class Joueur
{
public:


private:
    QString _Nom;
    QString _Prenom;
    int _Age;
    int _NLisence;
    int _Tel;
    int _NumMaillot;
    QString _Email;
    QString _Addresse;
    QString _poste;
    int _num;
    //statJoueur tabAction[3];
    statFinal statMatch;
    statFinal statSet;


public:
    /// constructeur
    Joueur();
    /// acceseur
    QString get_Prenom();
    void set_Prenom(QString prenon);
    int get_Age();
    void set_Age(int age);
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
    void SetListAction(QStringList list,QStringList valeur);

};

#endif // JOUEUR_H

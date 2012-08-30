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
#ifndef EQUIPE_H
#define EQUIPE_H
#include "qstring.h"
#include <QList>
#include <QDomDocument>
#include "Joueur.h"
#include "club.h"


class Equipe
{
private:    //attribut
    QString _Nom;
    QVector<statFinal*> _VectorStat;
    QList <Joueur*>_ListeJoueur;
    QString _Division;
    QString _Categorie;
    QStringList _ListValeur;
    QStringList _ListAction;
    int _NbSet;

public: //fonction

    /// acceseur
    QString GetNom();
    void SetNom(QString Nom);

    QList <Joueur*> GetListeJoueur();
    void AddJoueur(Joueur* joue);
    void supJoueur(Joueur* joue);

    /// constructeur
    Equipe();
    Equipe(QString nom);
    ~Equipe();

    void SetDivision(QString div);
    QString GetDivision();
    void SetCategorie(QString cat);
    QString GetCategorie();

    /// Sauvegarde
    void EnregistrerXML(QDomDocument doc,QDomElement root);
    void RestaurerXML(QDomNode noeud);

    /// recherche d'un joueur dans l'equipe
    Joueur* seachjoueur(QString nomJoueur);
    Joueur* seachjoueur(int numjoueur);



    void ExportCVS(QString Fichier);
    void ImportCVS(QString);

    void InitialisationStat(int NbSet,QStringList Action,QStringList Valeur);
    QStringList GetListAction();
    QStringList GetListValeur();
    int GetNbSet();

    /// stat
    void addStatMatch(int action,int pos);
    double getStatMatch(int action,int pos);
    void addStatSet(int action,int pos,int numset);
    void setStatSet(int action,int pos,double valeur,int numset);
    double getStatSet(int action,int pos,int numset);
    void supStatMatch(int action,int pos);
    void supStatSet(int action,int pos,int numset);
    void setStatMatch(int action,int pos,double valeur);




};

#endif // EQUIPE_H

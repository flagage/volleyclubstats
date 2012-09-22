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
    Equipe(Equipe* team);
    ~Equipe();

    /// operateur

    void operator ==(Equipe * team);

    void SetDivision(QString div);
    QString GetDivision();
    void SetCategorie(QString cat);
    QString GetCategorie();

    /// Sauvegarde
    void EnregistrerXML(QDomDocument doc,QDomElement root);
    void RestaurerXML(QDomNode noeud);

    /// recherche d'un joueur dans l'equipe
    Joueur* RechercheJoueur(QString strjoueur);
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
    void initSet(int numset);




};

#endif // EQUIPE_H

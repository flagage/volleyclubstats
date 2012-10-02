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

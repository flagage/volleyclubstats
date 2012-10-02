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



    /// stat
    void addStatMatch(int action,int pos);
    void setStatMatch(int action,int pos,double valeur);
    double getStatMatch(int action,int pos);
    void addStatSet(int action,int pos,int numset);
    void setStatSet(int action,int pos,double valeur,int numset);
    double getStatSet(int action,int pos,int numset);
    void initSet(int numset);
    void supStatMatch(int action,int pos);
    void supStatSet(int action,int pos,int numset);

    void SetPosition(int numpos);
    int GetPosition();
    void InitialisationStat(int NbSet,QStringList Action,QStringList Valeur);
    QStringList GetListAction();
    QStringList GetListValeur();
    int GetNbSet();
    //void SetListAction(QStringList list);

};

#endif // JOUEUR_H

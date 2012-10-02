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

#ifndef MATCH_H
#define MATCH_H


//#include "set.h"
#include "Equipe.h"
#include "Score.h"
#include "matchxml.h"
#include "parametrematch.h"
#include <QDomDocument>
#include <QFile>
#include <QDate>
#include <QMap>

class Match
{

private:
    static Match* instanceMatch;
    Equipe* _currentEquipe;
    Equipe* _EquipeVisiteur;
    ParametreMatch* _ParamMatch;
    Score* _score;

    QString _nomFichier;

    QMap<QString,QString> _MatchSave;
    int _numCurentSet;
     bool _lancementok;
    QTime _TempsSet;
    QList <Joueur*>  _ListTerrain;
    Joueur * _JouerAdvers;
    MatchXml *_Fichierxml;
    int _point;
    int _pointAdv;
    int _faute;
    int _fauteAdv;
    QList <QString> _listPosition;
    QDomDocument _doc;
    QFile _fileXmlCurrent;
    QDomElement _root;
    bool _isStart;
    QStringList _ListEvenement;

protected:
    Match();
    ~Match();
    Match(const Match&);



public:
    static Match* donneInstance();
    static void libereInstance();
    static Match * GetInstance();
    bool lancer();
    void setCurrentEquipe(Equipe* Team);
    void setAdvers(QString advers);
    Equipe* getTeam();
    QString getadvs();
    Score * GetScore();
    QString GetTemps();



    int GetCurentSet();
    void SetNbSet(int i);

    QStringList GetListAction();


    QString GetType();

    void EnregistrerXMl();
    bool FinSet();
    bool isFinMatch();
     void Enregistrer();
    //QString Restaurer(QString id);
    QString GetDate();



    QString GetArbitre();

    QString GetFichierXml();
    void CreerSet(QString score,QStringList list);


    void Enregistrer(QStringList list);

    void Restaurer();

    QString StatString(QString id);

    bool AddAction(QString joueurname,int position, StatValeur valu,int action);
    bool SupAction(QString joueurname, StatValeur valu,int action);
    QList <Joueur*> GetListJoueur();

    /// traitement de la sauvegarde
    void EcritureCurrentMatch();

    void SetJoueurTerr(QList<Joueur *> list);
    QList<Joueur *> GetListJoueurTerr();

    int GetPoint(bool adv=false);
    int GetFaute(bool adv=false);
    void addPoint(bool adv=false);
    void addFaute(bool adv=false);
    void supPoint(bool adv=false);
    void supFaute(bool adv=false);
    /// restauration xml
    void InfoFromXML( QList <Equipe*> listequipe);
    /// acce au parametre du match
    void setParametreMatch(ParametreMatch *);
    ParametreMatch* GetParametreMatch();
    QString Rechercheposte(int post);
    void MiseaJourposte();
    void MiseajourScore();
    void MiseAjourStat(Equipe* team,Joueur *player,int Action,bool isSet=false);
    void MiseAjourStatTeam( QDomElement f,int Action,Equipe* team,bool isSet);
    void MiseAjourStatPlayer( QDomElement f,int Action,Joueur* player,bool isSet);

    bool isStart();
    void setStart(bool);
    void InitListTerrainfromPosition();

    Equipe * GetEquipeVisiteur();
   void EcrireStatMatchxml(QDomElement * element);
   void EcrireStatXml(QDomElement * element,bool isMatch=false);
   Joueur* RechercheJoueur(QString strjoueur);
   void AddJoueurToXml(Joueur * player,bool isset=false);
   void AddSetToXml();

   void SetListEvenement(QStringList);
   QStringList GetListEvenement();

   void AjoutEvenement(QString,QString);
   void SuppElement(QString identifiant);

   void addJoueurTerrain(Joueur* joueur);

};


#endif // MATCH_H

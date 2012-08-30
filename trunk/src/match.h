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
    QList <Joueur*> _ListJoueur;
    QList <Joueur*> _ListTerrain;
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
    void FinSet();
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
    void InitStatFromXml(QDomNode child,int TemOrPl,bool isSet,int numset=0,Joueur* player=0);
    Equipe * GetEquipeVisiteur();
   void EcrireStatMatchxml(QDomElement * element);
   void EcrireStatXml(QDomElement * element);
   Joueur* RechercheJoueur(QString strjoueur);
   void AddJoueurToXml(Joueur * player,bool isset=false);
   void AddSetToXml();

};


#endif // MATCH_H

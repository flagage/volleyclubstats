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
    Equipe* _currrentEquipe;
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


};


#endif // MATCH_H

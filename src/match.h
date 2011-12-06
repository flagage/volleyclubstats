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


#include "set.h"
#include "Score.h"
#include <QDomDocument>
#include <QFile>
#include <QDate>

class Match
{

private:
    static Match* instanceMatch;
    Equipe* _currrentEquipe;
    QString _advers;
    QString _nomFichier;
    QString _Arbitre;
    QString _Type;
    QList <Set*> _ListeSet;
    QMap<QString,QString> _MatchSave;
    Set* _curentset;
    int _nbSet;
    QDateTime _date;
    bool _lancementok;
    QTime _TempsSet;
protected:
    Match();
    Match(const Match&);
    Score* _score;

public:
    static Match* donneInstance();
    static void libereInstance();
    bool lancer();
    void setCurrentEquipe(Equipe* Team);
    void setAdvers(QString advers);
    Equipe* getTeam();
    QString getadvs();
    Set* GetCurrentSet();
    Score * GetScore();
    QString GetTemps();

    Set* GetOldSet(int i);
    int Getnbset();
    void SetNbSet(int i);

    void SetType(QString str);
    QString GetType();

    void EnregistrerXMl();
    void FinSet();
     void Enregistrer();
    //QString Restaurer(QString id);
    QString GetDate();
    void SetDate(QString str);

    void setArbitre(QString);
    QString GetArbitre();

    QString GetFichierXml();
    void CreerSet(QString score,QStringList list);


    void Enregistrer(QStringList list);

    void Restaurer();

    QString StatString(QString id);

};


#endif // MATCH_H

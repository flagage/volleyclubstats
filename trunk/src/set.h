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
#ifndef SET_H
#define SET_H
#include <QString>
#include <QDomDocument>
#include <QList>
#include "Equipe.h"
#include "QDateTime"
#include "volleyInit.h"

class Set
{

private:
    int _ScoreEquipe;
    int _ScoreAdv;
    QString _Commentaire;
    QMap<QString,QString> _SetSave;
    QList <Joueur*> _ListJoueur;
    Equipe* _team;
    QString _ScoreSave;
    QDateTime _DateDebut;
    QTime _TempsSet;

    int _num;
public:
    Set( Equipe *team,int numero);
    void setEquipe(int i);
    void setAdv(int i);
    void setCommetaire(QString msg);
    bool Attaque(QString joueurname,int position,StatValeur valu);
    bool Service(QString joueurname,int position, StatValeur valu);
    bool Reception(QString joueurname,int position, StatValeur valu);
    bool AddAction(QString joueurname,int position, StatValeur valu,int Action);
    void EnregistrerXML( QDomDocument doc,QDomElement root);
    void RestaurerXML();
    void Restaurer();
    void Initialise();
    void Enregistrer();
    void Enregistrer(QStringList list);
    void SetScore(QString Score);
    QString GetTempsSet();
    QString Restaurer(QString id);
    QString ScoreSave();


};

#endif // SET_H

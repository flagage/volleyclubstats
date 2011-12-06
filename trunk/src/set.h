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
#ifndef SET_H
#define SET_H
#include <QString>
#include <QDomDocument>
#include <QList>
#include "Equipe.h"
#include "QDateTime"


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

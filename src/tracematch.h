/**
Copyright LAGAGE Frederic ,2011
flagage@gmail.com

Ce logiciel est un programme informatique servant  capturer en direct des statistiques des joueurs de volley-ball.

Ce logiciel est rgi par la licence CeCILLsoumise au droit franais et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL telle que diffuse par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilit au code source et des droits de copie,
de modification et de redistribution accords par cette licence, il n'est
offert aux utilisateurs qu'une garantie limite.  Pour les mmes raisons,
seule une responsabilit restreinte pse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concdants successifs.

A cet gard  l'attention de l'utilisateur est attire sur les risques
associs au chargement,   l'utilisation,   la modification et/ou au
dveloppement et  la reproduction du logiciel par l'utilisateur tant
donn sa spcificit de logiciel libre, qui peut le rendre complexe
manipuler et qui le rserve donc  des dveloppeurs et des professionnels
avertis possdant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invits  charger  et  tester  l'adquation  du
logiciel  leurs besoins dans des conditions permettant d'assurer la
scurit de leurs systmes et ou de leurs donnes et, plus gnralement,
 l'utiliser et l'exploiter dans les mmes conditions de scurit.

Le fait que vous puissiez accder  cet en-tte signifie que vous avez
pris connaissance de la licence CeCILL et que vous en avez accept les
**/

#ifndef TRACEMATCH_H
#define TRACEMATCH_H
#include "qstring.h"
#include "QObject"
#include "QFile"
#include "QDateTime"

class TraceMatch: public QObject
{
    Q_OBJECT
private:
    QString _file;
public:
    explicit TraceMatch(QObject *parent = 0);
    void SetTrace(QString msg,bool date=true);
    void SetFile(QString filename);

};

#endif // TRACEMATCH_H

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
#ifndef STAT_H
#define STAT_H

#include "QMap"
#include "QStringList"
#include "volleyInit.h"
class statValeur
{
private:
    double vpp;
    double vp;
    double v0;
    double vm;
    double vmm;
    double tot;
    double eff1;
    double eff2;
    double eff3;
    double eff4;

    /// coefficient
    int _coef1;
    int _coef2;
    int _coef3;
    int _coef4;
    int _coef5;

    /// nombre de valeur � afficher

     QStringList _ListValeur;
     QStringList _ListEntre;
public:
    statValeur(QStringList valeur);
    void Initialisation();
    void addValeur(int pos);
    void SupValeur(int pos);
    double getValeur(int pos);
    void setValeur(int pos,double valeur);
    double ValeurEff(int pos);
    void SetValeurEff(int pos,double valeur);
    void init();
    void AddCoef(int C1,int C2,int C3,int C4,int C5);

    QStringList GetListValeurStat();
};

class statFinal
{
private:
    QMap <int,statValeur*>statMap;
    QStringList _listAction;
public:
    statFinal();
    statFinal(QStringList,QStringList);
    ~statFinal();
    void AjoutValeur(int action,int pos);
    void SupValeur(int action, int pos);
    double GetValeur(int action,int pos);
    void SetValeur(int action,int pos,double valeur);
    int GetNbValeur();
    int GetTotal();
    void init();
    //void SetListAction(QStringList list);
    QStringList GetListValeurStat();
};

#endif // STAT_H

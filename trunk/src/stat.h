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

    /// nombre de valeur à afficher

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

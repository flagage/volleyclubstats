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

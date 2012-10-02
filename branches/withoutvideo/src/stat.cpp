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

#include "stat.h"
#include "volleyInit.h"

statValeur::statValeur(QStringList valeur)
{
    this->vpp=0;
    this->vp=0;
    this->v0=0;
    this->vm=0;
    this->vmm=0;
    this->tot=0;


    this->eff1=0;
    this->eff2=0;
    this->eff3=0;
    this->eff4=0;


    this->_coef1=0;
    this->_coef2=0;
    this->_coef3=0;
    this->_coef4=0;
    this->_coef5=0;

    _ListEntre=valeur;

    Initialisation();

}

void statValeur::Initialisation()
{

    for(int k=0;k<_ListEntre.size();k++)
    {
        if(_ListEntre.at(k)=="(")
        {
            QString strValeur=_ListEntre.at(k+1);
            QStringList listCoeff=strValeur.split(";");
            this->AddCoef(listCoeff[0].toInt(),listCoeff[1].toInt(),listCoeff[2].toInt(),listCoeff[3].toInt(),listCoeff[4].toInt());
            break;
        }

        _ListValeur<<_ListEntre.at(k);
    }
}

void statValeur::addValeur(int pos)
{
    switch (pos)
    {
    case 0:
        vpp=vpp+1;
        break;
    case 1:
        vp=vp+1;
        break;
    case 2:
        v0=v0+1;
        break;
    case 3:
        vm=vm+1;
        break;
    case 4:
        vmm=vmm+1;
        break;
    default:
        break;
    }
    tot=tot+1;
    int diff=this->vpp-this->vmm;
    eff3=diff;
    if(tot!=0)
    {

        double effd=(diff/tot);
        eff1=effd*100;
        effd=vpp/tot;
        eff2=effd*100;

        diff=_coef1*vpp+_coef2*vp+_coef3*v0-_coef4*vm-_coef5*vmm;
        effd=(diff/tot);
        eff4=effd;


    }
    else
    {
        eff1=0;
        eff2=0;
        eff4=0;
    }
}

void statValeur::AddCoef(int C1,int C2,int C3,int C4,int C5)
{
    this->_coef1=C1;
    this->_coef2=C2;
    this->_coef3=C3;
    this->_coef4=C4;
    this->_coef5=C5;
}

void statValeur::SupValeur(int pos)
{
    switch (pos)
    {
    case 0:
        if(vpp!=0)
        vpp=vpp-1;
        break;
    case 1:
        if(vp!=0)
        vp=vp-1;
        break;
    case 2:
        if(v0!=0)
        v0=v0-1;
        break;
    case 3:
        if(vm!=0)
        vm=vm-1;
        break;
    case 4:
        if(vmm!=0)
        vmm=vmm-1;
        break;
    default:
        break;
    }
    tot=tot-1;
    int diff=this->vpp-this->vmm;
    eff3=diff;
    if(tot!=0)
    {

        double effd=(diff/tot);
        eff1=effd*100;
        effd=vpp/tot;
        eff2=effd*100;

        diff=_coef1*vpp+_coef2*vp+_coef3*v0-_coef4*vm-_coef5*vmm;
        effd=(diff/tot);
        eff4=effd;


    }
    else
    {
        eff1=0;
        eff2=0;
        eff3=0;
        eff4=0;
    }
}

double statValeur::getValeur(int pos)
{
    switch (pos)
    {
    case 0:
        return vpp;
        break;
    case 1:
        return vp;
        break;
    case 2:
        return v0;
        break;
    case 3:
        return vm;
        break;
    case 4:
        return vmm;
        break;
    case 5:
        return tot;
    default:
        return ValeurEff(pos);
        break;
    }

}

void statValeur::setValeur(int pos,double valeur)
{
    switch (pos)
    {
    case 0:
        //return vpp;
        vpp=valeur;
        break;
    case 1:
        //return vp;
        vp=valeur;
        break;
    case 2:
        //return v0;
        v0=valeur;
        break;
    case 3:
        //return vm;
        vm=valeur;
        break;
    case 4:
        //return vmm;
        vmm=valeur;
        break;
    case 5:
        //return tot;
        tot=valeur;
        break;
    default:
        SetValeurEff(pos,valeur);
        break;
    }

}
void  statValeur::SetValeurEff(int pos,double valeur)
{

    if(this->_ListValeur.at(pos)=="eff1")
    {
        this->eff1=valeur;
    }
    if(this->_ListValeur.at(pos)=="eff2")
    {
        this->eff2=valeur;
    }
    if(this->_ListValeur.at(pos)=="eff3")
    {
        this->eff3=valeur;
    }
    if(this->_ListValeur.at(pos)=="eff4")
    {
        this->eff4=valeur;
    }
}
double statValeur::ValeurEff(int value)
{

   // this->_ListEntre=InitValeur::donneInstance()->GetListValeur();
    if(this->_ListEntre.at(value)=="eff1")
    {
        return this->eff1;
    }
    if(this->_ListEntre.at(value)=="eff2")
    {
        return this->eff2;
    }
    if(this->_ListEntre.at(value)=="eff3")
    {
        return this->eff3;
    }
    if(this->_ListEntre.at(value)=="eff4")
    {
        return this->eff4;
    }
}

void statValeur::init()
{
    this->vpp=0;
    this->vp=0;
    this->v0=0;
    this->vm=0;
    this->vmm=0;
    this->tot=0;
    this->eff1=0;
    this->eff2=0;
    this->eff3=0;
    this->eff4=0;

}



QStringList statValeur::GetListValeurStat()
{
    return _ListValeur;
}

statFinal::statFinal()
{

}

statFinal::statFinal(QStringList Action,QStringList Valeur)
{

    _listAction=Action;
    for(int i=0;i<_listAction.size();i++)
    {
        statMap[i]=new statValeur(Valeur);
    }

}
statFinal::~statFinal()
{
    for(int i=0;i<_listAction.size();i++)
    {
        delete statMap[i];
    }
}


int statFinal::GetTotal()
{
    return 0;
}

QStringList statFinal::GetListValeurStat()
{
    return statMap[0]->GetListValeurStat();
}
/*
void statFinal::SetListAction(QStringList list)
{
    _listAction=list;
    for(int i=0;i<_listAction.size();i++)
    {
        statMap[i]=new statValeur(InitValeur::donneInstance()->GetListValeur());
    }
}
*/
void statFinal::AjoutValeur(int action, int pos)
{
    statMap[action]->addValeur(pos);


}

void statFinal::SupValeur(int action, int valeur)
{

    statMap[action]->SupValeur(valeur);

}


double statFinal::GetValeur(int action, int valeur)
{
    double Dvaleur=statMap[action]->getValeur(valeur);
    return Dvaleur;

}

void statFinal::SetValeur(int action, int pos,double valeur)
{
    statMap[action]->setValeur (pos,valeur);

}
void statFinal::init()
{
    for(int i;i<_listAction.size();i++)
    {
        statMap[i]->init();
    }
}

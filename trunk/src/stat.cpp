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
#include "stat.h"

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
    this->_AfficheValeur=6;

    _ListValeur<<"++"<<"+"<<"0"<<"-"<<"--"<<"tot";
    for(int k=0;k<_ListEntre.size();k++)
    {
        if(_ListEntre.at(k)=="(")
        {
            QString strValeur=_ListEntre.at(k+1);
            QStringList listCoeff=strValeur.split(";");
            this->AddCoef(listCoeff[0].toInt(),listCoeff[1].toInt(),listCoeff[2].toInt(),listCoeff[3].toInt(),listCoeff[4].toInt());
            break;
        }
        _AfficheValeur=_AfficheValeur+1;
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
        vpp=vpp-1;
        break;
    case 1:
        vp=vp-1;
        break;
    case 2:
        v0=v0-1;
        break;
    case 3:
        vm=vm-1;
        break;
    case 4:
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
    int value=pos-6;
    if(this->_ListEntre.at(value)=="eff1")
    {
        this->eff1=valeur;
    }
    if(this->_ListEntre.at(value)=="eff2")
    {
        this->eff2=valeur;
    }
    if(this->_ListEntre.at(value)=="eff3")
    {
        this->eff3=valeur;
    }
    if(this->_ListEntre.at(value)=="eff4")
    {
        this->eff4=valeur;
    }
}
double statValeur::ValeurEff(int pos)
{
    int value=pos-6;
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

int statValeur::GetAfficheValeur()
{
    return _AfficheValeur;
}

QStringList statValeur::GetListValeurStat()
{
    return _ListValeur;
}

statFinal::statFinal()
{


}
int statFinal::GetNbValeur()
{
    return statMap[0]->GetAfficheValeur();
}

QStringList statFinal::GetListValeurStat()
{
    return statMap[0]->GetListValeurStat();
}

void statFinal::SetListAction(QStringList list,QStringList valeur)
{
    _listAction=list;
    for(int i=0;i<_listAction.size();i++)
    {
        statMap[i]=new statValeur(valeur);
    }
}

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

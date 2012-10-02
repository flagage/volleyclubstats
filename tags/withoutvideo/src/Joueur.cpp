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

#include "Joueur.h"
#include "match.h"

Joueur::Joueur()
{
    _Nom="";
    _Prenom="";
    _Age="";
    _NLisence=0;
    _Tel=0;
    _Email="";
    _Addresse="";
    _poste="";
    _num=0;
    _nbSet=0;
}

Joueur::~Joueur()
{
    for(int i=0;i<_nbSet;i++)
    {
        delete _listStat[i] ;
    }
}


int Joueur::get_num()
{
    return _num;
}

QString Joueur::get_Nom()
{
    return _Nom;
}

QString Joueur::get_Prenom()
{
    return _Prenom;
}
QString Joueur::get_Age()
{
    return _Age;
}
int Joueur::get_NLisence()
{
    return _NLisence;
}
int Joueur::get_Tel()
{
    return _Tel;
}
QString Joueur::get_Email()
{
    return _Email;
}

QString Joueur::get_Addresse()
{
    return _Addresse;
}

QString Joueur::get_poste()
{
    return  _poste;
}

void Joueur::set_Nom(QString nom)
{
    _Nom=nom;
}

void Joueur::set_Prenom(QString prenon)
{
    _Prenom=prenon;
}

void Joueur::set_Age(QString age)
{
    _Age=age;
}

void Joueur::set_NLisence(int lisence)
{
    _NLisence=lisence;
}

void Joueur::set_Tel(int tel)
{
    this->_Tel=tel;
}

void Joueur::set_Email(QString email)
{
    this->_Email=email;
}

void Joueur::set_poste(QString poste)
{
    this->_poste=poste;
}

void Joueur::set_Addresse(QString add)
{
    this->_Addresse=add;
}

void Joueur::set_NumMaillot(int Num)
{
    this->_NumMaillot=Num;
}
int Joueur::get_NumMaillot()
{
    return this->_NumMaillot;
}
void Joueur::EnregistrerXML(QDomDocument doc,  QDomElement Equipe)
{
    QDomElement tag = doc.createElement("joueur");
    tag.setAttribute("Nom",_Nom);
    tag.setAttribute("Prenom",_Prenom);
    tag.setAttribute("Age",_Age);
    tag.setAttribute("Adresse",this->_Addresse);
    tag.setAttribute("Email",this->_Email);
    tag.setAttribute("Tel",this->_Tel);
    tag.setAttribute("License",this->_NLisence);
    tag.setAttribute("poste",this->_poste);
    tag.setAttribute("Maillot",this->_NumMaillot);
    Equipe.appendChild(tag);

}


void Joueur::RestaurerXML(QDomNode noeud)
{
    QDomElement playeur=noeud.toElement();

    _Nom=playeur.attribute("Nom");
    _Prenom=playeur.attribute("Prenom");
    _Age=playeur.attribute("Age");
    _NLisence=playeur.attribute("License").toInt();
    _Tel=playeur.attribute("Tel").toInt();
    _Email=playeur.attribute("Email");
    _Addresse=playeur.attribute("Adresse");
    _poste=playeur.attribute("poste");
    _NumMaillot=playeur.attribute("Maillot").toInt();


}


void Joueur::addStatMatch(int action,int pos)
{
    this->_listStat[0]->AjoutValeur(action,pos);
}
void Joueur::setStatMatch(int action,int pos,double valeur)
{
    this->_listStat[0]->SetValeur (action,pos,valeur);
}

void Joueur::supStatMatch(int action,int pos)
{
    this->_listStat[0]->SupValeur (action,pos);
}

void Joueur::supStatSet(int action,int pos,int numset)
{
    this->_listStat[numset]->SupValeur (action,pos);
}


double Joueur::getStatMatch(int action,int pos)
{
    return this->_listStat[0]->GetValeur(action,pos);
}

void Joueur::setStatSet(int action,int pos,double valeur,int numset)
{
    this->_listStat[numset]->SetValeur (action,pos,valeur);
}

void Joueur::addStatSet(int action,int pos,int numset)
{
    this->_listStat[numset]->AjoutValeur(action,pos);
}

double Joueur::getStatSet(int action,int pos,int numset)
{
   return  this->_listStat[numset]->GetValeur(action,pos);
}

void Joueur::initSet(int numset)
{
    this->_listStat[numset]->init();
}
void Joueur::SetPosition(int numpos)
{
    this->_Position=numpos;
}
int Joueur::GetPosition()
{
    return _Position;
}

void Joueur::InitialisationStat(int NbSet,QStringList Action,QStringList Valeur)
{
    _nbSet=NbSet+1; //+1 pour les stats sur le match en entier.
    _ListAction=Action;
    _ListValeur=Valeur;
    _listStat.clear();
    for(int i=0;i<_nbSet;i++)
    {
        this->_listStat.append(new statFinal(Action,Valeur));
    }
}

QStringList Joueur::GetListAction()
{
    return _ListAction;
}
QStringList Joueur::GetListValeur()
{
    return _ListValeur;
}
int Joueur::GetNbSet()
{
    return _nbSet;
}

/**
Copyright Frederic volleyclubstats ,2011
fred@volleyclubstats.com

This file is part of volleyclubstats.

volleyclubstats is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Volleyclubstats.  If not, see <http://www.gnu.org/licenses/>.
**/
#include "Equipe.h"
#include "QFileDialog"
#include "QTextStream"
#include "volleyInit.h"
#include "match.h"
#include <QFile>

Equipe::Equipe()
{
    _Nom="";
    _Categorie="";
    _Division="";
    _NbSet=0;
}

void Equipe::InitialisationStat(int NbSet,QStringList Action,QStringList Valeur)
{
    _NbSet=NbSet+1; //+1 pour les stats sur le match en entier.
    _ListAction=Action;
    _ListValeur=Valeur;
    _VectorStat.clear();
    for(int i=0;i<_NbSet;i++)
    {
        this->_VectorStat.append(new statFinal(Action,Valeur));
    }
    /// Initialisation stat joueur
    for(int i=0;i<_ListeJoueur.size();i++)
    {
        _ListeJoueur.at(i)->InitialisationStat(NbSet,Action,Valeur);
    }
}
QStringList Equipe::GetListAction()
{
    return _ListAction;
}
QStringList Equipe::GetListValeur()
{
    return _ListValeur;
}
int Equipe::GetNbSet()
{
    return this->_NbSet;
}

Equipe::Equipe(QString nom)
{
    _Nom=nom;
}
Equipe::Equipe(Equipe *team)
{
    _Nom=team->GetNom();
    _NbSet=team->GetNbSet();
    _Categorie=team->GetCategorie();
    _Division=team->GetDivision();
    _ListeJoueur=team->GetListeJoueur();
    _ListValeur=team->GetListValeur();
    _ListAction=team->GetListAction();
     //_VectorStat=team->Get;
    }

Equipe::~Equipe()
{
    for(int i=0;i<_ListeJoueur.size();i++)
    {
        delete (_ListeJoueur.at(i));
    }
    _ListeJoueur.clear();
    for(int j=0;j<_NbSet;j++)
    {
        delete(_VectorStat.at(j));
    }


}


QString Equipe::GetNom()
{
    return _Nom;
}

void Equipe::SetNom(QString Nom)
{

    _Nom=Nom;
}

QList <Joueur*> Equipe::GetListeJoueur()
{
    return _ListeJoueur;
}


void Equipe::AddJoueur(Joueur* joue)
{
    for (int i=0;i<_ListeJoueur.size();i++)
    {
        if(_ListeJoueur.at(i)->get_NumMaillot()==joue->get_NumMaillot())
        {
            _ListeJoueur.removeAt(i);
        }
    }
    _ListeJoueur.append(joue);
}
void Equipe::supJoueur(Joueur* joue)
{
    for(int i=0;i<_ListeJoueur.count();i++)
    {
        if(_ListeJoueur.at(i)->get_NumMaillot()==joue->get_NumMaillot())
        {
            _ListeJoueur.removeAt(i);

            break;
        }
    }

}

/// recherche joueur avec la string "premon_numMaillot"
Joueur* Equipe::RechercheJoueur(QString strjoueur)
{

    QStringList liststrjoueur=strjoueur.split("_");
    for(int i=0;i<this->GetListeJoueur().size();i++)
    {
        if(this->GetListeJoueur().at(i)->get_NumMaillot()==liststrjoueur.at(1).toInt())
        {
            return this->GetListeJoueur().at(i);
        }
    }
    return 0;
}
Joueur* Equipe::seachjoueur(QString nomJoueur)
{
    Joueur* player=0;
    if(nomJoueur!="")
    {
        for(int i=0;i<_ListeJoueur.size();i++)
        {
            if(_ListeJoueur.at(i)->get_Prenom()==nomJoueur)
            {
                player=_ListeJoueur.at(i);
                break;
            }
        }
    }
    return player;
}
Joueur* Equipe::seachjoueur(int numjoueur)
{
    Joueur* player=0;

        for(int i=0;i<_ListeJoueur.size();i++)
        {
            if(_ListeJoueur.at(i)->get_NumMaillot()==numjoueur)
            {
                player=_ListeJoueur.at(i);
                break;
            }
        }
      return player;
}

void Equipe::EnregistrerXML( QDomDocument doc,QDomElement root)
{
    QDomElement Equipe = doc.createElement("Equipe");
    Equipe.setAttribute("Nom",_Nom);
    Equipe.setAttribute("Categorie",_Categorie);
    Equipe.setAttribute("Division",_Division);

    root.appendChild(Equipe);
    for(int i=0;i<_ListeJoueur.count();i++)
    {
        Joueur* player=_ListeJoueur.at(i);
        player->EnregistrerXML(doc,Equipe);
    }


}

void Equipe::RestaurerXML(QDomNode noeud)
{
    QDomElement Team=noeud.toElement();
    this->_Nom=Team.attribute("Nom");
    _Categorie=Team.attribute("Categorie");
    _Division=Team.attribute("Division");
    QDomNode child = Team.firstChild();
    while(!child.isNull())
    {
        Joueur* Player=new Joueur();
        Player->RestaurerXML(child);
        this->AddJoueur(Player);
        child=child.nextSibling();
    }

}

/*
QString Equipe::GetStringValeur()
{
    QString str;
    for(int k=0;k<_listValeur.size()-1;k++)
    {
        str=str+_listValeur.at(k)+"_";
    }
    str=str+_listValeur.at(_listValeur.size()-1);
    return str;
}

void Equipe::SetStringValeur(QString action)
{
    this->_listValeur=action.split("_");
}


QString Equipe::GetStringAction()
{
    QString str;
    for(int k=0;k<_listAction.size()-1;k++)
    {
        str=str+_listAction.at(k)+"_";
    }
    str=str+_listAction.at(_listAction.size()-1);
    return str;
}

void Equipe::SetStringAction(QString action)
{
    this->_listAction=action.split("_");
}

int Equipe::GetnbValeurStat()
{
    return this->_VectorStat[0]->GetNbValeur();
}
*/

void Equipe::addStatMatch(int action,int pos)
{
    _VectorStat[0]->AjoutValeur(action,pos);
}
void Equipe::setStatMatch(int action,int pos,double valeur)
{
    this->_VectorStat[0]->SetValeur (action,pos,valeur);
}
double Equipe::getStatMatch(int action,int pos)
{
   return this->_VectorStat[0]->GetValeur(action,pos);
}
/*int Equipe::GetTotalPoint()
{
    return this->_VectorStat[0]->GetTotal();
}*/

void Equipe::addStatSet(int action,int pos,int numset)
{
    this->_VectorStat[numset]->AjoutValeur(action,pos);
}
void Equipe::setStatSet(int action,int pos,double valeur,int numset)
{
    this->_VectorStat[numset]->SetValeur (action,pos,valeur);
}
double Equipe::getStatSet(int action,int pos,int numset)
{
    double Dvalue=this->_VectorStat[numset]->GetValeur(action,pos);
   return  Dvalue;
}

/*void Equipe::initSet()
{

    //this->_VectorStat[Match::donneInstance()->GetCurentSet()]->init();

}*/
void Equipe::initSet(int numset)
{
    this->_VectorStat[numset]->init();
}
void Equipe::supStatMatch(int action,int pos)
{
    this->_VectorStat[0]->SupValeur (action,pos);
}
void Equipe::supStatSet(int action,int pos,int numset)
{
    this->_VectorStat[numset]->SupValeur (action,pos);
}

void Equipe::ExportCVS(QString fichier)
{

    QFile file(fichier);

    if (file.open(QFile::WriteOnly))
    {
        QTextStream out(&file);
        out<<"Nom_Equipe;Nom;Prenom;Maillot;Poste;Licence;Adresse;Telephone;Email;Age\n";
        out<<this->GetNom()<<"\n";

        for(int i=0;i<this->GetListeJoueur().size();i++)
        {
            Joueur * player=this->GetListeJoueur().at(i);
            out<<";"<<player->get_Nom()+";"<<player->get_Prenom()+";";
            QString strint;
            strint.setNum(player->get_NumMaillot());
            out<<strint+";"<<player->get_poste()+";";
            strint="";
            strint.setNum(player->get_NLisence());
            out<<strint+";"<<player->get_Addresse()+";";
            strint.setNum(player->get_Tel());
            out<<strint+";"<<player->get_Email()+";";

            out<<player->get_Age()+";"<<"\n";
        }
        file.close();
}

}
void Equipe::ImportCVS(QString fichier)
{
    QFile file(fichier);
    QString line;
    QStringList  joueur;


    if (file.open(QFile::ReadOnly))
    {
        QTextStream stream( &file );
        bool first=false;
        while ( !stream.atEnd() )
        {
            line=stream.readLine();
            joueur=line.split(";");
            if (first==false)
            {
                stream.readLine();
                first=true;
            }
            else
            {
                if(joueur.at(0)!="")
                {
                Joueur * play=new Joueur();
                play->set_Nom(joueur.at(1));
                play->set_Prenom(joueur.at(2));
                play->set_NumMaillot(joueur.at(3).toInt());
                play->set_poste(joueur.at(4));
                if(joueur.size()>=5)
                play->set_NLisence(joueur.at(5).toInt());
                if(joueur.size()>=6)
                play->set_Addresse(joueur.at(6));
                if(joueur.size()>=7)
                play->set_Tel(joueur.at(7).toInt());
                if(joueur.size()>=8)
                play->set_Email(joueur.at(8));
                if(joueur.size()>=9)
                play->set_Age(joueur.at(9));

                this->AddJoueur(play);
                }


            }
        }
        file.close();
    }
}


void Equipe::SetDivision(QString div)
{
    _Division=div;
}

QString Equipe::GetDivision()
{
    return _Division;

}

void Equipe::SetCategorie(QString cat)
{
    _Categorie=cat;
}

QString Equipe::GetCategorie()
{
    return _Categorie;
}
void Equipe::operator ==(Equipe * team)
{
    _Nom=team->GetNom();
    _NbSet=team->GetNbSet();
    _Categorie=team->GetCategorie();
    _Division=team->GetDivision();
    _ListeJoueur=team->GetListeJoueur();
    _ListValeur=team->GetListValeur();
    _ListAction=team->GetListAction();

}

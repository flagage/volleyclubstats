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

#include "Equipe.h"
#include "QFileDialog"
#include "QTextStream"
#include "volleyInit.h"
#include <QFile>

Equipe::Equipe()
{
    _Nom="";
    this->_listAction=InitAction::donneInstance()->GetListAction();
    this->_listValeur=InitValeur::donneInstance()->GetListValeur();
}
Equipe::Equipe(QString nom)
{
    _Nom=nom;
}

Equipe::~Equipe()
{
    for(int i=0;i<_ListeJoueur.size();i++)
    {
        delete (_ListeJoueur.at(i));
    }
    _ListeJoueur.clear();
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
    if(numjoueur!=0)
    {
        for(int i=0;i<_ListeJoueur.size();i++)
        {
            if(_ListeJoueur.at(i)->get_NumMaillot()==numjoueur)
            {
                player=_ListeJoueur.at(i);
                break;
            }
        }
    }
    return player;
}

void Equipe::EnregistrerXML( QDomDocument doc,QDomElement root)
{
    QDomElement Equipe = doc.createElement("Equipe");
    Equipe.setAttribute("Nom",_Nom);
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
    QDomNode child = Team.firstChild();
    while(!child.isNull())
    {
        Joueur* Player=new Joueur();
        Player->RestaurerXML(child);
        this->AddJoueur(Player);
        child=child.nextSibling();
    }

}


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
    return this->statMatch.GetNbValeur();
}


void Equipe::addStatMatch(int action,int pos)
{
    this->statMatch.AjoutValeur(action,pos);
}
void Equipe::setStatMatch(int action,int pos,double valeur)
{
    this->statMatch.SetValeur (action,pos,valeur);
}
double Equipe::getStatMatch(int action,int pos)
{
   return this->statMatch.GetValeur(action,pos);
}

void Equipe::addStatSet(int action,int pos)
{
    this->statSet.AjoutValeur(action,pos);
}
void Equipe::setStatSet(int action,int pos,double valeur)
{
    this->statSet.SetValeur (action,pos,valeur);
}
double Equipe::getStatSet(int action,int pos)
{
    double Dvalue=this->statSet.GetValeur(action,pos);
   return  Dvalue;
}

void Equipe::initSet()
{

    this->statSet.init();

}

void Equipe::supStatMatch(int action,int pos)
{
    this->statMatch.SupValeur (action,pos);
}
void Equipe::supStatSet(int action,int pos)
{
    this->statSet.SupValeur (action,pos);
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
            strint.setNum(player->get_Age());
            out<<strint+";"<<"\n";
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
               // this->SetNom(joueur.at(3));
                stream.readLine();
                first=true;
            }
            else
            {
                if(joueur.at(0)!="")
                {
                Joueur * play=new Joueur();
                play->set_Nom(joueur.at(0));
                play->set_Prenom(joueur.at(1));
                play->set_NumMaillot(joueur.at(2).toInt());
                play->set_poste(joueur.at(3));
                if(joueur.size()>=5)
                play->set_NLisence(joueur.at(4).toInt());
                if(joueur.size()>=6)
                play->set_Addresse(joueur.at(5));
                if(joueur.size()>=7)
                play->set_Tel(joueur.at(6).toInt());
                if(joueur.size()>=8)
                play->set_Email(joueur.at(7));
                if(joueur.size()>=9)
                play->set_Age(joueur.at(8).toInt());

                this->AddJoueur(play);
                }


            }
        }
        file.close();
    }
}


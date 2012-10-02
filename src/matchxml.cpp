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

#include "matchxml.h"

MatchXml::MatchXml(ParametreMatch *ParamMatch, Score *score,Equipe* visiteur,QStringList *listevenement,QList<QString> *listposition)
{
    _ParamMatch=ParamMatch;
    _score=score;
    _EquipeVisiteur=visiteur;
    _ListEvenement=listevenement;
    _listPosition=listposition;
}
void MatchXml::setEquipe(Equipe *team)
{
    this->_EquipeLocal=team;
}
Equipe * MatchXml::GetEquipe()
{
   return this->_EquipeLocal;
}


void MatchXml::LectureXML(QString filename)
{
    _fileXmlCurrent.setFileName(QString(filename));

    if (!_fileXmlCurrent.open(QIODevice::ReadOnly))
        return;
    QString msg;
    int posli;
    int poscol;
    if (!_doc.setContent(&_fileXmlCurrent,&msg,&posli,&poscol))
    {
        _fileXmlCurrent.close(); // tablit le document XML  partir des donnes du fichier (hirarchie, etc.)
        return;
    }
    _fileXmlCurrent.close();
    QDomElement racine = _doc.documentElement(); // renvoie la balise racine
    QDomNode noeud = racine.firstChild(); // renvoie la premire balise  mesure
    while(!noeud.isNull())
    {

        QDomElement element=noeud.toElement();



            if(element.tagName()=="Ratio")
            {
                QStringList listelement=element.text().split(",");
                _ParamMatch->set_Valeur(listelement);
            }
            if(element.tagName()=="Action")
            {
                QStringList listelement=element.text().split(",");
                _ParamMatch->set_Action(listelement);
                /// creation de l'equipe adverse
                this->_EquipeVisiteur->SetNom(_ParamMatch->get_NomEquipeVisiteur());
                this->_EquipeVisiteur->InitialisationStat(_ParamMatch->get_NbSet(),_ParamMatch->get_Action(),_ParamMatch->get_Valeur());
                this->_EquipeLocal->InitialisationStat(_ParamMatch->get_NbSet(),_ParamMatch->get_Action(),_ParamMatch->get_Valeur());

            }
            if(element.tagName()=="ActionDefilement")
            {
                QStringList listelement=element.text().split(",");
                _ParamMatch->set_ActionDefile(listelement);


            }


            if(element.tagName()=="Score")
            {
                _score->set_ScLocal(element.attribute("ScLocal").toInt());
                _score->set_SetLocal(element.attribute("SetLocal").toInt());
                _score->set_TmLocal(element.attribute("TmLocal").toInt());
                _score->set_ScVisiteur(element.attribute("ScVisiteur").toInt());
                _score->set_SetVisiteur(element.attribute("SetVisiteur").toInt());
                _score->set_TmVisiteur(element.attribute("TmVisiteur").toInt());
                _score->set_Service(element.attribute("Service").toInt());
                _score->set_ServiceSet(element.attribute("ServiceSet").toInt());
                QStringList listScore=element.attribute("ListScore").split("_");
                _score->Set_ListScore(listScore);
                 _ParamMatch->SetNumSet(_score->get_SetLocal()+_score->get_SetVisiteur()+1);


            }

            /// Relecture des stats
            if(element.tagName()=="StatMatch")
            {
                QDomNode child=element.firstChild();
                while(!child.isNull())
                {
                    if(child.toElement().tagName()=="EquipeLocal")
                    {
                        InitStatFromXml(child,0,false);

                    }
                    else if(child.toElement().tagName()=="EquipeVisiteur")
                    {
                        InitStatFromXml(child,1,false);
                    }
                    else
                    {
                        Joueur *player=_EquipeLocal->RechercheJoueur(child.toElement().tagName());
                        if(player!=0)
                        {
                            InitStatFromXml(child,3,false,0,player);
                        }
                    }
                    child=child.nextSibling();
                }
            }
            if(element.tagName().contains("StatSet"))
            {
                QString strSet=element.tagName().right(1);
                QDomNode child=element.firstChild();
                while(!child.isNull())
                {
                    if(child.toElement().tagName()=="EquipeLocal")
                    {
                        InitStatFromXml(child,0,true,strSet.toInt());

                    }
                    else if(child.toElement().tagName()=="EquipeVisiteur")
                    {
                        InitStatFromXml(child,1,true,strSet.toInt());
                    }
                    else
                    {
                        Joueur *player=_EquipeLocal->RechercheJoueur(child.toElement().tagName());
                        if(player!=0)
                        {
                            InitStatFromXml(child,3,true,strSet.toInt(),player);
                        }
                    }
                    child=child.nextSibling();
                }
            }

            if(element.tagName()=="Position")
            {
                QDomNode child = element.firstChild();
                while(!child.isNull())
                {

                    _listPosition->append(child.toElement().text());
                    child=child.nextSibling();
                }
            }
            if(element.tagName()=="ListEvenement")
            {
                QDomNode child=element.firstChild();
                while(!child.isNull())
                {
                    QString identifiant=child.toElement().tagName();
                    identifiant=identifiant.remove(0,1);
                    _ListEvenement->append(identifiant+" "+child.toElement().text());
                    child=child.nextSibling();
                }
            }
            noeud=noeud.nextSibling();
        }

    }


void MatchXml::InitStatFromXml(QDomNode child,int TemOrPl,bool isSet,int numset,Joueur* player)
{
    QDomNode Gchild=child.firstChild();
    while(!Gchild.isNull())
    {
        QDomElement GchElement=Gchild.toElement();
        QString strAction=GchElement.tagName();

        int action=_ParamMatch->GetActionFromString(strAction);
        if (action==-1)
            return;
        for(int i=0;i<_ParamMatch->get_Valeur().size();i++)
        {
            QString valeur=_ParamMatch->get_Valeur().at(i);
            QString element=GchElement.attribute(valeur);
            switch (TemOrPl)
            {
            case 0: /// Equipe local
            {
                if(isSet==false)
                {
                    double Dvaleur=element.toDouble();
                    _EquipeLocal->setStatMatch(action,i,Dvaleur);
                }
                else
                {
                    _EquipeLocal->setStatSet(action,i,element.toDouble(),numset);
                }
                break;
            }
            case 1: /// Equipe Visiteur
            {
                if(isSet==false)
                {
                    _EquipeVisiteur->setStatMatch(action,i,element.toDouble());
                }
                else
                {
                    _EquipeVisiteur->setStatSet(action,i,element.toDouble(),numset);
                }
                break;
            }
            case 3: /// Joueur
            {
                if(isSet==false)
                {
                    player->setStatMatch(action,i,element.toDouble());
                }
                else
                {
                    player->setStatSet(action,i,element.toDouble(),numset);
                }
                break;

            }
            default:
                break;

            }



        }
        Gchild=Gchild.nextSibling();
    }
}

void MatchXml::LectureParametreMatch(QString filename)
{
    _fileXmlCurrent.setFileName(filename);

    if (!_fileXmlCurrent.open(QIODevice::ReadOnly))
        return;
    QString msg;
    int posli;
    int poscol;
    if (!_doc.setContent(&_fileXmlCurrent,&msg,&posli,&poscol))
    {
        _fileXmlCurrent.close(); // tablit le document XML  partir des donnes du fichier (hirarchie, etc.)
        return;
    }
    _fileXmlCurrent.close();
    QDomElement racine = _doc.documentElement(); // renvoie la balise racine
    QDomNode noeud = racine.firstChild(); // renvoie la premire balise  mesure
    while(!noeud.isNull())
    {

        QDomElement element=noeud.toElement();

        if(element.tagName()=="Match")
        {

            _ParamMatch->set_NomEquipeVisiteur(element.attribute("Contre"));

            _ParamMatch->set_NomArbitre1(element.attribute("Arbitre1"));
            _ParamMatch->set_NomArbitre2(element.attribute("Arbitre2"));
            _ParamMatch->set_TypeDeMatch(element.attribute("Type"));
            _ParamMatch->set_NbSet(element.attribute("NbDeSet").toInt());
            _ParamMatch->set_NbJoueur(element.attribute("Nbjoueur").toInt());
            _ParamMatch->SetLibero(element.attribute("Aveclibero").toInt());
            _ParamMatch->set_ScoreMax(element.attribute("NbPoint").toInt());

            QString nomEquipe=element.attribute("Equipe");
            _ParamMatch->set_NomEquipeLocal(nomEquipe);

        }
        noeud=noeud.nextSibling();
    }
}

QDomDocument MatchXml::Getdoc()
{
    return _doc;
}

QDomElement MatchXml::GetRoot()
{
    return _doc.documentElement();
}

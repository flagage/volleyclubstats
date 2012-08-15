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
#include "match.h"
#include "fenetrelancement.h"
#include "fenetreposition.h"
#include <QTextStream>


Match* Match::instanceMatch = NULL;

Match::Match()

{

    _nomFichier="";
    _numCurentSet=1;
    _lancementok=false;
    _score=new Score();
    _Fichierxml=0;
    _faute=0;
    _fauteAdv=0;
    _point=0;
    _pointAdv=0;



}
Match* Match::GetInstance()
{
    return instanceMatch;
}

Match* Match::donneInstance()
{
    if(instanceMatch == NULL)
    {
        instanceMatch=new Match();
    }
    return instanceMatch;
}

void Match::libereInstance()
{
    if(instanceMatch!=NULL)
    {
        delete instanceMatch;
        instanceMatch=NULL;
    }
}

bool Match::lancer()
{


    _date=_date.currentDateTime();

    _nomFichier="Match_"+_date.toString("ddMMyyyy_hms")+".xml";

    /*FenetrePosition* pos=new FenetrePosition(_ecran);
        if(pos->exec())
        {*/
    Joueur* Adversaire=new Joueur();
    Adversaire->set_NumMaillot(0);
    Adversaire->set_Prenom(_advers);
    _currrentEquipe->AddJoueur(Adversaire);
    //this->_curentset=new Set(this->_currrentEquipe,_numCurentSet);
    //this->_ListeSet.append(_curentset);
    _lancementok=true;
    //}
    //}
    return _lancementok;
}

void Match::setCurrentEquipe(Equipe *Team)
{
    _currrentEquipe=Team;
    _score->set_Equipe_1(Team->GetNom());

}

void Match::setAdvers(QString nom)
{
    _advers=nom;
    _score->set_Equipe_2(nom);

}

Equipe* Match::getTeam()
{

    return _currrentEquipe;
}
QString Match::getadvs()
{
    return _advers;
}

QString Match::GetDate()
{
    return _date.toString("dd_MM_yyyy_hh_mm_ss");
}
void Match::SetDate(QString str)
{
    _date=QDateTime::fromString(str,"dd_MM_yyyy");
}



/*Set* Match::GetCurrentSet()
{
    //return this->_curentset;
}*/
Score* Match::GetScore()
{

    return this->_score;
}
QString Match::GetFichierXml()
{
    return this->_nomFichier;
}

void Match::EnregistrerXMl()
{
    QString Joueur;
    QString clef;
    QDomDocument doc("Info");
    QDomNode noeud=doc.createProcessingInstruction ("xml","version=\"1.0\" encoding=\"ISO-8859-1\" standalone=\"yes\"");
    doc.insertBefore (noeud,doc.firstChild ());
    QDomElement root = doc.createElement("Info");
    doc.appendChild(root);

    QDomElement Info = doc.createElement("Match");
    Info.setAttribute("Date",_date.toString("dd_MM_yyyy"));
    Info.setAttribute ("Heure",_date.toString ("hh:mm:ss"));
    Info.setAttribute("Equipe",_currrentEquipe->GetNom ());
    Info.setAttribute ("Type",_Type);
    Info.setAttribute("Contre",_advers);
    Info.setAttribute ("Arbitre",this->_Arbitre);
    Info.setAttribute ("Duree","temps");
    Info.setAttribute("NbDeSet",_numCurentSet-1);
    root.appendChild(Info);


    QDomElement Equipe= doc.createElement("Equipe");
    Equipe.setAttribute("Nom",this->_currrentEquipe->GetNom());
    Equipe.setAttribute("listAction",this->_currrentEquipe->GetStringAction());
    Equipe.setAttribute("ListeValeur",_currrentEquipe->GetStringValeur());
    root.appendChild(Equipe);
    for(int k=0;k<this->_currrentEquipe->GetListeJoueur ().size ();k++)
    {
        QDomElement Joueur= doc.createElement("Joueur");
        Joueur.setAttribute("Nom",_currrentEquipe->GetListeJoueur ().at(k)->get_Prenom());
        QString num;
        num.setNum(_currrentEquipe->GetListeJoueur ().at(k)->get_NumMaillot());
        Joueur.setAttribute("NumMaillot",num);
        Joueur.setAttribute("poste",_currrentEquipe->GetListeJoueur ().at(k)->get_poste());
        Equipe.appendChild(Joueur);
    }



    QDomElement Stat=doc.createElement ("Statisitique");
    root.appendChild(Stat);
    //le match

    QDomElement statMatch=doc.createElement ("MatchStat");

    //team.setAttribute ("Match",this->Restaurer ("team"));
    Stat.appendChild (statMatch);
    QDomElement equipe=doc.createElement ("team");

    equipe.setAttribute ("stat",this->StatString ("team"));
    statMatch.appendChild (equipe);
    for(int k=0;k<this->_currrentEquipe->GetListeJoueur ().size ();k++)
    {

        Joueur.setNum (this->_currrentEquipe->GetListeJoueur ().at (k)->get_NumMaillot ());
        clef="Num_"+Joueur;
        QDomElement joueur=doc.createElement (clef);

        joueur.setAttribute ("stat",this->StatString (Joueur));
        statMatch.appendChild (joueur);
    }

    for(int i=1;i<_numCurentSet;i++)
    {
        QString numset;
        numset.setNum (i);
        numset="Set"+numset;
        QDomElement Set=doc.createElement (numset);
        //Set.setAttribute("score",this->_ListeSet.at (i-1)->ScoreSave());


        //  Set.setAttribute ("stat",this->_ListeSet.at (i-1)->Restaurer ("team"));
        Stat.appendChild (Set);


        /// Equipe
        clef="Team";
        QDomElement equipe=doc.createElement (clef);

        //equipe.setAttribute ("stat",this->_ListeSet.at (i-1)->Restaurer ("team"));
        Set.appendChild (equipe);
        for(int k=0;k<this->_currrentEquipe->GetListeJoueur ().size ();k++)
        {

            Joueur.setNum (this->_currrentEquipe->GetListeJoueur ().at (k)->get_NumMaillot ());
            clef="Num_"+Joueur;
            QDomElement joueur=doc.createElement (clef);

            //   joueur.setAttribute ("stat",this->_ListeSet.at (i-1)->Restaurer (Joueur));
            Set.appendChild (joueur);
        }
    }

    /*  for(int k=0;k<this->_currrentEquipe->GetListeJoueur ().size ();k++)
    {

        QString Joueur;
        QString clef;

        Joueur.setNum (this->_currrentEquipe->GetListeJoueur ().at (k)->get_NumMaillot ());
        clef="Num_"+Joueur;
        QDomElement joueur=doc.createElement (clef);
        Stat.appendChild (joueur);
        joueur.setAttribute ("Match",this->Restaurer (Joueur));

        for(int i=1;i<_numCurentSet;i++)
        {
            QString numset;
            numset.setNum (i);
            numset="Set"+numset;
            QDomElement Set=doc.createElement (numset);
           // Set.setAttribute("score",this->_ListeSet.at (i-1)->ScoreSave());


            Set.setAttribute ("stat",this->_ListeSet.at (i-1)->Restaurer (Joueur));
            joueur.appendChild (Set);

        }

    }*/

    QFile file(QString("Sauvegarde/"+_nomFichier));
    if (!file.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &file );
    ts << doc.toString();
    file.close();
}

void Match::CreerSet(QString score,QStringList list)
{
    //this->_curentset=new Set(this->_currrentEquipe,_numCurentSet);
    //this->_curentset->SetScore(score);
    //this->_curentset->Enregistrer(list);
    // this->_ListeSet.append(_curentset);
    //this->_curentset->Enregistrer ();
    //_numCurentSet++;
}

void Match::FinSet()
{
    _numCurentSet++;
    //this->_curentset->setAdv(this->GetScore()->get_Score_E2());
    //this->_curentset->setEquipe(this->GetScore()->get_Score_E1());
    //this->_curentset->Enregistrer();
    //this->_curentset=new Set(this->_currrentEquipe,_numCurentSet);
    //this->_curentset->Initialise();
    //this->_ListeSet.append(_curentset);
    this->_Fichierxml->ChangementDeSet(_numCurentSet);
    if(this->_score->get_Score_E1()>this->_score->get_Score_E2())
    {
        this->_score->set_Set_E1(this->_score->get_Set_E1()+1);
    }
    else
    {
        this->_score->set_Set_E2(this->_score->get_Set_E2()+1);
    }
    this->_score->set_Score_E1(0);
    this->_score->set_Score_E2(0);
    int nbmax=InitGlobal::donneInstance()->GetNbSet()+1;
    if(_numCurentSet<nbmax)
    {
        this->_currrentEquipe->initSet();
        for(int i=0;i<_currrentEquipe->GetListeJoueur().size();i++)
        {
            _currrentEquipe->GetListeJoueur().at(i)->initSet();
        }

    }


}



int Match::GetCurentSet ()
{
    return this->_numCurentSet;
}


/*Set* Match::GetOldSet (int i)
{
   // return this->_ListeSet.at (i-1);
}*/

void Match::Enregistrer()
{
    QString Msg;
    QString id;
    QString str;
    double value;
    Joueur *player;
    for (int i=0;i<this->_currrentEquipe->GetListeJoueur ().size ();i++)
    {
        player=_currrentEquipe->GetListeJoueur ().at (i);
        value=player->get_NumMaillot ();
        id.setNum (value);
        for(int Action=0;Action<InitAction::donneInstance()->GetSizeAction();Action++)
        {
            for(int valeur=0;valeur<InitValeur::donneInstance()->GetSizeValeur();valeur++)
            {
                value=player->getStatMatch (Action,valeur);
                str=str.setNum(value,'g',4);
                Msg=Msg+str+"_";
            }
        }

        _MatchSave.insert (id,Msg);
        Msg="";
    }

    Msg="";
    for(int Action=0;Action<InitAction::donneInstance()->GetSizeAction();Action++)
    {
        for(int valeur=0;valeur<InitValeur::donneInstance()->GetSizeValeur();valeur++)
        {
            value=_currrentEquipe->getStatMatch (Action,valeur);
            str=str.setNum (value,'g',4);
            Msg=Msg+str+"_";
        }
    }
    _MatchSave.insert ("team",Msg);

    this->_TempsSet.addSecs(_date.secsTo(QDateTime::currentDateTime()));
}

void Match::Enregistrer(QStringList list)
{
    int value;
    QString id;
    Joueur *player;
    _MatchSave.insert("team",list.at (0));
    for (int i=0;i<this->_currrentEquipe->GetListeJoueur ().size ();i++)
    {
        player=this->_currrentEquipe->GetListeJoueur ().at (i);
        value=player->get_NumMaillot ();
        id.setNum (value);
        _MatchSave.insert (id,list.at(i+1));
    }
}

QString Match::StatString(QString id)
{
    return _MatchSave[id];
}

void Match::Restaurer()
{

    // pour l'equipe
    QString old=this->_MatchSave["team"];
    QStringList listold=old.split ("_");
    int count=0;

    for(int Action=0;Action<InitAction::donneInstance()->GetSizeAction();Action++)
    {
        for(int valeur=0;valeur<InitValeur::donneInstance()->GetSizeValeur();valeur++)
        {
            QString strvalu=listold.at (count);
            _currrentEquipe->setStatMatch (Action,valeur,strvalu.toDouble ());
            count++;
        }
    }
    // pour les joueurs
    QString id;
    Joueur *player;
    for (int i=0;i<this->_currrentEquipe->GetListeJoueur ().size ();i++)
    {
        player=this->_currrentEquipe->GetListeJoueur ().at (i);
        int value=player->get_NumMaillot ();

        id.setNum (value);
        old=this->_MatchSave[id];
        listold=old.split ("_");
        int count=0;
        for(int Action=0;Action<InitAction::donneInstance()->GetSizeAction();Action++)
        {
            for(int valeur=0;valeur<InitValeur::donneInstance()->GetSizeValeur();valeur++)
            {
                QString strvalu=listold.at (count);
                player->setStatMatch (Action,valeur,strvalu.toDouble ());
                count++;
            }
        }
    }

}
QString Match::GetTemps()
{
    QString str;
    str=this->_TempsSet.toString("hh:mm::ss");
    return str;
}

/*QString Match::Restaurer(QString id)
{
    return this->_MatchSave[id];
}*/


void Match::setArbitre(QString Nom)
{
    this->_Arbitre=Nom;
}

QString Match::GetArbitre()
{
    return this->_Arbitre;
}

void Match::SetType(QString str)
{
    this->_Type=str;
}

QString Match::GetType()
{
    return this->_Type;
}
bool Match::AddAction(QString joueurname,int position, StatValeur valu,int action)
{
    Joueur* player=NULL;
    int currentjoueur;
    int numjoueur;
    bool error=true;
    QList <Joueur*> listJoueur=_currrentEquipe->GetListeJoueur();
    if(joueurname.toInt()==0)
    {
        player=_currrentEquipe->seachjoueur(0);
    }
    else
    {
        for(int i=0;i<listJoueur.count();i++)
        {
            currentjoueur=listJoueur.at(i)->get_NumMaillot();
            if(currentjoueur==joueurname.toInt())
            {
                numjoueur=i;
                player=listJoueur.at(i);

                break;
            }
        }
    }
    if(player!=NULL)
    {
        //player->Service(position,valu);
        player->addStatMatch(action,valu);
        player->addStatSet(action,valu);
        if(player->get_NumMaillot ()!=0)
        {
            _currrentEquipe->addStatMatch (action,valu);
            _currrentEquipe->addStatSet (action,valu);
        }
        error=false;
        //QString nomjoueur=player->get_Nom()+"_"+QString::number(player->get_NumMaillot());
        this->_Fichierxml->SauvegardeAction(player,action,2);
    }

    return error;

}

QList <Joueur*> Match::GetListJoueur()
{
    return _currrentEquipe->GetListeJoueur();
}

void Match::InitFichierXml()
{
    QStringList Info;
    QStringList Ratio;
    QStringList Action;
    Info.append(GetDate());
    Info.append(GetTemps());
    Info.append(_currrentEquipe->GetNom());
    Info.append(GetType());
    Info.append(getadvs());
    Info.append(GetArbitre());
    Info.append("temps");
    for(int i=0;i<InitValeur::donneInstance()->GetSizeValeur();i++)
    {
        Ratio.append(InitValeur::donneInstance()->GetElementValeur(i));
    }
    for(int i=0;i<InitAction::donneInstance()->GetSizeAction();i++)
    {
        Action.append(InitAction::donneInstance()->GetElementAction(i));
    }

    this->_Fichierxml=new MatchXml(Info,_ListTerrain,Ratio,Action);
}

void Match::SetJoueurTerr(QList<Joueur *> list)
{
    _ListTerrain=list;
    if(_Fichierxml!=0)
    {
        this->_Fichierxml->UpdateListJoueur(list);
    }
}


int Match::GetPoint(bool adv)
{
    if(adv==false)
    {
        return this->_point;
    }
    else
    {
        return this->_pointAdv;
    }
}

void Match::addPoint(bool adv)
{
    if(adv==false)
    {
        _point++;
    }
    else
    {
        _pointAdv++;
    }
    if(_Fichierxml!=0)
    {
        this->_Fichierxml->SauvegardeScore(_score->get_Score_E1(),_score->get_Score_E2());
        this->_Fichierxml->MiseaJourposte();
    }

}

int Match::GetFaute(bool adv)
{
    if(adv==false)
    {
        return this->_faute;
    }
    else
    {
        return this->_fauteAdv;
    }
}

void Match::addFaute(bool adv)
{
    if(adv==false)
    {
        this->_faute++;
    }
    else
    {
       this->_fauteAdv++;
    }
}

void Match::supFaute(bool adv)
{
    if(adv==false)
    {
        this->_faute--;
    }
    else
    {
       this->_fauteAdv--;
    }
}

void Match::InfoFromXML( QList <Equipe*> listequipe)
{
    QFile file("Current/Match.xml");
    QDomDocument doc;
    if (!file.open(QIODevice::ReadOnly))
        return;
    QString msg;
    int posli;
    int poscol;
    if (!doc.setContent(&file,&msg,&posli,&poscol))
    {
        file.close(); // tablit le document XML  partir des donnes du fichier (hirarchie, etc.)
        return;
    }
    file.close();
    QString nomEquipe="";
    QString adv="";
    QDomElement racine = doc.documentElement(); // renvoie la balise racine
    QDomNode noeud = racine.firstChild(); // renvoie la premire balise  mesure
    while(!noeud.isNull())
    {

          QDomElement element=noeud.toElement();

          if(element.tagName()=="Match")
          {

              this->_advers=element.attribute("Contre");
              this->_Arbitre=element.attribute("Arbitre");
              this->_numCurentSet=element.attribute("NbDeSet").toInt();
              this->_Type=element.attribute("Type");
              nomEquipe=element.attribute("Equipe");
              if(nomEquipe!="")
              {
                  for(int i=0;i<listequipe.size();i++)
                  {
                      if(listequipe.at(i)->GetNom()==nomEquipe)
                      {
                          this->_currrentEquipe=listequipe.at(i);
                          break;
                      }
                  }
              }
              _score->set_Equipe_1(nomEquipe);
              _score->set_Equipe_2(this->_advers);
          }
          if(element.tagName()=="Ratio")
          {
              QStringList listelement=element.text().split(",");
              InitValeur::donneInstance()->SetSelection(listelement);
          }
          if(element.tagName()=="Action")
          {
              QStringList listelement=element.text().split(",");
              InitAction::donneInstance()->SetSelection(listelement);
          }
          if(element.tagName()=="S1")
          {
              QDomNode child = element.firstChild();
              while(!child.isNull())
              {
                  if(child.toElement().tagName()=="Score")
                  {
                      QString score=child.toElement().text();
                      QStringList listScore=score.split(":");
                      _score->set_Score_E1(listScore[0].toInt());
                      //this->_point=listScore[0].toInt();
                       _score->set_Score_E2(listScore[1].toInt());
                  }
                  if(child.toElement().tagName()=="Stat")
                  {

                      QDomNode Gchild=child.firstChild();
                      while(!Gchild.isNull())
                      {
                          QString str=Gchild.toElement().tagName();
                          QStringList lis=str.split("_");
                          Joueur * joue=_currrentEquipe->seachjoueur(lis[1].toInt());
                          QDomNode G2child=Gchild.firstChild();
                          while(!G2child.isNull())
                          {

                              QString strAction=G2child.toElement().tagName();
                              int action=InitAction::donneInstance()->GetActionFromString(strAction);
                              for(int i=0;i<InitValeur::donneInstance()->GetSizeValeur();i++)
                              {
                                 joue->setStatMatch(action,i,G2child.toElement().attribute(InitValeur::donneInstance()->GetElementValeur(i)).toDouble());

                              }
                              G2child=G2child.nextSibling();
                          }


                          Gchild=Gchild.nextSibling();
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

                _listPosition.append(child.toElement().text());
               child=child.nextSibling();
              }
          }
             noeud=noeud.nextSibling();
    }

}
QList<Joueur *>  Match::GetListJoueurTerr()
{
    QList<Joueur *> listjoueur=this->_currrentEquipe->GetListeJoueur();
    for(int i=0;i<this->_listPosition.size();i++)
    {
        QString valeur=_listPosition.at(i);
        QStringList listval=valeur.split("_");
        for(int k=0;k<listjoueur.size();k++)
        {
            if(listjoueur.at(k)->get_NumMaillot()==listval[1].toInt())
            {
                listjoueur.at(k)->SetPosition(i+1);
                _ListTerrain.append(listjoueur.at(k));
                break;
            }


        }
    }
    return _ListTerrain;
}


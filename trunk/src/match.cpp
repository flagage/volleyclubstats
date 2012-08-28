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
    _ParamMatch=new ParametreMatch();
    _Fichierxml=0;
    _faute=0;
    _fauteAdv=0;
    _point=0;
    _pointAdv=0;



}

Match::~Match()
{
    delete _score;
    delete _ParamMatch;

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


    this->_ParamMatch->set_Date(QDate::currentDate());

    _nomFichier="Match_"+QDateTime::currentDateTime().toString("ddMMyyyy_hms")+".xml";

    /*FenetrePosition* pos=new FenetrePosition(_ecran);
        if(pos->exec())
        {*/
    Joueur* Adversaire=new Joueur();
    Adversaire->set_NumMaillot(0);
    Adversaire->set_Prenom(_ParamMatch->get_NomEquipeVisiteur());
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
    //_advers=nom;
    _ParamMatch->set_NomEquipeVisiteur(nom);
    _score->set_Equipe_2(nom);

}

Equipe* Match::getTeam()
{

    return _currrentEquipe;
}
QString Match::getadvs()
{
    return _ParamMatch->get_NomEquipeVisiteur();
}

QString Match::GetDate()
{
    return _ParamMatch->get_Date().toString("dd_MM_yyyy_hh_mm_ss");
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


QStringList Match::GetListAction()
{
    return _ParamMatch->get_Action();
}

void Match::EnregistrerXMl()
{
   /* QString Joueur;
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

    Equipe.setAttribute("listAction", this->_listActionMatch.join(","));
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

    }

    QFile file(QString("Sauvegarde/"+_nomFichier));
    if (!file.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &file );
    ts << doc.toString();
    file.close();*/
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

    if(_Fichierxml==0)
        return;

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
        //this->_currrentEquipe->initSet();
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
            //value=_currrentEquipe->getStatMatch (Action,valeur);
            str=str.setNum (value,'g',4);
            Msg=Msg+str+"_";
        }
    }
    _MatchSave.insert ("team",Msg);

   // this->_TempsSet.addSecs(_date.secsTo(QDateTime::currentDateTime()));
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
            //_currrentEquipe->setStatMatch (Action,valeur,strvalu.toDouble ());
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



QString Match::GetArbitre()
{
    return _ParamMatch->get_NomArbitre1();
}


QString Match::GetType()
{
    return _ParamMatch->get_TypeDeMatch();
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
            //_currrentEquipe->addStatMatch (action,valu);
            //_currrentEquipe->addStatSet (action,valu);
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

void Match::EcritureCurrentMatch()
{/*
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
    for(int i=0;i<_ParamMatch->get_Action().size();i++)
    {
        Action.append(_ParamMatch->get_Action().at(i));
    }

    this->_Fichierxml=new MatchXml(Info,_ListTerrain,Ratio,Action);
    */
    QDomDocument doc;
    QFile file;
    QDomElement root;
    QDomNode noeud=doc.createProcessingInstruction ("xml","version=\"1.0\" encoding=\"ISO-8859-1\" standalone=\"yes\"");
   doc.insertBefore (noeud,doc.firstChild ());
    root = doc.createElement("Info");
    doc.appendChild(root);

    QDomElement Info = doc.createElement("Match");
    Info.setAttribute("Date",_ParamMatch->get_Date().toString("ddMMyyyy"));
    //Info.setAttribute ("Heure",_ListInfo.at(1));
    Info.setAttribute("Equipe",_ParamMatch->get_NomEquipeLocal());
    Info.setAttribute("Contre",_ParamMatch->get_NomEquipeVisiteur());
    Info.setAttribute ("Type",_ParamMatch->get_TypeDeMatch());
    Info.setAttribute ("Arbitre1",_ParamMatch->get_NomArbitre1());
    Info.setAttribute ("Arbitre2",_ParamMatch->get_NomArbitre2());
    Info.setAttribute ("Nbjoueur",_ParamMatch->get_NbJoueur());
    Info.setAttribute("NbDeSet",_ParamMatch->get_NbSet());
    Info.setAttribute("NbPoint",_ParamMatch->get_ScoreMax());
    Info.setAttribute("Aveclibero",_ParamMatch->AvecLibero());
    //Info.setAttribute ("Duree",_ListInfo.at(6));
    //Info.setAttribute("NbDeSet",0);
    root.appendChild(Info);
    /// Information sur les ratio choisie
    QDomElement Ratio=doc.createElement("Ratio");
    QDomText text=doc.createTextNode(_ParamMatch->get_Valeur().join(","));
    Ratio.appendChild(text);
    root.appendChild(Ratio);

    /// Information sur les actions choisies
    QDomElement Action=doc.createElement("Action");
    text=doc.createTextNode(_ParamMatch->get_Action().join(","));
    Action.appendChild(text);
    root.appendChild(Action);
    /// position des joueurs
    QDomElement position=doc.createElement("Position");
    root.appendChild(position);
    QDomElement poste1=doc.createElement ("Poste1");
     text=doc.createTextNode(Rechercheposte(1));
    poste1.appendChild(text);
    position.appendChild(poste1);

    QDomElement poste2=doc.createElement ("Poste2");
    text=doc.createTextNode(Rechercheposte(2));
    poste2.appendChild(text);
    position.appendChild(poste2);

    QDomElement poste3=doc.createElement ("Poste3");
    text=doc.createTextNode(Rechercheposte(3));
    poste3.appendChild(text);
    position.appendChild(poste3);

    QDomElement poste4=doc.createElement ("Poste4");
    text=doc.createTextNode(Rechercheposte(4));
    poste4.appendChild(text);
    position.appendChild(poste4);

    QDomElement poste5=doc.createElement ("Poste5");
    text=doc.createTextNode(Rechercheposte(5));
    poste5.appendChild(text);
    position.appendChild(poste5);

    QDomElement poste6=doc.createElement ("Poste6");
    text=doc.createTextNode(Rechercheposte(6));
    poste6.appendChild(text);
    position.appendChild(poste6);

    QDomElement poste7=doc.createElement ("Poste7");
    text=doc.createTextNode(Rechercheposte(7));
    poste7.appendChild(text);
    position.appendChild(poste7);
/*
    QDomElement set1=doc.createElement();
    root.appendChild(set1);


/*
    /// score
    QDomElement score=_doc.createElement("Score");
    set1.appendChild(score);
    text=_doc.createTextNode("0:0");
    score.appendChild(text);

    /// stat liste des joueurs sur le terrain le reste ne sert pas
    QDomElement stat=_doc.createElement("Stat");
    set1.appendChild(stat);
    for(int i=0;i<this->_ListJoueurTer.size();i++)
    {
        QString label=_ListJoueurTer.at(i)->get_Prenom()+"_"+QString::number(_ListJoueurTer.at(i)->get_NumMaillot());
        QDomElement player=_doc.createElement(label);
        stat.appendChild(player);
        for(int j=0;j<InitAction::donneInstance()->GetSizeAction();j++)
        {
          QDomElement action=_doc.createElement(InitAction::donneInstance()->GetElementAction(j));
          for(int k=0;k<InitValeur::donneInstance()->GetSizeValeur();k++)
          {
              action.setAttribute(InitValeur::donneInstance()->GetElementValeur(k),0);
          }
          player.appendChild(action);
        }
    }
*/
  file.setFileName(QString("Current/Match.xml"));
    if (!file.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &file );
    ts << doc.toString();
    file.close();
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
    QDomElement racine = doc.documentElement(); // renvoie la balise racine
    QDomNode noeud = racine.firstChild(); // renvoie la premire balise  mesure
    while(!noeud.isNull())
    {

          QDomElement element=noeud.toElement();

          if(element.tagName()=="Match")
          {

              _ParamMatch->set_NomEquipeVisiteur(element.attribute("Contre"));
              _ParamMatch->set_NomArbitre1(element.attribute("Arbitre1"));
              _ParamMatch->set_NomArbitre2(element.attribute("Arbitre2"));
              //this->_numCurentSet=element.attribute("NbDeSet").toInt();
              _ParamMatch->set_TypeDeMatch(element.attribute("Type"));
              _ParamMatch->set_NbSet(element.attribute("NbDeSet").toInt());
              _ParamMatch->set_NbJoueur(element.attribute("NbJoueur").toInt());
              _ParamMatch->SetLibero(element.attribute("AvecLibero").toInt());
              _ParamMatch->set_ScoreMax(element.attribute("NbPoint").toInt());

              QString nomEquipe=element.attribute("Equipe");
              _ParamMatch->set_NomEquipeLocal(nomEquipe);
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
              _score->set_Equipe_2(_ParamMatch->get_NomEquipeVisiteur());
          }
          if(element.tagName()=="Ratio")
          {
              QStringList listelement=element.text().split(",");
              _ParamMatch->set_Valeur(listelement);
          }
          if(element.tagName()=="Action")
          {
              QStringList listelement=element.text().split(",");
              //_listActionMatch=listelement;
              _ParamMatch->set_Action(listelement);

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
                              QDomElement G2chElement=G2child.toElement();
                              QString strAction=G2chElement.tagName();

                              int action=InitAction::donneInstance()->GetActionFromString(strAction);
                              for(int i=0;i<InitValeur::donneInstance()->GetSizeValeur();i++)
                              {
                                  QString valeur=InitValeur::donneInstance()->GetElementValeur(i);
                                  QString element=G2chElement.attribute(valeur);

                                 joue->setStatMatch(action,i,element.toDouble());

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
    //InitFichierXml();*/
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
    this->SetJoueurTerr(_ListTerrain);
    return _ListTerrain;
}

void Match::setParametreMatch(ParametreMatch * param)
{
    _ParamMatch=param;
}

ParametreMatch* Match::GetParametreMatch()
{
    return _ParamMatch;
}

QString Match::Rechercheposte(int post)
{
    QString label="";
    for(int i=0;i<this->_ListTerrain.size();i++)
    {
        if(_ListTerrain.at(i)->GetPosition()==post)
         {
          label=_ListTerrain.at(i)->get_Prenom()+"_"+QString::number(_ListTerrain.at(i)->get_NumMaillot());
          break;
        }
    }
    return label;
}

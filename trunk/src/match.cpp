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
    _isStart=false;



}

Match::~Match()
{
    delete _score;
    delete _ParamMatch;
    delete _EquipeVisiteur;

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

    QDateTime date=QDateTime::currentDateTime();
    this->_ParamMatch->set_Date(date.date());

    _nomFichier="Match_"+QDateTime::currentDateTime().toString("ddMMyyyy_hms")+".xml";


    _lancementok=true;

    return _lancementok;
}



void Match::setAdvers(QString nom)
{

    _ParamMatch->set_NomEquipeVisiteur(nom);
    _EquipeVisiteur=new Equipe(nom);
    _EquipeVisiteur->InitialisationStat(_ParamMatch->get_NbSet(),_ParamMatch->get_Action(),_ParamMatch->get_Valeur());


}

Equipe* Match::getTeam()
{

    return _currentEquipe;
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
    QDomElement _root = doc.createElement("Info");
    doc.appendChild(_root);

    QDomElement Info = doc.createElement("Match");
    Info.setAttribute("Date",_date.toString("dd_MM_yyyy"));
    Info.setAttribute ("Heure",_date.toString ("hh:mm:ss"));
    Info.setAttribute("Equipe",_currentEquipe->GetNom ());
    Info.setAttribute ("Type",_Type);
    Info.setAttribute("Contre",_advers);
    Info.setAttribute ("Arbitre",this->_Arbitre);
    Info.setAttribute ("Duree","temps");
    Info.setAttribute("NbDeSet",_numCurentSet-1);
    _root.appendChild(Info);


    QDomElement Equipe= doc.createElement("Equipe");
    Equipe.setAttribute("Nom",this->_currentEquipe->GetNom());

    Equipe.setAttribute("listAction", this->_listActionMatch.join(","));
    Equipe.setAttribute("ListeValeur",_currentEquipe->GetStringValeur());
    _root.appendChild(Equipe);
    for(int k=0;k<this->_currentEquipe->GetListeJoueur ().size ();k++)
    {
        QDomElement Joueur= doc.createElement("Joueur");
        Joueur.setAttribute("Nom",_currentEquipe->GetListeJoueur ().at(k)->get_Prenom());
        QString num;
        num.setNum(_currentEquipe->GetListeJoueur ().at(k)->get_NumMaillot());
        Joueur.setAttribute("NumMaillot",num);
        Joueur.setAttribute("poste",_currentEquipe->GetListeJoueur ().at(k)->get_poste());
        Equipe.appendChild(Joueur);
    }



    QDomElement Stat=doc.createElement ("Statisitique");
    _root.appendChild(Stat);
    //le match

    QDomElement statMatch=doc.createElement ("MatchStat");

    //team.setAttribute ("Match",this->Restaurer ("team"));
    Stat.appendChild (statMatch);
    QDomElement equipe=doc.createElement ("team");

    equipe.setAttribute ("stat",this->StatString ("team"));
    statMatch.appendChild (equipe);
    for(int k=0;k<this->_currentEquipe->GetListeJoueur ().size ();k++)
    {

        Joueur.setNum (this->_currentEquipe->GetListeJoueur ().at (k)->get_NumMaillot ());
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
        for(int k=0;k<this->_currentEquipe->GetListeJoueur ().size ();k++)
        {

            Joueur.setNum (this->_currentEquipe->GetListeJoueur ().at (k)->get_NumMaillot ());
            clef="Num_"+Joueur;
            QDomElement joueur=doc.createElement (clef);

            //   joueur.setAttribute ("stat",this->_ListeSet.at (i-1)->Restaurer (Joueur));
            Set.appendChild (joueur);
        }
    }

    /*  for(int k=0;k<this->_currentEquipe->GetListeJoueur ().size ();k++)
    {

        QString Joueur;
        QString clef;

        Joueur.setNum (this->_currentEquipe->GetListeJoueur ().at (k)->get_NumMaillot ());
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
    //this->_curentset=new Set(this->_currentEquipe,_numCurentSet);
    //this->_curentset->SetScore(score);
    //this->_curentset->Enregistrer(list);
    // this->_ListeSet.append(_curentset);
    //this->_curentset->Enregistrer ();
    //_numCurentSet++;
}

void Match::FinSet()
{

    if(_ParamMatch->GetNumSet()<_ParamMatch->get_NbSet())
    {
        _score->SauvegardeScore();
        _ParamMatch->SetNumSet(_ParamMatch->GetNumSet()+1);
        this->MiseajourScore();
        this->AddSetToXml();

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
    /* QString Msg;
    QString id;
    QString str;
    double value;
    Joueur *player;
    for (int i=0;i<this->_currentEquipe->GetListeJoueur ().size ();i++)
    {
        player=_currentEquipe->GetListeJoueur ().at (i);
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
            //value=_currentEquipe->getStatMatch (Action,valeur);
            str=str.setNum (value,'g',4);
            Msg=Msg+str+"_";
        }
    }
    _MatchSave.insert ("team",Msg);

   // this->_TempsSet.addSecs(_date.secsTo(QDateTime::currentDateTime()));*/
}

void Match::Enregistrer(QStringList list)
{
    int value;
    QString id;
    Joueur *player;
    _MatchSave.insert("team",list.at (0));
    for (int i=0;i<this->_currentEquipe->GetListeJoueur ().size ();i++)
    {
        player=this->_currentEquipe->GetListeJoueur ().at (i);
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
    /* QString old=this->_MatchSave["team"];
    QStringList listold=old.split ("_");
    int count=0;

    for(int Action=0;Action<InitAction::donneInstance()->GetSizeAction();Action++)
    {
        for(int valeur=0;valeur<InitValeur::donneInstance()->GetSizeValeur();valeur++)
        {
            QString strvalu=listold.at (count);
            //_currentEquipe->setStatMatch (Action,valeur,strvalu.toDouble ());
            count++;
        }
    }
    // pour les joueurs
    QString id;
    Joueur *player;
    for (int i=0;i<this->_currentEquipe->GetListeJoueur ().size ();i++)
    {
        player=this->_currentEquipe->GetListeJoueur ().at (i);
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
*/
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
    QList <Joueur*> listJoueur=_currentEquipe->GetListeJoueur();
    if(joueurname.toInt()==0)
    {
        _EquipeVisiteur->addStatMatch(action,valu);
        _EquipeVisiteur->addStatSet(action,valu,_ParamMatch->GetNumSet());
        MiseAjourStat(_EquipeVisiteur,0,action);
        error=false;
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

        player->addStatMatch(action,valu);
        player->addStatSet(action,valu,_ParamMatch->GetNumSet());

        _currentEquipe->addStatMatch (action,valu);
        _currentEquipe->addStatSet (action,valu,_ParamMatch->GetNumSet());
        MiseAjourStat(_currentEquipe,player,action);

        error=false;
        //QString nomjoueur=player->get_Nom()+"_"+QString::number(player->get_NumMaillot());
        //this->_Fichierxml->SauvegardeAction(player,action,2);

    }

    return error;

}

QList <Joueur*> Match::GetListJoueur()
{
    return _currentEquipe->GetListeJoueur();
}

void Match::EcritureCurrentMatch()
{
    _fileXmlCurrent.setFileName(QString("Current/Match.xml"));
    QDomNode noeud=_doc.createProcessingInstruction ("xml","version=\"1.0\" encoding=\"ISO-8859-1\" standalone=\"yes\"");
    _doc.insertBefore (noeud,_doc.firstChild ());
    _root = _doc.createElement("Info");
    _doc.appendChild(_root);

    QDomElement Info = _doc.createElement("Match");
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
    _root.appendChild(Info);
    /// Information sur les ratio choisie
    QDomElement Ratio=_doc.createElement("Ratio");
    QDomText text=_doc.createTextNode(_ParamMatch->get_Valeur().join(","));
    Ratio.appendChild(text);
    _root.appendChild(Ratio);

    /// Information sur les actions choisies
    QDomElement Action=_doc.createElement("Action");
    text=_doc.createTextNode(_ParamMatch->get_Action().join(","));
    Action.appendChild(text);
    _root.appendChild(Action);
    /// position des joueurs
    QDomElement position=_doc.createElement("Position");
    _root.appendChild(position);
    QDomElement poste1=_doc.createElement ("Poste1");
    text=_doc.createTextNode(Rechercheposte(1));
    poste1.appendChild(text);
    position.appendChild(poste1);

    QDomElement poste2=_doc.createElement ("Poste2");
    text=_doc.createTextNode(Rechercheposte(2));
    poste2.appendChild(text);
    position.appendChild(poste2);

    QDomElement poste3=_doc.createElement ("Poste3");
    text=_doc.createTextNode(Rechercheposte(3));
    poste3.appendChild(text);
    position.appendChild(poste3);

    QDomElement poste4=_doc.createElement ("Poste4");
    text=_doc.createTextNode(Rechercheposte(4));
    poste4.appendChild(text);
    position.appendChild(poste4);

    QDomElement poste5=_doc.createElement ("Poste5");
    text=_doc.createTextNode(Rechercheposte(5));
    poste5.appendChild(text);
    position.appendChild(poste5);

    QDomElement poste6=_doc.createElement ("Poste6");
    text=_doc.createTextNode(Rechercheposte(6));
    poste6.appendChild(text);
    position.appendChild(poste6);

    QDomElement poste7=_doc.createElement ("Poste7");
    text=_doc.createTextNode(Rechercheposte(7));
    poste7.appendChild(text);
    position.appendChild(poste7);
    /*
    QDomElement set1=_doc.createElement();
    _root.appendChild(set1);

*/

    /// score
    QDomElement score=_doc.createElement("Score");
    score.setAttribute("ScLocal",_score->get_ScLocal());
    score.setAttribute("SetLocal",_score->get_SetLocal());
    score.setAttribute("TmLocal",_score->get_TmLocal());
    score.setAttribute("ScVisiteur",_score->get_ScVisiteur());
    score.setAttribute("SetVisiteur",_score->get_SetVisiteur());
    score.setAttribute("TmVisiteur",_score->get_TmVisiteur());
    score.setAttribute ("Service",_score->get_Service());
    _root.appendChild(score);

    /// Stat Equipe
    //QDomElement StatEquipe=_doc.createElement("StatEquipes");
    QDomElement statMatchlocal=_doc.createElement("StatMatch");
    EcrireStatMatchxml(&statMatchlocal);
    _root.appendChild(statMatchlocal);
    QDomElement statSet1=_doc.createElement("StatSet1");
    EcrireStatMatchxml(&statSet1);
    _root.appendChild(statSet1);

    /*
    /// stat liste des joueurs sur le terrain le reste ne sert pas
    QDomElement stat=__doc.createElement("Stat");
    set1.appendChild(stat);
    for(int i=0;i<this->_ListJoueurTer.size();i++)
    {
        QString label=_ListJoueurTer.at(i)->get_Prenom()+"_"+QString::number(_ListJoueurTer.at(i)->get_NumMaillot());
        QDomElement player=__doc.createElement(label);
        stat.appendChild(player);
        for(int j=0;j<InitAction::donneInstance()->GetSizeAction();j++)
        {
          QDomElement action=__doc.createElement(InitAction::donneInstance()->GetElementAction(j));
          for(int k=0;k<InitValeur::donneInstance()->GetSizeValeur();k++)
          {
              action.setAttribute(InitValeur::donneInstance()->GetElementValeur(k),0);
          }
          player.appendChild(action);
        }
    }
*/

    if (!_fileXmlCurrent.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &_fileXmlCurrent );
    ts << _doc.toString();
    _fileXmlCurrent.close();
}

void Match::EcrireStatMatchxml(QDomElement * element)
{

    QDomElement EquipeLocal=_doc.createElement("EquipeLocal");
    EquipeLocal.setAttribute("Nom",_currentEquipe->GetNom());
    EcrireStatXml(&EquipeLocal);
    element->appendChild(EquipeLocal);
    QDomElement EquipeVisiteur=_doc.createElement("EquipeVisiteur");
    EquipeVisiteur.setAttribute("Nom",_EquipeVisiteur->GetNom());
    EcrireStatXml(&EquipeVisiteur);
    element->appendChild(EquipeVisiteur);
    for(int i=0;i<_ListTerrain.size();i++)
    {
        QString valeur=_ListTerrain.at(i)->get_Prenom()+"_"+QString::number(_ListTerrain.at(i)->get_NumMaillot());
        QDomElement joueur=_doc.createElement(valeur);
        EcrireStatXml(&joueur);
        element->appendChild(joueur);
    }

}

void Match::EcrireStatXml(QDomElement * element)
{
    for(int j=0;j<_currentEquipe->GetListAction().size();j++)
    {
        QDomElement action=_doc.createElement(_currentEquipe->GetListAction().at(j));
        for(int k=0;k<_currentEquipe->GetListValeur().size();k++)
        {
            action.setAttribute(_currentEquipe->GetListValeur().at(k),_currentEquipe->getStatMatch(j,k));
        }
        element->appendChild(action);
    }

}

void Match::SetJoueurTerr(QList<Joueur *> list)
{
    _ListTerrain.clear();
    _ListTerrain=list;

    MiseaJourposte();

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
    /* if(_Fichierxml!=0)
    {
        this->_Fichierxml->SauvegardeScore(_score->get_Score_E1(),_score->get_Score_E2());

    }*/
    MiseajourScore();
    MiseaJourposte();

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
    _fileXmlCurrent.setFileName(QString("Current/Match.xml"));

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
            if(nomEquipe!="")
            {
                for(int i=0;i<listequipe.size();i++)
                {
                    if(listequipe.at(i)->GetNom()==nomEquipe)
                    {
                        this->_currentEquipe=listequipe.at(i);
                        break;
                    }
                }
            }
            //_score->set_Equipe_1(nomEquipe);
            //  _score->set_Equipe_2(_ParamMatch->get_NomEquipeVisiteur());
        }
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
            this->_EquipeVisiteur=new Equipe(_ParamMatch->get_NomEquipeVisiteur());
            this->_EquipeVisiteur->InitialisationStat(_ParamMatch->get_NbSet(),_ParamMatch->get_Action(),_ParamMatch->get_Valeur());
            _currentEquipe->InitialisationStat(_ParamMatch->get_NbSet(),_ParamMatch->get_Action(),_ParamMatch->get_Valeur());

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
            QStringList listScore=element.attribute("ListScore").split("_");
            _score->Set_ListScore(listScore);
            _ParamMatch->SetNumSet(listScore.size());

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
                    Joueur *player=RechercheJoueur(child.toElement().tagName());
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
                    Joueur *player=RechercheJoueur(child.toElement().tagName());
                    if(player!=0)
                    {
                        InitStatFromXml(child,3,true,strSet.toInt(),player);
                    }
                }
                child=child.nextSibling();
            }
        }
        /*if(element.tagName()=="S1")
          {
              QDomNode child = element.firstChild();
              while(!child.isNull())
              {
                  if(child.toElement().tagName()=="Score")
                  {
                      QString score=child.toElement().text();
                      QStringList listScore=score.split(":");
                      //_score->set_Score_E1(listScore[0].toInt());
                      //_score->set_Score_E2(listScore[1].toInt());
                  }
                  if(child.toElement().tagName()=="Stat")
                  {

                      QDomNode Gchild=child.firstChild();
                      while(!Gchild.isNull())
                      {
                          QString str=Gchild.toElement().tagName();
                          QStringList lis=str.split("_");
                          Joueur * joue=_currentEquipe->seachjoueur(lis[1].toInt());
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

          }*/
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
    InitListTerrainfromPosition();
}

void Match::InitStatFromXml(QDomNode child,int TemOrPl,bool isSet,int numset,Joueur* player)
{
    QDomNode Gchild=child.firstChild();
    while(!Gchild.isNull())
    {
        QDomElement GchElement=Gchild.toElement();
        QString strAction=GchElement.tagName();

        int action=_ParamMatch->GetActionFromString(strAction);
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
                    _currentEquipe->setStatMatch(action,i,Dvaleur);
                }
                else
                {
                    _currentEquipe->setStatSet(action,i,element.toDouble(),numset);
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

void Match::InitListTerrainfromPosition()
{
    _ListTerrain.clear();
    QList<Joueur *> listjoueur=this->_currentEquipe->GetListeJoueur();
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
}


QList<Joueur *>  Match::GetListJoueurTerr()
{

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
void Match::MiseajourScore()
{
    QDomElement docElem = _doc.documentElement();
    QDomNode n = docElem.firstChild();
    while(!n.isNull())
    {
        QDomElement e = n.toElement();
        if(e.tagName()=="Score")
        {
            e.setAttribute("ScLocal",_score->get_ScLocal());
            e.setAttribute("SetLocal",_score->get_SetLocal());
            e.setAttribute("TmLocal",_score->get_TmLocal());
            e.setAttribute("ScVisiteur",_score->get_ScVisiteur());
            e.setAttribute("SetVisiteur",_score->get_SetVisiteur());
            e.setAttribute("TmVisiteur",_score->get_TmVisiteur());
            e.setAttribute ("Service",_score->get_Service());
            e.setAttribute("ListScore",_score->ListdesScore().join("_"));

        }
        n = n.nextSibling();
    }


    if (!_fileXmlCurrent.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &_fileXmlCurrent );
    ts << _doc.toString();
    _fileXmlCurrent.close();
}

void Match:: MiseaJourposte()
{

    QDomElement docElem = _doc.documentElement();
    QDomNode n = docElem.firstChild();
    while(!n.isNull())
    {
        QDomElement e = n.toElement();
        if(e.tagName()=="Position")
        {
            QDomNode child=e.firstChild();
            while(!child.isNull())
            {
                QDomElement f=child.toElement();
                QString poste=f.tagName();
                QString number=poste.at(5);
                int ipost=number.toInt();
                f.replaceChild(_doc.createTextNode(this->Rechercheposte(ipost)),f.firstChild());

                child=child.nextSibling();
            }

        }
        n = n.nextSibling();
    }


    if (!_fileXmlCurrent.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &_fileXmlCurrent );
    ts << _doc.toString();
    _fileXmlCurrent.close();
}

bool Match::isStart()
{
    return _isStart;
}

void Match::setStart(bool valeur)
{
    _isStart=valeur;
}

void Match::setCurrentEquipe(Equipe *Team)
{
    _currentEquipe=Team;
    _currentEquipe->InitialisationStat(_ParamMatch->get_NbSet(),_ParamMatch->get_Action(),_ParamMatch->get_Valeur());


}



Equipe* Match::GetEquipeVisiteur()
{
    return _EquipeVisiteur;
}

void Match::MiseAjourStat(Equipe* team,Joueur *player,int Action,bool isSet)
{
    QDomElement docElem = _doc.documentElement();
    QDomNode n = docElem.firstChild();
    QString strjoueur="";
    QString strSetMatch="";
    if(player!=0)
    {
        strjoueur=player->get_Prenom()+"_"+QString::number(player->get_NumMaillot());
    }
    if(isSet==true)
    {
        strSetMatch="StatSet"+QString::number(_ParamMatch->GetNumSet());
    }
    else
    {
        strSetMatch="StatMatch";
    }

    while(!n.isNull())
    {
        QDomElement e = n.toElement();

        if(e.tagName()==strSetMatch)
        {
            QDomNode child=e.firstChild();
            while(!child.isNull())
            {
                QDomElement f=child.toElement();
                if(f.attribute("Nom")==team->GetNom())
                {
                    MiseAjourStatTeam(f,Action,team,isSet);
                }
                if(f.tagName()==strjoueur)
                {
                    MiseAjourStatPlayer(f,Action,player,isSet);
                }
                child=child.nextSibling();
            }
        }
        n=n.nextSibling();
    }
    if (!_fileXmlCurrent.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &_fileXmlCurrent );
    ts << _doc.toString();
    _fileXmlCurrent.close();
    if(isSet==false)
    {
        this->MiseAjourStat(team,player,Action,true);
    }
}



void Match::MiseAjourStatTeam( QDomElement f,int Action,Equipe* team,bool isSet)
{
    QDomNode GChild=f.firstChild();
    while (!GChild.isNull())
    {

        QDomElement h=GChild.toElement();
        //test=h.tagName();
        if(h.tagName()==_ParamMatch->get_Action().at(Action))
        {
            for(int k=0;k<_ParamMatch->get_Valeur().size();k++)
            {
                double valeur;
                if(isSet==false)
                {
                    valeur=team->getStatMatch(Action,k);
                }
                else
                {
                    valeur=team->getStatSet(Action,k,_ParamMatch->GetNumSet());
                }
                QString attValeur=_ParamMatch->get_Valeur().at(k);
                QString valuValeur=QString::number(valeur);
                h.setAttribute(attValeur,valuValeur);
            }
        }

        GChild=GChild.nextSibling();
    }
}

void Match::MiseAjourStatPlayer( QDomElement f,int Action,Joueur* player,bool isSet)
{
    QDomNode GChild=f.firstChild();
    while (!GChild.isNull())
    {

        QDomElement h=GChild.toElement();
        //test=h.tagName();
        if(h.tagName()==_ParamMatch->get_Action().at(Action))
        {
            for(int k=0;k<_ParamMatch->get_Valeur().size();k++)
            {
                double valeur;
                if(isSet==false)
                {
                    valeur=player->getStatMatch(Action,k);
                }
                else
                {
                    valeur=player->getStatSet(Action,k,_ParamMatch->GetNumSet());
                }
                QString attValeur=_ParamMatch->get_Valeur().at(k);
                QString valuValeur=QString::number(valeur);
                h.setAttribute(attValeur,valuValeur);
            }
        }

        GChild=GChild.nextSibling();
    }
}

void Match::AddSetToXml()
{
    QString strSet="StatSet"+QString::number(_ParamMatch->GetNumSet());
    QDomElement statSet=_doc.createElement(strSet);
    EcrireStatMatchxml(&statSet);
    _root.appendChild(statSet);
}

void Match::AddJoueurToXml(Joueur * player,bool isSet)
{
    QDomElement docElem = _doc.documentElement();
    QDomNode n = docElem.firstChild();
    QString  strjoueur=player->get_Prenom()+"_"+QString::number(player->get_NumMaillot());
    QDomElement placerici;
    QString strSetMatch;
    if(isSet==true)
    {
        strSetMatch="StatSet"+QString::number(_ParamMatch->GetNumSet());
    }
    else
    {
        strSetMatch="StatMatch";
    }
    while(!n.isNull())
    {

        QDomElement e = n.toElement();

        if(e.tagName()==strSetMatch)
        {
            placerici=e;
            //On cherche si le joueur n'est pas deja dans les stats pour pas avoir de doublon
            QDomNode Gchild=placerici.firstChild();
            while(!Gchild.isNull())
            {
                if(Gchild.toElement().tagName()==strjoueur)
                {
                    return;
                }
                Gchild=Gchild.nextSibling();
            }

        }


        n=n.nextSibling();
    }
    QDomElement joueur=_doc.createElement(strjoueur);
    EcrireStatXml(&joueur);
    placerici.appendChild(joueur);

    if (!_fileXmlCurrent.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &_fileXmlCurrent );
    ts << _doc.toString();
    _fileXmlCurrent.close();
    if(isSet==false)
    {
        AddJoueurToXml(player,true);
    }
}

Joueur* Match::RechercheJoueur(QString strjoueur)
{

    QStringList liststrjoueur=strjoueur.split("_");
    for(int i=0;i<_currentEquipe->GetListeJoueur().size();i++)
    {
        if(_currentEquipe->GetListeJoueur().at(i)->get_NumMaillot()==liststrjoueur.at(1).toInt())
        {
            return _currentEquipe->GetListeJoueur().at(i);
        }
    }
    return 0;
}
/*void Match::AjouterSetXml()
{

}*/

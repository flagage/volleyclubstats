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
    _ListJoueur=_currrentEquipe->GetListeJoueur();
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
    if(joueurname.toInt()==0)
    {
        player=_currrentEquipe->seachjoueur(0);
    }
    else
    {
        for(int i=0;i<_ListJoueur.count();i++)
        {
            currentjoueur=_ListJoueur.at(i)->get_NumMaillot();
            if(currentjoueur==joueurname.toInt())
            {
                numjoueur=i;
                player=_ListJoueur.at(i);

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
    }

    return error;

}

QList <Joueur*> Match::GetListJoueur()
{
    return _ListJoueur;
}

void Match::InitFichierXml()
{
    this->_Fichierxml=new MatchXml();
}

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
#include "set.h"

Set::Set( Equipe * team,int numero)
{
    _ScoreAdv=0;
    _ScoreEquipe=0;
    _Commentaire="";
    _num=numero;
    _team=team;
    _DateDebut=QDateTime::currentDateTime();
    this->_ListJoueur=_team->GetListeJoueur ();
    Initialise();
}
void Set::Initialise()
{

        for(int i=0;i<_team->GetListeJoueur ().size ();i++)
    {
        _team->GetListeJoueur ().at (i)->initSet ();
    }

    _team->initSet ();
}

void Set::setEquipe(int i)
{
    _ScoreEquipe=i;
}


void Set::setAdv(int i)
{
    _ScoreAdv=i;
}


void Set::setCommetaire(QString msg)
{
    _Commentaire=msg;
}


void Set::EnregistrerXML(QDomDocument doc, QDomElement root)
{
   /* QDomElement Set = doc.createElement("Set");
    Set.setAttribute("ScoreEquipe",_ScoreEquipe);
    Set.setAttribute("ScoreAdv",_ScoreAdv);
    Set.setAttribute("Commentaire",_Commentaire);
    Set.setAttribute("Numero",_num);
    root.appendChild(Set);
    for(int i=0;i<_ListJoueur.count();i++)
    {
        Joueur* player=_ListJoueur.at(i);
        QDomElement tag = doc.createElement("joueur");
        tag.setAttribute("Prenom",player->get_Prenom());
        tag.setAttribute("Maillot",player->get_NumMaillot());
        Set.appendChild(tag);

        //score par position
        QDomElement tag2=doc.createElement("Attaques");
        tag.appendChild(tag2);
        QDomElement tag3;
        for(int p=0;p<6;p++)
        {
        QString strpos="position";
        QString num;
        num.setNum(p);
        strpos=strpos+num;
        tag3=doc.createElement(strpos);
        tag3.setAttribute("PP",this->_TabAtta[i].GetValeur(VPP,p));
        tag3.setAttribute("P",this->_TabAtta[i].GetValeur(VP,p));
        tag3.setAttribute("O",this->_TabAtta[i].GetValeur(V0,p));
        tag3.setAttribute("M",this->_TabAtta[i].GetValeur(VM,p));
        tag3.setAttribute("MM",this->_TabAtta[i].GetValeur(VMM,p));
         tag2.appendChild(tag3);
        }

         tag2=doc.createElement("Reception");
        tag.appendChild(tag2);
        for(int p=0;p<6;p++)
        {
        QString strpos="position";
        QString num;
        num.setNum(p);
        strpos=strpos+num;
        tag3=doc.createElement(strpos);
        tag3.setAttribute("PP",this->_TabRece[i].GetValeur(VPP,p));
        tag3.setAttribute("P",this->_TabRece[i].GetValeur(VP,p));
        tag3.setAttribute("O",this->_TabRece[i].GetValeur(V0,p));
        tag3.setAttribute("M",this->_TabRece[i].GetValeur(VM,p));
        tag3.setAttribute("MM",this->_TabRece[i].GetValeur(VMM,p));
         tag2.appendChild(tag3);
        }

        tag2=doc.createElement("Service");
        tag.appendChild(tag2);
        QString strpos="position";
        QString num;
        num.setNum(1);
        strpos=strpos+num;
        tag3=doc.createElement(strpos);
        tag3.setAttribute("PP",this->_TabAtta[i].GetValeur(VPP,1));
        tag3.setAttribute("P",this->_TabAtta[i].GetValeur(VP,1));
        tag3.setAttribute("O",this->_TabAtta[i].GetValeur(V0,1));
        tag3.setAttribute("M",this->_TabAtta[i].GetValeur(VM,1));
        tag3.setAttribute("MM",this->_TabAtta[i].GetValeur(VMM,1));
         tag2.appendChild(tag3);
        }

        //player->EnregistrerStatXML(doc,Set);*/

}
void Set::SetScore(QString Score)
{
    _ScoreSave=Score;
}

void Set::Enregistrer(QStringList list)
{
 int value;
  QString id;
 Joueur *player;
     _SetSave.insert("team",list.at(0));
    for (int i=0;i<_team->GetListeJoueur ().size ();i++)
    {
        player=_team->GetListeJoueur ().at (i);
        value=player->get_NumMaillot ();
        id.setNum (value);
        _SetSave.insert (id,list.at(i+1));
        }
       // _team->setStatSet ();
       this->Restaurer ();
}

void Set::Restaurer ()
{
   QString old=this->_SetSave["team"];
        QStringList listold=old.split ("_");
int count=0;
         for(int Action=0;Action<InitAction::donneInstance()->GetSizeAction();Action++)
    {
        for(int valeur=0;valeur<InitValeur::donneInstance()->GetSizeValeur();valeur++)
        {
            int k=(Action*InitValeur::donneInstance()->GetSizeValeur())+valeur;
            QString strvalu=listold.at (count);
            _team->setStatSet (Action,valeur,strvalu.toDouble ());
            count++;
        }
   }
// pour les joueurs
         QString id;
         Joueur *player;
         for (int i=0;i<this->_team->GetListeJoueur ().size ();i++)
         {
             player=this->_team->GetListeJoueur ().at (i);
             int value=player->get_NumMaillot ();

             id.setNum (value);
             old=this->_SetSave[id];
             listold=old.split ("_");
             count=0;
             for(int Action=0;Action<InitAction::donneInstance()->GetSizeAction();Action++)
             {
                 for(int valeur=0;valeur<InitValeur::donneInstance()->GetSizeValeur();valeur++)
                 {
                     QString strvalu=listold.at (count);
                     player->setStatSet (Action,valeur,strvalu.toDouble ());
                     count++;
                 }
             }
         }

}
void Set::Enregistrer()
{
 QString Msg;
 QString id;
 QString str;
 double value;
 Joueur *player;
    for (int i=0;i<_team->GetListeJoueur ().size ();i++)
    {
        player=_team->GetListeJoueur ().at (i);
        value=player->get_NumMaillot ();
        id.setNum (value);
        for(int Action=0;Action<InitAction::donneInstance()->GetSizeAction();Action++)
        {
            for(int valeur=0;valeur<InitValeur::donneInstance()->GetSizeValeur();valeur++)
            {
                value=player->getStatSet (Action,valeur);
                str=str.setNum (value,'g',4);
                Msg=Msg+str+"_";
            }
        }

        _SetSave.insert (id,Msg);
        Msg="";
    }

    Msg="";
    for(int Action=0;Action<InitAction::donneInstance()->GetSizeAction();Action++)
    {
        for(int valeur=0;valeur<InitValeur::donneInstance()->GetSizeValeur();valeur++)
        {
            value=_team->getStatSet (Action,valeur);
            str=str.setNum (value,'g',4);
            Msg=Msg+str+"_";
        }
    }
    _SetSave.insert ("team",Msg);
	
	Msg="";
	Msg.setNum(_ScoreEquipe);
	id="";
	id.setNum(_ScoreAdv);
	Msg=Msg+":"+id;
	_ScoreSave=Msg;
        int temp=(this->_DateDebut.secsTo(QDateTime::currentDateTime()));
        _TempsSet.addSecs(temp);
}

QString Set::GetTempsSet()
{
    QString str=this->_TempsSet.toString("hh:mm:ss");
    return str;
}

QString Set::Restaurer(QString id)
{
    return this->_SetSave[id];
}

bool Set::Attaque(QString joueurname,int position, StatValeur valu)
{

    Joueur* player=NULL;
      bool error=true;
    int numjoueur;
    int currentjoueur;

    for(int i=0;i<_ListJoueur.count();i++)
    {
        currentjoueur=_ListJoueur.at(i)->get_NumMaillot();
        if(currentjoueur==joueurname.toInt())
        {
            player=_ListJoueur.at(i);
            numjoueur=i;
            break;
        }
    }
    if(player!=NULL)
    {
        //player->Attaque(position,valu);
        player->addStatMatch(2,valu);
        player->addStatSet(2,valu);
        if(player->get_NumMaillot ()!=0)
        {
            _team->addStatMatch (2,valu);
            _team->addStatSet (2,valu);
        }
        error=false;
    }

return error;



}

bool Set::Reception(QString joueurname,int position, StatValeur valu)
{

    Joueur* player=NULL;
    bool error=true;

    //QString strCompare;
    int currentjoueur;
     int numjoueur;
    for(int i=0;i<_ListJoueur.count();i++)
    { //strCompare.setNum(_ListJoueur.at(i)->get_NumMaillot());
        currentjoueur=_ListJoueur.at(i)->get_NumMaillot();
        if(currentjoueur==joueurname.toInt())
        {
            player=_ListJoueur.at(i);
            numjoueur=i;
            break;
        }
    }
    if(player!=NULL)
    {
        //player->Reception(position,valu);
        player->addStatMatch(1,valu);
        player->addStatSet(1,valu);
     //   _TabRece[numjoueur].Ajouter(position,valu);
      if(player->get_NumMaillot ()!=0)
        {
            _team->addStatMatch (1,valu);
            _team->addStatSet (1,valu);
        }
        error=false;
    }

return error;


}


bool Set::Service(QString joueurname,int position, StatValeur valu)
{

    Joueur* player=NULL;
     int currentjoueur;
     int numjoueur;
     bool error=true;

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
    if(player!=NULL)
    {
        //player->Service(position,valu);
        player->addStatMatch(0,valu);
        player->addStatSet(0,valu);
        //_TabServ[numjoueur].Ajouter(position,valu);
         if(player->get_NumMaillot ()!=0)
        {
            _team->addStatMatch (0,valu);
            _team->addStatSet (0,valu);
        }
        error=false;
    }

return error;

}

bool Set::AddAction(QString joueurname,int position, StatValeur valu,int action)
{
    Joueur* player=NULL;
     int currentjoueur;
     int numjoueur;
     bool error=true;

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
    if(player!=NULL)
    {
        //player->Service(position,valu);
        player->addStatMatch(action,valu);
        player->addStatSet(action,valu);
         if(player->get_NumMaillot ()!=0)
        {
            _team->addStatMatch (action,valu);
            _team->addStatSet (action,valu);
        }
        error=false;
    }

return error;

}


QString Set::ScoreSave()
{
return _ScoreSave;
}

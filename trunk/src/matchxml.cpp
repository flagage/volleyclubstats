#include "matchxml.h"

MatchXml::MatchXml(QStringList listInfo, QList<Joueur *> listJoueur)
{
    _ListInfo=listInfo;
    _ListJoueurTer=listJoueur;
    Initialisation();
}

void MatchXml::Initialisation()
{

    /// information generiques sur le match
    _doc.setNodeValue("Info");
    QDomNode noeud=_doc.createProcessingInstruction ("xml","version=\"1.0\" encoding=\"ISO-8859-1\" standalone=\"yes\"");
   _doc.insertBefore (noeud,_doc.firstChild ());
    QDomElement root = _doc.createElement("Info");
    _doc.appendChild(root);

    QDomElement Info = _doc.createElement("Match");
    Info.setAttribute("Date",_ListInfo.at(0));
    Info.setAttribute ("Heure",_ListInfo.at(1));
    Info.setAttribute("Equipe",_ListInfo.at(2));
    Info.setAttribute ("Type",_ListInfo.at(3));
    Info.setAttribute("Contre",_ListInfo.at(4));
    Info.setAttribute ("Arbitre",_ListInfo.at(5));
    Info.setAttribute ("Duree",_ListInfo.at(6));
    Info.setAttribute("NbDeSet",0);
    root.appendChild(Info);
    QDomElement set1=_doc.createElement("S1");
    root.appendChild(set1);
    /// position des joueurs
    QDomElement position=_doc.createElement("Position");
    set1.appendChild(position);
    QDomElement poste1=_doc.createElement ("Poste1");
    QDomText text=_doc.createTextNode(Rechercheposte(1));
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

    QDomElement poste7=_doc.createElement ("Libero");
    text=_doc.createTextNode(Rechercheposte(7));
    poste7.appendChild(text);
    position.appendChild(poste7);


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

  _file.setFileName(QString("Current/Match.xml"));
    if (!_file.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &_file );
    ts << _doc.toString();
    _file.close();
}

QString MatchXml::Rechercheposte(int post)
{
    QString label="";
    for(int i=0;i<this->_ListJoueurTer.size();i++)
    {
        if(_ListJoueurTer.at(i)->GetPosition()==post)
         {
          label=_ListJoueurTer.at(i)->get_Prenom()+"_"+QString::number(_ListJoueurTer.at(i)->get_NumMaillot());
          break;
        }
    }
    return label;
}

void MatchXml::SauvegardeAction(Joueur* player,int Action,int valu)
{


    QString nom=player->get_Prenom()+"_"+QString::number(player->get_NumMaillot());


         QDomElement docElem = _doc.documentElement();
         QDomNode n = docElem.firstChild();
         while(!n.isNull())
         {
             QDomElement e = n.toElement();
             QString test=e.tagName();
             if(e.tagName()=="S1")
             {
                 QDomNode child=e.firstChild();
                 while(!child.isNull())
                 {
                     QDomElement f=child.toElement();
                     if(f.tagName()=="Stat")
                     {
                         QDomNode Gchild=f.firstChild();
                                          while(!Gchild.isNull())
                                          {
                                              QDomElement g=Gchild.toElement();
                                              test=g.tagName();
                                              if(g.tagName()==nom)
                                              {
                                                  QDomNode G2child=g.firstChild();
                                                                   while(!G2child.isNull())
                                                                   {
                                                                        QDomElement h=G2child.toElement();
                                                                        test=h.tagName();
                                                                        if(h.tagName()==InitAction::donneInstance()->GetElementAction(Action))
                                                                        {
                                                                            for(int k=0;k<InitValeur::donneInstance()->GetSizeValeur();k++)
                                                                            {
                                                                            double valeur=player->getStatSet(Action,k);
                                                                            h.setAttribute(InitValeur::donneInstance()->GetElementValeur(k),QString::number(valeur));
                                                                            }
                                                                        }

                                                                        G2child=G2child.nextSibling();
                                                                   }

                                              }
                                              Gchild=Gchild.nextSibling();
                                          }

                     }
                     child=child.nextSibling();
                 }
             }
             // C'est ici que l'on va marquer le code
             n = n.nextSibling();
         }
         if (!_file.open(QIODevice::WriteOnly))
             return;
         QTextStream ts( &_file );
         ts << _doc.toString();
         _file.close();
    }

void MatchXml::SauvegardeScore(int Slocal,int Svisiteur)
{
    QDomElement docElem = _doc.documentElement();
    QDomNode n = docElem.firstChild();
    while(!n.isNull())
    {
        QDomElement e = n.toElement();
        //QString test=e.tagName();
        if(e.tagName()=="S1")
        {
            QDomNode child=e.firstChild();
            while(!child.isNull())
            {
                QDomElement f=child.toElement();
                if(f.tagName()=="Score")
                {
                    QString score=QString::number(Slocal)+":"+QString::number(Svisiteur);
                    QDomText text=_doc.createTextNode(score);
                     f.replaceChild(text,f.firstChild());
                }
                child=child.nextSibling();
            }
        }
        // C'est ici que l'on va marquer le code
        n = n.nextSibling();
        }

    if (!_file.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &_file );
    ts << _doc.toString();
    _file.close();


}
        /*
    QDomElement Equipe= _doc.createElement("Equipe");
    Equipe.setAttribute("Nom",this->_currrentEquipe->GetNom());
    Equipe.setAttribute("listAction",this->_currrentEquipe->GetStringAction());
    Equipe.setAttribute("ListeValeur",_currrentEquipe->GetStringValeur());
    root.appendChild(Equipe);
    for(int k=0;k<this->_currrentEquipe->GetListeJoueur ().size ();k++)
    {
        QDomElement Joueur= _doc.createElement("Joueur");
        Joueur.setAttribute("Nom",_currrentEquipe->GetListeJoueur ().at(k)->get_Prenom());
        QString num;
        num.setNum(_currrentEquipe->GetListeJoueur ().at(k)->get_NumMaillot());
        Joueur.setAttribute("NumMaillot",num);
        Joueur.setAttribute("poste",_currrentEquipe->GetListeJoueur ().at(k)->get_poste());
        Equipe.appendChild(Joueur);
    }



    QDomElement Stat=_doc.createElement ("Statisitique");
    root.appendChild(Stat);
    //le match

    QDomElement statMatch=_doc.createElement ("MatchStat");

    //team.setAttribute ("Match",this->Restaurer ("team"));
    Stat.appendChild (statMatch);
    QDomElement equipe=_doc.createElement ("team");

    equipe.setAttribute ("stat",this->StatString ("team"));
    statMatch.appendChild (equipe);
    for(int k=0;k<this->_currrentEquipe->GetListeJoueur ().size ();k++)
    {

        Joueur.setNum (this->_currrentEquipe->GetListeJoueur ().at (k)->get_NumMaillot ());
        clef="Num_"+Joueur;
        QDomElement joueur=_doc.createElement (clef);

        joueur.setAttribute ("stat",this->StatString (Joueur));
        statMatch.appendChild (joueur);
    }

    for(int i=1;i<_numCurentSet;i++)
    {
        QString numset;
        numset.setNum (i);
        numset="Set"+numset;
        QDomElement Set=_doc.createElement (numset);
        //Set.setAttribute("score",this->_ListeSet.at (i-1)->ScoreSave());


        //  Set.setAttribute ("stat",this->_ListeSet.at (i-1)->Restaurer ("team"));
        Stat.appendChild (Set);


        /// Equipe
        clef="Team";
        QDomElement equipe=_doc.createElement (clef);

        //equipe.setAttribute ("stat",this->_ListeSet.at (i-1)->Restaurer ("team"));
        Set.appendChild (equipe);
        for(int k=0;k<this->_currrentEquipe->GetListeJoueur ().size ();k++)
        {

            Joueur.setNum (this->_currrentEquipe->GetListeJoueur ().at (k)->get_NumMaillot ());
            clef="Num_"+Joueur;
            QDomElement joueur=_doc.createElement (clef);

            //   joueur.setAttribute ("stat",this->_ListeSet.at (i-1)->Restaurer (Joueur));
            Set.appendChild (joueur);
        }
    }

      for(int k=0;k<this->_currrentEquipe->GetListeJoueur ().size ();k++)
    {

        QString Joueur;
        QString clef;

        Joueur.setNum (this->_currrentEquipe->GetListeJoueur ().at (k)->get_NumMaillot ());
        clef="Num_"+Joueur;
        QDomElement joueur=_doc.createElement (clef);
        Stat.appendChild (joueur);
        joueur.setAttribute ("Match",this->Restaurer (Joueur));

        for(int i=1;i<_numCurentSet;i++)
        {
            QString numset;
            numset.setNum (i);
            numset="Set"+numset;
            QDomElement Set=_doc.createElement (numset);
           // Set.setAttribute("score",this->_ListeSet.at (i-1)->ScoreSave());


            Set.setAttribute ("stat",this->_ListeSet.at (i-1)->Restaurer (Joueur));
            joueur.appendChild (Set);

        }

    }*/





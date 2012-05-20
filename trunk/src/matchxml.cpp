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
    QDomDocument doc("Info");
    QDomNode noeud=doc.createProcessingInstruction ("xml","version=\"1.0\" encoding=\"ISO-8859-1\" standalone=\"yes\"");
    doc.insertBefore (noeud,doc.firstChild ());
    QDomElement root = doc.createElement("Info");
    doc.appendChild(root);

    QDomElement Info = doc.createElement("Match");
    Info.setAttribute("Date",_ListInfo.at(0));
    Info.setAttribute ("Heure",_ListInfo.at(1));
    Info.setAttribute("Equipe",_ListInfo.at(2));
    Info.setAttribute ("Type",_ListInfo.at(3));
    Info.setAttribute("Contre",_ListInfo.at(4));
    Info.setAttribute ("Arbitre",_ListInfo.at(5));
    Info.setAttribute ("Duree",_ListInfo.at(6));
    Info.setAttribute("NbDeSet",0);
    root.appendChild(Info);
    /// position des joueurs
    QDomElement position=doc.createElement("Position");
    root.appendChild(position);
    QDomElement poste1=doc.createElement ("Poste1");
    QDomText text=doc.createTextNode(Rechercheposte(1));
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

    QDomElement poste7=doc.createElement ("Libero");
    text=doc.createTextNode(Rechercheposte(7));
    poste7.appendChild(text);
    position.appendChild(poste7);


    /// score
    QDomElement score=doc.createElement("Score");
    root.appendChild(score);
    QDomElement set1=doc.createElement("S1");
    text=doc.createTextNode("0:0");
    set1.appendChild(text);
    score.appendChild(set1);

    /// stat liste des joueurs sur le terrain le reste ne sert pas
    QDomElement stat=doc.createElement("Stat");
    root.appendChild(stat);
    for(int i=0;i<this->_ListJoueurTer.size();i++)
    {
        QString label=_ListJoueurTer.at(i)->get_Prenom()+"_"+QString::number(_ListJoueurTer.at(i)->get_NumMaillot());
        QDomElement player=doc.createElement(label);
        stat.appendChild(player);
          QDomElement set=doc.createElement("S1");
          player.appendChild(set);
          QDomElement attaque=doc.createElement("Attaque");
          attaque.setAttribute("V++",0);
          attaque.setAttribute("V+",0);
          attaque.setAttribute("V0",0);
          attaque.setAttribute("V-",0);
          attaque.setAttribute("V--",0);
          set.appendChild(attaque);
    }

    QFile file(QString("Current/Match.xml"));
    if (!file.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &file );
    ts << doc.toString();
    file.close();
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
        QDomDocument dom("mon_xml");
         QFile file("Current/Match.xml");
         if (!file.open(QIODevice::ReadWrite))
             return;
         if (!dom.setContent(&file))
         {
             file.close();
             return;
         }
         file.close();
         QDomElement docElem = dom.documentElement();
         QDomNode n = docElem.firstChild();
         while(!n.isNull())
         {
             QDomElement e = n.toElement();
             if(e.tagName()==nom)
             {
                 QDomElement child=e.childNodes();
                 while(!child.isNull())
                 {
                     QDomElement f=child.toElement();
                     if(f.tagName()=="S"+QString::number(1))
                     {
                         QDomElement Gchild=f.childNodes();
                                          while(!Gchild.isNull())
                                          {
                                              QDomElement g=child.toElement();
                                              if(g.tagName()=="Action")
                                              {
                                                  g.setAttribute("V++",player->getStatSet(Action,valu));
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
         if (!file.open(QIODevice::WriteOnly))
             return;
         QTextStream ts( &file );
         ts << doc.toString();
         file.close();
    }
        /*
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

      for(int k=0;k<this->_currrentEquipe->GetListeJoueur ().size ();k++)
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





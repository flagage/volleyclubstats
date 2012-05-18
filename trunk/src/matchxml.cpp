#include "matchxml.h"

MatchXml::MatchXml()
{
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
    Info.setAttribute("Date","0");
    Info.setAttribute ("Heure","0");
    Info.setAttribute("Equipe","0");
    Info.setAttribute ("Type","0");
    Info.setAttribute("Contre","0");
    Info.setAttribute ("Arbitre","0");
    Info.setAttribute ("Duree","temps");
    Info.setAttribute("NbDeSet",0);
    root.appendChild(Info);
    /// position des joueurs
    QDomElement position=doc.createElement("Position");
    root.appendChild(position);
    QDomElement poste1=doc.createElement ("Poste1");
    QString text=doc.createTextNode("0");
    poste1.setNodeValue(text);
    position.appendChild(poste1);

    QDomElement poste2=doc.createElement ("Poste2");
    text=doc.createTextNode("0");
    poste2.setNodeValue(text);
    position.appendChild(poste2);

    QDomElement poste3=doc.createElement ("Poste3");
    text=doc.createTextNode("0");
    poste3.setNodeValue(text);
    position.appendChild(poste3);

    QDomElement poste4=doc.createElement ("Poste4");
    text=doc.createTextNode("0");
    poste4.setNodeValue(text);
    position.appendChild(poste4);

    QDomElement poste5=doc.createElement ("Poste5");
    text=doc.createTextNode("0");
    poste5.setNodeValue(text);
    position.appendChild(poste5);

    QDomElement poste6=doc.createElement ("Poste6");
    text=doc.createTextNode("0");
    poste6.setNodeValue(text);
    position.appendChild(poste6);

    QDomElement poste7=doc.createElement ("Libero");
    text=doc.createTextNode("0");
    poste7.setNodeValue(text);
    position.appendChild(poste7);


    /// score
    QDomElement score=doc.createElement("Score");
    root.appendChild(score);
    QDomElement set1=doc.createElement("S1");
    text=doc.createTextNode("0:0");
    set1.setNodeValue(text);
    score.appendChild(set1);

    /// stat liste des joueurs sur le terrain le reste ne sert pas
    QDomElement stat=doc.createElement("Stat");
    root.appendChild(stat);
    for(int i=0;i<this->_ListJoueurTer.size();i++)
    {
        QString label=_ListJoueurTer.at(i)->get_Prenom()+"_"+_ListJoueurTer.at(i)->get_NumMaillot();
        QDomElement player=doc.createElement(label);
        stat.appendChild(player);
    }

    QFile file(QString("Sauvegarde/"+_nomFichier));
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




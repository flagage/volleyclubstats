class Equipe
!!!140037.cpp!!!	Equipe()

    _Nom="";
    _Categorie="";
    _Division="";
    this->_listAction=InitAction::donneInstance()->GetListAction();
    this->_listValeur=InitValeur::donneInstance()->GetListValeur();
    for(int i=0;i<6;i++)
    {
        this->_VectorStat.append(new statFinal());
    }
!!!140165.cpp!!!	Equipe(in nom : QString)

    _Nom=nom;
!!!140293.cpp!!!	~Equipe()

    for(int i=0;i<_ListeJoueur.size();i++)
    {
        delete (_ListeJoueur.at(i));
    }
    _ListeJoueur.clear();
    for(int i=0;i<6;i++)
    {
        delete _VectorStat[i];
    }

!!!139397.cpp!!!	GetNom() : QString

    return _Nom;
!!!139525.cpp!!!	SetNom(in Nom : QString) : void


    _Nom=Nom;
!!!139653.cpp!!!	GetListeJoueur() : QList<Joueur*>

    return _ListeJoueur;
!!!139781.cpp!!!	AddJoueur(inout joue : Joueur) : void

    for (int i=0;i<_ListeJoueur.size();i++)
    {
        if(_ListeJoueur.at(i)->get_NumMaillot()==joue->get_NumMaillot())
        {
            _ListeJoueur.removeAt(i);
        }
    }
    _ListeJoueur.append(joue);
!!!139909.cpp!!!	supJoueur(inout joue : Joueur) : void

    for(int i=0;i<_ListeJoueur.count();i++)
    {
        if(_ListeJoueur.at(i)->get_NumMaillot()==joue->get_NumMaillot())
        {
            _ListeJoueur.removeAt(i);

            break;
        }
    }

!!!141189.cpp!!!	seachjoueur(in nomJoueur : QString) : Joueur

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
!!!141317.cpp!!!	seachjoueur(in numjoueur : int) : Joueur

    Joueur* player=0;

        for(int i=0;i<_ListeJoueur.size();i++)
        {
            if(_ListeJoueur.at(i)->get_NumMaillot()==numjoueur)
            {
                player=_ListeJoueur.at(i);
                break;
            }
        }
      return player;
!!!140933.cpp!!!	EnregistrerXML(in doc : QDomDocument, in root : QDomElement) : void

    QDomElement Equipe = doc.createElement("Equipe");
    Equipe.setAttribute("Nom",_Nom);
    Equipe.setAttribute("Categorie",_Categorie);
    Equipe.setAttribute("Division",_Division);

    root.appendChild(Equipe);
    for(int i=0;i<_ListeJoueur.count();i++)
    {
        Joueur* player=_ListeJoueur.at(i);
        player->EnregistrerXML(doc,Equipe);
    }


!!!141061.cpp!!!	RestaurerXML(in noeud : QDomNode) : void

    QDomElement Team=noeud.toElement();
    this->_Nom=Team.attribute("Nom");
    _Categorie=Team.attribute("Categorie");
    _Division=Team.attribute("Division");
    QDomNode child = Team.firstChild();
    while(!child.isNull())
    {
        Joueur* Player=new Joueur();
        Player->RestaurerXML(child);
        this->AddJoueur(Player);
        child=child.nextSibling();
    }

!!!142725.cpp!!!	GetStringValeur() : QString

    QString str;
    for(int k=0;k<_listValeur.size()-1;k++)
    {
        str=str+_listValeur.at(k)+"_";
    }
    str=str+_listValeur.at(_listValeur.size()-1);
    return str;
!!!142597.cpp!!!	SetStringValeur(in action : QString) : void

    this->_listValeur=action.split("_");
!!!142853.cpp!!!	GetStringAction() : QString

    QString str;
    for(int k=0;k<_listAction.size()-1;k++)
    {
        str=str+_listAction.at(k)+"_";
    }
    str=str+_listAction.at(_listAction.size()-1);
    return str;
!!!142981.cpp!!!	SetStringAction(in action : QString) : void

    this->_listAction=action.split("_");
!!!142469.cpp!!!	GetnbValeurStat() : int

    return this->_VectorStat[0]->GetNbValeur();
!!!141445.cpp!!!	addStatMatch(in action : int, in pos : int) : void

    _VectorStat[0]->AjoutValeur(action,pos);
!!!143237.cpp!!!	setStatMatch(in action : int, in pos : int, in valeur : double) : void

    this->_VectorStat[0]->SetValeur (action,pos,valeur);
!!!141573.cpp!!!	getStatMatch(in action : int, in pos : int) : double

   return this->_VectorStat[0]->GetValeur(action,pos);
!!!143109.cpp!!!	GetTotalPoint() : int

    return this->_VectorStat[0]->GetTotal();
!!!141701.cpp!!!	addStatSet(in action : int, in pos : int) : void

    this->_VectorStat[Match::donneInstance()->GetCurentSet()]->AjoutValeur(action,pos);
!!!141829.cpp!!!	setStatSet(in action : int, in pos : int, in valeur : double) : void

    this->_VectorStat[Match::donneInstance()->GetCurentSet()]->SetValeur (action,pos,valeur);
!!!141957.cpp!!!	getStatSet(in action : int, in pos : int) : double

    double Dvalue=this->_VectorStat[Match::donneInstance()->GetCurentSet()]->GetValeur(action,pos);
   return  Dvalue;
!!!142085.cpp!!!	initSet() : void


    this->_VectorStat[Match::donneInstance()->GetCurentSet()]->init();

!!!142213.cpp!!!	supStatMatch(in action : int, in pos : int) : void

    this->_VectorStat[0]->SupValeur (action,pos);
!!!142341.cpp!!!	supStatSet(in action : int, in pos : int) : void

    this->_VectorStat[Match::donneInstance()->GetCurentSet()]->SupValeur (action,pos);
!!!143365.cpp!!!	ExportCVS(in fichier : QString) : void


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

            out<<player->get_Age()+";"<<"\n";
        }
        file.close();
}

!!!143493.cpp!!!	ImportCVS(in fichier : QString) : void

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
                stream.readLine();
                first=true;
            }
            else
            {
                if(joueur.at(0)!="")
                {
                Joueur * play=new Joueur();
                play->set_Nom(joueur.at(1));
                play->set_Prenom(joueur.at(2));
                play->set_NumMaillot(joueur.at(3).toInt());
                play->set_poste(joueur.at(4));
                if(joueur.size()>=5)
                play->set_NLisence(joueur.at(5).toInt());
                if(joueur.size()>=6)
                play->set_Addresse(joueur.at(6));
                if(joueur.size()>=7)
                play->set_Tel(joueur.at(7).toInt());
                if(joueur.size()>=8)
                play->set_Email(joueur.at(8));
                if(joueur.size()>=9)
                play->set_Age(joueur.at(9));

                this->AddJoueur(play);
                }


            }
        }
        file.close();
    }
!!!140421.cpp!!!	SetDivision(in div : QString) : void

    _Division=div;
!!!140549.cpp!!!	GetDivision() : QString

    return _Division;

!!!140677.cpp!!!	SetCategorie(in cat : QString) : void

    _Categorie=cat;
!!!140805.cpp!!!	GetCategorie() : QString

    return _Categorie;

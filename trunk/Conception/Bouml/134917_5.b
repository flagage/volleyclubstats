class Joueur
!!!143621.cpp!!!	Joueur()

    _Nom="";
    _Prenom="";
    _Age="";
    _NLisence=0;
    _Tel=0;
    _Email="";
    _Addresse="";
    _poste="";
    _num=0;
    for(int i=0;i<6;i++)
    {
        this->_listStat.append(new statFinal());
    }


!!!143749.cpp!!!	~Joueur()

    for(int i=0;i<6;i++)
    {
        delete _listStat[i] ;
    }
!!!145797.cpp!!!	get_num() : int

    return _num;
!!!145669.cpp!!!	get_Nom() : QString

    return _Nom;
!!!143877.cpp!!!	get_Prenom() : QString

    return _Prenom;
!!!144133.cpp!!!	get_Age() : QString

    return _Age;
!!!144389.cpp!!!	get_NLisence() : int

    return _NLisence;
!!!144773.cpp!!!	get_Tel() : int

    return _Tel;
!!!145029.cpp!!!	get_Email() : QString

    return _Email;
!!!145285.cpp!!!	get_Addresse() : QString

    return _Addresse;
!!!145541.cpp!!!	get_poste() : QString

    return  _poste;
!!!145925.cpp!!!	set_Nom(in nom : QString) : void

    _Nom=nom;
!!!144005.cpp!!!	set_Prenom(in prenon : QString) : void

    _Prenom=prenon;
!!!144261.cpp!!!	set_Age(in age : QString) : void

    _Age=age;
!!!144517.cpp!!!	set_NLisence(in lisence : int) : void

    _NLisence=lisence;
!!!144645.cpp!!!	set_Tel(in tel : int) : void

    this->_Tel=tel;
!!!144901.cpp!!!	set_Email(in email : QString) : void

    this->_Email=email;
!!!145413.cpp!!!	set_poste(in poste : QString) : void

    this->_poste=poste;
!!!145157.cpp!!!	set_Addresse(in add : QString) : void

    this->_Addresse=add;
!!!146053.cpp!!!	set_NumMaillot(in Num : int) : void

    this->_NumMaillot=Num;
!!!146181.cpp!!!	get_NumMaillot() : int

    return this->_NumMaillot;
!!!146309.cpp!!!	EnregistrerXML(in doc : QDomDocument, in Equipe : QDomElement) : void

    QDomElement tag = doc.createElement("joueur");
    tag.setAttribute("Nom",_Nom);
    tag.setAttribute("Prenom",_Prenom);
    tag.setAttribute("Age",_Age);
    tag.setAttribute("Adresse",this->_Addresse);
    tag.setAttribute("Email",this->_Email);
    tag.setAttribute("Tel",this->_Tel);
    tag.setAttribute("License",this->_NLisence);
    tag.setAttribute("poste",this->_poste);
    tag.setAttribute("Maillot",this->_NumMaillot);
    Equipe.appendChild(tag);

!!!146565.cpp!!!	EnregistrerStatXML(in doc : QDomDocument, in Set : QDomElement) : void

    /*QDomElement tag = doc.createElement("joueur");
    tag.setAttribute("Prenom",_Prenom);
    tag.setAttribute("Maillot",this->_NumMaillot);
    Set.appendChild(tag);


    //score par position
    QDomElement tag2=doc.createElement("Attaques");
    tag.appendChild(tag2);
    QDomElement tag3;
    for(int i=0;i<6;i++)
    {
        QString strpos="position";
        QString num;
        num.setNum(i);
        strpos=strpos+num;
        tag3=doc.createElement(strpos);
        tag3.setAttribute("PP",this->GetAction(Atta,VPP,i));
        tag3.setAttribute("P",this->GetAction(Atta,VP,i));
        tag3.setAttribute("o",this->GetAction(Atta,V0,i));
        tag3.setAttribute("M",this->GetAction(Atta,VM,i));
        tag3.setAttribute("MM",this->GetAction(Atta,VMM,i));
        tag2.appendChild(tag3);
    }
    tag2=doc.createElement("Reception");
    tag.appendChild(tag2);
    for(int i=0;i<6;i++)
    {
        QString strpos="position";
        QString num;
        num.setNum(i);
        strpos=strpos+num;
        QDomElement tag3=doc.createElement(strpos);
        tag3.setAttribute("PP",this->GetAction(Recep,VPP,i));
        tag3.setAttribute("P",this->GetAction(Recep,VP,i));
        tag3.setAttribute("o",this->GetAction(Recep,V0,i));
        tag3.setAttribute("M",this->GetAction(Recep,VM,i));
        tag3.setAttribute("MM",this->GetAction(Recep,VMM,i));
        tag2.appendChild(tag3);
    }
    tag2=doc.createElement("Service");
    tag.appendChild(tag2);

    QString strpos="position1";


    tag3=doc.createElement(strpos);
    tag3.setAttribute("PP",this->GetAction(Serv,VPP,1));
    tag3.setAttribute("P",this->GetAction(Serv,VP,1));
    tag3.setAttribute("O",this->GetAction(Serv,V0,1));
    tag3.setAttribute("M",this->GetAction(Serv,VM,1));
    tag3.setAttribute("MM",this->GetAction(Serv,VMM,1));
    tag2.appendChild(tag3);

*/


!!!146437.cpp!!!	RestaurerXML(in noeud : QDomNode) : void

    QDomElement playeur=noeud.toElement();

    _Nom=playeur.attribute("Nom");
    _Prenom=playeur.attribute("Prenom");
    _Age=playeur.attribute("Age");
    _NLisence=playeur.attribute("License").toInt();
    _Tel=playeur.attribute("Tel").toInt();
    _Email=playeur.attribute("Email");
    _Addresse=playeur.attribute("Adresse");
    _poste=playeur.attribute("poste");
    _NumMaillot=playeur.attribute("Maillot").toInt();


!!!146821.cpp!!!	addStatMatch(in action : int, in pos : int) : void

    this->_listStat[0]->AjoutValeur(action,pos);
!!!146949.cpp!!!	setStatMatch(in action : int, in pos : int, in valeur : double) : void

    this->_listStat[0]->SetValeur (action,pos,valeur);
!!!147717.cpp!!!	supStatMatch(in action : int, in pos : int) : void

    this->_listStat[0]->SupValeur (action,pos);
!!!147845.cpp!!!	supStatSet(in action : int, in pos : int) : void

    this->_listStat[Match::donneInstance()->GetCurentSet()]->SupValeur (action,pos);
!!!147077.cpp!!!	getStatMatch(in action : int, in pos : int) : double

    return this->_listStat[0]->GetValeur(action,pos);
!!!147333.cpp!!!	setStatSet(in action : int, in pos : int, in valeur : double) : void

    this->_listStat[Match::donneInstance()->GetCurentSet()]->SetValeur (action,pos,valeur);
!!!147205.cpp!!!	addStatSet(in action : int, in pos : int) : void

    this->_listStat[Match::donneInstance()->GetCurentSet()]->AjoutValeur(action,pos);
!!!147461.cpp!!!	getStatSet(in action : int, in pos : int) : double

   return  this->_listStat[Match::donneInstance()->GetCurentSet()]->GetValeur(action,pos);
!!!147589.cpp!!!	initSet() : void

    this->_listStat[Match::donneInstance()->GetCurentSet()]->init();
!!!147973.cpp!!!	SetPosition(in numpos : int) : void

    this->_Position=numpos;
!!!148101.cpp!!!	GetPosition() : int

    return _Position;

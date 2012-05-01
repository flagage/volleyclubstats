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
#include "Joueur.h"


Joueur::Joueur()
{
    _Nom="";
    _Prenom="";
    _Age=0;
    _NLisence=0;
    _Tel=0;
    _Email="";
    _Addresse="";
    _poste="";
    _num=0;

}

int Joueur::get_num()
{
    return _num;
}

QString Joueur::get_Nom()
{
    return _Nom;
}

QString Joueur::get_Prenom()
{
    return _Prenom;
}
int Joueur::get_Age()
{
    return _Age;
}
int Joueur::get_NLisence()
{
    return _NLisence;
}
int Joueur::get_Tel()
{
    return _Tel;
}
QString Joueur::get_Email()
{
    return _Email;
}

QString Joueur::get_Addresse()
{
    return _Addresse;
}

QString Joueur::get_poste()
{
    return  _poste;
}

void Joueur::set_Nom(QString nom)
{
    _Nom=nom;
}

void Joueur::set_Prenom(QString prenon)
{
    _Prenom=prenon;
}

void Joueur::set_Age(int age)
{
    _Age=age;
}

void Joueur::set_NLisence(int lisence)
{
    _NLisence=lisence;
}

void Joueur::set_Tel(int tel)
{
    this->_Tel=tel;
}

void Joueur::set_Email(QString email)
{
    this->_Email=email;
}

void Joueur::set_poste(QString poste)
{
    this->_poste=poste;
}

void Joueur::set_Addresse(QString add)
{
    this->_Addresse=add;
}

void Joueur::set_NumMaillot(int Num)
{
    this->_NumMaillot=Num;
}
int Joueur::get_NumMaillot()
{
    return this->_NumMaillot;
}
void Joueur::EnregistrerXML(QDomDocument doc,  QDomElement Equipe)
{
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

}
void Joueur::EnregistrerStatXML(QDomDocument doc, QDomElement Set)
{
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


}

void Joueur::RestaurerXML(QDomNode noeud)
{
    QDomElement playeur=noeud.toElement();

    _Nom=playeur.attribute("Nom");
    _Prenom=playeur.attribute("Prenom");
    _Age=playeur.attribute("Age").toInt();
    _NLisence=playeur.attribute("License").toInt();
    _Tel=playeur.attribute("Tel").toInt();
    _Email=playeur.attribute("Email");
    _Addresse=playeur.attribute("Adresse");
    _poste=playeur.attribute("poste");
    _NumMaillot=playeur.attribute("Maillot").toInt();


}
/*
void Joueur::Attaque(int position,StatValeur valeur)
{
    switch (valeur)
    {
    case  VPP:
        this->tabAction[0].AjouterVPP(position);
        break;
    case VP:
        this->tabAction[0].AjouterVP(position);
        break;
    case V0:
        this->tabAction[0].AjouterV0(position);
        break;
    case VM:
        this->tabAction[0].AjouterVM(position);
        break;
    case VMM:
        this->tabAction[0].AjouterVMM(position);
        break;
    }

}
void Joueur::Reception(int position,StatValeur valeur)
{
    switch (valeur)
    {
    case  VPP:
        this->tabAction[1].AjouterVPP(position);
        break;
    case VP:
        this->tabAction[1].AjouterVP(position);
        break;
    case V0:
        this->tabAction[1].AjouterV0(position);
        break;
    case VM:
        this->tabAction[1].AjouterVM(position);
        break;
    case VMM:
        this->tabAction[1].AjouterVMM(position);
        break;
    }

}
void Joueur::Service(int position, StatValeur valeur)
{

    switch (valeur)
    {
    case  VPP:
        this->tabAction[2].AjouterVPP(position);
        break;
    case VP:
        this->tabAction[2].AjouterVP(position);
        break;
    case V0:
        this->tabAction[2].AjouterV0(position);
        break;
    case VM:
        this->tabAction[2].AjouterVM(position);
        break;
    case VMM:
        this->tabAction[2].AjouterVMM(position);
        break;
    }
}
/*int Joueur::GetAction(Action action,StatValeur valeur,int position)
{
    int statretour=0;
    statJoueur stat=this->tabAction[action];
    switch (valeur)
    {
    case  VPP:
        statretour = stat.GetVPP(position);
        break;
    case VP:
        statretour = stat.GetVP(position);
        break;
    case V0:
        statretour = stat.GetV0(position);
        break;
    case VM:
        statretour = stat.GetVM(position);
        break;
    case VMM:
        statretour = stat.GetVMM(position);
        break;
    }
    return statretour;
}*/

void Joueur::addStatMatch(int action,int pos)
{
    this->statMatch.AjoutValeur(action,pos);
}
void Joueur::setStatMatch(int action,int pos,double valeur)
{
    this->statMatch.SetValeur (action,pos,valeur);
}

void Joueur::supStatMatch(int action,int pos)
{
    this->statMatch.SupValeur (action,pos);
}

void Joueur::supStatSet(int action,int pos)
{
    this->statSet.SupValeur (action,pos);
}


double Joueur::getStatMatch(int action,int pos)
{
    return this->statMatch.GetValeur(action,pos);
}

void Joueur::setStatSet(int action,int pos,double valeur)
{
    this->statSet.SetValeur (action,pos,valeur);
}

void Joueur::addStatSet(int action,int pos)
{
    this->statSet.AjoutValeur(action,pos);
}

double Joueur::getStatSet(int action,int pos)
{
   return  this->statSet.GetValeur(action,pos);
}

void Joueur::initSet()
{
    this->statSet.init();
}

void Joueur::SetListAction(QStringList list)
{
    this->statMatch.SetListAction(list);
    this->statSet.SetListAction(list);
}

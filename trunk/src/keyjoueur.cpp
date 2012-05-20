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

#include "keyjoueur.h"
#include "fbjoueur.h"
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>

KeyJoueur::KeyJoueur(QWidget *parent,int nbjoueur,bool libero) :
        QWidget(parent)
{
    _nbJoueur=nbjoueur;
    _Islibero=libero;
    _parent=parent;
    _pos=0;
    int compte=0;
    for(int i=0;i<_nbJoueur;i++)
    {
        QString strPosition="Position"+QString::number (i+1);
        buttons[i]=new BouttonJoueur(strPosition,this);

        connect(buttons[i],SIGNAL(lclicked()),this,SLOT(bouttonLClicked()));
        connect(buttons[i],SIGNAL(rclicked()),this,SLOT(bouttonRClicked()));


    }
     buttons[_nbJoueur]=new BouttonJoueur(tr("Adv"),this);

    _labelPosition=new QLabel();
    QFont police("calibri");
    police.setPointSize (20);
_labelPosition->setStyleSheet("color:gray; font-size: 30px;");


    for  (int i=0;i<_nbJoueur;i++)
    {


        buttons[i]->setStyleSheet ("color: black;");

    }
    createLayout(this->_pos);


}


void KeyJoueur::bouttonLClicked()
{
    QPushButton *button=(QPushButton*) sender();
    emit Changement (button);
}

void KeyJoueur::bouttonRClicked()
{
    QPushButton *button=(QPushButton*) sender();
    emit ModifPoste (button);
}

void KeyJoueur::createLayout(int pos)
{
    _pos=pos;
   int colonne=pos+1;
    if(colonne==3)
    {
        colonne=2;
    }
    int nbJoueutTerrain;
    QLayout* layout=_parent->layout ();
    if(layout!=0)
    {
        delete layout;
    }
    _layout=new QGridLayout(this);
    _layout->setSpacing(6);
    _layout->addWidget(_labelPosition, 0,4);
    //_layout->addWidget(_labelPosition,2,5);
    _layout->addWidget(buttons[_nbJoueur],0,colonne,1,3);
   QGridLayout* gridLayout = new QGridLayout();
    gridLayout->setSpacing(6);
    switch(pos)
    {
        case 0:

       // buttons[0]->adjustSize();
        gridLayout->addWidget (buttons[0],2,4);

        //buttons[1]->adjustSize();
        gridLayout->addWidget (buttons[1],2,0);


      //  buttons[2]->adjustSize();
        gridLayout->addWidget (buttons[2],6,0);


       // buttons[3]->adjustSize();
        gridLayout->addWidget (buttons[3],12,0);


       // buttons[4]->adjustSize();
        gridLayout->addWidget (buttons[4],12,4);


//        buttons[5]->adjustSize();
        gridLayout->addWidget (buttons[5],6,4);

        if (_Islibero==true)
        {
          //  buttons[6]->adjustSize();
            gridLayout->addWidget (buttons[6],6,2);

        }
        break;

    case 1:




        gridLayout->addWidget (buttons[3],2,0);


        gridLayout->addWidget (buttons[2],2,2);


        gridLayout->addWidget (buttons[1],2,4);


        gridLayout->addWidget (buttons[4],12,0);


        gridLayout->addWidget (buttons[5],12,2);


        gridLayout->addWidget (buttons[0],12,4);

        if (_Islibero==true)
        {
            gridLayout->addWidget (buttons[6],6,2);

        }

        break;

        case 2:



        gridLayout->addWidget (buttons[4],2,0);


        gridLayout->addWidget (buttons[3],2,4);


        gridLayout->addWidget (buttons[5],6,0);


        gridLayout->addWidget (buttons[2],6,4);


        gridLayout->addWidget (buttons[0],12,0);


        gridLayout->addWidget (buttons[1],12,4);



        if (_Islibero==true)
        {
            gridLayout->addWidget (buttons[6],6,2);

        }
        break;
        case 3:
        gridLayout->addWidget (buttons[0],2,0);


        gridLayout->addWidget (buttons[5],2,2);


        gridLayout->addWidget (buttons[4],2,4);


        gridLayout->addWidget (buttons[1],12,0);


        gridLayout->addWidget (buttons[2],12,2);


        gridLayout->addWidget (buttons[3],12,4);

        if (_Islibero==true)
        {
            gridLayout->addWidget (buttons[6],6,2);

        }
        break;

    }


_layout->addLayout(gridLayout, 1, colonne,1,3);
    if(_Islibero==true)
    {
        buttons[6]->setStyleSheet ("color: black; background-color: cyan; border-style: outset;border-width: 2px; border-color: beige;");


        nbJoueutTerrain=7;
    }
    else
    {
        nbJoueutTerrain=6;
    }

    QGridLayout* gridLayout2 = new QGridLayout();
     gridLayout2->setSpacing(6);
    for(int i=nbJoueutTerrain;i<this->_nbJoueur;i++)
    {
        gridLayout2->addWidget(buttons[i],0,i-nbJoueutTerrain,1,1);
    }
_layout->addLayout(gridLayout2, 3, colonne,1,3);

    _parent->setLayout(_layout);


}
void KeyJoueur::InitLineEditSize()
{


}
void KeyJoueur::Start()
{


    createLayout(this->_pos);

}

void KeyJoueur::InitListJoueur(QList <Joueur*> joueur)
{
    this->_listjoueur=joueur;



    createLayout(this->_pos);

}

void KeyJoueur::Initialisation()
{
    bool ok;




}

QString KeyJoueur::GetServeur()
{
    return buttons[0]->text();
}
QString KeyJoueur::ChercherPasseur()
{
    for(int i=0;i<6;i++)
    {
        if (buttons[i]->text ().contains ("*"))
        {
         return    buttons[i]->text ();
        }
    }
    return "";
}

QString KeyJoueur::ChercherJoueur(int &currentposition)
{

     currentposition=0;
    /// Initialisation
    for(int i=0;i<6;i++)
    {
        buttons[i]->setStyleSheet("color: black; background-color: grey; border-style: outset;border-width: 2px; border-color: beige;");
        buttons[i]->adjustSize();
    }
    /// Recherche du passeur
    for(int i=0;i<6;i++)
    {
        if (buttons[i]->text ().contains ("*"))
        {
            buttons[i]->setStyleSheet("color: black; background-color: magenta;  border-style: outset;border-width: 2px; border-color: beige;");
            buttons[i]->adjustSize();
            currentposition=i;
        }
        if(buttons[i]->text ().contains ("$"))
        {
            buttons[i]->setStyleSheet("color: black; background-color: cyan;  border-style: outset;border-width: 2px; border-color: beige;");
            buttons[i]->adjustSize();
        }
        if(_Islibero==true)
        {
            buttons[6]->setStyleSheet("color: black; background-color: cyan; border-style: outset;border-width: 2px; border-color: beige;");
            buttons[6]->adjustSize();

        }

    }
    switch(currentposition)
    {
    case 0:
        _labelPosition->setText("P1");
        return "P1";
        break;
    case 1:
        _labelPosition->setText("P2");
        return "P2";
        break;
    case 2:
        _labelPosition->setText("P3");
        return "P3";
        break;
    case 3:
        _labelPosition->setText("P4");
        return "P4";
        break;
    case 4:
        _labelPosition->setText("P5");
        return "P5";
        break;
    case 5:
        _labelPosition->setText("P6");
        return "P6";
        break;
    default:
        return "Pas de Passeur";
        break;
    }
    currentposition++;


}

void KeyJoueur::Rotation(int &joueur)
{
    QString post1=buttons[0]->text();
    buttons[0]->setText(buttons[1]->text());
    buttons[1]->setText(buttons[2]->text());
    buttons[2]->setText(buttons[3]->text());
    buttons[3]->setText(buttons[4]->text());
    buttons[4]->setText(buttons[5]->text());
    buttons[5]->setText(post1);

    this->ChercherJoueur(joueur);
}
void KeyJoueur::RotationM(int &joueur)
{

    QString post1=buttons[0]->text();
    buttons[0]->setText(buttons[5]->text());
    buttons[5]->setText(buttons[4]->text());
    buttons[4]->setText(buttons[3]->text());
    buttons[3]->setText(buttons[2]->text());
    buttons[2]->setText(buttons[1]->text());
    buttons[1]->setText(post1);
    this->ChercherJoueur(joueur);
}

Joueur* KeyJoueur::RechercheJoueur(int numero)
{
    for(int i=0;i<_listjoueur.size();i++)
    {
        if(numero==_listjoueur.at(i)->get_NumMaillot())
        {
            return _listjoueur.at(i);
            break;
        }
    }
}

void KeyJoueur::Stat()
{
    QString strtext;
    QStringList listtext;
    QStringList listStr;
    int numero;
    Joueur* player;
    QString valeur;
    /// position 1
    strtext =buttons[0]->text();
    listtext=strtext.split("\n");
    strtext=listtext.at(0);
    listStr=strtext.split("(");
    numero=listStr.at(0).toInt();

    player=RechercheJoueur(numero);

    if(player!=0)
    {
    valeur.setNum(player->getStatMatch(0,6),'g',4);
    strtext=strtext+"\n S("+valeur+"%)";
    valeur.setNum(player->getStatMatch(1,6),'g',4);
    strtext=strtext+"\n R("+valeur+"%)";
    buttons[0]->setText(strtext);
    }

    /// position 2
    strtext =buttons[1]->text();
    listtext=strtext.split("\n");
    strtext=listtext.at(0);
    listStr=strtext.split("(");
    numero=listStr.at(0).toInt();
    player=RechercheJoueur(numero);
    if(player!=0)
    {
    valeur.setNum(player->getStatMatch(2,6),'g',4);
    strtext=strtext+"\n A("+valeur+"%)";
    buttons[1]->setText(strtext);
    }

    /// position 3
    strtext =buttons[2]->text();
    listtext=strtext.split("\n");
    strtext=listtext.at(0);
    listStr=strtext.split("(");
    numero=listStr.at(0).toInt();
    if(player!=0)
    {
    player=RechercheJoueur(numero);
    valeur.setNum(player->getStatMatch(2,6),'g',4);
    strtext=strtext+"\n A("+valeur+"%)";
    buttons[2]->setText(strtext);
    }

    /// position 4
    strtext =buttons[3]->text();
    listtext=strtext.split("\n");
    strtext=listtext.at(0);
    listStr=strtext.split("(");
    numero=listStr.at(0).toInt();
    player=RechercheJoueur(numero);
    if(player!=0)
    {
    valeur.setNum(player->getStatMatch(2,6),'g',4);
    strtext=strtext+"\n A("+valeur+"%)";
    buttons[3]->setText(strtext);
    }

    /// position 5
    strtext =buttons[4]->text();
    listtext=strtext.split("\n");
    strtext=listtext.at(0);
    listStr=strtext.split("(");
    numero=listStr.at(0).toInt();
    player=RechercheJoueur(numero);
    if(player!=0)
    {
    valeur.setNum(player->getStatMatch(1,6),'g',4);
    strtext=strtext+"\n R("+valeur+"%)";
    buttons[4]->setText(strtext);
    }

    /// position 6
    strtext =buttons[5]->text();
    listtext=strtext.split("\n");
    strtext=listtext.at(0);
    listStr=strtext.split("(");
    numero=listStr.at(0).toInt();
    player=RechercheJoueur(numero);
    if(player!=0)
    {
    valeur.setNum(player->getStatMatch(1,6),'g',4);
    strtext=strtext+"\n R("+valeur+"%)";
    buttons[5]->setText(strtext);
    }

    /// libero
    strtext =buttons[6]->text();
    listtext=strtext.split("\n");
    strtext=listtext.at(0);
    listStr=strtext.split("(");
    numero=listStr.at(0).toInt();
    player=RechercheJoueur(numero);
    if(player!=0)
    {
    valeur.setNum(player->getStatMatch(1,6),'g',4);
    strtext=strtext+"\n R("+valeur+"%)";
    buttons[6]->setText(strtext);
    }

this->createLayout(this->_pos);
}

QString KeyJoueur::UpdateJoueur(Joueur* player)
{
    QString text="";

        QString strposte=player->get_poste();
        if(strposte==tr("Passeur"))
        {
           text=text.setNum(player->get_NumMaillot());
           text=text+" ("+player->get_Prenom()+")*";
        }
        else if(strposte==tr("Libero"))
        {

            text=text.setNum(player->get_NumMaillot());
            text=text+" ("+player->get_Prenom()+")$";
        }


    return text;

}

bool KeyJoueur::SetLineEdit (QDropEvent *e)
{
    bool bretour=false;
    QPoint PosFenetre=this->_parent->pos ();

    for(int i=0;i<this->_nbJoueur;i++)
    {
        int posx=line[i]->pos ().x ()+PosFenetre.x ();
        int posy=line[i]->pos ().y ()+PosFenetre.y ();
        int ex=e->pos ().x ();
        int ey=e->pos ().y ();
        if(((ex > posx) && (ex<(posx+50)))
            && ((ey> posy) && (ey<(posy+50)))
            && line[i]->isReadOnly()==true)
            {
            QString strText=e->mimeData ()->text ();
            line[i]->setText (strText);
            line[i]->setReadOnly(false);
            line[i]->setEnabled(false);
            line[i]->adjustSize();
            bretour=true;

            break;
        }
    }
     createLayout(this->_pos);
    //InitLineEditSize();
    return bretour;

}



void KeyJoueur::SetAdv(QString nom)
{
    this->buttons[this->_nbJoueur]->setText(nom);
}


QList<Joueur *> KeyJoueur::GetJoueurTerrain()
{
    QList<Joueur *> list;
    int tot=InitGlobal::donneInstance()->GetNbJoueur();
    for(int i=0;i<tot;i++)
    {
        QString strtext =buttons[i]->text();
        QStringList listtext=strtext.split("\n");
        strtext=listtext.at(0);
        QStringList listStr=strtext.split("(");
        int numero=listStr.at(0).toInt();

        Joueur* player=RechercheJoueur(numero);
        if(player!=0)
        {
            list.append(player);
        }
    }
    return list;
}

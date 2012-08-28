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
    _nbjoueurEnPlace=0;

    for(int i=0;i<_nbJoueur;i++)
    {
         QString strPosition;
        if(i==3)
        {
           strPosition="Position"+QString::number (1);
        }
        else if(i==5)
        {
             strPosition="Position"+QString::number (5);
        }
        else if(i==6)
        {
            strPosition="Position"+QString::number (7);
        }
        else
        {
         strPosition="Position"+QString::number (i+2);
        }
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

void KeyJoueur::bouttonRClicked()
{
    QPushButton *button=(QPushButton*)sender();
    emit JoueurStat(button);
}

void KeyJoueur::bouttonLClicked()
{
    QPushButton *button=(QPushButton*) sender();
    emit Changement (button);
    _nbjoueurEnPlace++;
    bool isenplace=false;
    int nbjoueuraplacer=Match::donneInstance()->GetParametreMatch()->get_NbJoueur();
    if(Match::donneInstance()->GetParametreMatch()->AvecLibero()==true)
    {
        nbjoueuraplacer++;
    }

    if(_nbjoueurEnPlace>nbjoueuraplacer)
    {
        QList<Joueur *> list_terrain=this->GetJoueurTerrain();
        for(int i=0;i<this->_listjoueur.size();i++)
        {
             QString text=_listjoueur.at(i)->get_Prenom()+"_"+QString::number(_listjoueur.at(i)->get_NumMaillot());
            isenplace=false;
            for(int k=0;k<list_terrain.size();k++)
            {
                 QString text2=list_terrain.at(k)->get_Prenom()+"_"+QString::number(list_terrain.at(k)->get_NumMaillot());
                 if(text==text2)
                 {
                     isenplace=true;
                     break;
                 }
            }

        }
        emit Tlm_en_place();
    }
}


void KeyJoueur::createLayout(int pos)
{
     QLayout* layout=_parent->layout ();
    if(layout!=0)
    {
        delete layout;
    }
    _layout=new QGridLayout(this);

   QGridLayout* gridLayout_7 = _layout;
   gridLayout_7->setSpacing(6);
   gridLayout_7->setContentsMargins(11, 11, 11, 11);
   gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
  QGridLayout* gridLayout_6 = new QGridLayout();
   gridLayout_6->setSpacing(6);
   gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
  QGridLayout* gridLayout_4 = new QGridLayout();
   gridLayout_4->setSpacing(6);
   gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
  QSpacerItem *  verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

   gridLayout_4->addItem(verticalSpacer_8, 0, 0, 1, 1);

   buttons[6]->setObjectName(QString::fromUtf8("pushButton_7"));

   gridLayout_4->addWidget(buttons[6], 3, 0, 1, 1);

  QSpacerItem *  verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

   gridLayout_4->addItem(verticalSpacer_7, 2, 0, 1, 1);

 QGridLayout*  gridLayout_3 = new QGridLayout();
   gridLayout_3->setSpacing(6);
   gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
 QGridLayout*  gridLayout_2 = new QGridLayout();
   gridLayout_2->setSpacing(6);
   gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

   buttons[4] ->setObjectName(QString::fromUtf8("pushButton_5"));

   gridLayout_2->addWidget(buttons[4] , 3, 0, 1, 1);

  QSpacerItem* verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

   gridLayout_2->addItem(verticalSpacer_3, 4, 0, 1, 1);


    buttons[5]->setObjectName(QString::fromUtf8("pushButton_6"));

   gridLayout_2->addWidget( buttons[5], 5, 0, 1, 1);

  QSpacerItem *  verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

   gridLayout_2->addItem(verticalSpacer_4, 2, 0, 1, 1);


    buttons[3]->setObjectName(QString::fromUtf8("pushButton_4"));

   gridLayout_2->addWidget( buttons[3], 1, 0, 1, 1);

  QSpacerItem *  verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

   gridLayout_2->addItem(verticalSpacer_6, 0, 0, 1, 1);


   gridLayout_3->addLayout(gridLayout_2, 0, 2, 1, 1);

  QGridLayout* gridLayout = new QGridLayout();
   gridLayout->setSpacing(6);
   gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
  QSpacerItem *  verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

   gridLayout->addItem(verticalSpacer_5, 0, 0, 1, 1);

    buttons[2]->setObjectName(QString::fromUtf8("pushButton_3"));

   gridLayout->addWidget( buttons[2], 6, 0, 1, 1);


    buttons[0]->setObjectName(QString::fromUtf8("pushButton"));

   gridLayout->addWidget( buttons[0], 1, 0, 1, 1);


    buttons[1]->setObjectName(QString::fromUtf8("pushButton_2"));

   gridLayout->addWidget( buttons[1], 4, 0, 1, 1);

  QSpacerItem *  verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

   gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

  QSpacerItem *  verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

   gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);


   gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

 QSpacerItem *   horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

   gridLayout_3->addItem(horizontalSpacer_2, 0, 1, 1, 1);

 QSpacerItem *  horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

   gridLayout_3->addItem(horizontalSpacer_3, 0, 3, 1, 1);


   gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);


   gridLayout_6->addLayout(gridLayout_4, 0, 1, 1, 1);

  QGridLayout* gridLayout_5 = new QGridLayout();
   gridLayout_5->setSpacing(6);
   gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
  QSpacerItem *  horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

   gridLayout_5->addItem(horizontalSpacer_4, 0, 0, 1, 1);

    buttons[7]->setObjectName(QString::fromUtf8("pushButton_8"));

   gridLayout_5->addWidget( buttons[7], 0, 1, 1, 1);

   QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

   gridLayout_5->addItem(horizontalSpacer, 0, 2, 1, 1);


   gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);


   gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);


    _parent->setLayout(gridLayout_7);


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
    return buttons[3]->text();
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
    QString post1=buttons[3]->text();
    buttons[3]->setText(buttons[0]->text());
    buttons[0]->setText(buttons[1]->text());
    buttons[1]->setText(buttons[2]->text());
    buttons[2]->setText(buttons[5]->text());
    buttons[5]->setText(buttons[4]->text());
    buttons[4]->setText(post1);
    this->ChercherJoueur(joueur);
    this->UpdatePosition();
}
void KeyJoueur::RotationM(int &joueur)
{

    QString post1=buttons[0]->text();
    buttons[0]->setText(buttons[3]->text());
    buttons[3]->setText(buttons[4]->text());
    buttons[4]->setText(buttons[5]->text());
    buttons[5]->setText(buttons[2]->text());
    buttons[2]->setText(buttons[1]->text());
    buttons[1]->setText(post1);
    this->ChercherJoueur(joueur);
    this->UpdatePosition();
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
    strtext =buttons[3]->text();
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
    buttons[3]->setText(strtext);
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
    player=RechercheJoueur(numero);
    if(player!=0)
    {
    valeur.setNum(player->getStatMatch(2,6),'g',4);
    strtext=strtext+"\n A("+valeur+"%)";
    buttons[2]->setText(strtext);
    }

    /// position 4
    strtext =buttons[0]->text();
    listtext=strtext.split("\n");
    strtext=listtext.at(0);
    listStr=strtext.split("(");
    numero=listStr.at(0).toInt();
    player=RechercheJoueur(numero);
    if(player!=0)
    {
    valeur.setNum(player->getStatMatch(2,6),'g',4);
    strtext=strtext+"\n A("+valeur+"%)";
    buttons[0]->setText(strtext);
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
        else
        {
            text=text.setNum(player->get_NumMaillot());
            text=text+" ("+player->get_Prenom()+")";
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
    //int tot=InitGlobal::donneInstance()->GetNbJoueur()+1;
    int tot=Match::donneInstance()->GetParametreMatch()->get_NbJoueur();
    if(Match::donneInstance()->GetParametreMatch()->AvecLibero()==true)
    {
        tot++;
    }
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

             if(i==3)
            {
                player->SetPosition(1);
            }

            else if(i==5)
            {
                player->SetPosition(5);
            }
            else if(i==6)
            {
                player->SetPosition(7);
            }
            else
            {
                player->SetPosition(i+2);
            }
            list.append(player);
        }
    }
    return list;
}


void KeyJoueur::Reinitialisation()
{

    for(int i=0;i<_nbJoueur;i++)
    {
        QString strPosition="Position"+QString::number (i+1);
        buttons[i]->setText(strPosition);
    }
    _nbjoueurEnPlace=0;

}

void KeyJoueur::UpdatePosition()
{
    int tot=Match::donneInstance()->GetParametreMatch()->get_NbJoueur();
    if(Match::donneInstance()->GetParametreMatch()->AvecLibero()==true)
    {
        tot++;
    }
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

             if(i==3)
            {
                player->SetPosition(1);
            }

            else if(i==5)
            {
                player->SetPosition(5);
            }
            else if(i==6)
            {
                player->SetPosition(7);
            }
            else
            {
                player->SetPosition(i+2);
            }
    }
    }
}
void KeyJoueur::Placement(QList<Joueur *> joueur)
{
    for(int i=0;i<joueur.size();i++)
    {
        int pos=joueur.at(i)->GetPosition();
        QString text=joueur.at(i)->get_Prenom()+"_"+QString::number(joueur.at(i)->get_NumMaillot());
        switch (pos)
        {
        case 1:
            buttons[3]->setText(this->UpdateJoueur(joueur.at(i)));
            break;
        case 2:
            buttons[0]->setText(this->UpdateJoueur(joueur.at(i)));
            break;
        case 3:
            buttons[1]->setText(this->UpdateJoueur(joueur.at(i)));
            break;
        case 4:
            buttons[2]->setText(this->UpdateJoueur(joueur.at(i)));
            break;
        case 5:
            buttons[5]->setText(this->UpdateJoueur(joueur.at(i)));
            break;
        case 6:
            buttons[4]->setText(this->UpdateJoueur(joueur.at(i)));
            break;
        case 7:
            buttons[6]->setText(this->UpdateJoueur(joueur.at(i)));
            break;
        }

    }
    _listjoueur=Match::donneInstance()->GetListJoueur();
    //this->ChercherJoueur(0);
}

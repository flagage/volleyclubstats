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

#include "widgettabeff.h"
#include "ui_widgettabeff.h"
#include "ecran.h"

WidgetTabEff::WidgetTabEff(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::WidgetTabEff)
{
    ui->setupUi(this);
    if(parent->layout() != 0)
        parent->layout()->addWidget(this);
}

WidgetTabEff::~WidgetTabEff()
{
    delete ui;
}

void WidgetTabEff::Ouvrir()
{

    this->show ();
}
void WidgetTabEff::clean()
{
    delete _tabElts;
}

void WidgetTabEff::Init(Equipe* team)
{

    _listJoueur=team->GetListeJoueur ();
    _listaction=InitAction::donneInstance()->GetListAction();
    _tabElts=new TableEff(ui->groupBox,_listJoueur,_listaction);
}

void WidgetTabEff::SlotMiseAJour()
{
    for(int k=0;k<_listJoueur.size();k++)
    {
        Joueur * player=_listJoueur.at(k);
        for(int i=0;i<_listaction.size();i++)
        {
            QTableWidgetItem *item=_tabElts->item(k+1,i+1);
            double valeur=player->getStatMatch(i,6);
            QString strValeur;
            strValeur.setNum(valeur,'g',4);
            if(item!=0)
            {
                item->setText(strValeur);
            }
        }
    }
}


TableEff::TableEff(QWidget * parent,QList <Joueur*> listJoueur,QStringList Listaction)
    :  QTableWidget(parent)
{
    this->setColumnCount (Listaction.size()+1);
    this->setRowCount (listJoueur.size()+1);
    //this->setSpan (0,1,0,5);


    //this->setHorizontalHeaderItem(0,new QTableWidgetItem(QString( "Attaque" ) ));
    // this->hideRow (0);
    this->horizontalHeader ()->hide();
    this->verticalHeader ()->hide();
    /*QTableWidgetItem * item=new QTableWidgetItem(QString( "Attaque"));
    item->setTextAlignment (Qt::AlignCenter);*/
    this->setItem (0,0,new QTableWidgetItem(QString( "Joueur")));
    /*this->setItem (2,0,new QTableWidgetItem(QString( "Match")));
    }*/
    /// On remplit la premiere ligne
    for(int i=0;i<Listaction.size();i++)
    {
        this->setItem (0,i+1,new QTableWidgetItem(QString(Listaction.at(i))));
    }
    /// On remplit la premiere colonne
    for(int k=0;k<listJoueur.size();k++)
    {
        this->setItem(k+1,0,new QTableWidgetItem(QString(listJoueur.at(k)->get_Prenom())));
    }

    /// On remplit le reste

    for(int k=0;k<listJoueur.size();k++)
    {
        Joueur * player=listJoueur.at(k);
        for(int i=0;i<Listaction.size();i++)
        {
            double valeur=player->getStatMatch(i,6);
            QString strValeur;
            strValeur.setNum(valeur);
            this->setItem(k+1,i+1,new QTableWidgetItem(QString(strValeur)));
        }
    }


    if(parent->layout() != 0)
        parent->layout()->addWidget(this);


    this->resizeColumnsToContents();
    this->resizeRowsToContents();

}




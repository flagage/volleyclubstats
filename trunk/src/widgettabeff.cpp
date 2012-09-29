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

#include "widgettabeff.h"
#include "ui_widgettabeff.h"
#include "ecran.h"
#include "fenetrejoueurstat.h"

WidgetTabEff::WidgetTabEff(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::WidgetTabEff)
{
    ui->setupUi(this);
    if(parent->layout() != 0)
        parent->layout()->addWidget(this);


    _tabElts=0;
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
    if(_tabElts!=0)
    delete _tabElts;
}

void WidgetTabEff::Init(  QList <Joueur*> listjoueur,QStringList listaction)
{

    _listJoueur=listjoueur;
    _listaction=listaction;
    _tabElts=new TableEff(ui->groupBox,_listJoueur,_listaction);
}

void WidgetTabEff::SlotMiseAJour(bool isSet,int numSet)
{
     _tabElts->setSortingEnabled(false);
    for(int k=0;k<_listJoueur.size();k++)
    {

        QTableWidgetItem *item=_tabElts->item(k,1);
        Joueur * player=PlayerfromNum(item->text());

        for(int i=0;i<_listaction.size();i++)
        {
            ///Total
            item=_tabElts->item(k,(i*2)+2);
            double valeur;
            if(isSet==false)
                valeur=player->getStatMatch(i,5);
            else
                valeur=player->getStatSet(i,5,numSet);
            QString strValeur;
            strValeur.setNum(valeur,'g',4);
            if(item!=0)
            {
                item->setText(strValeur);
            }
            ///Efficacite
            QTableWidgetItem *itemEff=_tabElts->item(k,(i*2)+3);
            double valeurEff;
            if(isSet==false)
                valeurEff=player->getStatMatch(i,6);
            else
                valeurEff=player->getStatSet(i,6,numSet);
            QString strValeurEff;
            strValeurEff.setNum(valeurEff,'g',4);
            if(itemEff!=0)
            {
                itemEff->setText(strValeurEff);
            }

        }
    }
    _tabElts->setSortingEnabled(true);
}


Joueur* WidgetTabEff::PlayerfromNum(QString num)
{
    for(int k=0;k<_listJoueur.size();k++)
    {

        if(num.toInt()==_listJoueur.at(k)->get_NumMaillot())
        {
            return _listJoueur.at(k);
        }
    }
}

TableEff::TableEff(QWidget * parent,QList <Joueur*> listJoueur,QStringList Listaction)
    :  QTableWidget(parent)
{
    this->setColumnCount (Listaction.size()*2+2);
    this->setRowCount (listJoueur.size());
    _list=listJoueur;

    this->horizontalHeader ();
    this->verticalHeader ()->hide();

    this->setSortingEnabled(true);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);

    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->setHorizontalHeaderItem(0,new QTableWidgetItem(QString( "Joueur")));
     this->setHorizontalHeaderItem (1,new QTableWidgetItem(QString( "Num")));

    /// On remplit la premiere ligne
    for(int i=0;i<Listaction.size();i++)
    {
        QString strAction=Listaction.at(i).left(3)+" tot";
        QString strEff=Listaction.at(i).left(3)+" Eff";
        this->setHorizontalHeaderItem ((i*2)+2,new QTableWidgetItem(strAction));
        this->setHorizontalHeaderItem((i*2)+3,new QTableWidgetItem(strEff));
    }
    /// On remplit la premiere colonne
    for(int k=0;k<listJoueur.size();k++)
    {
        this->setItem(k,0,new QTableWidgetItem(QString(listJoueur.at(k)->get_Prenom())));
        this->item(k,0)->setBackground(QColor(167,167,167));
        QString numero=QString::number(listJoueur.at(k)->get_NumMaillot());
        if(numero.size()==1)
            numero="0"+numero;
         this->setItem(k,1,new QTableWidgetItem(numero));
         this->item(k,1)->setBackground(QColor(167,167,167));
    }

    /// On remplit le reste

    for(int k=0;k<listJoueur.size();k++)
    {
        Joueur * player=listJoueur.at(k);
        for(int i=0;i<Listaction.size();i++)
        {
            QColor ColorAction;
            switch (i)
            {
            case 0:
                ColorAction=QColor(255,153,153);
                break;
            case 1:
                ColorAction= QColor(64,224,208);
                break;
            case 2:
                ColorAction=QColor(153,255,153);
                break;
            case 3:
                ColorAction=QColor(204,204,255);
                break;
            case 4:
                ColorAction=QColor(255,102,255);
                break;
            case 5:
                ColorAction=QColor(238,203,173);
                break;

            default:
                ColorAction=QColor(Qt::white);
                break;

            }

            double valeureff=player->getStatMatch(i,6);
            double valeurtot=player->getStatMatch(i,5);
            QString strValeureff;
            strValeureff.setNum(valeureff);
            QString strValeurtot;
            strValeurtot.setNum(valeurtot);
            this->setItem(k,(i*2)+2,new QTableWidgetItem(QString(strValeurtot)));
            this->item(k,(i*2)+2)->setBackgroundColor(ColorAction);
            this->setItem(k,(i*2)+3,new QTableWidgetItem(QString(strValeureff)));
            this->item(k,(i*2)+3)->setBackgroundColor(ColorAction);
        }
    }


    if(parent->layout() != 0)
        parent->layout()->addWidget(this);

    connect(this,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SlotDDClick(int,int)));
    this->resizeColumnsToContents();
    this->resizeRowsToContents();

}

void TableEff::SlotDDClick(int row,int col)
{

    for(int i=0;i<_list.size();i++)
    {

        if (_list.at(i)->get_Prenom()==this->item(row,0)->text())
        {

            FenetreJoueurStat* fstat=new FenetreJoueurStat(_list.at(i),0,this);
            fstat->show();


        }
    }
}




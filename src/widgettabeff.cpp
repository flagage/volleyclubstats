/**
Copyright Frederic volleyclubstats ,2011
fred@volleyclubstats.com

This file is part of volleyclubstats.

volleyclubstats is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

volleyclubstats is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Volleyclubstats.  If not, see <http://www.gnu.org/licenses/>.
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




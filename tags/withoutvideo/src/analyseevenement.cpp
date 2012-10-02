/**
Copyright Frederic volleyclubstats ,2011
fred@volleyclubstats.com

This file is part of volleyclubstats.

volleyclubstats is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Volleyclubstats.  If not, see <http://www.gnu.org/licenses/>.
**/
#include "analyseevenement.h"
#include "ui_analyseevenement.h"

AnalyseEvenement::AnalyseEvenement(QStringList listjoueur,QStringList listEvent, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalyseEvenement)
{
    ui->setupUi(this);
    QStringList listAction;
    QStringList listValeur;
    QStringList listPosition;
    QStringList listPlayer;
    listAction<<"Tous"<<"Att"<<"Con"<<"Rec"<<"Def"<<"Pas"<<"Ser";
    listValeur<<"Tous"<<"++"<<"+"<<"0"<<"-"<<"--";
    listPosition<<"Tous"<<"P1"<<"P2"<<"P3"<<"P4"<<"P5"<<"P6";
    listPlayer<<"Tous"<<listjoueur;
    ui->cBoxActions->addItems(listAction);
    ui->cBoxPositions->addItems(listPosition);
    ui->cBoxValeur->addItems(listValeur);
    ui->cBoxJoueur->addItems(listPlayer);
    _listevent=listEvent;
    _compteur=0;
    this->setWindowTitle("FiltreAction");
    Connection();
    Initialisation();

}
void AnalyseEvenement::Connection()
{
    connect(ui->cBoxActions,SIGNAL(currentIndexChanged(QString)),this,SLOT(changement()));
    connect(ui->cBoxJoueur,SIGNAL(currentIndexChanged(QString)),this,SLOT(changement()));
    connect(ui->cBoxPositions,SIGNAL(currentIndexChanged(QString)),this,SLOT(changement()));
    connect(ui->cBoxValeur,SIGNAL(currentIndexChanged(QString)),this,SLOT(changement()));

}

void AnalyseEvenement::Initialisation()
{
    QStringList listTitre;
    listTitre<<tr("Numero")<<tr("joueurs")<<tr("Action")<<tr("Valeur")<<tr("Positions");
    ui->tableWidget->setRowCount(_listevent.size());
    ui->tableWidget->setColumnCount(listTitre.size());
    ui->tableWidget->setHorizontalHeaderLabels(listTitre);
    ui->tableWidget->verticalHeader()->hide();


    for(int i=0;i<_listevent.size();i++)
    {
        QStringList splitlist=_listevent.at(i).split(" ");
        if(splitlist.size()>=4)
        {
            if(splitlist.at(1)!="00" && splitlist.at(1)!="99")
            {
            ui->tableWidget->setItem(_compteur,0,new QTableWidgetItem(QString::number(_compteur)));
            ui->tableWidget->setItem(_compteur,1,new QTableWidgetItem(splitlist.at(1)));
            ui->tableWidget->setItem(_compteur,2,new QTableWidgetItem(splitlist.at(2)));
            ui->tableWidget->setItem(_compteur,3,new QTableWidgetItem(splitlist.at(3)));
            ui->tableWidget->setItem(_compteur,4,new QTableWidgetItem(splitlist.at(4)));
            _compteur++;
            }
        }

    }
    ui->tableWidget->setRowCount(_compteur);
    ui->label_nb->setText(QString::number(_compteur));
    ui->tableWidget->show();

}


void AnalyseEvenement::changement()
{
    int nbselection=0;
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        QString joueur=ui->tableWidget->item(i,1)->text();
        QString Position=ui->tableWidget->item(i,4)->text();
        QString Action=ui->tableWidget->item(i,2)->text();
        QString Valeur=ui->tableWidget->item(i,3)->text();
        if((ui->cBoxActions->currentText()=="Tous" || ui->cBoxActions->currentText()==Action) &&
                (ui->cBoxJoueur->currentText()=="Tous" || ui->cBoxJoueur->currentText()==joueur) &&
                (ui->cBoxPositions->currentText()=="Tous" || ui->cBoxPositions->currentText()==Position) &&
                (ui->cBoxValeur->currentText()=="Tous" || ui->cBoxValeur->currentText()==Valeur)
                )
        {
            ui->tableWidget->showRow(i);
            nbselection++;
        }
        else
        {
            ui->tableWidget->hideRow(i);
        }

    }
    ui->label_nb->setText(QString::number(nbselection));

}

AnalyseEvenement::~AnalyseEvenement()
{
    delete ui;
}

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

#include "fenetreposition.h"
#include "ui_fenetreposition.h"
#include "match.h"
#include <QtGui>
#include <QList>
FenetrePosition::FenetrePosition(Ecran* ecran,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetrePosition)
{
    ui->setupUi(this);
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    connect(ui->pushButton_ok,SIGNAL(clicked()),this,SLOT(ok()));
    connect(ui->pushButton_Annuler,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(changement(int,int)));
    _ecran=ecran;
    Initialiser();
}

FenetrePosition::~FenetrePosition()
{
    delete ui;
}

void FenetrePosition::Initialiser()
{
    QStringList listColumn;
  listColumn<<"Position"<<"Joueur";
  ui->tableWidget->setColumnCount(listColumn.size());
 ui->tableWidget->setHorizontalHeaderLabels(listColumn);
  Equipe* team=Match::donneInstance()->getTeam();
  QStringList*  listjoueur=new QStringList();

    QList<Joueur*> LJoueur=team->GetListeJoueur();
    ui->tableWidget->setRowCount(LJoueur.count());
    for(int i=0;i<LJoueur.count();i++)
    {
        QString strjoueur;
        strjoueur.setNum(LJoueur.at(i)->get_NumMaillot());
        listjoueur->append(strjoueur);

     }
    for(int i=0;i<LJoueur.count();i++)
    {

         QComboBox*  box=new QComboBox();
        for(int k=0;k<listjoueur->size();k++)
        {
            box->addItem(listjoueur->at(k));
        }
        if((i)<6)
        {
        QLabel * qlab;
        QString num;
        num=num.setNum(i+1);
        qlab=new QLabel(num,this);
        ui->tableWidget->setCellWidget(i,0,qlab);
        ui->tableWidget->setCellWidget(i,1,box);
        }
        else
        {
            QLabel * qlab;
            qlab=new QLabel("banc",this);
            ui->tableWidget->setCellWidget(i,0,qlab);
             ui->tableWidget->setCellWidget(i,1,box);
        }


    }
}

void FenetrePosition::ok()
{
    //_ecran->ui;
    QStringList * position=new QStringList();

    for(int k=0;k<ui->tableWidget->rowCount();k++)
    {
    QComboBox*  box =(QComboBox*)ui->tableWidget->cellWidget ( k, 1 );
            position->append(box->currentText());
    }
    //_ecran->setPosition(position);
    accept();
}
void FenetrePosition::changement(int row,int col)
{

}

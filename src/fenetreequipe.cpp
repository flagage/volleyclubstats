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

#include "fenetreequipe.h"
#include "ui_fenetreequipe.h"
#include "fbjoueur.h"
#include "Equipe.h"
#include "fenetrevisualisation.h"

Fenetreequipe::Fenetreequipe(Ecran* ecran,QWidget *parent,bool supp) :
        QDialog(parent),
        ui(new Ui::Fenetreequipe)
{
    ui->setupUi(this);
    _ecran=ecran;
     Connexion();
    _listColumn<<tr("Numero")<<tr("Nom")<<tr("Prenom")<<tr("Poste")<<tr("License");
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));

    InitListEquipe();

}
void Fenetreequipe::Connexion()
{
    connect(ui->ButtonAjouter,SIGNAL(clicked()),this,SLOT(Ajouter()));
    connect(ui->ButtonAnnuler,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->SuppresionBox,SIGNAL(currentIndexChanged(int)),this,SLOT(ListChange()));
    connect(ui->ButtonModifier,SIGNAL(clicked()),this,SLOT(Modifier()));
    connect(ui->ButtonSupprimer,SIGNAL(clicked()),this,SLOT(Supprimer()));
    connect(ui->ButtonEquipe,SIGNAL(clicked()),this,SLOT(GestionEquipe()));

}

Fenetreequipe::~Fenetreequipe()
{
    delete ui;
}
void Fenetreequipe::ListChange()
{

    RaffraichirList();

}

void Fenetreequipe::RemplitTableauJoueur(Joueur* player,int row)
{



    //delete qlab;
    QString strnum;
    strnum=strnum.setNum(player->get_NumMaillot());
    if(strnum.size()==1)
    {
        strnum="0"+strnum;
    }
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString(strnum)));//"Numero"

 ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString(player->get_Nom())));//"Nom"
     ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString(player->get_Prenom()))); //Premon
    // delete qlab;
    ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString(player->get_poste())));


    //delete qlab;
    QString strLisence;
    strLisence=strLisence.setNum(player->get_NLisence());

    ui->tableWidget->setItem(row,4,new QTableWidgetItem(QString(strLisence)));//"License";
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);


}

void Fenetreequipe::Enregistrer()
{


    this->accept();
}


void Fenetreequipe::InitListEquipe()
{
    ui->SuppresionBox->clear();
    QList<Equipe*> LEquipe=_ecran->GetListeEquipe();
    for(int i=0;i<LEquipe.count();i++)
    {
        Equipe* Team=LEquipe.at(i);
        ui->SuppresionBox->addItem(Team->GetNom());
    }
    if(LEquipe.size()!=0)
        _currentTeam=LEquipe.at(0);
    else
        _currentTeam=0;

RaffraichirList();
}

void Fenetreequipe::Ajouter()
{
    if(_currentTeam!=0)
    {
        if(QDialog* joueur=new fbjoueur(_currentTeam,0,this));
                 RaffraichirList();
    }
    else
    {
        QMessageBox::warning (this,tr("erreur"),tr("Verifiez que l'équipe est bien selectionnée"));
    }

}

void Fenetreequipe::Modifier()
{


    QTableWidgetItem *item=ui->tableWidget->item(ui->tableWidget->currentRow(),0);
    if(item!=0)
    {
        QString text=item->text();
        QList<Joueur*> LJoueur=_currentTeam->GetListeJoueur();
        for(int i=0;i<LJoueur.count();i++)
        {
            if(text.toInt()==LJoueur.at(i)->get_NumMaillot())
            {
                if(fbjoueur* joueur=new fbjoueur(_currentTeam,LJoueur.at(i),this));

                break;
            }

        }
        RaffraichirList();
    }
    else
    {
        QMessageBox::warning (this,tr("erreur"),tr("Verifiez que le joueur est bien selectionné"));
    }
}

void Fenetreequipe::Supprimer()
{

    QTableWidgetItem *item=ui->tableWidget->item(ui->tableWidget->currentRow(),0);
    if(item!=0)
    {
        QString text=item->text();
        QList<Joueur*> LJoueur=_currentTeam->GetListeJoueur();


        for(int i=0;i<LJoueur.count();i++)
        {
            if(text.toInt()==LJoueur.at(i)->get_NumMaillot())
            {
                _currentTeam->supJoueur(LJoueur.at(i));
                break;
            }
        }
        RaffraichirList();
    }
    else
    {
        QMessageBox::warning (this,tr("erreur"),tr("Verifiez que le joueur est bien selectionné"));
    }
}

void Fenetreequipe::RaffraichirList()
{

    ui->tableWidget->clear();
    ui->tableWidget->setSortingEnabled(false);
    QList<Equipe*> LEquipe=_ecran->GetListeEquipe();
    Equipe* Team;
    for(int i=0;i<LEquipe.count();i++)
    {
        Team=LEquipe.at(i);
        if(Team->GetNom()==(ui->SuppresionBox->currentText()))
        {
            _currentTeam=Team;
            break;
        }

    }
    if(_currentTeam!=0)
    {
        ui->lineEdit_2->setText(_currentTeam->GetDivision());
        ui->lineEdit->setText(_currentTeam->GetCategorie());
        QList<Joueur*> LJoueur=_currentTeam->GetListeJoueur();
        ui->tableWidget->setColumnCount(_listColumn.size());
        ui->tableWidget->setHorizontalHeaderLabels(_listColumn);
        ui->tableWidget->setRowCount(LJoueur.count());
        for(int i=0;i<LJoueur.count();i++)
        {
            RemplitTableauJoueur(LJoueur.at(i),i);
        }

    }
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->sortItems(0,Qt::AscendingOrder);
}

void Fenetreequipe::GestionEquipe()
{
    FenetreVisualisation* visualisation=new FenetreVisualisation(_ecran->GetListeEquipe(),0,this);
    if(visualisation->exec());
    {
        _ecran->SetListeEquipe(visualisation->GetlistEquipe());
        ui->SuppresionBox->clear();
        InitListEquipe();
    }
}


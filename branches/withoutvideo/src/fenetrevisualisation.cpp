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

#include "fenetrevisualisation.h"
#include "ui_fenetrevisualisation.h"
#include "QMessageBox"

FenetreVisualisation::FenetreVisualisation(QList <Equipe*> listEquipe,int act,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreVisualisation)
{
    ui->setupUi(this);
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
     _listEquipe=listEquipe;
     _whataction=act;
     connect(ui->pushAjouter,SIGNAL(clicked()),this,SLOT(Valider()));
     connect(ui->pushButton_Annuler,SIGNAL(clicked()),this,SLOT(close()));
     connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(changement(int)));
     connect(ui->comboBox_2,SIGNAL(currentIndexChanged(QString)),this,SLOT(Slot_InitCatDiv(QString)));

    Initialisation();
}
void FenetreVisualisation::Initialisation()
{
     ui->comboBox->clear();
    for(int i=0;i<_listEquipe.count();i++)
    {
           ui->comboBox->addItem(_listEquipe.at(i)->GetNom());
           ui->comboBox_2->addItem(_listEquipe.at(i)->GetNom());
    }
    if(_whataction==1)
    {
       ui->tab->setVisible(false);
       ui->tab->setEnabled(true);
       ui->tabWidget->setCurrentIndex(2);
       ui->tab_2->setVisible(true);
       ui->tabWidget->setTabText(2,"Exporter");
       ui->pushButton_Annuler->setVisible(false);

       ui->pushAjouter->setVisible(false);
       ui->tabWidget->setTabEnabled(0,false);
       ui->tabWidget->setTabEnabled(1,false);

        ui->pushAjouter->setVisible(true);
        ui->pushAjouter->setText("exporter");
    }
    else if(_whataction==2)
    {
        ui->pushButton_Annuler->setVisible(false);

        ui->tabWidget->setTabEnabled(1,false);
        ui->tabWidget->setTabEnabled(2,false);
    }

}

FenetreVisualisation::~FenetreVisualisation()
{
    delete ui;
}
void FenetreVisualisation::Valider()
{
    if(ui->tabWidget->currentIndex()==0)
    {
        this->Ajouter();
    }
    else if(ui->tabWidget->currentIndex()==1)
    {
        this->Modifier();

    }
    else
    {
        this->Supprimer();
    }

}

void FenetreVisualisation::changement(int i)
{
    switch (i)
    {
    case 0:
        ui->pushAjouter->setText("Ajouter");
        break;
    case 1:
        ui->pushAjouter->setText("Modifier");
        break;
    case 2:
        ui->pushAjouter->setText("Suprimer");
        break;
    default:
        break;
    }

}
void FenetreVisualisation::Slot_InitCatDiv(QString team)
{

    for(int i=0;i<_listEquipe.size ();i++)
    {
        if(_listEquipe.at (i)->GetNom ()==team)
        {
            ui->lineEdit_4->setText(_listEquipe.at (i)->GetDivision());
            ui->lineEdit_cat_2->setText(_listEquipe.at (i)->GetCategorie());
        }
    }
}

void FenetreVisualisation::Ajouter()
{


        for(int i=0;i<_listEquipe.size ();i++)
        {
            if(_listEquipe.at (i)->GetNom ()==ui->lineEdit->text())
            {
                QMessageBox::warning (this,tr("Attention"),tr("Equipe déjà presente"));
                return ;
            }
        }

        Equipe * Team=new Equipe(ui->lineEdit->text());
        Team->SetDivision(ui->lineEdit_4->text());
        Team->SetCategorie(ui->lineEdit_cat->text());

        _listEquipe.append(Team);

        ui->lineEdit->setText("");
        if (_whataction==2)
        {
            this->_CurrentTeam=Team;
            this->accept();
        }
        else
        {
            Initialisation();
        }

}

void FenetreVisualisation::Modifier()
{
    for(int i=0;i<_listEquipe.size ();i++)
    {
        if(_listEquipe.at (i)->GetNom ()==ui->comboBox_2->currentText())
        {
            _listEquipe.at (i)->SetCategorie(ui->lineEdit_cat_2->text());
            _listEquipe.at (i)->SetDivision(ui->lineEdit_4->text());

        }
    }
    this->accept();
}

void FenetreVisualisation::Supprimer()
{
   // QList <Equipe*> ListEquipe=_ecran->GetListeEquipe();
    if(_whataction==0)
    {
    for(int i=0;i<_listEquipe.count();i++)
    {
        if(_listEquipe.at(i)->GetNom()==ui->comboBox->currentText())
        {
            _listEquipe.removeAt(i);
            break;
        }
    }
    ui->comboBox->clear();
    Initialisation();
    }
    else
    {
        bool isvalide=false;

        for(int i=0;i<_listEquipe.count();i++)
        {
            if(_listEquipe.at(i)->GetNom()==ui->comboBox->currentText())
            {
                _CurrentTeam= _listEquipe.at(i);
                isvalide=true;
                break;
            }
        }
        if(isvalide)
        {
            this->accept();
        }
        else
        {
            this->reject();
        }
    }
}

QList <Equipe*> FenetreVisualisation::GetlistEquipe()
{
    return this->_listEquipe;
}

Equipe * FenetreVisualisation::GetSelectedTeam()
{
    return _CurrentTeam;
}

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
       ui->tabWidget->setCurrentIndex(1);
       ui->tab_2->setVisible(true);
       ui->tabWidget->setTabText(1,"Exporter");
       ui->pushButton_Annuler->setVisible(false);
       ui->pushAjouter->setVisible(false);
       ui->tabWidget->setTabEnabled(0,false);
       ui->tabWidget->setTabEnabled(1,false);
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

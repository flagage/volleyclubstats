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
    connect(ui->ButtonAjouter,SIGNAL(clicked()),this,SLOT(Ajouter()));
    connect(ui->ButtonAnnuler,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->SuppresionBox,SIGNAL(currentIndexChanged(int)),this,SLOT(ListChange()));
    connect(ui->ButtonModifier,SIGNAL(clicked()),this,SLOT(Modifier()));
    connect(ui->ButtonSupprimer,SIGNAL(clicked()),this,SLOT(Supprimer()));
    connect(ui->ButtonEquipe,SIGNAL(clicked()),this,SLOT(GestionEquipe()));
    _listColumn<<tr("Numero")<<tr("Nom")<<tr("Prenom")<<tr("Poste")<<tr("License");
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));

    InitListEquipe();

}

Fenetreequipe::~Fenetreequipe()
{
    delete ui;
}
void Fenetreequipe::ListChange()
{
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



}

void Fenetreequipe::Enregistrer()
{


    this->accept();
}


void Fenetreequipe::InitListEquipe()
{
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
        QDialog* joueur=new fbjoueur(_currentTeam,this);
        if(joueur->exec())
            RaffraichirList();
    }
    else
    {
        QMessageBox::warning (this,tr("erreur"),tr("Verifier que l'équipe est bien selectionné"));
    }

}

void Fenetreequipe::Modifier()
{

    //QLabel * qlab=(QLabel*)(ui->tableWidget(ui->tableWidget->currentRow(),1));
    QTableWidgetItem *item=ui->tableWidget->item(ui->tableWidget->currentRow(),0);
    if(item!=0)
    {
        QString text=item->text();
        QList<Joueur*> LJoueur=_currentTeam->GetListeJoueur();
        for(int i=0;i<LJoueur.count();i++)
        {
            if(text.toInt()==LJoueur.at(i)->get_NumMaillot())
            {
                fbjoueur* joueur=new fbjoueur(_currentTeam,this);
                joueur->Modif(LJoueur.at(i));
                break;
            }

        }
        RaffraichirList();
    }
    else
    {
        QMessageBox::warning (this,tr("erreur"),tr("Verifier que le joueur est bien selectionné"));
    }
}

void Fenetreequipe::Supprimer()
{
    //QLabel * qlab=(QLabel*)(ui->tableWidget->cellWidget(ui->tableWidget->currentRow(),1));
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
        QMessageBox::warning (this,tr("erreur"),tr("Verifier que le joueur est bien selectionné"));
    }
}

void Fenetreequipe::RaffraichirList()
{

    ui->tableWidget->clear();
    ui->tableWidget->setSortingEnabled(false);
    if(_currentTeam!=0)
    {
    QList<Joueur*> LJoueur=_currentTeam->GetListeJoueur();
    ui->tableWidget->setColumnCount(_listColumn.size());
    ui->tableWidget->setHorizontalHeaderLabels(_listColumn);
    ui->tableWidget->setRowCount(LJoueur.count());
    for(int i=0;i<LJoueur.count();i++)
    {
        RemplitTableauJoueur(LJoueur.at(i),i);
    }
    //ui->tableWidget->setSortingEnabled();
    }
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->sortItems(0,Qt::AscendingOrder);
}

void Fenetreequipe::GestionEquipe()
{
    QDialog* visualisation=new FenetreVisualisation(_ecran,this);
    visualisation->exec();
    ui->SuppresionBox->clear();
    InitListEquipe();
}


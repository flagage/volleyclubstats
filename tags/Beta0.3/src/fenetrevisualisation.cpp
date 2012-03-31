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
#include "fenetrevisualisation.h"
#include "ui_fenetrevisualisation.h"
#include "QMessageBox"

FenetreVisualisation::FenetreVisualisation(Ecran *ecran,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreVisualisation)
{
    ui->setupUi(this);
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
     _ecran=ecran;
     connect(ui->pushAjouter,SIGNAL(clicked()),this,SLOT(Ajouter()));
     connect(ui->pushButton_Supprimer,SIGNAL(clicked()),this,SLOT(Supprimer()));
     connect(ui->pushButton_Annuler,SIGNAL(clicked()),this,SLOT(close()));

    Initialisation();
}
void FenetreVisualisation::Initialisation()
{
     ui->comboBox->clear();
QList <Equipe*> ListEquipe=_ecran->GetListeEquipe();
    for(int i=0;i<ListEquipe.count();i++)
    {
           ui->comboBox->addItem(ListEquipe.at(i)->GetNom());
    }

}

FenetreVisualisation::~FenetreVisualisation()
{
    delete ui;
}
void FenetreVisualisation::Ajouter()
{

    for(int i=0;i<_ecran->GetListeEquipe ().size ();i++)
    {
        if(_ecran->GetListeEquipe ().at (i)->GetNom ()==ui->lineEdit->text())
        {
            QMessageBox::warning (this,tr("Attention"),tr("Equipe d�j� presente"));
            return ;
        }
    }

    Equipe * Team=new Equipe(ui->lineEdit->text());
    _ecran->AddEquipe(Team);
    ui->lineEdit->setText("");
    Initialisation();

}
void FenetreVisualisation::Supprimer()
{
    QList <Equipe*> ListEquipe=_ecran->GetListeEquipe();
    for(int i=0;i<ListEquipe.count();i++)
    {
        if(ListEquipe.at(i)->GetNom()==ui->comboBox->currentText())
        {
            _ecran->SupEquipe(ListEquipe.at(i));
            break;
        }
    }
    ui->comboBox->clear();
    Initialisation();
}

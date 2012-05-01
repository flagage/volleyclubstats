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
#include "fenetrelancement.h"
#include "ui_fenetrelancement.h"
#include "QMessageBox"
#include "match.h"
#include "volleyInit.h"

FenetreLancement::FenetreLancement(Ecran* ecran,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreLancement)
{
    ui->setupUi(this);
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));

    _ecran=ecran;
    connect(ui->pushButton_ok,SIGNAL(clicked()),this,SLOT(ok()));
    connect(ui->pushButton_annuler,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->checkBox_10,SIGNAL(clicked(bool)),this,SLOT(Slot_perso(bool)));
    Initialisation();
}

FenetreLancement::~FenetreLancement()
{
    delete ui;
}

void FenetreLancement::Initialisation()
{
    ui->checkBox->setChecked(true);
    ui->checkBox_2->setChecked(true);
    ui->checkBox_3->setChecked(true);
    ui->checkBox_7->setChecked(true);
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->spinBox_4->setValue(0);
    ui->spinBox_5->setValue(0);
    ui->radioButton->setChecked (true);
    ui->radioButton_3->setChecked (true);
    ui->radioButton_4->setCheckable (false);

    QList<Equipe*> LEquipe=_ecran->GetListeEquipe();
    for(int i=0;i<LEquipe.count();i++)
    {
        Equipe* Team=LEquipe.at(i);
        ui->comboBox->addItem(Team->GetNom());
    }
    ui->comboBox->adjustSize();
    QStringList listType;
    listType<<tr("Championnat")<<tr("Coupe")<<tr("Amical")<<tr("Entrainement");
    ui->comboBox_2->addItems(listType);
}

void FenetreLancement::ok()
{
    QList<Equipe*> LEquipe=_ecran->GetListeEquipe();
    Equipe* Team;

    if(ui->comboBox->currentText()!="")
    {
    for(int i=0;i<LEquipe.count();i++)
    {
        Team=LEquipe.at(i);
        if(Team->GetNom()==(ui->comboBox->currentText()))
        {
            Match::donneInstance()->setCurrentEquipe(Team);
            break;
        }

    }
    Match::donneInstance()->setAdvers(ui->lineEdit->text());
    ///Initialise l'arbitre
    Match::donneInstance()->setArbitre(ui->lineEditArbitre->text());
    Match::donneInstance()->SetType(ui->comboBox_2->currentText());
    ///list des actions a prendre en compte
    QStringList actionSelection;
    actionSelection<<tr("Service")<<tr("R�c�ption");
    if(ui->checkBox_4->isChecked())
        actionSelection <<tr("Contre");
    if(ui->checkBox_5->isChecked())
        actionSelection <<tr("D�fense");
    if(ui->checkBox_6->isChecked())
        actionSelection <<tr("Passe");

     actionSelection<<tr("Attaque");
    this->_ecran->InitialisationAction(actionSelection);

    QStringList ValeurSelection;

    if(ui->checkBox_7->isChecked())
        ValeurSelection<<tr("eff1");
    if(ui->checkBox_8->isChecked())
        ValeurSelection<<tr("eff2");
    if(ui->checkBox_9->isChecked())
        ValeurSelection<<tr("eff3");
    if(ui->checkBox_10->isChecked())
    {
        ValeurSelection<<tr("eff4");
        QString valeur,valeur1,valeur2,valeur3,valeur4;
        valeur.setNum(ui->spinBox->value());
        ValeurSelection<<"(";
        QString strvalue=valeur+";"+valeur1.setNum(ui->spinBox_2->value())+";"+valeur2.setNum(ui->spinBox_3->value())+";"
                       +valeur3.setNum(ui->spinBox_4->value())+";"+valeur4.setNum(ui->spinBox_5->value());
        ValeurSelection<<strvalue;
    }


    InitValeur::donneInstance()->SetSelection(ValeurSelection);
    //this->_ecran->InitialisationValeur(ValeurSelection);

    if(ui->radioButton_2->isChecked ())
    {
        _ecran->SetTactile (true);
    }
    accept();
    }
    else
    {
        QMessageBox::warning (this,tr("Erreur de saisi"),tr("Verrifier que le nom de l'equipe est bien renseign�"));
    }

}

void FenetreLancement::Slot_perso(bool checked)
{
    if(checked==true)
    {
        ui->spinBox->setEnabled(true);
        ui->spinBox_2->setEnabled(true);
        ui->spinBox_3->setEnabled(true);
        ui->spinBox_4->setEnabled(true);
        ui->spinBox_5->setEnabled(true);
    }
    else
    {
        ui->spinBox->setEnabled(false);
        ui->spinBox_2->setEnabled(false);
        ui->spinBox_3->setEnabled(false);
        ui->spinBox_4->setEnabled(false);
        ui->spinBox_5->setEnabled(false);
    }

}

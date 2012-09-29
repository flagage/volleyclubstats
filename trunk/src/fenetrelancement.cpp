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

FenetreLancement::FenetreLancement(QList<Equipe*> ListEquipe,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreLancement)
{
    ui->setupUi(this);
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    connect(ui->pushButton_ok,SIGNAL(clicked()),this,SLOT(ok()));
    connect(ui->pushButton_annuler,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->checkBox_10,SIGNAL(clicked(bool)),this,SLOT(Slot_perso(bool)));
    connect(ui->checkBox_4,SIGNAL(stateChanged(int)),this,SLOT(Slot_Check4(int)));
    connect(ui->checkBox_5,SIGNAL(stateChanged(int)),this,SLOT(Slot_Check5(int)));
    connect(ui->checkBox_6,SIGNAL(stateChanged(int)),this,SLOT(Slot_Check6(int)));
    _ListEquipe=ListEquipe;
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


    for(int i=0;i<_ListEquipe.count();i++)
    {
        Equipe* Team=_ListEquipe.at(i);
        ui->comboBox->addItem(Team->GetNom());
    }
    ui->comboBox->adjustSize();
    QStringList listType;
    listType<<tr("Championnat")<<tr("Coupe")<<tr("Amical")<<tr("Entrainement");
    ui->comboBox_2->addItems(listType);
}

void FenetreLancement::ok()
{

ParametreMatch * param=Match::donneInstance()->GetParametreMatch();
if(ui->comboBox->currentText()!="" && ui->lineEdit->text()!="")
    {
        param->set_NomEquipeLocal(ui->comboBox->currentText());


    param->set_NomEquipeVisiteur(ui->lineEdit->text());

    ///Initialise l'arbitre
    param->set_NomArbitre1(ui->lineEditArbitre->text());
    param->set_NomArbitre2(ui->lineEditArbitre_2->text());
    param->set_TypeDeMatch(ui->comboBox_2->currentText());
    ///list des actions a prendre en compte
    QStringList actionSelection;

    if(ui->checkBox->isChecked())
    {
        actionSelection<<tr("Service");
    }
    if(ui->checkBox_2->isChecked())
    {
          actionSelection<<tr("Reception");
    }
    if(ui->checkBox_3->isChecked())
    {
           actionSelection<<tr("Attaque");
    }
    if(ui->checkBox_4->isChecked())
        actionSelection <<tr("Contre");
    if(ui->checkBox_5->isChecked())
        actionSelection <<tr("Defense");
    if(ui->checkBox_6->isChecked())
        actionSelection <<tr("Passe");
    if(ui->checkBox_18->isChecked())
        actionSelection <<tr("Relance");


    param->set_Action(actionSelection);

    ///List des action de defilmenent
    QStringList actionDefilement;

    if(ui->checkBox_16->isChecked())
        actionDefilement<<tr("Service");
    if(ui->checkBox_15->isChecked())
          actionDefilement<<tr("Reception");
    if(ui->checkBox_12->isChecked())
           actionDefilement<<tr("Attaque");
    if(ui->checkBox_14->isChecked())
        actionDefilement <<tr("Contre");
    if(ui->checkBox_13->isChecked())
        actionDefilement <<tr("Defense");
    if(ui->checkBox_17->isChecked())
        actionSelection <<tr("Passe");


    param->set_ActionDefile(actionDefilement);

    QStringList ValeurSelection;
    ValeurSelection<<"PP"<<"P"<<"Z"<<"M"<<"MM"<<"tot";
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



    param->set_Valeur(ValeurSelection);
    //this->_ecran->InitialisationValeur(ValeurSelection);

    param->SetLibero(ui->checkBox_11->isChecked());
    param->set_NbJoueur(ui->spinBox_8->value());
    param->set_NbSet(ui->spinBox_6->value());
    param->set_ScoreMax(ui->spinBox_7->value());


    /// ajout de l'equipe
    for(int i=0;i<_ListEquipe.count();i++)
    {
        Equipe* Team=_ListEquipe.at(i);
        if(ui->comboBox->currentText()==Team->GetNom())
        {
        Match::donneInstance()->setCurrentEquipe(Team);
        break;
        }
    }
    Match::donneInstance()->setAdvers(ui->lineEdit->text());
    Match::donneInstance()->GetScore()->set_ScLocal(ui->spinBox_9->value());
    Match::donneInstance()->GetScore()->set_ScVisiteur(ui->spinBox_10->value());
    if(Match::donneInstance()->getTeam()->GetListeJoueur().size()<Match::donneInstance()->GetParametreMatch()->get_NbJoueur())
    {
        QMessageBox::warning (this,tr("Erreur pas assez de joueur"),tr("Verrifier l'equipe selectionner contient assez de joueur"));
        return;
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

void FenetreLancement::Slot_Check4(int state)
{
    if(state==2)
    {
        ui->checkBox_14->setEnabled(true);
    }
    else
    {
        ui->checkBox_14->setEnabled(false);
    }
}


void FenetreLancement::Slot_Check5(int state)
{
    if(state==2)
    {
        ui->checkBox_13->setEnabled(true);
    }
    else
    {
        ui->checkBox_13->setEnabled(false);
    }
}

void FenetreLancement::Slot_Check6(int state)
{
    if(state==2)
    {
        ui->checkBox_17->setEnabled(true);
    }
    else
    {
        ui->checkBox_17->setEnabled(false);
    }
}

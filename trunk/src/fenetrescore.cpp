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
#include "fenetrescore.h"
#include "ui_fenetrescore.h"
#include "QMessageBox"

FenetreScore::FenetreScore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreScore)
{
    _currentMatch=Match::donneInstance();
    ui->setupUi(this);
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(parent,SIGNAL(ScorePlus(int)),this,SLOT(Slot_Scoreplus()));
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(slot_changeScore(int)));
    connect(ui->spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(slot_changeScore(int)));
    ui->widgetScore->setStyleSheet ("background-color: blue");
    ui->spinBox->setStyleSheet (" font: bold 124px;background-color:beige; border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;padding: 6px;b");
    ui->spinBox_2->setStyleSheet (" font: bold 124px;background-color:beige; border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;padding: 6px;b");
    ui->spinBox_3->setStyleSheet (" font: bold 64px;background-color:beige; border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;padding: 6px;b");
    ui->spinBox_4->setStyleSheet (" font: bold 64px;background-color:beige; border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;padding: 6px;b");

    //this->setStyleSheet ("QSpinBox {    width: 13px; height: 13px; font: bold 24px;background-color:beige; border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;min-width: 10em;padding: 6px;}");
    InitialiseIHMFromData();
}
void FenetreScore::InitialiseIHMFromData()

{

    if(_currentMatch->GetScore()!=0)
    {

        ui->label_2->setText(_currentMatch->GetParametreMatch()->get_NomEquipeLocal());
        ui->label_3->setText(_currentMatch->GetParametreMatch()->get_NomEquipeVisiteur());
        ui->spinBox->setValue(_currentMatch->GetScore()->get_ScLocal());
        ui->spinBox_2->setValue(_currentMatch->GetScore()->get_ScVisiteur());
        ui->spinBox_4->setValue(_currentMatch->GetScore()->get_SetLocal());
        ui->spinBox_3->setValue(_currentMatch->GetScore()->get_SetVisiteur());

    }

}
void FenetreScore::InitialiseDataFromIHM()
{
    _currentMatch->GetScore()->set_SetLocal(ui->spinBox->value());
    _currentMatch->GetScore()->set_ScVisiteur(ui->spinBox_2->value());
    _currentMatch->GetScore()->set_SetLocal(ui->spinBox_4->value());
    _currentMatch->GetScore()->set_SetVisiteur(ui->spinBox_3->value());
}

void FenetreScore::Slot_Scoreplus()
{
    this->InitialiseIHMFromData();

}

FenetreScore::~FenetreScore()
{
    delete ui;

}

void FenetreScore::slot_changeScore(int )
{
    _currentMatch->GetScore()->set_ScLocal(ui->spinBox->value());
    _currentMatch->GetScore()->set_ScVisiteur(ui->spinBox_2->value());
}


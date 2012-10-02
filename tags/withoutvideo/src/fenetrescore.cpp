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


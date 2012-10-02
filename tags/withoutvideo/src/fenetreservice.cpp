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

#include "fenetreservice.h"
#include "ui_fenetreservice.h"

FenetreService::FenetreService(QString team1,QString team2,bool tMort,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreService)
{
    ui->setupUi(this);
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    ui->radioButton->setText(team1);
    ui->radioButton_2->setText(team2);
    this->setWindowTitle ("Service");
    if(tMort==true)
    {
        ui->groupBox->setTitle ("Temps mort à");
        this->setWindowTitle ("Temps mort");
    }
}

FenetreService::~FenetreService()
{
    delete ui;
}
bool FenetreService::isUS()
{
    if (ui->radioButton->isChecked())
    {

        return true;
    }
    else
    {
        return false;
    }
}

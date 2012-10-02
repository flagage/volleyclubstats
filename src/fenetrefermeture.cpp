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

#include "fenetrefermeture.h"
#include "ui_fenetrefermeture.h"

FenetreFermeture::FenetreFermeture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreFermeture)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_Sauvegarde()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT (slot_Plustard()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(slot_Supprimer()));

    //ui->pushButton->setBackgroundRole(QColor(165,167,165));
}

FenetreFermeture::~FenetreFermeture()
{
    delete ui;
}
void FenetreFermeture::slot_Sauvegarde()
{
    QFile file("Current/Match.xml");
    if(file.exists())
    {

        QString date=QDateTime::currentDateTime().toString("dMyyhm");
        file.rename("Sauvegarde/Match"+date+".xml");
    }
    this->accept();
}

void FenetreFermeture::slot_Plustard()
{
    this->accept();
}

void FenetreFermeture::slot_Supprimer()
{
    if(QMessageBox::warning(this,tr("Attention"),tr("Toutes les données en cours seront supprimer")))
    {
        QFile file("Current/Match.xml");

        if(file.exists())
        {
            file.remove();
        }
      this->accept();
    }


}

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

#include "fenetremodifaction.h"
#include "ui_fenetremodifaction.h"

FenetreModifAction::FenetreModifAction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreModifAction)
{
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    ui->setupUi(this);
}

void FenetreModifAction::Initialisation(QStringList list,int numJoueur,QString action)
{

    ui->comboBox->addItems(list);
    ui->spinBox->setValue(numJoueur);
    ui->lineEdit->setText(action);
}
QString FenetreModifAction::GetValeur()
{
    QString value;
    value.setNum(ui->spinBox->value());
    value=value+"_"+ui->comboBox->currentText()+"_"+ui->lineEdit->text();

    return value;
}

FenetreModifAction::~FenetreModifAction()
{
    delete ui;
}

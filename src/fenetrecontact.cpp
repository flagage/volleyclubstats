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
#include "fenetrecontact.h"
#include "ui_fenetrecontact.h"

FenetreContact::FenetreContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreContact)
{
    ui->setupUi(this);
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    this->exec();
}

FenetreContact::~FenetreContact()
{
    delete ui;
}

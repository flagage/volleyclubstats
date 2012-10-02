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

#include "tablematch.h"
#include "QLayout"

TableMatch::TableMatch(QWidget *parent) :
    QTableWidget(parent)
{

    _listColonne<<tr("NomFichier")<<tr("Date")<<tr("Heure")<<tr("Type")<<tr("Equipe")<<tr("Adversaire")<<tr("arbitre")<<tr("duree")<<tr("nbSet");

    this->setColumnCount (_listColonne.size ());
    for(int i=0;i<_listColonne.size ();i++)
    {
        this->setHorizontalHeaderItem (i,new QTableWidgetItem(QString(_listColonne.at (i))));
    }
      this->setSelectionMode( QAbstractItemView::SingleSelection );
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
     if(parent->layout() != 0)
        parent->layout()->addWidget(this);
}


void TableMatch::Vider()
{

    while (this->rowCount() != 0)
    {
        this->removeRow(0);
    }

}

void TableMatch::AjusterColonnes()
{
    this->hideColumn (0);
    this->resizeColumnsToContents();
    this->resizeRowsToContents();
}

void TableMatch::ActualiserLigne(int num_ligne,QStringList valeur)
{

    for(int k=0;k<valeur.size ();k++)
    {
        this->setItem(num_ligne,k,new QTableWidgetItem(valeur.at(k)));

     }
        this->AjusterColonnes();

}


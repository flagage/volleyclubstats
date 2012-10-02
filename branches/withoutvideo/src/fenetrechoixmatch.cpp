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

#include "fenetrechoixmatch.h"
#include "ui_fenetrechoixmatch.h"
#include "QDir"
#include "lecturematch.h"
#include "QListWidgetItem"
#include "QFileDialog"

FenetreChoixMatch::FenetreChoixMatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreChoixMatch)
{
    ui->setupUi(this);
       _table=new TableMatch(ui->groupBox);

       connect(ui->pushButton_ouv,SIGNAL(clicked()),this,SLOT(Slot_ok()));
       connect(ui->pushButton_sup,SIGNAL(clicked()),this,SLOT(Slot_sup()));
       connect(ui->pB_Importer,SIGNAL(clicked()),this,SLOT(Slot_importer()));
       connect(ui->pB_exporter,SIGNAL(clicked()),this,SLOT(Slot_exporter()));
       this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    //this->Widget=new WidgRevMatch(ui->frame);
    //Widget->Ouvrir ();
}

bool FenetreChoixMatch::Ouvrir()
{

    Actualiser();
    return this->exec ();

}

void FenetreChoixMatch::Actualiser()
{
    _table->clearContents();
    //Recupertation du nombre de fiche present dans le repertoire de sauvegarde
   QString nom_repertoire = QString("Sauvegarde");
   QDir Repertoir(nom_repertoire);
   QStringList filtre;
   filtre<<"*.xml";
   Repertoir.setNameFilters (filtre);
   QStringList listFiche=Repertoir.entryList(QDir::Files|QDir::NoDotAndDotDot);
   int nbFile=listFiche.size();

   _table->setRowCount(nbFile);

   for(int i=0;i<listFiche.size ();i++)
   {
       ///lecture du fichier xml
       LectureMatch* fichier=new LectureMatch(listFiche.at (i));
       QStringList Info;
       Info.append(listFiche.at(i));
       for(int k=0;k< fichier->GetInfoGeneral().size();k++)
       {
            Info.append(fichier->GetInfoGeneral().at(k));
       }
       ///ecriture des info dans le tableau
       _table->ActualiserLigne (i,Info);

   }
}

FenetreChoixMatch::~FenetreChoixMatch()
{
    delete ui;
}

void FenetreChoixMatch::Slot_ok ()
{
    QList<QTableWidgetItem *> ql = _table->selectedItems();


    if ( ! ql.empty())
    {

    QTableWidgetItem* item= _table->item(ql[0]->row (),0);
    _FichierSelectionner=item->text ();

    this->accept ();
    }
    else
    {
    this->close ();
    }
}
void FenetreChoixMatch::Slot_sup()
{
    QList<QTableWidgetItem *> ql = _table->selectedItems();


    if ( ! ql.empty())
    {

    QTableWidgetItem* item= _table->item(ql[0]->row (),0);
    QString Fichier="Sauvegarde/"+item->text();
    QFile file(Fichier);
    file.setFileName(Fichier);
    bool test=file.remove();
    _table->removeRow(ql[0]->row ());
   // _FichierSelectionner=item->text ();
    }
}

QString FenetreChoixMatch::GetFichierSelectionner()
{
    return _FichierSelectionner;
}

void FenetreChoixMatch::Slot_importer()
{
 QString fichier = QFileDialog::getOpenFileName(this, "Importer un fichier", QString(), "file (*.xml)");
 QStringList listnom=fichier.split("/");
 QString nom=listnom.at(listnom.size()-1);
 QFile::copy(fichier,"Sauvegarde/"+nom);
 Actualiser();
}

void FenetreChoixMatch::Slot_exporter()
{
QString dossier = QFileDialog::getExistingDirectory(this);
QList<QTableWidgetItem *> ql = _table->selectedItems();


if ( ! ql.empty())
{

    QTableWidgetItem* item= _table->item(ql[0]->row (),0);
    QString Fichier="Sauvegarde/"+item->text();
     QFile::copy(Fichier,dossier+"/"+item->text());
}
}

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

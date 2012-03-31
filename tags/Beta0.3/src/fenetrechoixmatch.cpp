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

#include "fenetrechoixmatch.h"
#include "ui_fenetrechoixmatch.h"
#include "QDir"
#include "lecturematch.h"
#include "QListWidgetItem"

FenetreChoixMatch::FenetreChoixMatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreChoixMatch)
{
    ui->setupUi(this);
       _table=new TableMatch(ui->groupBox);

       connect(ui->pushButton_ouv,SIGNAL(clicked()),this,SLOT(Slot_ok()));
       connect(ui->pushButton_sup,SIGNAL(clicked()),this,SLOT(Slot_sup()));
       this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    //this->Widget=new WidgRevMatch(ui->frame);
    //Widget->Ouvrir ();
}

bool FenetreChoixMatch::Ouvrir()
{
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

    return this->exec ();

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

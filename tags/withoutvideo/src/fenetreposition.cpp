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
#include "fenetreposition.h"
#include "ui_fenetreposition.h"
#include "match.h"
#include <QtGui>
#include <QList>
FenetrePosition::FenetrePosition(Ecran* ecran,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetrePosition)
{
    ui->setupUi(this);
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    connect(ui->pushButton_ok,SIGNAL(clicked()),this,SLOT(ok()));
    connect(ui->pushButton_Annuler,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(changement(int,int)));
    _ecran=ecran;
    Initialiser();
}

FenetrePosition::~FenetrePosition()
{
    delete ui;
}

void FenetrePosition::Initialiser()
{
    QStringList listColumn;
  listColumn<<"Position"<<"Joueur";
  ui->tableWidget->setColumnCount(listColumn.size());
 ui->tableWidget->setHorizontalHeaderLabels(listColumn);
  Equipe* team=Match::donneInstance()->getTeam();
  QStringList*  listjoueur=new QStringList();

    QList<Joueur*> LJoueur=team->GetListeJoueur();
    ui->tableWidget->setRowCount(LJoueur.count());
    for(int i=0;i<LJoueur.count();i++)
    {
        QString strjoueur;
        strjoueur.setNum(LJoueur.at(i)->get_NumMaillot());
        listjoueur->append(strjoueur);

     }
    for(int i=0;i<LJoueur.count();i++)
    {

         QComboBox*  box=new QComboBox();
        for(int k=0;k<listjoueur->size();k++)
        {
            box->addItem(listjoueur->at(k));
        }
        if((i)<6)
        {
        QLabel * qlab;
        QString num;
        num=num.setNum(i+1);
        qlab=new QLabel(num,this);
        ui->tableWidget->setCellWidget(i,0,qlab);
        ui->tableWidget->setCellWidget(i,1,box);
        }
        else
        {
            QLabel * qlab;
            qlab=new QLabel("banc",this);
            ui->tableWidget->setCellWidget(i,0,qlab);
             ui->tableWidget->setCellWidget(i,1,box);
        }


    }
}

void FenetrePosition::ok()
{
    //_ecran->ui;
    QStringList * position=new QStringList();

    for(int k=0;k<ui->tableWidget->rowCount();k++)
    {
    QComboBox*  box =(QComboBox*)ui->tableWidget->cellWidget ( k, 1 );
            position->append(box->currentText());
    }
    //_ecran->setPosition(position);
    accept();
}
void FenetrePosition::changement(int row,int col)
{

}

#include "twstatjoueur.h"
#include "ui_twstatjoueur.h"

TwStatJoueur::TwStatJoueur(Joueur *player, QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TwStatJoueur)
{
    ui->setupUi(this);
    _currentJoueur=player;
     _statJoueurMatch=new TableStateJoueur(ui->tab);
     _statJoueurSet=new TableStateJoueur(ui->tab_2);
    this->Connection();
    this->Initialisation();
    ui->pushButton->setText(player->get_Prenom()+"_"+QString::number(player->get_NumMaillot())+"_Fermer");
    ui->pushButton_2->setText(player->get_Prenom()+"_"+QString::number(player->get_NumMaillot())+"_Fermer");
}

void TwStatJoueur::Connection()
{
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Slot_fermer()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Slot_fermer()));
}

void TwStatJoueur::Initialisation()
{

    for (int i=0;i<InitAction::donneInstance()->GetSizeAction();i++)
    {
        for (int j=0;j<InitValeur::donneInstance()->GetSizeValeur();j++)
        {
            QString strAffiche;
           double valeur= _currentJoueur->getStatMatch(i,j);
            strAffiche=QString::number(valeur);
            _statJoueurMatch->setItem (i+1,j+1,new QTableWidgetItem(strAffiche));
        }
    }

    for (int i=0;i<InitAction::donneInstance()->GetSizeAction();i++)
    {
        for (int j=0;j<InitValeur::donneInstance()->GetSizeValeur();j++)
        {
            QString strAffiche;
           double valeur= _currentJoueur->getStatSet(i,j);
            strAffiche=QString::number(valeur);
            _statJoueurSet->setItem (i+1,j+1,new QTableWidgetItem(strAffiche));
        }
    }


    this->show();

}

void TwStatJoueur::Slot_fermer()
{
    this->hide();
}


TwStatJoueur::~TwStatJoueur()
{
    delete ui;
}

















/********************************************************
/   Tableau stats joueur
/*********************************************************/

TableStateJoueur::TableStateJoueur(QWidget * parent)
{
    int sizeValeur=InitValeur::donneInstance()->GetSizeValeur();
    int sizeAction=InitAction::donneInstance()->GetSizeAction();
    this->setColumnCount (sizeValeur+1);
    this->setRowCount (sizeAction+1);
    this->horizontalHeader ()->hide();
    this->verticalHeader ()->hide();

    QColor color;
    for(int i=0;i<sizeValeur;i++)
    {
        this->setItem(0,i+1,new QTableWidgetItem(QString(InitValeur::donneInstance()->GetElementValeur(i))));
    }
    for(int j=0;j<sizeAction;j++)
    {
        this->setItem(j+1,0,new QTableWidgetItem(QString(InitAction::donneInstance()->GetElementAction(j))));
    }
    /*for(int i=0;i<sizeAction;i++)
    {
        switch(i)
        {
        case 0:
            color.setRgb (255,153,153);
            break;
        case 1:
            color.setRgb (64,224,208);
            break;
        case 2:
            color.setRgb (153,255,153);
            break;
        case 3:
            color.setRgb (204,204,255);
            break;
        case 4:
            color.setRgb (255,102,255);
            break;
        case 5:
            color.setRgb (238,203,173);
            break;
        }

        int col=sizeValeur/2;
        QString valeurAction=InitAction::donneInstance()->GetElementAction(i);
        this->setItem (0,(i*sizeValeur)+col,new QTableWidgetItem(valeurAction));
        for(int k=0;k<sizeValeur;k++)
        {
            this->setItem (1,(i*sizeValeur)+k+1,new QTableWidgetItem(InitValeur::donneInstance()->GetElementValeur((k))));
            QTableWidgetItem * Item;
            Item=this->item (1,(i*sizeValeur)+k+1);
            Item->setBackground (color);
            Item->setToolTip("(Vpp-Vmm)/tot");
            Item=this->item (0,(i*sizeValeur)+k+1);
            if(Item!=0)
                Item->setBackground (color);
        }



    }*/

    if(parent->layout() != 0)
        parent->layout()->addWidget(this);


    this->resizeColumnsToContents();
    this->resizeRowsToContents();

}


void TableStateJoueur::Resize()
{
this->resizeColumnsToContents ();
this->resizeRowsToContents ();
}

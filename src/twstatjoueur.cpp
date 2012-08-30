#include "twstatjoueur.h"
#include "ui_twstatjoueur.h"

TwStat::TwStat(Joueur *player,Equipe* team, QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TwStatJoueur)
{
    ui->setupUi(this);
    if(player!=0)
    {
        _currentJoueur=player;
        _ListAction=_currentJoueur->GetListAction();
        _ListValeur=_currentJoueur->GetListValeur();
        _NbSet=_currentJoueur->GetNbSet();
        InitJoueur();
    }
    else
    {
        _currentTeam=team;
        _ListAction=_currentTeam->GetListAction();
        _ListValeur=_currentTeam->GetListValeur();
        _NbSet=_currentTeam->GetNbSet();

        InitEquipe();

    }



    Initialisation();
    Connection();

}


void TwStat::Connection()
{
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Slot_fermer()));
    // connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Slot_fermer()));
}
void TwStat::Initialisation()
{
    _statMatch=new TableState(ui->tab,_ListAction,_ListValeur);
    ///creation des tab
    for(int t=1;t<_NbSet;t++)
    {
        QWidget *CreerNouveauOnglet = new QWidget;

        QVBoxLayout *layout = new QVBoxLayout;
        layout->setContentsMargins(0,0,0,0);

        CreerNouveauOnglet->setLayout(layout);
        QString strlabel="Set n°"+QString::number(t);
        this->addTab(CreerNouveauOnglet,strlabel);
        _VectorStatSet.append(new TableState(CreerNouveauOnglet,_ListAction,_ListValeur));
    }

}

void TwStat::InitEquipe()
{

    ui->pushButton->setText(_currentTeam->GetNom()+"_Fermer");
    for (int i=0;i<_currentTeam->GetListAction().size();i++)
    {
        for (int j=0;j<_currentTeam->GetListValeur().size();j++)
        {
            QString strAffiche;
            double valeur= _currentTeam->getStatMatch(i,j);
            strAffiche=QString::number(valeur);
            _statMatch->setItem (i+1,j+1,new QTableWidgetItem(strAffiche));
        }
    }

    for(int t=1;t<_currentTeam->GetNbSet();t++)
    {
        for (int i=0;i<_currentTeam->GetListAction().size();i++)
        {
            for (int j=0;j<_currentTeam->GetListValeur().size();j++)
            {
                QString strAffiche;
                double valeur= _currentTeam->getStatSet(i,j,t);
                strAffiche=QString::number(valeur);
                _VectorStatSet.at(t-1)->setItem(i+1,j+1,new QTableWidgetItem(strAffiche));
            }
        }
    }

    this->show();

}

void TwStat::InitJoueur()
{

    ui->pushButton->setText(_currentJoueur->get_Prenom()+"_"+QString::number(_currentJoueur->get_NumMaillot())+"_Fermer");
    for (int i=0;i<_currentJoueur->GetListAction().size();i++)
    {
        for (int j=0;j<_currentJoueur->GetListValeur().size();j++)
        {
            QString strAffiche;
            double valeur= _currentJoueur->getStatMatch(i,j);
            strAffiche=QString::number(valeur);
            _statMatch->setItem (i+1,j+1,new QTableWidgetItem(strAffiche));
        }
    }

    for(int t=1;t<_currentJoueur->GetNbSet();t++)
    {
        for (int i=0;i<_currentJoueur->GetListAction().size();i++)
        {
            for (int j=0;j<_currentJoueur->GetListValeur().size();j++)
            {
                QString strAffiche;
                double valeur= _currentJoueur->getStatSet(i,j,t);
                strAffiche=QString::number(valeur);
                _VectorStatSet.at(t-1)->setItem(i+1,j+1,new QTableWidgetItem(strAffiche));
            }
        }
    }

    this->show();

}
void TwStat::Slot_fermer()
{
    this->hide();
}


TwStat::~TwStat()
{

    delete _statMatch;


     _VectorStatSet.clear();

    delete ui;
}

















/********************************************************
/   Tableau stats joueur
/*********************************************************/

TableState::TableState(QWidget * parent,QStringList Action,QStringList valeur)
{
    QStringList ListAction=Action;
    QStringList ListValeur=valeur;

    int sizeValeur=ListValeur.size();
    int sizeAction=ListAction.size();

    this->setColumnCount (sizeValeur+1);
    this->setRowCount (sizeAction+1);
    this->horizontalHeader ()->hide();
    this->verticalHeader ()->hide();

    QColor color;
    for(int i=0;i<sizeValeur;i++)
    {
        this->setItem(0,i+1,new QTableWidgetItem(QString(ListValeur.at(i))));
    }
    for(int j=0;j<sizeAction;j++)
    {
        this->setItem(j+1,0,new QTableWidgetItem(QString(ListAction.at(j))));
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


void TableState::Resize()
{
    this->resizeColumnsToContents ();
    this->resizeRowsToContents ();
}

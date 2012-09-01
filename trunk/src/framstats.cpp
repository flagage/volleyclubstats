#include "framstats.h"
#include "ui_framstats.h"

FramStats::FramStats(int action,QList <Joueur*> joueur,QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FramStats)
{
    ui->setupUi(this);
    this->_Action=action;
    this->_listJoueur=joueur;
    this->_listvaleur=_listJoueur.at(0)->GetListValeur();
    _tabStat=0;

}


FramStats::~FramStats()
{
    delete ui;
}

void FramStats::SlotMiseAJour()
{
    for(int k=0;k<_listJoueur.size();k++)
    {
        Joueur * player=_listJoueur.at(k);
        for(int i=0;i<_listvaleur.size();i++)
        {
            QTableWidgetItem *item=_tabStat->item(k+1,i+1);
            double valeur=player->getStatMatch(_Action,i);
            QString strValeur;
            strValeur.setNum(valeur,'g',4);
            if(item!=0)
            {
                item->setText(strValeur);
            }
        }
    }
}
void FramStats::clean()
{
    if(_tabStat!=0)
    delete _tabStat;
}


void FramStats::Init()
{
    _tabStat=new TableStat(ui->groupBox,_listJoueur,_Action,_listvaleur);
    this->show();
}





TableStat::TableStat(QWidget * parent,QList <Joueur*> listJoueur,int action,QStringList ListValeur)
    :  QTableWidget(parent)
{
    this->setColumnCount (ListValeur.size()+1);
    this->setRowCount (listJoueur.size()+1);

    this->setSortingEnabled(true);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);

    this->setEditTriggers(QAbstractItemView::NoEditTriggers);

 //   this->horizontalHeader ()->hide();
    this->verticalHeader ()->hide();

    this->setHorizontalHeaderItem(0,new QTableWidgetItem(QString( "Joueur")));
    this->setHorizontalHeaderItem(1,new QTableWidgetItem(QString( "Num")));
    /// On remplit la premiere ligne
    for(int i=0;i<ListValeur.size();i++)
    {
        QString strvaleur=ListValeur.at(i);

        this->setHorizontalHeaderItem(i+2,new QTableWidgetItem(strvaleur));

    }
    /// On remplit la premiere colonne
    for(int k=0;k<listJoueur.size();k++)
    {
        this->setItem(k,0,new QTableWidgetItem(QString(listJoueur.at(k)->get_Prenom())));
        QString num=QString::number(listJoueur.at(k)->get_NumMaillot());
        if(num.size()==1)
        {
            num="0"+num;
        }
        this->setItem(k,1,new QTableWidgetItem(num));
        this->item(k,0)->setBackgroundColor(QColor(167,167,167));
        this->item(k,1)->setBackgroundColor(QColor(167,167,167));
    }

    /// On remplit le reste

    for(int k=0;k<listJoueur.size();k++)
    {
        Joueur * player=listJoueur.at(k);
        for(int i=0;i<ListValeur.size();i++)
        {
            double valeur=player->getStatMatch(action,i);
            QString strValeur;
            strValeur.setNum(valeur);

            this->setItem(k,i+2,new QTableWidgetItem(QString(strValeur)));

        }
    }


    if(parent->layout() != 0)
        parent->layout()->addWidget(this);


    this->resizeColumnsToContents();
    this->resizeRowsToContents();

}

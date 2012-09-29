#include "framstats.h"
#include "ui_framstats.h"

FramStats::FramStats(int action,Equipe* team,QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FramStats)
{
    ui->setupUi(this);
    this->_Action=action;
    this->_listJoueur=team->GetListeJoueur();
    this->_team=team;
    this->_listvaleur=_listJoueur.at(0)->GetListValeur();
    _tabStat=0;

}


FramStats::~FramStats()
{
    delete ui;
}

void FramStats::SlotMiseAJour(bool isSet,int numSet)
{
    _tabStat->setSortingEnabled(false);
   for(int k=0;k<_listJoueur.size();k++)
   {

       QTableWidgetItem *item=_tabStat->item(k,1);
       Joueur * player=PlayerfromNum(item->text());

       for(int i=0;i<_listvaleur.size();i++)
       {
           QTableWidgetItem *item=_tabStat->item(k,i+2);
           double valeur;
            if(isSet==false)
                   valeur=player->getStatMatch(_Action,i);
            else
                 valeur=player->getStatSet(_Action,i,numSet);
           QString strValeur;
           strValeur.setNum(valeur,'g',4);
           if(item!=0)
           {
               item->setText(strValeur);
           }
       }

       /// Equipe
       for(int i=0;i<_listvaleur.size();i++)
       {
           QTableWidgetItem *item=_tabStat->item(_listJoueur.size()+1,i+2);
           double valeur;
            if(isSet==false)
                   valeur=_team->getStatMatch(_Action,i);
            else
                 valeur=_team->getStatSet(_Action,i,numSet);
           QString strValeur;
           strValeur.setNum(valeur,'g',4);
           if(item!=0)
           {
               item->setText(strValeur);
           }

   }


   _tabStat->setSortingEnabled(true);

}

}
Joueur* FramStats::PlayerfromNum(QString num)
{
    for(int k=0;k<_listJoueur.size();k++)
    {

        if(num.toInt()==_listJoueur.at(k)->get_NumMaillot())
        {
            return _listJoueur.at(k);
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
    _tabStat=new TableStat(ui->groupBox,_team,_Action,_listvaleur);
    this->show();
}





TableStat::TableStat(QWidget * parent,Equipe * team,int action,QStringList ListValeur)
    :  QTableWidget(parent)
{

    QList <Joueur*>  listJoueur=team->GetListeJoueur();
    QColor ColorAction;
    switch (action)
    {
    case 0:
        ColorAction=QColor(255,153,153);
        break;
    case 1:
        ColorAction= QColor(64,224,208);
        break;
    case 2:
        ColorAction=QColor(153,255,153);
        break;
    case 3:
        ColorAction=QColor(204,204,255);
        break;
    case 4:
        ColorAction=QColor(255,102,255);
        break;
    case 5:
        ColorAction=QColor(238,203,173);
        break;

    default:
        ColorAction=QColor(Qt::white);
        break;

    }

    this->setColumnCount (ListValeur.size()+2);
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
         Joueur * player=listJoueur.at(k);
        this->setItem(k,0,new QTableWidgetItem(QString(player->get_Prenom())));
        this->item(k,0)->setBackgroundColor(QColor(167,167,167));
        QString num=QString::number(player->get_NumMaillot());
        if(num.size()==1)
        {
            num="0"+num;
        }
        this->setItem(k,1,new QTableWidgetItem(num));

        this->item(k,1)->setBackgroundColor(QColor(167,167,167));



        for(int i=0;i<ListValeur.size();i++)
        {
            double valeur=player->getStatMatch(action,i);
            QString strValeur;
            strValeur.setNum(valeur);

            this->setItem(k,i+2,new QTableWidgetItem(QString(strValeur)));
            this->item(k,i+2)->setBackgroundColor(ColorAction);
        }

    }
    /// On remplit le total
    int iC=listJoueur.size();
    this->setItem(iC,0,new QTableWidgetItem("Equipe"));
     this->item(iC,0)->setBackgroundColor(QColor(167,167,167));
    this->setItem(iC,1,new QTableWidgetItem("99"));
     this->item(iC,1)->setBackgroundColor(QColor(167,167,167));

    for(int i=0;i<ListValeur.size();i++)
    {
        double valeur=team->getStatMatch(action,i);
        QString strValeur;
        strValeur.setNum(valeur);

        this->setItem(iC,i+2,new QTableWidgetItem(QString(strValeur)));
        this->item(iC,i+2)->setBackgroundColor(ColorAction);
    }


    if(parent->layout() != 0)
        parent->layout()->addWidget(this);


    this->resizeColumnsToContents();
    this->resizeRowsToContents();

}

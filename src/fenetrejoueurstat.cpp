#include "fenetrejoueurstat.h"
#include "ui_fenetrejoueurstat.h"


FenetreJoueurStat::FenetreJoueurStat(Joueur* player,Equipe* team,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreJoueurStat)
{
    ui->setupUi(this);

    _tabWidget = new TwStat(player,team,this);

    _tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    ui->gridLayout->addWidget(_tabWidget, 0, 0, 1, 1);
    this->show();
}





FenetreJoueurStat::~FenetreJoueurStat()
{
    if(_tabWidget!=0)
        delete _tabWidget;

delete ui;
}

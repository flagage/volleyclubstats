#include "fenetrejoueurstat.h"
#include "ui_fenetrejoueurstat.h"


FenetreJoueurStat::FenetreJoueurStat(Joueur* player,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreJoueurStat)
{
    ui->setupUi(this);

       _MyWidget=new TwStatJoueur(player,ui->groupBox);
       _MyWidget->show();
}

FenetreJoueurStat::~FenetreJoueurStat()
{
    delete ui;
}

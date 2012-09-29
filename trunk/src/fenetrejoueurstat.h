#ifndef FENETREJOUEURSTAT_H
#define FENETREJOUEURSTAT_H

#include <QDialog>
#include "twstatjoueur.h"
#include "Joueur.h"
#include "Equipe.h"


namespace Ui {
class FenetreJoueurStat;
}

class FenetreJoueurStat : public QDialog
{
    Q_OBJECT
    
public:
   explicit FenetreJoueurStat(Joueur* player,Equipe* team=0,QWidget *parent = 0);



    ~FenetreJoueurStat();
    
private:
    Ui::FenetreJoueurStat *ui;
     TwStat* _tabWidget;
};

#endif // FENETREJOUEURSTAT_H

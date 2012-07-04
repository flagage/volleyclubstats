#ifndef FENETREJOUEURSTAT_H
#define FENETREJOUEURSTAT_H

#include <QDialog>
#include "twstatjoueur.h"
#include "Joueur.h"

namespace Ui {
class FenetreJoueurStat;
}

class FenetreJoueurStat : public QDialog
{
    Q_OBJECT
    
public:
    explicit FenetreJoueurStat(Joueur* player,QWidget *parent = 0);
    ~FenetreJoueurStat();
    
private:
    Ui::FenetreJoueurStat *ui;
    TwStatJoueur *_MyWidget;
};

#endif // FENETREJOUEURSTAT_H

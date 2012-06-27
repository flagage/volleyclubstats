#ifndef TWSTATJOUEUR_H
#define TWSTATJOUEUR_H

#include <QTabWidget>
#include "QTableWidget"
#include "Joueur.h"

namespace Ui {
class TwStatJoueur;
}


class TableStateJoueur: public QTableWidget
{

public:

   TableStateJoueur(QWidget * parent);
   void Resize();
};

class TwStatJoueur : public QTabWidget
{
    Q_OBJECT
    
public:
    explicit TwStatJoueur(Joueur * player,QWidget *parent = 0);
    ~TwStatJoueur();
    void Initialisation();
    
private:
    Ui::TwStatJoueur *ui;
    Joueur* _currentJoueur;
    void Connection();
    TableStateJoueur* _statJoueurSet;
    TableStateJoueur* _statJoueurMatch;
public slots:
    void Slot_fermer();
};

#endif // TWSTATJOUEUR_H

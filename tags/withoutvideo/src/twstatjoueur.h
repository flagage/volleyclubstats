#ifndef TWSTATJOUEUR_H
#define TWSTATJOUEUR_H

#include <QTabWidget>
#include "QTableWidget"
#include "QVector"
#include "Joueur.h"
#include "Equipe.h"

namespace Ui {
class TwStatJoueur;
}


class TableState: public QTableWidget
{

public:

   TableState(QWidget * parent,QStringList action,QStringList valeur);
   void Resize();
};



class TwStat : public QTabWidget
{
    Q_OBJECT
    
public:
    explicit TwStat(Joueur * player,Equipe* team,QWidget *parent = 0);

    ~TwStat();
    void Initialisation();
    void InitJoueur();
    void InitEquipe();
private:
    Ui::TwStatJoueur *ui;
    Joueur* _currentJoueur;
    Equipe* _currentTeam;
    QStringList _ListAction;
    QStringList _ListValeur;
    int _NbSet;
    void Connection();
    QVector <TableState*> _VectorStatSet;
    TableState* _statMatch;

public slots:
    void Slot_fermer();
};

#endif // TWSTATJOUEUR_H

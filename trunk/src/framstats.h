#ifndef FRAMSTATS_H
#define FRAMSTATS_H

#include <QFrame>
#include "QTableWidget"
#include "QLayout"
#include "Joueur.h"

namespace Ui {
class FramStats;
}

class TableStat: public QTableWidget
{

public:

    TableStat(QWidget * parent,QList <Joueur*> list,int Action,QStringList ListValeur);
};



class FramStats : public QFrame
{
    Q_OBJECT
    
public:
    explicit FramStats(int action,QList <Joueur*> joueur,QWidget *parent = 0);
    ~FramStats();
    void Init();
    void clean();

    
private:
    Ui::FramStats *ui;
    TableStat* _tabStat;
    QStringList _listvaleur;
    QList <Joueur*>_listJoueur;
    int _Action;

public slots:
    void SlotMiseAJour();
};

#endif // FRAMSTATS_H

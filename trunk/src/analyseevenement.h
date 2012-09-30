#ifndef ANALYSEEVENEMENT_H
#define ANALYSEEVENEMENT_H

#include <QDialog>

namespace Ui {
class AnalyseEvenement;
}

class AnalyseEvenement : public QDialog
{
    Q_OBJECT
    
public:
    explicit AnalyseEvenement(QStringList listjoueur,QStringList listEvent,QWidget *parent = 0);
    ~AnalyseEvenement();
    void Connection();
    void Initialisation();
public slots:
    void changement();

private:
    Ui::AnalyseEvenement *ui;
    QStringList _listevent;
    int _compteur;
};

#endif // ANALYSEEVENEMENT_H

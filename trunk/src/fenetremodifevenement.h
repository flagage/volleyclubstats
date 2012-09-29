#ifndef FENETREMODIFEVENEMENT_H
#define FENETREMODIFEVENEMENT_H

#include <QDialog>

namespace Ui {
    class FenetreModifEvenement;
}

class FenetreModifEvenement : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreModifEvenement(QStringList list1,QStringList list2,QStringList list3,QWidget *parent = 0);
    ~FenetreModifEvenement();

    void Modif(QString message);
    QString ReturnText();

private:
    Ui::FenetreModifEvenement *ui;
};

#endif // FENETREMODIFEVENEMENT_H

#ifndef FENETREFERMETURE_H
#define FENETREFERMETURE_H

#include <QDialog>
#include "QFile"
#include "QDateTime"
#include "QMessageBox"

namespace Ui {
class FenetreFermeture;
}

class FenetreFermeture : public QDialog
{
    Q_OBJECT
    
public:
    explicit FenetreFermeture(QWidget *parent = 0);
    ~FenetreFermeture();
    
private:
    Ui::FenetreFermeture *ui;

public slots:
    void slot_Sauvegarde();
    void slot_Plustard();
    void slot_Supprimer();
};

#endif // FENETREFERMETURE_H

#include "fenetremodifevenement.h"
#include "ui_fenetremodifevenement.h"

FenetreModifEvenement::FenetreModifEvenement(QStringList listJoueur,QStringList listAction,QStringList listValeur,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreModifEvenement)
{
    ui->setupUi(this);
    listJoueur<<"00";
    ui->comboBox->addItems (listJoueur);
    ui->comboBox_2->addItems (listAction);
    ui->comboBox_3->addItems (listValeur);
    QStringList listPosition;
    listPosition<<"P1"<<"P2"<<"P3"<<"P4"<<"P5"<<"P6";
    ui->comboBox_4->addItems(listPosition);
}

FenetreModifEvenement::~FenetreModifEvenement()
{
    delete ui;
}

void FenetreModifEvenement::Modif(QString message)
{
    QStringList list=message.split (" ");
    for(int i=0;i<(ui->comboBox->count ());i++)
    {
        if (list[0]==ui->comboBox->itemText (i))
        {
            ui->comboBox->setCurrentIndex (i);
            break;
        }
    }
    for(int i=0;i<ui->comboBox_2->count();i++)
    {
        if (list[1]==ui->comboBox_2->itemText (i).left(3))
        {
            ui->comboBox_2->setCurrentIndex (i);
            break;
        }
    }
    for(int i=0;i<ui->comboBox_3->count ();i++)
    {
        if (list[2]==ui->comboBox_3->itemText (i))
        {
            ui->comboBox_3->setCurrentIndex (i);
            break;
        }
    }
    for(int i=0;i<ui->comboBox_4->count ();i++)
    {
        if (list[3]==ui->comboBox_4->itemText (i))
        {
            ui->comboBox_4->setCurrentIndex (i);
            break;
        }
    }
}

QString FenetreModifEvenement::ReturnText()
{
    QString text=ui->comboBox->currentText ()+" "+ui->comboBox_2->currentText ().left(3)+" "+
            ui->comboBox_3->currentText ()+ " "+ui->comboBox_4->currentText();

    return text;
}


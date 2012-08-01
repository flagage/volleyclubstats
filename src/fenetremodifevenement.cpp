#include "fenetremodifevenement.h"
#include "ui_fenetremodifevenement.h"

FenetreModifEvenement::FenetreModifEvenement(QStringList list1,QStringList list2,QStringList list3,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreModifEvenement)
{
    ui->setupUi(this);
    ui->comboBox->addItems (list1);
    ui->comboBox_2->addItems (list2);
    ui->comboBox_3->addItems (list3);
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
        if (list[1]==ui->comboBox_2->itemText (i))
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
}

QString FenetreModifEvenement::ReturnText()
{
    QString text=ui->comboBox->currentText ()+" "+ui->comboBox_2->currentText ()+" "+
    ui->comboBox_3->currentText ();

    return text;
}


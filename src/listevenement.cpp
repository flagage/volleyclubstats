#include "listevenement.h"
#include "QMessageBox"
#include "QInputDialog"


ListEvenement::ListEvenement(bool MenuActif,QWidget *parent) :
    QListWidget(parent)
{

    _MenuActif=MenuActif;
    Initialisation();
    Connection();
}
ListEvenement::~ListEvenement ()
{
    delete _menu;
    delete _menuTm;
}

void ListEvenement::Initialisation()
{
    _menu=new QMenu(this);
    _menu->addAction (tr("Ajouter Avant"));
    _menu->addAction (tr("Modifier"));
    _menu->addAction (tr("Supprimer"));

    _menuTm=new QMenu(this);
    _menuTm->addAction(tr("Supprimer tm"));

}

void ListEvenement::Connection()
{
    connect(this,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(Slot_DClick()));
    connect(_menu,SIGNAL(triggered(QAction*)),this,SLOT(Slot_Action(QAction *)));
    connect(_menuTm,SIGNAL(triggered(QAction*)),this,SLOT(Slot_ActionTm(QAction *)));
}

void ListEvenement::Slot_DClick()
{
    if(_MenuActif==true)
    {

        if(this->currentItem()->text().contains("Temps mort"))
        {
            _menuTm->exec(QCursor::pos());
        }
        else
        {
            _menu->exec (QCursor::pos ());
        }
    }


}

void ListEvenement::Slot_Action(QAction * action)
{

    if(action->text ()==tr("Ajouter Avant"))
    {
        emit add(this->currentRow ());

    }
    if(action->text ()==(tr("Modifier")))
    {

        emit modif(this->currentRow ());
    }
    if(action->text ()==(tr("Supprimer")))
    {

        emit sup(this->currentRow ());

    }
}

void ListEvenement::Slot_ActionTm(QAction * action)
{
    if(action->text()==tr("Supprimer tm"))
    {
        emit supTm(this->currentRow());
    }
}

void ListEvenement::addItem( QString label)
{
    QStringList Listlabel=label.split(" ");
    if(Listlabel.size()==5)
    {
        QListWidget::addItem(Listlabel[1]+" "+Listlabel[2]+" "+Listlabel[3]+" "+Listlabel[4] );
    }
    else
    {
        QListWidget::addItem(Listlabel[1]);
    }

}



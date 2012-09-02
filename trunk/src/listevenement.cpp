#include "listevenement.h"
#include "QMessageBox"
#include "QInputDialog"


ListEvenement::ListEvenement(QWidget *parent) :
    QListWidget(parent)
{

     Initialisation();
    Connection();
}
ListEvenement::~ListEvenement ()
{
    delete _menu;
}

void ListEvenement::Initialisation()
{
     _menu=new QMenu(this);
     _menu->addAction (tr("Ajouter Avant"));
     _menu->addAction (tr("Modifier"));
     _menu->addAction (tr("Supprimer"));

}

void ListEvenement::Connection()
{
    connect(this,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(Slot_DClick()));
    connect(_menu,SIGNAL(triggered(QAction*)),this,SLOT(Slot_Action(QAction *)));
}

void ListEvenement::Slot_DClick()
{

    _menu->exec (QCursor::pos ());


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

void ListEvenement::addItem( QString label)
{
    QStringList Listlabel=label.split(" ");
    if(Listlabel.size()==5)
    QListWidget::addItem(Listlabel[1]+" "+Listlabel[2]+" "+Listlabel[3]+" "+Listlabel[4] );
}



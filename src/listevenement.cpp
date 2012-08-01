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
     //_ItemSelect=0;
     _menu=new QMenu(this);
     _menu->addAction (tr("Ajouter Avant"));
     _menu->addAction (tr("Modifier"));
     _menu->addAction (tr("Supprimer"));

}

void ListEvenement::Connection()
{
    connect(this,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(Slot_DClick()));
   // connect(this,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(Slot_Click()));
    connect(_menu,SIGNAL(triggered(QAction*)),this,SLOT(Slot_Action(QAction *)));
}

void ListEvenement::Slot_DClick()
{

   // _ItemSelect=this->currentItem ();
    _menu->exec (QCursor::pos ());


}

/*void ListEvenement::Slot_Click()
{
 _ItemSelect=this->currentItem ();
 }*/
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



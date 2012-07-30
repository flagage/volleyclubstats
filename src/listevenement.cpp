#include "listevenement.h"

ListEvenement::ListEvenement(QObject *parent) :
    QObject(parent)
{
}


QStringList ListEvenement::GetListEvenet()
{
    return _list;
}

void ListEvenement::AddEvenement(QString event)
{
    _list.append(event);
    Update();
}

void ListEvenement::SuppEvenement(QString event)
{
    for (int i=0;i<event.size();i++)
    {
        if(_list.at(i)==event)
        {
            _list.removeAt(i);
        }
    }
    Update();
}

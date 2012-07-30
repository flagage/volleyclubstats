#ifndef LISTEVENEMENT_H
#define LISTEVENEMENT_H

#include <QObject>
#include "QStringList"

class ListEvenement : public QObject
{
    Q_OBJECT
private:
    QStringList _list;

public:
    explicit ListEvenement(QObject *parent = 0);
    void AddEvenement(QString);
    void SuppEvenement(QString);
    QStringList GetListEvenet();
signals:
    void Update();

public slots:
    
};

#endif // LISTEVENEMENT_H

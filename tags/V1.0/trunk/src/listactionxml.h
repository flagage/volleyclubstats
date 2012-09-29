#ifndef LISTACTIONXML_H
#define LISTACTIONXML_H
#include "QFile"
#include "QString"
#include "QDateTime"
#include "QTextStream"

class ListActionXml
{
private:
    QString _file;
public:
    ListActionXml();
    void SetFile(QString nom);
    void SetTrace(QString msg);
    void Fin();
    void Debut();
    void SupprimerAction(int IdAction);
};

#endif // LISTACTIONXML_H

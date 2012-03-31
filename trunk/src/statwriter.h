#ifndef STATWRITER_H
#define STATWRITER_H
#include <QtGui>
#include "Joueur.h"

class statWriter
{
public:
    statWriter(Joueur playeur);
    ~statWriter();
     void write(const QString &fileName);
     void addstat();
private:
    QTextBlockFormat centerFormat;
    QTextCharFormat boldFormat;
    QTextCursor m_cursor;
    QTextDocument *m_document;
    Joueur _player;
};

#endif // STATWRITER_H

/**
Copyright Frederic volleyclubstats ,2011
fred@volleyclubstats.com

This file is part of volleyclubstats.

volleyclubstats is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

volleyclubstats is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Volleyclubstats.  If not, see <http://www.gnu.org/licenses/>.
**/

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

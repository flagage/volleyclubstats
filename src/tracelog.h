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

#ifndef TRACELOG_H
#define TRACELOG_H

#include <QObject>

class TraceLog : public QObject
{
    Q_OBJECT
private:
    QString _file;
public:
    explicit TraceLog(QObject *parent = 0);
    void SetTrace(QString msg,bool date=true);
    void SetFile(QString filename);

signals:
    void EnvoieTrace(QString texte);

public slots:

};

#endif // TRACELOG_H

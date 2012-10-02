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

#include "tracelog.h"
#include <QFile>
#include <QDate>
#include <QTextStream>

TraceLog::TraceLog(QObject *parent) :
    QObject(parent)
{

}

void TraceLog::SetFile(QString filename)
{
_file=filename;
}

void TraceLog::SetTrace(QString msg,bool date)
{
    QString message;
    QDateTime time;
    QString nomRep="Sauvegarde/"+_file+".log";
    QFile file(nomRep);
    if(date==true)
    {
        time=time.currentDateTime();
        message=time.toString("d-MM-yyyy/hh:mm:ss");
        message=message+" "+msg+"\n";
    }
    else
    {
        message=msg;
    }




    if (!file.open(QIODevice::Append |QIODevice::WriteOnly|QIODevice::Text ))
    return;

    QTextStream out(&file);
    out << message;

    file.close();
    emit EnvoieTrace(message);
}

#include "tracematch.h"

TraceMatch::TraceMatch(QObject *parent) :
    QObject(parent)
{

}

void TraceMatch::SetFile(QString filename)
{
_file=filename;
}

void TraceMatch::SetTrace(QString msg,bool date)
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
}

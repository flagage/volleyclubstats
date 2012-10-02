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

#ifndef LECTUREMATCH_H
#define LECTUREMATCH_H
#include "QString"
#include "QDomDocument"
#include "QStringList"
#include "QMap"

class LectureMatch
{
private :
QDomDocument _doc;
QStringList  ListGeneral;
QStringList _ListJoueur;
QString _nomEquipe;
QString _ListValeur;
QString _ListAction;
QStringList _MatchStat;
QMap <int,QString > _Score;
QMap <int,QStringList > _Stat;

public:
    LectureMatch(QString chemin);
    void lectureInfoGeneral(QString chemin);
    void lectureStat(QString chemin);
    QStringList GetInfoGeneral();
    QString GetNomEquipe();
    QString GetListAction();
    QString GetListValeur();
    QStringList GetListJoueur();
    QStringList GetStat(int indice);
    QString GetScore(int indice);
    QStringList GetStatMatch();
};

#endif // LECTUREMATCH_H

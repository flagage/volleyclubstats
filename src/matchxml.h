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

#ifndef MATCHXML_H
#define MATCHXML_H
#include "QString"
#include "QDomElement"
#include "QFile"
#include "parametrematch.h"
#include "Score.h"
#include "Equipe.h"
#include <QTextStream>

class MatchXml
{
private:
    QFile _fileXmlCurrent;
    ParametreMatch *_ParamMatch;
    Score* _score;
    Equipe* _EquipeLocal;
    Equipe* _EquipeVisiteur;
    QStringList* _ListEvenement;
    QList <QString>* _listPosition;
    QDomDocument _doc;
    QDomElement _root;

public:
    MatchXml( ParametreMatch *,Score*,Equipe*,QStringList*,QList <QString>*);
    void LectureXML(QString);
    void setEquipe(Equipe *team);
    Equipe * GetEquipe();
    void InitStatFromXml(QDomNode child,int TemOrPl,bool isSet,int numset=0,Joueur* player=0);
    void LectureParametreMatch(QString);
    QDomDocument Getdoc();
    QDomElement GetRoot();


};

#endif // MATCHXML_H

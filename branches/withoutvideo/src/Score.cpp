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

#include "Score.h"


Score::Score()
{
    _ScLocal=0;
    _ScVisiteur=0;
    _SetLocal=0;
    _SetVisiteur=0;
    _TmLocal=0;
    _TmVisiteur=0;
    _ServeurSet=0;
    _ServeurCurrent=0;
}

Score::~Score()
{

}

void Score::set_Service(int value)
{
    _ServeurCurrent = value;
}

void Score::set_ServiceSet(int value)
{
    _ServeurSet=value;
}

void Score::set_TmVisiteur(int value)
{
    _TmVisiteur = value;
}

void Score::set_TmLocal(int value)
{
    _TmLocal = value;
}

void Score::set_SetVisiteur(int value)
{
    _SetVisiteur = value;
}

void Score::set_SetLocal(int value)
{
    _SetLocal = value;
}

void Score::set_ScVisiteur(int value)
{
    _ScVisiteur = value;
}

void Score::set_ScLocal(int value)
{
    _ScLocal=value;
}

int Score::get_Service()
{
    return _ServeurCurrent;
}
int Score::get_ServiceSet()
{
    return _ServeurCurrent;
}

int Score::get_TmVisiteur()
{
    return _TmVisiteur;
}

int Score::get_TmLocal()
{
    return _TmLocal;
}

int Score::get_SetVisiteur()
{
    return _SetVisiteur;
}

int Score::get_SetLocal()
{
    return _SetLocal;
}

int Score::get_ScVisiteur()
{
    return _ScVisiteur;
}

int Score::get_ScLocal()
{
    return _ScLocal;
}
void Score::SauvegardeScore()
{
    QString score=QString::number(_ScLocal)+":"+QString::number(_ScVisiteur)+"_";
    _ListScore.append(score);
    if(_ScLocal>_ScVisiteur)
    {
        _SetLocal++;
    }
    else
    {
        _SetVisiteur++;
    }
    _ScLocal=0;
    _ScVisiteur=0;
}

QStringList Score::ListdesScore()
{
    return _ListScore;
}

void Score::Set_ListScore(QStringList list)
{
    _ListScore.clear();
    _ListScore=list;
}

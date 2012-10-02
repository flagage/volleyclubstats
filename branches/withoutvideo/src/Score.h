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

#ifndef _SCORE_H
#define _SCORE_H
#include "QStringList"


//Classe decrivant le score du match en cours
class Score
{
private:
    int _ScLocal;

    int _ScVisiteur;

    int _SetLocal;

    int _SetVisiteur;

    int _TmLocal;

    int _TmVisiteur;

    //determine qui a le premier service
    //si 0 service pour l'equipe local
    //si 1 service pour l'equipe visiteur

    int  _ServeurSet;
    int _ServeurCurrent;

    QStringList _ListScore;

public:
    int get_Service();

    void set_Service(int value);

    int get_ServiceSet();

    void set_ServiceSet(int value);

    int get_TmVisiteur();

    void set_TmVisiteur(int value);

    int get_TmLocal();

    void set_TmLocal(int value);

    int get_SetVisiteur();

    void set_SetVisiteur(int value);

    int get_SetLocal();

    void set_SetLocal(int value);

    int get_ScVisiteur();

    void set_ScVisiteur(int value);

    int get_ScLocal();
    void set_ScLocal(int value);

    void SauvegardeScore();
    QStringList ListdesScore();

    void Set_ListScore(QStringList list);

    Score();

    ~Score();

};

#endif

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

#ifndef CLUB_H
#define CLUB_H
#include "QString"

class Club
{
public:
    Club();
    void init(int num,QString nom,QString cat,QString div);
    void setNum(int num);
    void setNom(QString nom);
    void setCat(QString cat);
    void setDiv(QString div);
    int GetNum();
    QString GetNom();
    QString GetCat();
    QString GetDiv();


private:
    int _num;
    QString _nom;
    QString _categorie;
    QString _division;
};

#endif // CLUB_H

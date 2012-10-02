/**
Copyright Frederic volleyclubstats ,2011
fred@volleyclubstats.com

This file is part of volleyclubstats.

volleyclubstats is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Volleyclubstats.  If not, see <http://www.gnu.org/licenses/>.
**/
#include "club.h"

Club::Club()
{
    _categorie="";
    _division="";
    _nom="";
    _num=0;
}

void Club::init(int num, QString nom, QString cat, QString div)
{
    _num=num;
    _nom=nom;
    _categorie=cat;
    _division=div;

}

void Club::setCat(QString cat)
{
    _categorie=cat;
}

void Club::setDiv(QString div)
{
    _division=div;
}
void Club::setNom(QString nom)
{
    _nom=nom;
}

QString Club::GetCat()
{
    return _categorie;
}

QString Club::GetNom()
{
    return _nom;
}
QString Club::GetDiv()
{
    return _division;
}
int Club::GetNum()
{
    return _num;
}

void Club::setNum(int num)
{
    _num=num;
}

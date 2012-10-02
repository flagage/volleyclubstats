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

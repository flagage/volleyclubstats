#include "parametrematch.h"

ParametreMatch::ParametreMatch()
{
    this->_NumSet=1;
}



void ParametreMatch::set_NomEquipeVisiteur(QString value)
{
    _NomEquipeVisiteur = value;
}

QString ParametreMatch::get_NomEquipeVisiteur()
{
    return _NomEquipeVisiteur;
}

void ParametreMatch::set_NomEquipeLocal(QString value)
{
    _NomEquipeLocal = value;
}
QString ParametreMatch::get_NomEquipeLocal()
{
    return _NomEquipeLocal;
}

void ParametreMatch::set_NomArbitre1(QString value)
{
    _NomArbitre1 = value;
}
QString ParametreMatch::get_NomArbitre1()
{
    return _NomArbitre1;
}

void ParametreMatch::set_NomArbitre2(QString value)
{
    _NomArbitre2 = value;
}

QString ParametreMatch::get_NomArbitre2()
{
    return _NomArbitre2;
}

void ParametreMatch::set_TypeDeMatch(QString value)
{
    _TypeDeMatch = value;
}

QString ParametreMatch::get_TypeDeMatch()
{
    return _TypeDeMatch;
}

void ParametreMatch::set_Date(QDate value)
{
    _Date = value;
}
QDate ParametreMatch::get_Date()
{
    return _Date;
}

void ParametreMatch::set_Duree(QDateTime value)
{
    _Duree = value;
}

QDateTime ParametreMatch::get_Duree()
{
    return _Duree;
}

void ParametreMatch::set_Valeur(QStringList value)
{
    _Valeur = value;
}

QStringList ParametreMatch::get_Valeur()
{
    return _Valeur;
}

void ParametreMatch::set_Action(QStringList value)
{
    _Action = value;
}

QStringList ParametreMatch::get_Action()
{
    return _Action;
}
/*
void ParametreMatch::set_Position(QMap value)
{
    _Position = value;
}

QMap ParametreMatch::get_Position()
{
    return _Position;
}
*/
int ParametreMatch::get_NbSet()
{
    return _Nb_Set;
}

void ParametreMatch::set_NbSet(int i)
{
    _Nb_Set=i;
}

int ParametreMatch::get_NbJoueur()
{
    return _Nb_Joueur;
}

void ParametreMatch::set_NbJoueur(int i)
{
    _Nb_Joueur=i;
}

int ParametreMatch::get_ScoreMax()
{
    return _Score_Max;
}


void ParametreMatch::set_ScoreMax(int i)
{
    _Score_Max=i;
}

int ParametreMatch::AvecLibero()
{
    return _AvecLibero;
}

void ParametreMatch::SetLibero(int valeur)
{
    _AvecLibero=valeur;
}

int ParametreMatch::get_TotJoueur()
{
    if(_AvecLibero==0)
    {
        return _Nb_Joueur;
    }
    else
        return _Nb_Joueur+1;
}
int ParametreMatch::GetNumSet()
{
    return _NumSet;
}

void ParametreMatch::SetNumSet(int valeur)
{
    _NumSet=valeur;
}
int ParametreMatch::GetActionFromString(QString strValeur)
{
    for(int i=0;i<_Action.size();i++)
    {
        if(_Action.at(i)==strValeur)
        {
            return i;
        }
    }
    return 0;
}

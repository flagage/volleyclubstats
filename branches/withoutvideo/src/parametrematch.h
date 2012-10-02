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

#ifndef PARAMETREMATCH_H
#define PARAMETREMATCH_H
#include <QString>
#include <QStringList>
#include <QMap>
#include <QDateTime>

class ParametreMatch
{
public:
    ParametreMatch();

private :
    QString _NomEquipeVisiteur;

       QString _NomEquipeLocal;

       QString _NomArbitre1;

       QString _NomArbitre2;

       QString _TypeDeMatch;

       QDate _Date;

       QDateTime _Duree;

       QStringList _Valeur;

       QStringList _Action;

       QStringList _ActionDefilement;

       //QMap _Position;

       int _Nb_Set;
       int _Nb_Joueur;
       int _Score_Max;
       bool _AvecLibero;
       int _NumSet;


public:
  QString get_NomEquipeVisiteur();

  void set_NomEquipeVisiteur(QString value);

   QString get_NomEquipeLocal();

  void set_NomEquipeLocal(QString value);

   QString get_NomArbitre1();

  void set_NomArbitre1(QString value);

   QString get_NomArbitre2();

  void set_NomArbitre2(QString value);

   QString get_TypeDeMatch();

  void set_TypeDeMatch(QString value);

   QDate get_Date();

  void set_Date(QDate value);

   QDateTime get_Duree();

  void set_Duree(QDateTime value);

   QStringList get_Valeur();

  void set_Valeur(QStringList value);

   QStringList get_Action();

  void set_Action(QStringList value);

  QStringList get_ActionDefile();
  void set_ActionDefile(QStringList value);

  // QMap get_Position();

  //void set_Position(QMap value);

  int get_NbSet();
  void set_NbSet(int );

  int get_NbJoueur();
  void set_NbJoueur(int);

  int get_ScoreMax();
  void set_ScoreMax(int);

  bool AvecLibero();
  void SetLibero(bool );

  int get_TotJoueur();

  int GetNumSet();

  void SetNumSet(int valeur);

  int GetActionFromString(QString);

};

#endif // PARAMETREMATCH_H







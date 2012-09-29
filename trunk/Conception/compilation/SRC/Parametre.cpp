
#include "Parametre.h"

void Parametres::set__NomEquipeVisiteur(QString value) {
  _NomEquipeVisiteur = value;
}

void Parametres::set__NomEquipeLocal(QString value) {
  _NomEquipeLocal = value;
}

void Parametres::set__NomArbitre1(QString value) {
  _NomArbitre1 = value;
}

void Parametres::set__NomArbitre2(QString value) {
  _NomArbitre2 = value;
}

void Parametres::set__TypeDeMatch(Enum value) {
  _TypeDeMatch = value;
}

void Parametres::set__Date(QDate value) {
  _Date = value;
}

void Parametres::set__Duree(QDateTime value) {
  _Duree = value;
}

void Parametres::set__Valeur(QStringList value) {
  _Valeur = value;
}

void Parametres::set__Action(QStringList value) {
  _Action = value;
}

void Parametres::set__Position(QMap value) {
  _Position = value;
}


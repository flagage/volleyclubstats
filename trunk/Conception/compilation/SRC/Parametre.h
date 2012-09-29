#ifndef _PARAMETRE_H
#define _PARAMETRE_H


class Parametres {
  private:
    //Nom de l'equipe adverse
    
    QString _NomEquipeVisiteur;

    QString _NomEquipeLocal;

    QString _NomArbitre1;

    QString _NomArbitre2;

    Enum _TypeDeMatch;

    QDate _Date;

    QDateTime _Duree;

    QStringList _Valeur;

    QStringList _Action;

    QMap _Position;


  public:
    inline const QString get__NomEquipeVisiteur() const;

    void set__NomEquipeVisiteur(QString value);

    inline const QString get__NomEquipeLocal() const;

    void set__NomEquipeLocal(QString value);

    inline const QString get__NomArbitre1() const;

    void set__NomArbitre1(QString value);

    inline const QString get__NomArbitre2() const;

    void set__NomArbitre2(QString value);

    inline const Enum get__TypeDeMatch() const;

    void set__TypeDeMatch(Enum value);

    inline const QDate get__Date() const;

    void set__Date(QDate value);

    inline const QDateTime get__Duree() const;

    void set__Duree(QDateTime value);

    inline const QStringList get__Valeur() const;

    void set__Valeur(QStringList value);

    inline const QStringList get__Action() const;

    void set__Action(QStringList value);

    inline const QMap get__Position() const;

    void set__Position(QMap value);

};
inline const QString Parametres::get__NomEquipeVisiteur() const {
  return _NomEquipeVisiteur;
}

inline const QString Parametres::get__NomEquipeLocal() const {
  return _NomEquipeLocal;
}

inline const QString Parametres::get__NomArbitre1() const {
  return _NomArbitre1;
}

inline const QString Parametres::get__NomArbitre2() const {
  return _NomArbitre2;
}

inline const Enum Parametres::get__TypeDeMatch() const {
  return _TypeDeMatch;
}

inline const QDate Parametres::get__Date() const {
  return _Date;
}

inline const QDateTime Parametres::get__Duree() const {
  return _Duree;
}

inline const QStringList Parametres::get__Valeur() const {
  return _Valeur;
}

inline const QStringList Parametres::get__Action() const {
  return _Action;
}

inline const QMap Parametres::get__Position() const {
  return _Position;
}

#endif

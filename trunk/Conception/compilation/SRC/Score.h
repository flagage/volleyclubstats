#ifndef _SCORE_H
#define _SCORE_H


//Classe decrivant le score du match en cours
class Score {
  private:
    int _ScLocal;

    int _ScVisiteur;

    int _SetLocal;

    int _SetVisiteur;

    int _TmLocal;

    int _TmVisiteur;

    //determine qui a le premier service
    //si true service pour l'equipe local
    //si false service pour l'equipe visiteur
    bool _Service;


  public:
    inline const bool get__Service() const;

    void set__Service(bool value);

    inline const int get__TmVisiteur() const;

    void set__TmVisiteur(int value);

    inline const int get__TmLocal() const;

    void set__TmLocal(int value);

    inline const int get__SetVisiteur() const;

    void set__SetVisiteur(int value);

    inline const int get__SetLocal() const;

    void set__SetLocal(int value);

    inline const int get__ScVisiteur() const;

    void set__ScVisiteur(int value);

    inline const int get__ScLocal() const;

    Score();

    ~Score();

};
inline const bool Score::get__Service() const {
  return _Service;
}

inline const int Score::get__TmVisiteur() const {
  return _TmVisiteur;
}

inline const int Score::get__TmLocal() const {
  return _TmLocal;
}

inline const int Score::get__SetVisiteur() const {
  return _SetVisiteur;
}

inline const int Score::get__SetLocal() const {
  return _SetLocal;
}

inline const int Score::get__ScVisiteur() const {
  return _ScVisiteur;
}

inline const int Score::get__ScLocal() const {
  return _ScLocal;
}

#endif

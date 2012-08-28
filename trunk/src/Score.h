#ifndef _SCORE_H
#define _SCORE_H


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
    int _Service;


public:
    int get_Service();

    void set_Service(int value);

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

    Score();

    ~Score();

};

#endif

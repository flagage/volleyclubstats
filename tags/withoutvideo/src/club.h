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

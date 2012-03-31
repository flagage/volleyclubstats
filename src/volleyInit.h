#ifndef VOLLEYINIT_H
#define VOLLEYINIT_H

#include <QStringList>
#include <QString>

namespace VolleyStats
{
 static enum
    {
        SERV,
        RECEP,
        CONTRE,
        DEF,
        PASSE,
        ATTA
    }ACTION;

   static  enum
    {
        VPP,
        VP,
        V0,
        VM,
        VMM,
        TOT,
        EFF1,
        EFF2,
        EFF3,
        EFF4
    }VALEUR;


    class Valeur
    {
        Valeur();
        ~Valeur();
    public:
         int GetSizeValeur();
         QString GetElementValeur(int valu);
    private:
        QStringList _ListValeur;
    };

    /*class Action
    {
        Action();
        ~Action();
    public:
         int GetSizeAction();
         QString GetElementAction(int action);
        // QStringList GetListAction();
    private:
        QStringList _ListAction;
    };*/

    QStringList GetMAction();
      //inline int test=0;
    //QStringList m_ListAction=(QStringList()<<"Service"<<"Récéption"<<"Contre"<<"Défense"<<"Passe"<<"Attaque");

}
#endif // VOLLEYINIT_H

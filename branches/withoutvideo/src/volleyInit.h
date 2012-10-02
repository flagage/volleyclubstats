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


#ifndef VOLLEYINIT_H
#define VOLLEYINIT_H
#include <QStringList>
#include <QString>



/**
* \class InitValeur
* \brief classe decrivant tous les paramétres essentiel à l'initialisation du projet
* cette classe est un singleton on ne peut l'initialiser qu'une seul fois
*/

class InitValeur
{
private:
   static InitValeur* _InstanceValeur;
    QStringList _ListValeur;
protected:
    InitValeur();
    ~InitValeur();


public:
    static InitValeur* donneInstance();
    static void libereInstance();
    static InitValeur * GetInstance();

    int GetSizeValeur();

    QString GetElementValeur(int valu);
    int GetValeurFromString(QString valeur);
    QStringList GetListValeur();
    void SetSelection(QStringList list);


};


/**
* \class InitAction
* \brief classe decrivant tous les paramétres essentiel à l'initialisation du projet
* cette classe est un singleton on ne peut l'initialiser qu'une seul fois
*/

class InitAction
{
private:
   static InitAction* _InstanceAction;
    QStringList _ListAction;
protected:
    InitAction();
    ~InitAction();

public:
    static InitAction* donneInstance();
    static void libereInstance();
    static InitAction * GetInstance();

    int GetSizeAction();
    QString GetElementAction(int valu);
    QStringList GetListAction();
    int GetActionFromString(QString valeur);
    void SetSelection(QStringList list);


};

class InitGlobal
{
private:
   static InitGlobal* _InstanceGlobal;
   int _nbSet;
   int _nbJoueur;

protected:
    InitGlobal();
    ~InitGlobal();

public:
    static InitGlobal* donneInstance();
    static void libereInstance();
    static InitGlobal * GetInstance();
    int GetNbJoueur();
    void SetNbJoueur(int nbJoueur);
    int GetNbSet();
    void SetNbSet(int nbSet);
};

  enum ACTION
    {
        SERV,
        RECEP,
        CONTRE,
        DEF,
        PASSE,
        ATTA
    };

     enum StatValeur
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


      //inline int test=0;
    //QStringList m_ListAction=(QStringList()<<"Service"<<"Récéption"<<"Contre"<<"Défense"<<"Passe"<<"Attaque");


#endif // VOLLEYINIT_H

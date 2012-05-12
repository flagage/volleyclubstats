/**
Copyright LAGAGE Frédéric ,2011
flagage@gmail.com

Ce logiciel est un programme informatique servant à capturer en direct des statistiques des joueurs de volley-ball.

Ce logiciel est régi par la licence CeCILLsoumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe à
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL et que vous en avez accepté les
**/
#ifndef VOLLEYINIT_H
#define VOLLEYINIT_H
#include <QStringList>
#include <QString>

#define MAXSET 5;

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
    int _nbSet;

public:
    static InitValeur* donneInstance();
    static void libereInstance();
    static InitValeur * GetInstance();

    int GetSizeValeur();
    int GetNbSet();
    QString GetElementValeur(int valu);
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
    void SetSelection(QStringList list);


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

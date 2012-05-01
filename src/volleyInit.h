/**
Copyright LAGAGE Fr�d�ric ,2011
flagage@gmail.com

Ce logiciel est un programme informatique servant � capturer en direct des statistiques des joueurs de volley-ball.

Ce logiciel est r�gi par la licence CeCILLsoumise au droit fran�ais et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL telle que diffus�e par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilit� au code source et des droits de copie,
de modification et de redistribution accord�s par cette licence, il n'est
offert aux utilisateurs qu'une garantie limit�e.  Pour les m�mes raisons,
seule une responsabilit� restreinte p�se sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les conc�dants successifs.

A cet �gard  l'attention de l'utilisateur est attir�e sur les risques
associ�s au chargement,  � l'utilisation,  � la modification et/ou au
d�veloppement et � la reproduction du logiciel par l'utilisateur �tant
donn� sa sp�cificit� de logiciel libre, qui peut le rendre complexe �
manipuler et qui le r�serve donc � des d�veloppeurs et des professionnels
avertis poss�dant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invit�s � charger  et  tester  l'ad�quation  du
logiciel � leurs besoins dans des conditions permettant d'assurer la
s�curit� de leurs syst�mes et ou de leurs donn�es et, plus g�n�ralement,
� l'utiliser et l'exploiter dans les m�mes conditions de s�curit�.

Le fait que vous puissiez acc�der � cet en-t�te signifie que vous avez
pris connaissance de la licence CeCILL et que vous en avez accept� les
**/
#ifndef VOLLEYINIT_H
#define VOLLEYINIT_H
#include <QStringList>
#include <QString>

/**
* \class InitValeur
* \brief classe decrivant tous les param�tres essentiel � l'initialisation du projet
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
    QStringList GetListValeur();
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
    //QStringList m_ListAction=(QStringList()<<"Service"<<"R�c�ption"<<"Contre"<<"D�fense"<<"Passe"<<"Attaque");


#endif // VOLLEYINIT_H

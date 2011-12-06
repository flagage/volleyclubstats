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
#ifndef _SCORE_H
#define _SCORE_H
#include "QString"


class Score {
  private:
    QString Equipe_1;

    QString Equipe_2;

    int Score_E1;

    int Score_E2;

    int Set_E1;

    int Set_E2;

    bool adv;


  public:
    Score();

    ~Score();

      QString get_Equipe_1() ;

    void set_Equipe_1(QString value);

      QString get_Equipe_2() ;

    void set_Equipe_2(QString value);

      int get_Score_E1() ;

    void set_Score_E1(int value);

      int get_Score_E2() ;

    void set_Score_E2(int value);

      int get_Set_E1() ;

    void set_Set_E1(int value);

      int get_Set_E2() ;

    void set_Set_E2(int value);

    void set_bool_adv(bool value);
    bool get_bool_adv();

};

#endif

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

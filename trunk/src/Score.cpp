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
#include "Score.h"

Score::Score()
{
    Score_E1=0;

    Score_E2=0;

    Set_E1=0;

    Set_E2=0;

}


Score ::~Score() {
}


QString Score ::get_Equipe_1()
{
    return Equipe_1;
}


void Score ::set_Equipe_1(QString value) {
    Equipe_1 = value;
}


QString Score ::get_Equipe_2()  {
    return Equipe_2;
}


void Score ::set_Equipe_2(QString value) {
    Equipe_2 = value;
}


int Score ::get_Score_E1()  {
    return Score_E1;
}


void Score ::set_Score_E1(int value) {
    Score_E1 = value;
}


int Score ::get_Score_E2()
{
    return Score_E2;
}


void Score ::set_Score_E2(int value)
{
    Score_E2 = value;
}


int Score ::get_Set_E1()
{
    return Set_E1;
}


void Score ::set_Set_E1(int value)
{
    Set_E1 = value;
}


int Score ::get_Set_E2()
{
    return Set_E2;
}


void Score ::set_Set_E2(int value)
{
    Set_E2 = value;
}

void Score::set_bool_adv(bool value)
{
    this->adv=value;
}

bool Score::get_bool_adv()
{
    return this->adv;
}

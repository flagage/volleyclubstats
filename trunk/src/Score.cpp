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

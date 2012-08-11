/**
Copyright LAGAGE Frédéric ,2011
flagage@gmail.com

Ce logiciel est un programme informatique servant �  capturer en direct des statistiques des joueurs de volley-ball.

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
associés au chargement,  �  l'utilisation,  �  la modification et/ou au
développement et �  la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe � 
manipuler et qui le réserve donc �  des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités �  charger  et  tester  l'adéquation  du
logiciel �  leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
�  l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder �  cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL et que vous en avez accepté les
**/
#ifndef MATCHXML_H
#define MATCHXML_H
#include "QString"
#include "QDomElement"
#include "QFile"
#include "Joueur.h"
#include <QTextStream>

class MatchXml
{
public:
    MatchXml(QStringList listInfo,QList <Joueur*> listJoueur);
    void Initialisation();
    QString Rechercheposte(int post);
    void SauvegardeAction(Joueur* player,int Action,int valeur);
    void SauvegardeScore(int Slocal,int Svisiteur);
    void ChangementDeSet(int numero);
    void MiseaJourposte();
    void UpdateListJoueur(QList <Joueur*> listJoueur);
private:
    /// liste des joueurs sur le terrain
    QList <Joueur*> _ListJoueurTer;
    QStringList _ListInfo;
    QString _nomFichier;
    QString _CurrentSet;
    QDomDocument _doc;
    QFile _file;
    QDomElement _root;
};

#endif // MATCHXML_H

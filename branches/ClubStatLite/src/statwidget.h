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
#ifndef STATWIDGET_H
#define STATWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include "Equipe.h"

class TableElementsState: public QTableWidget
{

public:

   TableElementsState(QWidget * parent);
   void Resize();
};

namespace Ui {
    class StatWidget;
}

class StatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatWidget(QWidget *parent = 0,QWidget *Fenetreparent=0);
    ~StatWidget();
       TableElementsState * _tabElts;
     QMap <int,TableElementsState *> StatJoueur;
     void Ouvrir();
     void Initialisation();
     void SetEquipe(Equipe* team );
     void SetStatJoueurSet(Joueur *player,int numSet);
     void SetStatJoueurMatch(Joueur *player);
     void SetStatEquipeSet(Equipe *team,int numSet);
     void SetStatEquipeMatch(Equipe *team);
     void SetOldStatEquipeSet(int numSet);
     void SetOldStatJoueurSet(Joueur *player,int numSet);
     void InitListAction(QStringList action);
     void ExportCVS();
     void Imprimer();
     void clean();
     void SetColor(int Action,QTableWidgetItem *item);
     void SetStatoldEquipeMatch();
     QString ColonneHtml(QString html);
     void  Resize ();


private:
    Ui::StatWidget *ui;
    Equipe *_team;
    int _nbValeur;
    QList <Joueur*> _listJoueur;
    QWidget * _Fenetre;
    QStringList _listAction;

    public slots:
    void slot_recu(int i);
    void slot_changement(int i);
    void slot_export();
};

#endif // STATWIDGET_H

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
#ifndef ECRAN_H
#define ECRAN_H

#include <QMainWindow>
#include <QListWidget>
#include "QTimer"
#include "tracelog.h"
#include "Equipe.h"
#include "fenetrestat.h"
#include "fenetrescore.h"
#include "fenetrechoixmatch.h"
#include "statwidget.h"
#include "keyjoueur.h"
#include "widgettabeff.h"
#include "vcslineedit.h"
#include "listactionxml.h"
#include "volleyInit.h"

namespace Ui {
    class Ecran;
}

//using namespace VolleyStats;

class Ecran : public QMainWindow
{
    Q_OBJECT

public:


    explicit Ecran(QWidget *parent = 0);
    Ecran(const Ecran&);
    virtual ~Ecran();


    void Initialisation();
    void InitialisationError();
    void InitialisationMatch(QString team,QString adv);
    void InitialisationAction(QStringList Action);
   // void InitialisationValeur(QStringList Valeur);
    void ChercherPasseur();
    void Actionpasse();
    /// Sauvegarde
    void EnregistrerXML();
    void RestaurerXML();

    QList <Equipe*> GetListeEquipe();
    QStringList* _listBanc;
    QStringList* _listPosition;
    QPushButton* ChangeBouton;
    Equipe RechercheEquipe(QString nom);
    void AddEquipe(Equipe* team);
    void SupEquipe(Equipe* team);
    void setPosition(QStringList* position);
    void Rotation();
    void RotationInverse();
    void changement(int numjoueurSortant,int numjoueurEntrant);
    void keyPressEvent(QKeyEvent * event);
    void SetAction(QString numjoueur,QString ValeurAction);
    void PointPlus(QString numjoueur);
    void PointMoins(QString numjoueur);
    void dropEvent(QDropEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void changement(QString joueur,QPushButton *bouton);
    void RetirerPoint(bool );
    void SetTactile(bool);
    void SautAction(QString str);
    void JoueurAPlacer();



private:
    Ui::Ecran *ui;
    VCSLineEdit *LineEdit2;
    QList <Equipe*> _ListeEquipe;
    bool _Bchangement;
    bool _isMatchEnCour;
    bool _flagsup;
    bool _PointForUs;
    bool _Istactile;
    TraceLog* _trace;
    ListActionXml * _TraceListAction;
    int _position;
    int _positionEcran;
    FenetreStat* _FenetreStat;
    FenetreChoixMatch* _FenetreChoix;
    bool _ischangement;
    void IsService();
    QString ChangeJoueur;
    QTimer * _TimerChange;
    QTimer * _TimerScore;
    StatWidget* myWidget;
    WidgetTabEff* _WtabEff;
    bool _finSet;
    QList<QString> _ListActionModif;
    QStringList _listActionMatch;
    QStringList _listActionPlus;
    QStringList _listActionMoins;
    QStringList _listValeurStat;
    QStringList _listAction;
     KeyJoueur *_PlacementJoueur;
     int _currentSet;
     int _currentposition;
     InitValeur * _ValeurInitial;
     InitAction * _ListActionInit;

protected:
     void closeEvent(QCloseEvent * event );


public slots:
    void AffSession(QAction *);
    void Slot_Fenetre(QAction * action);
    void AfficherTrace(QString message);
    void TempsMort();
    void FinSet();
    void FinMatch();
    void ActionService(int );
    void SlotDrag(QListWidgetItem* item);
    void Slot_start();
    void slot_rotationP();
    void slot_rotationM();
    void score();
    void scoreadv();
    void slot_changement(QPushButton*);
    void slot_modifpost(QPushButton*);
    void slot_initChangement();
    void slot_score();
    void Slot_Scoreplus(int position);
    void Slot_SuppAction();
    void Slot_ModifAction();
    void Slot_ActionMM();
    void Slot_ActionM();
    void Slot_Action0();
    void Slot_ActionP();
    void Slot_ActionPP();

    void Slot_PplusL();
    void Slot_PplusA();
    void Slot_PmoinsL();
    void Slot_PmoinsA();

    void Slot_RotTerrain();
    void SlotCombobox();
    void Slot_posAction();
    void Slot_posService();
    void Slot_posReception();
    void Slot_posPasse();
    void Slot_posContre();
    void Slot_posDefense();
    void Slot_ComplAction();

    void bouttonLClicked();

signals:
    void ScorePlus(int);
    void ScoreMoins(int);
    void SignalAction(int);
    void Changement(QPushButton *button);





};


#endif // ECRAN_H

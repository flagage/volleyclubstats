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

#ifndef ECRAN_H
#define ECRAN_H

#include <QMainWindow>
#include <QListWidget>
#include "revumatch.h"
#include "QTimer"
#include "tracelog.h"
#include "fenetrestat.h"
#include "fenetrescore.h"
#include "fenetrechoixmatch.h"
#include "keyjoueur.h"
#include "widgettabeff.h"
#include "vcslineedit.h"
#include "listactionxml.h"
#include "volleyInit.h"
#include "listevenement.h"
#include "framstats.h"


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

    void InitialisationIhm();
    void Connexion();
    void InitialisationMatch();
    void InitialisationMatchFromXML();
    void InitIhmMatch();


    QString ChercherPasseur();
    void Actionpasse();
    /// Sauvegarde
    void EnregistrerXML();
    void RestaurerXML();

    QList <Equipe*> GetListeEquipe();
    void SetListeEquipe(QList <Equipe*> list);
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
    bool PointPlus(QString numjoueur);
    bool PointMoins(QString numjoueur);
    void dropEvent(QDropEvent* event);
    void dragEnterEvent(QDragEnterEvent* event);
    void changement(QString joueur,QPushButton *bouton);
    void RetirerPoint(bool );
    void SetTactile(bool);
    void SautAction(QString str);
    void JoueurAPlacer();
    void JoueurBanc();
    void AddJoueurBanc(Joueur* joueur);
     void AfficherStat();
     void InitTempsMort();

     void InitialisationFromXml();



private:
    Ui::Ecran *ui;
    VCSLineEdit *LineEdit2;
    QList <Equipe*> _ListeEquipe;
    QList < BouttonJoueur*> _ListBanc;
    bool _Bchangement;
    bool _isMatchEnCour;
    bool _flagsup;
    bool _PointForUs;
    bool _flagService;
    bool _isEnPlace;
    TraceLog* _trace;
    ListActionXml * _TraceListAction;
    int _position;
    int _positionEcran;
    FenetreStat* _FenetreStat;
    FenetreChoixMatch* _FenetreChoix;
    RevuMatch* _FenetreRevuMatch;
    bool _ischangement;
    void IsService();
    QString ChangeJoueur;
    QTimer * _TimerChange;
    QTimer * _TimerScore;
    //StatWidget* myWidget;
    QVector <WidgetTabEff*> _VectortabEff;
    QVector<FramStats*> _VectorTabFram;
    bool _finSet;
    QList<QString> _ListActionModif;
    QStringList _listActionPlus;
    QStringList _listActionMoins;
    QStringList _listValeurStat;
    QStringList _listAction;
     KeyJoueur *_PlacementJoueur;
     int _currentSet;
     int _currentposition;
     InitValeur * _ValeurInitial;
     InitAction * _ListActionInit;
     int _joueurBanc;
    ListEvenement* _ListEvent;


protected:
     void closeEvent(QCloseEvent * event );


public slots:
    void AffSession(QAction *);
    void Slot_Fenetre(QAction * action);
    void AfficherTrace(QString message);
    void TempsMort();
    bool FinSet();
    void FinMatch();
    void ActionService(int );
    void SlotDrag(QListWidgetItem* item);
    void Slot_start();
    void slot_rotationP();
    void slot_rotationM();
    void score();
    void scoreadv();
    void slot_changement(QPushButton*);
    void slot_AfficheStat(QPushButton* bu=0);
    void slot_Stat();
    void SlotModifJoueur();
    void slot_initChangement();
    void slot_score();
    void InitScore();
    void Slot_SuppAction();
    void Slot_ModifAction();
    void SlotMenuEquipe(QAction *action);


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
    void Slot_posRelance();
    void Slot_ComplAction();

    void bouttonLClicked();
    void SlotButonRclicked();
    void SlotAddJoueur();
    void SlotSupJoueur();
    void UpdateTabVue(int tab);

    void SlotMenupoint1(QAction*);
    void SlotMenupoint2(QAction*);
    void slot_UpdateListEvent();

    void slot_addEvent(int );
    void slot_ModifEvent(int);
    void slot_suppEvent(int);
    void slot_supTempsMort(int);
    void AjouterEvent(int index ,QString text,bool isModif=false);
    StatValeur GetStatValeur(QString valu);

    void MiseAjourtab(int i);
signals:

    void ScoreMoins(int);
    void SignalAction(int);
    void Changement(QPushButton *button);





};


#endif // ECRAN_H

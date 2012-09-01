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
#include "ecran.h"
#include "ui_ecran.h"
#include "fbjoueur.h"
#include "fenetreequipe.h"
#include "fenetrevisualisation.h"
#include "match.h"
#include "fenetreservice.h"
#include "fenetrelancement.h"
#include "fenetremodifaction.h"
#include <QKeyEvent>
#include "QRadioButton"
#include "fenetreinternet.h"
#include "lecteurvideo.h"
#include "fenetrejoueurstat.h"
#include "fenetremodifevenement.h"



Ecran::Ecran(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ecran)
{

    ui->setupUi(this);
    InitialisationIhm();
    Connexion();
    /// lecture du fichier contenant le nom des equipes
    this->RestaurerXML();
}

Ecran::~Ecran()
{
    delete LineEdit2;
    delete _PlacementJoueur;
    //delete myWidget;
    //delete _WtabEff;
}

void Ecran::InitialisationIhm()
{
    /// valeur a initialiser
    _joueurBanc=0;
    /// ligne de saisi
    ui->lineEdit->setVisible(false);
    LineEdit2 =  new VCSLineEdit(ui->centralWidget);
    LineEdit2->setObjectName(QString::fromUtf8("lineEdit"));
    ui->gridLayout->addWidget(LineEdit2,0, 0, 1, 1);



    /// Chargement des icons
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    ui->label_6->setPixmap((QPixmap("Icone/Yellow_card.png")));
    ui->label_7->setPixmap((QPixmap("Icone/Yellow_card.png")));
    ui->label_8->setPixmap((QPixmap("Icone/Yellow_card.png")));
    ui->label_9->setPixmap((QPixmap("Icone/Yellow_card.png")));

    ui->groupBox_4->setVisible(false);

    //myWidget=new StatWidget(ui->groupBox_3,this);
    //_WtabEff=new WidgetTabEff(ui->tabWidget->widget(1));

    ui->frame->setVisible(false);
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(false);


    QPalette    palette( ui->centralWidget->palette());
    QPixmap        bg("Icone/Volleyclubstats_gris.png");

    palette.setBrush(QPalette::Background, bg);
    ui->centralWidget->setPalette(palette);
    ui->tabWidget->setVisible(true);

    /// timer utiliser lors du changement d'un joueur
    _TimerChange = new QTimer (this);
    connect (_TimerChange,SIGNAL(timeout()),this,SLOT(slot_initChangement()));

    /// timer pour mettre a jour le score
    _TimerScore=new QTimer (this);
    connect (_TimerScore,SIGNAL(timeout()),this,SLOT(slot_score()));


    /// List des action marquan des points
    _listActionMoins<<tr("Attaque")<<tr("Contre");
    _listActionPlus<<tr("Service")<<tr("Attaque")<<tr("Contre");

}

void Ecran::Connexion()
{

    connect(this,SIGNAL(Changement(QPushButton*)),this,SLOT(slot_changement(QPushButton*)));
    connect(this->LineEdit2,SIGNAL(ChangeAction()),this,SLOT(SlotCombobox()));
    connect(this->LineEdit2,SIGNAL(Attaque()),this,SLOT(Slot_posAction()));
    connect(this->LineEdit2,SIGNAL(Reception()),this,SLOT(Slot_posReception()));
    connect(this->LineEdit2,SIGNAL(Service()),this,SLOT(Slot_posService()));
    connect(this->LineEdit2,SIGNAL(Defense()),this,SLOT(Slot_posDefense()));
    connect(this->LineEdit2,SIGNAL(Contre()),this,SLOT(Slot_posContre()));
    connect(this->LineEdit2,SIGNAL(Passe()),this,SLOT(Slot_posPasse()));
    connect(this->LineEdit2,SIGNAL(ComplementAction()),this,SLOT(Slot_ComplAction()));
    connect(ui->menuFichier, SIGNAL(triggered(QAction *)), this, SLOT(AffSession(QAction *)));
    connect(ui->menuMatch,SIGNAL(triggered(QAction*)),this,SLOT(AffSession(QAction*)));
    connect(ui->menuFenetre, SIGNAL(triggered(QAction *)), this, SLOT(Slot_Fenetre(QAction *)));
    connect(ui->menuEquipe,SIGNAL(triggered(QAction*)),this,SLOT(SlotMenuEquipe(QAction *)));
    connect(ui->pushButton_TM,SIGNAL(clicked()),this,SLOT(TempsMort()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(ActionService(int)));
    //bouton de rotation
    connect (ui->pBRotationPlus,SIGNAL(clicked()),this,SLOT(slot_rotationP()));
    connect (ui->pBRotationMoins,SIGNAL(clicked()),this,SLOT(slot_rotationM()));

    connect(this,SIGNAL(ScorePlus(int)),this,SLOT(Slot_Scoreplus(int)));

    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(UpdateTabVue(int)));


}


    /*
    _ValeurInitial=InitValeur::donneInstance();
    _ListActionInit=InitAction::donneInstance();
    _position=0;
    _joueurBanc=0;
    _Istactile=false;
    _ischangement=false;
    _finSet=false;



    //ui->lineEdit_PBP->setVisible(false);
    LineEdit2 =  new VCSLineEdit(ui->centralWidget);
    LineEdit2->setObjectName(QString::fromUtf8("lineEdit"));

    ui->gridLayout->addWidget(LineEdit2,0, 0, 1, 1);

    /*QDesktopWidget *desktop=QApplication::desktop ();
    QRect size=desktop->screenGeometry ();*/
    /*this->resize(1000,500);
    this->move(0,0);

    _PlacementJoueur=new KeyJoueur(ui->label_4,7,true);
    QHBoxLayout *layout=new QHBoxLayout();
    layout->addWidget (_PlacementJoueur);

    connect(this->_PlacementJoueur,SIGNAL(Changement(QPushButton*)),this,SLOT(slot_changement(QPushButton*)));
    connect(this->_PlacementJoueur,SIGNAL(JoueurStat(QPushButton*)),this,SLOT(slot_AfficheStat(QPushButton*)));
    // connect(this->_PlacementJoueur,SIGNAL(ModifPoste(QPushButton*)),this,SLOT(slot_modifpost(QPushButton*)));
    connect(this->_PlacementJoueur,SIGNAL(Tlm_en_place()),this,SLOT(Slot_start()));
    connect(this,SIGNAL(Changement(QPushButton*)),this,SLOT(slot_changement(QPushButton*)));
    connect(this->LineEdit2,SIGNAL(ChangeAction()),this,SLOT(SlotCombobox()));
    connect(this->LineEdit2,SIGNAL(Attaque()),this,SLOT(Slot_posAction()));
    connect(this->LineEdit2,SIGNAL(Reception()),this,SLOT(Slot_posReception()));
    connect(this->LineEdit2,SIGNAL(Service()),this,SLOT(Slot_posService()));
    connect(this->LineEdit2,SIGNAL(Defense()),this,SLOT(Slot_posDefense()));
    connect(this->LineEdit2,SIGNAL(Contre()),this,SLOT(Slot_posContre()));
    connect(this->LineEdit2,SIGNAL(Passe()),this,SLOT(Slot_posPasse()));
    connect(this->LineEdit2,SIGNAL(ComplementAction()),this,SLOT(Slot_ComplAction()));




   _isMatchEnCour=false;


    connect(ui->menuFichier, SIGNAL(triggered(QAction *)), this, SLOT(AffSession(QAction *)));
    connect(ui->menuMatch,SIGNAL(triggered(QAction*)),this,SLOT(AffSession(QAction*)));
    connect(ui->menuFenetre, SIGNAL(triggered(QAction *)), this, SLOT(Slot_Fenetre(QAction *)));
    connect(ui->menuEquipe,SIGNAL(triggered(QAction*)),this,SLOT(SlotMenuEquipe(QAction *)));
    _trace=new TraceLog(this);
    _TraceListAction= new ListActionXml();
    connect(this->_trace,SIGNAL(EnvoieTrace(QString)),this,SLOT(AfficherTrace(QString)));


    connect(ui->pushButton_TM,SIGNAL(clicked()),this,SLOT(TempsMort()));


    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(ActionService(int)));

    //bouton de rotation

    connect (ui->pBRotationPlus,SIGNAL(clicked()),this,SLOT(slot_rotationP()));
    connect (ui->pBRotationMoins,SIGNAL(clicked()),this,SLOT(slot_rotationM()));




    _TimerScore=new QTimer (this);
    connect (_TimerScore,SIGNAL(timeout()),this,SLOT(slot_score()));






    setAcceptDrops(true);
    QDate curentDate=QDate::currentDate();
    Initialisation();

    if(curentDate.year() == 2013)
    {
        if(curentDate.month() > 2)
        {
            InitialisationError();
        }

    }
    else if(curentDate.year() > 2013)
    {
        InitialisationError();
    }

    myWidget=new StatWidget(ui->groupBox_3,this);
    _WtabEff=new WidgetTabEff(ui->groupBox_6);
    /// version tactile
    /*connect(ui->Button_PP,SIGNAL(clicked()),this,SLOT(Slot_ActionPP()));
    connect(ui->Button_P,SIGNAL(clicked()),this,SLOT(Slot_ActionP()));
    connect(ui->Button_0,SIGNAL(clicked()),this,SLOT(Slot_Action0()));
    connect(ui->Button_M,SIGNAL(clicked()),this,SLOT(Slot_ActionM()));
    connect(ui->Button_MM,SIGNAL(clicked()),this,SLOT(Slot_ActionMM()));

    ui->Button_0->setVisible(false);
    ui->Button_M->setVisible(false);
    ui->Button_MM->setVisible(false);
    ui->Button_P->setVisible(false);
    ui->Button_PP->setVisible(false);
    ui->tabWidget->setVisible(false);*/
    /*ui->label_4->setPixmap (QPixmap("Image/new_terrain.png"));
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));


    ui->label_6->setPixmap((QPixmap("Icone/Yellow_card.png")));
    ui->label_7->setPixmap((QPixmap("Icone/Yellow_card.png")));
    ui->label_8->setPixmap((QPixmap("Icone/Yellow_card.png")));
    ui->label_9->setPixmap((QPixmap("Icone/Yellow_card.png")));

    ui->groupBox_4->setVisible(false);
    //ui->groupBox_10->setVisible(false);

    /// font d'ecran
    _positionEcran=0;

    /// modification du tableau de vue
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(UpdateTabVue(int)));


    //icon.addPixmap(QPixmap::fromImage(image), mode, state)
    // ui->label_4->setVisible(false);
}

Ecran::~Ecran()
{

    _listPosition->clear();
    delete ui;
}

void Ecran::Initialisation()
{
    _Bchangement=false;
    _listBanc=new QStringList();
    _listPosition=new QStringList();
    RestaurerXML();



    ui->frame->setVisible(false);
    ui->frame_2->setVisible(false);
    ui->frame_3->setVisible(false);


    QPalette    palette( ui->centralWidget->palette());
    QPixmap        bg("Icone/Volleyclubstats_gris.png");

    palette.setBrush(QPalette::Background, bg);
    ui->centralWidget->setPalette(palette);


    _FenetreStat=new FenetreStat();
    _listActionMoins<<tr("Attaque")<<tr("Contre");
    _listActionPlus<<tr("Service")<<tr("Attaque")<<tr("Contre");



    this->_listAction=InitAction::donneInstance()->GetListAction();
    ui->tabWidget->setVisible(true);

}



void Ecran::InitialisationError()
{

    //ui->textEdit->setVisible(false);
    ui->menuBar->setEnabled(false);


    QMessageBox::information(this,tr("Licence invalide"),tr("Votre licence a expirer"));
}
*/
void Ecran::InitIhmMatch()
{
    QMenu * menupoint=new QMenu(this);
    menupoint->addAction("+1");
    menupoint->addAction("-1");
    ui->pBScore->setMenu(menupoint);
    connect(menupoint,SIGNAL(triggered(QAction *)),this,SLOT(SlotMenupoint1(QAction*)));
    QMenu * menupoint2=new QMenu(this);
    menupoint2->addAction("+1");
    menupoint2->addAction("-1");
    ui->pBScore_2->setMenu(menupoint2);
    connect(menupoint2,SIGNAL(triggered(QAction *)),this,SLOT(SlotMenupoint2(QAction*)));
    /// les parametre du match
    Match* MatchEncour=Match::donneInstance();
    ParametreMatch* param=MatchEncour->GetParametreMatch();
    QString advs=param->get_NomEquipeVisiteur();
    QString team=param->get_NomEquipeLocal();


    /// Placement des joueurs
   int nbjoueur= Match::donneInstance()->GetParametreMatch()->get_TotJoueur();
    _PlacementJoueur=new KeyJoueur(ui->label_4,nbjoueur,true);
    QHBoxLayout *layout=new QHBoxLayout();
    layout->addWidget (_PlacementJoueur);
    connect(this->_PlacementJoueur,SIGNAL(Changement(QPushButton*)),this,SLOT(slot_changement(QPushButton*)));
    connect(this->_PlacementJoueur,SIGNAL(JoueurStat(QPushButton*)),this,SLOT(slot_AfficheStat(QPushButton*)));
    connect(this->_PlacementJoueur,SIGNAL(Tlm_en_place()),this,SLOT(Slot_start()));


    ui->comboBox->addItems(param->get_Action());


    QPalette palette;
    palette.setColor(QPalette::Window ,QColor(167,167,167));
    ui->centralWidget->setPalette(palette);
    ui->frame->setVisible(true);
    ui->frame_2->setVisible(true);


    ui->label_4->setPixmap(QPixmap("Image/new_terrain.png"));
    this->_positionEcran=0;
    this->_PlacementJoueur->createLayout(0);

    palette.setColor(QPalette::Window ,QColor(0, 0, 255));


    palette.setColor(QPalette::Window ,QColor(34, 139, 34));


    ui->groupBox->setPalette(palette);
    ui->groupBox_2->setPalette(palette);
    //ui->groupBox_3->setPalette (palette);


    this->_PlacementJoueur->SetAdv(advs);

    ui->label_2->setText(advs);
    ui->label->setText(team);
    ui->pBScore->setText(QString::number(MatchEncour->GetScore()->get_ScLocal()));
    ui->pBScore_2->setText(QString::number(MatchEncour->GetScore()->get_ScVisiteur()));
    ui->pBSet->setText("0");
    ui->pBSet_2->setText("0");
    ui->comboBox->setEnabled(false);
    LineEdit2->setEnabled(false);

    ChangeBouton=new QPushButton(this);
    this->_PlacementJoueur->InitLineEditSize ();
    ui->label_5->setText(advs.toUpper());
    ui->label_3->setText(team.toUpper());
    ui->label_11->setText("");
    ui->label_12->setText("");

    _ListEvent = new ListEvenement(ui->groupBox_9);
    _ListEvent->setObjectName(QString::fromUtf8("listWidget"));
    ui->gridLayout_7->addWidget(_ListEvent, 0, 0, 1, 1);
    connect(_ListEvent,SIGNAL(add(int)),this,SLOT(slot_addEvent(int)));
    connect(_ListEvent,SIGNAL(modif(int)),this,SLOT(slot_ModifEvent(int)));
    connect(_ListEvent,SIGNAL(sup(int)),this,SLOT(slot_suppEvent(int)));
    this->_TimerScore->start(10);

    /// Initialisation efficacite
    QTabWidget* tabWidget = new QTabWidget(ui->tabWidget->widget(1));
    QString NomOnglet;
    for(int i=0;i<Match::donneInstance()->GetParametreMatch()->get_NbSet()+1;i++)
     {
         QWidget* tabelement=new QWidget();

         if(i==0)
         {
             NomOnglet="Match";
         }
         else
         {
             NomOnglet="Set n�"+QString::number(i);
         }
         tabWidget->addTab(tabelement,NomOnglet);
         _VectortabEff.append(new WidgetTabEff(tabelement));
     }
    ui->gridLayout_21->addWidget(tabWidget, 0, 0, 1, 1);

    /// initialisation tabAction
    for(int a=0;a<Match::donneInstance()->GetListAction().size();a++)
    {
        QWidget *CreerNouveauOnglet = new QWidget;
        QGridLayout *layout = new QGridLayout;
        layout->setContentsMargins(0,0,0,0);

        CreerNouveauOnglet->setLayout(layout);

        QString strlabel=Match::donneInstance()->GetListAction().at(a);
        ui->tabWidget->addTab(CreerNouveauOnglet,strlabel);

        QTabWidget* tabWidget = new QTabWidget(ui->tabWidget->widget(a+2));
         tabWidget->setObjectName(QString::fromUtf8("tabWidget_2"));
         for(int i=0;i<Match::donneInstance()->GetParametreMatch()->get_NbSet()+1;i++)
         {
             QWidget* tabelement=new QWidget();
             if(i==0)
             {
                 NomOnglet="Match";
             }
             else
             {
                 NomOnglet="Set n�"+QString::number(i);
             }
             tabWidget->addTab(tabelement,NomOnglet);
              _VectorTabFram.append(new FramStats(a,Match::donneInstance()->getTeam()->GetListeJoueur(),tabelement));
         }

         layout->addWidget(tabWidget, 0, 0, 1, 1);

         //CreerNouveauOnglet->

       //ui->tabWidget_2
    }


}

void Ecran::InitialisationMatchFromXML()
{

    /// relecture du fichier
    InitialisationFromXml();
    /// mise en place
    int debug=Match::donneInstance()->getTeam()->getStatMatch(0,0);
    InitIhmMatch();
    /// placement des joueurs
    Match * MatchEncour=Match::donneInstance();
    this->_PlacementJoueur->Placement(MatchEncour->GetListJoueurTerr());
    //this->JoueurBanc();
   // this->JoueurAPlacer();

    InitScore();

    LineEdit2->setFocus();
    this->LineEdit2->setCursorPosition(LineEdit2->text().size());
    ui->comboBox->setEnabled(true);
    LineEdit2->setEnabled(true);
    this->_isMatchEnCour=true;
    Slot_start();

}

void Ecran::InitialisationMatch()
{



//    _TimerScore->start(10);




    InitIhmMatch();

 Match * MatchEncour=Match::donneInstance();
    QStringList joueurname;

    this->_PlacementJoueur->InitListJoueur(MatchEncour->GetListJoueur());
    JoueurAPlacer();
    for(int i=0;i<MatchEncour->GetListJoueur().size();i++)
    {
        Joueur*joue= MatchEncour->GetListJoueur().at(i);

        QString strjoueur="";
        strjoueur=((QString("%1 ").arg(joue->get_NumMaillot())));
        if(strjoueur.size()==2)
            strjoueur="0"+strjoueur;
        strjoueur=strjoueur +"("+joue->get_Prenom()+")";
        if(joue->get_poste ().toUpper ()=="PASSE" || joue->get_poste().toUpper ()=="PASSEUR")
        {
            strjoueur=strjoueur+ "*";
        }
        else if(joue->get_poste().toUpper ()=="LIBERO")
        {
            strjoueur=strjoueur+ "$";
        }
        joueurname.append(strjoueur);
    }




    ui->groupBox_4->setVisible(true);
    ui->listWidget->setVisible(false);



}

void Ecran::InitScore()
{
    Score* score= Match::donneInstance()->GetScore();
    ui->label->setText(Match::donneInstance()->GetParametreMatch()->get_NomEquipeLocal());
    ui->label_2->setText(Match::donneInstance()->GetParametreMatch()->get_NomEquipeVisiteur());
    QString stScore;
    stScore=QString("%1").arg(score->get_ScLocal());
    ui->pBScore->setText(stScore);
    stScore=QString("%1").arg(score->get_ScVisiteur());
    ui->pBScore_2->setText(stScore);

    stScore=QString("%1").arg(score->get_SetLocal());
    ui->pBSet->setText(stScore);
    stScore=QString("%1").arg(score->get_SetVisiteur());
    ui->pBSet_2->setText(stScore);
    /// TODO Initialiser les temps morts
    //if(score->get_TmVisiteur())
}

void Ecran::slot_score()
{
    Score* score= Match::donneInstance()->GetScore();
    QString stScore;
    stScore=QString("%1").arg(score->get_ScLocal());
    ui->pBScore->setText(stScore);
    stScore=QString("%1").arg(score->get_ScVisiteur());
    ui->pBScore_2->setText(stScore);

    stScore=QString("%1").arg(score->get_SetLocal());
    ui->pBSet->setText(stScore);
    stScore=QString("%1").arg(score->get_SetVisiteur());
    ui->pBSet_2->setText(stScore);
    this->_TimerScore->start(50);
    int diff=abs(score->get_SetLocal()-score->get_ScVisiteur());
    int scoreMax=Match::donneInstance()->GetParametreMatch()->get_ScoreMax();
    if((score->get_ScLocal()>=scoreMax && diff>=2)
            ||((score->get_ScVisiteur()>=scoreMax)
               && (diff>=2))
            &&(_finSet==false))
    {
        this->_TimerScore->stop();

        int reponse=QMessageBox::question(this,tr("Information"),tr("Fin de set"),QMessageBox::Yes,QMessageBox::No);
        if(reponse==QMessageBox::Yes)
        {

            //_finSet=true;
            this->FinSet();

        }
        else
        {
        }

    }

}



void Ecran::slot_initChangement()
{
    if(ChangeJoueur!="")
    {
        ChangeJoueur="";
    }
    _TimerChange->stop();
}

void Ecran::Slot_start()
{


        Match::donneInstance()->SetJoueurTerr(_PlacementJoueur->GetJoueurTerrain());
        Match::donneInstance()->setStart(true);
        this->JoueurBanc();
        ui->label_4-> setPixmap (QPixmap("Image/new_terrain.png"));
        ui->frame_3->setVisible(true);
        ui->groupBox_4->setVisible(false);

        LineEdit2->setFocus();
        this->LineEdit2->setCursorPosition(LineEdit2->text().size());
        ui->comboBox->setEnabled(true);
        LineEdit2->setEnabled(true);
        //ui->groupBox_5->setVisible (true);
        ui->label_6->setVisible(false);
        ui->label_7->setVisible(false);
        ui->label_8->setVisible(false);
        ui->label_9->setVisible(false);

        //ui->pushButton_FM->setVisible(true);
        ui->pushButton_TM->setVisible(true);

        //ui->Start->setVisible (false);

        FenetreService * fenetre=new FenetreService(Match::donneInstance()->getTeam()->GetNom(),Match::donneInstance()->getadvs());
        fenetre->exec();

        if(fenetre->isUS()==true)
        {
            ActionService(0);
            Match::donneInstance()->GetScore()->set_Service(0);
        }
        else
        {
            ui->comboBox->setCurrentIndex(1);
            this->LineEdit2->ChangeBackColor(1);
            Match::donneInstance()->GetScore()->set_Service(1);
        }
        this->_PlacementJoueur->Start();
        ChercherPasseur();

        _isMatchEnCour=true;
        Match::donneInstance()->SetJoueurTerr(this->_PlacementJoueur->GetJoueurTerrain());
        QFile file("Current/Match.xml");
        if(!file.exists())
        {
           Match::donneInstance()->EcritureCurrentMatch();
        }

        _isMatchEnCour=true;

}
void Ecran::ChercherPasseur()
{
    this->_PlacementJoueur->ChercherJoueur(this->_currentposition);


}
void Ecran::slot_changement(QPushButton *boutton)
{
    changement(boutton->text(),boutton);
    Match::donneInstance()->SetJoueurTerr(this->_PlacementJoueur->GetJoueurTerrain());
    QString strjoueur=boutton->text();
    strjoueur=strjoueur.split("/n").at(0);
    strjoueur=strjoueur.replace(")","");
    QStringList lisstr=strjoueur.split("(");
    strjoueur=lisstr.at(1)+"_"+lisstr.at(0);
    Match::donneInstance()->AddJoueurToXml(Match::donneInstance()->RechercheJoueur(strjoueur));
}

void Ecran::SlotAddJoueur()
{
    if(Match::donneInstance()->getTeam()!=0)
    {
        fbjoueur* Diajoueur=new fbjoueur(Match::donneInstance()->getTeam(),0,this);
        if(Diajoueur)
        {
            this->AddJoueurBanc(Diajoueur->GetCurrentJoueur());
            this->EnregistrerXML();
        }

     }
}
void Ecran::SlotSupJoueur()
{
    QPushButton *boutton=(QPushButton*) sender();


    QStringList strlist=boutton->text().split("(");
    strlist=strlist[1].split(")");
    QList <Joueur*> listJoueur=Match::donneInstance()->GetListJoueur();
    for(int i=0;i<listJoueur.size();i++)
    {

        if (listJoueur.at(i)->get_Prenom()==strlist[0])
        {
            Match::donneInstance()->getTeam()->supJoueur(listJoueur.at(i));
            this->EnregistrerXML();
            boutton->deleteLater();
            slot_initChangement();
        }
    }


}

void Ecran::SlotModifJoueur()
{
    QPushButton *boutton=(QPushButton*) sender();
    QStringList strlist=boutton->text().split("(");
    strlist=strlist[1].split(")");
    QList <Joueur*> listJoueur=Match::donneInstance()->GetListJoueur();
    for(int i=0;i<listJoueur.size();i++)
    {

        if (listJoueur.at(i)->get_Prenom()==strlist[0])
        {

            int num=listJoueur.at(i)->get_NumMaillot();
            QString prenom=listJoueur.at(i)->get_Prenom();
           // joueur->Modif(listJoueur.at(i),true);
              fbjoueur* joueur=new fbjoueur(Match::donneInstance()->getTeam(),listJoueur.at(i),this);
            if(joueur->exec()==1)
            {
                /*if(num!=listJoueur.at(i)->get_NumMaillot() ||
                  prenom!=listJoueur.at(i)->get_Prenom()   )
                {

                }
                else
                {*/
                    QString text=this->_PlacementJoueur->UpdateJoueur(listJoueur.at(i));
                    boutton->setText(text);
                //}

                break;
            }
        }
    }

}

void Ecran::changement(QString joueur,QPushButton *bouton)
{
    QStringList listjou;
    listjou=joueur.split("\n");
    joueur=listjou.at(0);
    if(ChangeJoueur=="")
    {

        ChangeJoueur=joueur;
        ChangeBouton=bouton;
    }
    else
    {
        QString msg;
        msg=QString(tr("Changement Joueur %1 par")).arg(ChangeJoueur);
        msg=msg+joueur;
        msg=msg+" S:"+ui->pBScore->text()+"-"+ui->pBScore_2->text();
        //this->_trace->SetTrace(msg);
        _TimerChange->start(30000);
        ChangeBouton->setText(joueur);
        bouton->setText(ChangeJoueur);
        ChangeJoueur="";

        this->ChercherPasseur();
        if(ui->comboBox->currentText()==tr("Service"))
        {
            ActionService(0);
        }
        //this->_PlacementJoueur->Stat();

    }


}
void Ecran::Slot_ModifAction()
{
    /*QList<QListWidgetItem *> list=ui->listAction->selectedItems ();

    if(list.size()>1)
    {
        QMessageBox::warning(this,tr("Erreur"),tr("selectionner une seul ligne"));
        return;
    }
    else if(list.size()==0)
    {
        QMessageBox::warning(this,tr("Erreur"),tr("selectionner une ligne"));
        return;
    }

    else
    {
        QListWidgetItem* item=list.at (0);
        QString str=item->text ();
        QStringList list=str.split ("_");
        int num=list[0].toInt();
        int valeur;
        QString strval=list[2];
        if(strval=="++")
            valeur=0;
        else if(strval=="+0")
            valeur=1;
        else if(strval=="00")
            valeur=2;
        else if(strval=="-0")
            valeur=3;
        else if(strval=="--")
            valeur=4;

        int action;
        for(int i=0;i<_listActionMatch.size();i++)
        {
            if(_listActionMatch.at(i)==list [1])
            {
                action=i;
            }
        }

        for (int k=0;k<Match::donneInstance ()->GetListJoueur().size ();k++)
        {
            if(num==Match::donneInstance ()->GetListJoueur ().at(k)->get_NumMaillot ())
            {
                Match::donneInstance ()->GetListJoueur ().at(k)->supStatMatch (action,valeur);
                Match::donneInstance ()->GetListJoueur ().at(k)->supStatSet (action,valeur);
                Match::donneInstance ()->getTeam ()->supStatMatch (action,valeur);
                Match::donneInstance ()->getTeam ()->supStatSet (action,valeur);
            }
        }
        this->_WtabEff->SlotMiseAJour();

        emit SignalAction(num);
        FenetreModifAction *fenetre=new FenetreModifAction();
        fenetre->Initialisation(this->_listActionMatch,num,strval);
        if(fenetre->exec()==1)
        {
            QString newstr=fenetre->GetValeur();

        }
        //   delete item;

        emit SignalAction(num);
    }*/
}

void Ecran::Slot_SuppAction()
{
    /*QList<QListWidgetItem *> list=ui->listAction->selectedItems ();

    for (int i=0;i<list.size();i++)
    {
        QListWidgetItem* item=list.at (i);
        QString str=item->text ();
        QStringList list=str.split ("_");
        int num=list[0].toInt();
        int valeur;
        QString strval=list[2];
        if(strval=="++")
            valeur=0;
        else if(strval=="+0")
            valeur=1;
        else if(strval=="00")
            valeur=2;
        else if(strval=="-0")
            valeur=3;
        else if(strval=="--")
            valeur=4;

        int action;

        for(int i=0;i<_listActionMatch.size();i++)
        {
            if(_listActionMatch.at(i)==list [1])
            {
                action=i;
            }
        }
        if(valeur==0 &&this->_listActionPlus.contains(_listActionMatch.at(action)))
        {
            RetirerPoint(this->_PointForUs);
        }
        if(valeur==4 &&this->_listActionMoins.contains(_listActionMatch.at(action)))
        {
            RetirerPoint(this->_PointForUs);
        }

        for (int k=0;k<Match::donneInstance ()->GetListJoueur ().size ();k++)
        {
            if(num==Match::donneInstance ()->GetListJoueur ().at(k)->get_NumMaillot ())
            {
                Match::donneInstance ()->GetListJoueur ().at(k)->supStatMatch (action,valeur);
                Match::donneInstance ()->GetListJoueur ().at(k)->supStatSet (action,valeur);
                Match::donneInstance ()->getTeam ()->supStatMatch (action,valeur);
                Match::donneInstance ()->getTeam ()->supStatSet (action,valeur);
            }
        }
        delete item;
        this->_WtabEff->SlotMiseAJour();
        QString msg;
        msg=tr("Suppresion action ")+str;
        this->_trace->SetTrace(msg);
        emit SignalAction(num);

    }
*/

}
void Ecran::RetirerPoint(bool qui)
{
    if(qui==true)
    {
        Match::donneInstance()->GetScore()->set_ScLocal(Match::donneInstance()->GetScore()->get_SetLocal()-1);
    }
    else
    {
        Match::donneInstance()->GetScore()->set_ScVisiteur(Match::donneInstance()->GetScore()->get_ScVisiteur()-1);
    }
    QString msgTrace=tr("Annulation du point");
    _trace->SetTrace(msgTrace);
    int score1=Match::donneInstance()->GetScore()->get_SetLocal();
    int score2=Match::donneInstance()->GetScore()->get_ScVisiteur();
    QString Strscore1,Strscore2;
    Strscore1.setNum(score1);
    Strscore2.setNum(score2);
    msgTrace=tr(" Score:")+Strscore1+"-"+Strscore2;
    _trace->SetTrace(msgTrace,false);

}

void Ecran::SlotMenuEquipe(QAction *action)
{
    if(action->text()=="Gestion Equipes")
    {

        QDialog* equipe=new Fenetreequipe(this);

        equipe->exec();
        this->EnregistrerXML();
    }
    if(action->text()=="Gestion Club")
    {

    }
    else if(action->text()=="Exporter Equipe")
    {
       // QString file=QInputDialog::getText(this)
        FenetreVisualisation * choixEquipe=new FenetreVisualisation(this->GetListeEquipe(),1,this);
        if( choixEquipe->exec())
        {
        Equipe * team=choixEquipe->GetSelectedTeam();
        QString fichier = QFileDialog::getSaveFileName(this, tr("Enregistrer un fichier"), QString(), "*.csv");
        team->ExportCVS(fichier);
        }
    }
    else if(action->text()=="Importer Equipe")
    {
          FenetreVisualisation * choixEquipe=new FenetreVisualisation(this->GetListeEquipe(),2,this);
          if(choixEquipe->exec())
          {
          Equipe * team=choixEquipe->GetSelectedTeam();
          this->SetListeEquipe(choixEquipe->GetlistEquipe());
           QString fichier = QFileDialog::getOpenFileName(this, tr("fichier d'import"), QString(), "*.csv");
           team->ImportCVS(fichier);
          }

    }
}

void Ecran::Slot_Fenetre(QAction *action)
{
    if(action->text()=="Score")
    {
        FenetreScore* Fenetre=new FenetreScore();
        Fenetre->InitialiseIHMFromData();
        Fenetre->show();
    }
    else if(action->text()=="Resultat(ffvb)")
    {
        FenetreInternet* Fenetre=new FenetreInternet(this);
        Fenetre->show();
    }
    else if(action->text()=="Lecteur")
    {
        lecteurVideo * fenetrelect=new lecteurVideo(this);
        fenetrelect->show();
    }
}

void Ecran::AffSession(QAction *action)
{

  if(action->text() == "Lancer le Match")
    {
        Match* play=Match::donneInstance();
        QFile file("Current/Match.xml");
        if(file.exists())
        {
            InitialisationMatchFromXML();
        }
        else
        {
        Match::donneInstance();
        FenetreLancement* lance=new FenetreLancement(this->_ListeEquipe);
        if(lance->exec())
        {
            InitialisationMatch();
            ui->actionRevoir_un_match->setEnabled(false);
            ui->actionGestion_Equipes->setEnabled(false);
            ui->actionLancer_le_Match->setEnabled(false);
        }

    }
  }
    else if(action->text ().toUpper ()=="REVOIR UN MATCH")
    {
        _FenetreChoix=new FenetreChoixMatch(this);
        if(_FenetreChoix->Ouvrir ())
        {
            //QMessageBox::information (this,"Info",_FenetreChoix->GetFichierSelectionner ());
            QString file=_FenetreChoix->GetFichierSelectionner ();
            if(file!="")
            {
                this->_FenetreStat->Initialisation(file);
            }

        }


    }
    else if(action->text()=="Quitter")
    {
        this->close();
    }

}


void Ecran::RestaurerXML()
{
    QFile file("Equipes.xml");
    QDomDocument doc;
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file))
    {
        file.close(); // �tablit le document XML � partir des donn�es du fichier (hi�rarchie, etc.)
        return;
    }
    file.close();

    QDomElement racine = doc.documentElement(); // renvoie la balise racine
    QDomNode noeud = racine.firstChild(); // renvoie la premi�re balise � mesure �
    while(!noeud.isNull())
    {
        Equipe* Team=new Equipe();
        Team->RestaurerXML(noeud);
        this->_ListeEquipe.append(Team);
        noeud=noeud.nextSibling();
    }
}

void Ecran::EnregistrerXML()
{

    QDomDocument doc("Equipes");
    QDomNode noeud=doc.createProcessingInstruction ("xml","version=\"1.0\" encoding=\"ISO-8859-1\" standalone=\"yes\"");
    doc.insertBefore (noeud,doc.firstChild ());
    QDomElement root = doc.createElement("root");
    doc.appendChild(root);

    for(int i=0;i<_ListeEquipe.count();i++)
    {
        Equipe* team=_ListeEquipe.at(i);
        team->EnregistrerXML(doc,root);
    }


    QFile file("Equipes.xml");
    if (!file.open(QIODevice::WriteOnly))
        return;
    QTextStream ts( &file );
    ts << doc.toString();
    file.close();
}

QList <Equipe*> Ecran::GetListeEquipe()
{
    return _ListeEquipe;
}
void Ecran::SetListeEquipe(QList <Equipe*> list)
{
    _ListeEquipe=list;
}

void Ecran::AddEquipe(Equipe* team)
{
    _ListeEquipe.append(team);
}

void Ecran::SupEquipe(Equipe* Team)
{
    for(int i=0;i<_ListeEquipe.count();i++)
    {
        if(_ListeEquipe.at(i)->GetNom()==Team->GetNom())
        {
            _ListeEquipe.removeAt(i);
            break;
        }
    }
}


void Ecran::slot_rotationP()
{
    Rotation();
}

void Ecran::slot_rotationM()
{

    _PlacementJoueur->RotationM(this->_currentposition);

    int joueur;
    _PlacementJoueur->ChercherJoueur(joueur);
}

void Ecran::score()
{
    if(_Bchangement==true)
    {
        _Bchangement=false;
        Rotation();
    }
}
void Ecran::scoreadv()
{
    _Bchangement=true;
}

void Ecran::Rotation()
{
    this->_PlacementJoueur->Rotation(this->_currentposition);
    //int joueur;
    //_PlacementJoueur->ChercherJoueur(this->_currentposition);

    ActionService(0);


}




void Ecran::AfficherTrace(QString message)
{
    //ui->textEdit->append(message);

}





void Ecran::TempsMort()
{
    FenetreService * fenetre=new FenetreService(Match::donneInstance()->getTeam()->GetNom(),Match::donneInstance()->getadvs(),true);
    fenetre->exec();
    QString nom;
    if(fenetre->isUS()==true)
    {
        if(ui->label_6->isVisible()==true)
        {
            QMessageBox::information(this,tr("Information"),tr("Tous les temps morts sont pris"));
            return;
        }
        if(ui->label_7->isVisible ()==true)
        {
            ui->label_6->setVisible (true);
        }
        else
            ui->label_7->setVisible (true);

        nom=Match::donneInstance()->getTeam()->GetNom();
    }
    else
    {
        if(ui->label_9->isVisible()==true)
        {
            QMessageBox::information(this,tr("Information"),tr("Tous les temps morts sont pris"));
            return;
        }
        if(ui->label_8->isVisible ()==true)
        {
            ui->label_9->setVisible (true);
        }
        else
            ui->label_8->setVisible (true);
        nom=Match::donneInstance()->getadvs();
    }
    LineEdit2->setFocus();
    LineEdit2->setCursorPosition(LineEdit2->text().size());
    QString msg=tr("Temps mort pour ")+nom;
    //this->_trace->SetTrace(msg);
}


void Ecran::FinSet()
{

    Match::donneInstance()->FinSet();
    _TimerScore->start(10);
}

void Ecran::FinMatch()
{
    if(QMessageBox::question(this,tr("Fin de match"),tr("Voulez vous quitter le match"),QMessageBox::Ok,QMessageBox::Cancel)==QMessageBox::Ok)
    {


    }

}

void Ecran::keyPressEvent(QKeyEvent * event)
{
    bool isValide=false;

    if((event->key()==Qt::Key_Enter) ||
            (event->key()==Qt::Key_Return) &&
            (_isMatchEnCour == true))
    {

        QString strValue=LineEdit2->text();
        QString strTemp;
        QString  valide;
        bool ok=false;
        int index=0;
        int max=0;
        if( (strValue.size() < 5) &&
                (strValue.size() > 0))
        {
            switch (strValue.size())
            {
            case 1:
                if(LineEdit2->text()==".")
                {


                    LineEdit2->clear();
                    index=ui->comboBox->currentIndex();
                    max=ui->comboBox->count();
                    if(index!=max-2)
                    {
                        ui->comboBox->setCurrentIndex(index+1);
                        this->LineEdit2->ChangeBackColor(index+1);
                    }
                    else
                    {
                        ui->comboBox->setCurrentIndex(0);
                        this->LineEdit2->ChangeBackColor(0);
                    }
                }
                else
                {
                    QMessageBox::warning(this,tr("erreur de saisi"),tr("Attention ligne non valide"));
                    isValide=false;
                }

                break;
            case 2:
                strValue="0"+strValue+"0";
                valide=strValue.right(2);
                valide.chop(1);
                if(valide=="0"||valide=="+"||valide =="-")
                {
                    isValide=true;
                }
                else
                {

                    QMessageBox::warning(this,tr("erreur de saisi"),tr("Attention ligne non valide"));
                    LineEdit2->clear();
                    isValide=false;
                }
                break;
            case 3:
                strTemp =strValue;
                strTemp.chop(1);
                strTemp.toInt(&ok);
                if(ok==true)
                    strValue=strValue+"0";
                else
                    strValue="0"+strValue;
                isValide=true;
                break;
            case 4:
                strTemp =strValue;
                strTemp.chop(2);
                strTemp.toInt(&ok);
                if(ok==false)
                {
                    QMessageBox::warning(this,tr("erreur de saisi"),tr("Attention ligne non valide"));
                    isValide=false;
                }
                else
                    isValide=true;
                break;
            }

        }
        else
        {
            QMessageBox::warning(this,tr("erreur de saisi"),tr("Attention ligne non valide"));
            isValide=false;
        }
        if(isValide==true)
        {
            isValide=false;
            if(this->_flagsup==true)
            {
                /*for(int i=ui->listAction->count ();i>=0;i--)
                {
                    QListWidgetItem* item=ui->listAction->takeItem (i);
                    delete item;
                }
                this->_flagsup=false;*/
            }
            LineEdit2->clear();
            QString strNumPlayer=strValue.left(2);
            if(strNumPlayer.toInt()!=0)
            {
                for(int i=0;i<Match::donneInstance ()->GetListJoueur ().size ();i++)
                {
                    int num=strNumPlayer.toInt ();
                    if(num==Match::donneInstance ()->GetListJoueur ().at (i)->get_NumMaillot ())
                    {
                        isValide=true;
                        break;
                    }
                }
            }
            else
            {
                isValide=true;
            }

            if(isValide==true)
            {
                QString value=strValue.right(2);
                SetAction(strNumPlayer,value);
            }
            else
            {
                QMessageBox::warning(this,tr("erreur de saisi"),tr("Attention Joueur non valide"));
                isValide=false;
            }
        }

    }
    if(ui->comboBox->currentText()==tr("Passe"))
    {
        Actionpasse();
    }
}

void Ecran::SetAction(QString numjoueur,QString ValeurAction)
{
    QString Action=ui->comboBox->currentText();
    int
            IAction=ui->comboBox->currentIndex();
    int position=1;
    QString strPosition;
    StatValeur StatAction=V0;
    QStringList listActionMatch=Match::donneInstance()->GetListAction();


    if(ValeurAction== "++")
    {
        StatAction=VPP;
    }
    else if (ValeurAction== "+0")
    {
        StatAction=VP;
    }
    else if (ValeurAction== "00")
    {
        StatAction=V0;
    }
    else if (ValeurAction== "-0")
    {
        StatAction=VM;
    }
    else if (ValeurAction== "--")
    {
        StatAction=VMM;
    }

    //Ajout des Stats
    bool error=Match::donneInstance()->AddAction(numjoueur,position,StatAction,IAction);
    if(error==true)
    {
        QMessageBox::warning(this,tr("Erreur"),tr("Probleme joueur"));
    }
    else
    {
        //QString msgTrace=numjoueur+" "+_listAction.at(IAction)+" "+ValeurAction+" "+strPosition;

        QString MsgAction;
        QString MsgEvent;
        QString MsgSet;
        QString MsgPos;
        MsgSet=MsgSet.setNum(_currentSet);
        MsgPos=MsgPos.setNum(_currentposition);
        MsgAction=MsgSet+"_"+MsgPos+"_"+numjoueur+"_"+Match::donneInstance()->GetParametreMatch()->get_Action().at(IAction)+"_"+ValeurAction;
        MsgEvent=numjoueur+" "+Match::donneInstance()->GetParametreMatch()->get_Action().at(IAction)+" "+ValeurAction;

        //_trace->SetTrace(msgTrace);
        //this->_TraceListAction->SetTrace(MsgAction);
        this->_ListEvent->addItem(MsgEvent);
        //ui->listAction->addItem (MsgAction);
        int i=ui->tabWidget->currentIndex();
        int numSet=Match::donneInstance()->GetParametreMatch()->GetNumSet();
        if(i==1)
        {
            this->_VectortabEff.at(0)->SlotMiseAJour();
            this->_VectortabEff.at(1)->SlotMiseAJour(true,numSet);
        }
        else if(i>1)
        {

                int num=(i-2)*(Match::donneInstance()->GetParametreMatch()->get_NbSet()+1);
                int numAcSet=num+numSet;
                _VectorTabFram.at(num)->SlotMiseAJour();
                _VectorTabFram.at(numAcSet)->SlotMiseAJour(true,numSet);


        }

        this->_PlacementJoueur->Stat();
    }

    //Algo de suivi des actions
    //Service;Defence;Passe;Attaque;Defence;Passe;Attaque

    IAction=listActionMatch.size()-1;
    for(int k=0;k<listActionMatch.size();k++)
    {
        if(Action==listActionMatch.at(k))
        {
            IAction=k;
            break;
        }

    }
    if(IAction==0)
    {

        // ui->comboBox->setCurrentIndex(2);
        // this->LineEdit2->ChangeBackColor(2);
        for(int i=0;i<ui->comboBox->count();i++)
        {
            if(ui->comboBox->itemText(i)==Match::donneInstance()->GetListAction().at(2))
            {
                ui->comboBox->setCurrentIndex (i);
                this->LineEdit2->ChangeBackColor(i);
                break;
            }
        }
    }
    else if(IAction==1)
    {
        if(listActionMatch.contains (tr("Passe")))
        {
            //ui->comboBox->setCurrentIndex (this->_listActionMatch.size()-2);
            //this->LineEdit2->ChangeBackColor(this->_listActionMatch.size()-2);

            for(int i=0;i<ui->comboBox->count();i++)
            {
                if(ui->comboBox->itemText(i)==listActionMatch.at(listActionMatch.size()-2))
                {
                    ui->comboBox->setCurrentIndex (i);
                    this->LineEdit2->ChangeBackColor(i);
                    break;
                }
            }
        }

        else
        {
            for(int i=0;i<ui->comboBox->count();i++)
            {
                if(ui->comboBox->itemText(i)==listActionMatch.at(listActionMatch.size()-1))
                {
                    ui->comboBox->setCurrentIndex (i);
                    this->LineEdit2->ChangeBackColor(i);
                    break;
                }
            }



        }
    }
    else if(IAction==listActionMatch.size()-1)
    {
        // ui->comboBox->setCurrentIndex(2);
        // this->LineEdit2->ChangeBackColor(2);
        for(int i=0;i<ui->comboBox->count();i++)
        {
            if(ui->comboBox->itemText(i)==listActionMatch.at(2))
            {
                ui->comboBox->setCurrentIndex (i);
                this->LineEdit2->ChangeBackColor(i);
                break;
            }
        }
    }
    else
    {
        for(int i=0;i<ui->comboBox->count();i++)
        {
            if(ui->comboBox->itemText(i)==listActionMatch.at(IAction+1))
            {
                ui->comboBox->setCurrentIndex (i);
                this->LineEdit2->ChangeBackColor(i);
                break;
            }
        }
        //ui->comboBox->setCurrentIndex(IAction+1);
        //this->LineEdit2->ChangeBackColor(IAction+1);
    }
    //Reception;Passe;Attaque;Defence;Passe

    //Algo suivi du score

    if(StatAction== VMM)
        PointMoins(numjoueur);
    if(_listActionMoins.contains(listActionMatch.at(IAction)) &&StatAction==VM)
    {
        PointMoins(numjoueur);
    }

    if(_listActionPlus.contains(listActionMatch.at(IAction))
            && StatAction== VPP)
    {
        this->PointPlus(numjoueur);
    }

    /// Apparition de la deuxieme bar de saisi sur reception + ou ++
    if(StatAction==VP || StatAction==VPP &&
            ui->comboBox->currentText()==tr("Attaque"))

    {
        //ui->lineEdit_PBP->setVisible(false);
    }
    int num=numjoueur.toInt();
    SignalAction(num);
}

void Ecran::PointPlus(QString numjoueur)
{

    if(numjoueur=="00")
    {
        //ui->spinBox_2->setValue(ui->spinBox_2->value()+1);
        ui->comboBox->setCurrentIndex(1);
        this->LineEdit2->ChangeBackColor(1);
        emit ScorePlus(0);
        _PointForUs=false;
        _flagsup=true;

    }
    else
    {
        //ui->spinBox->setValue(ui->spinBox->value()+1);
        ui->comboBox->setCurrentIndex(0);
        this->LineEdit2->ChangeBackColor(0);
        emit ScorePlus(1);
        _flagsup=true;
        _PointForUs=true;

    }
    //this->_WtabEff->SlotMiseAJour();
    //this->myWidget->Resize();
    this->AfficherStat();
}

void Ecran::PointMoins(QString numjoueur)
{
    if(numjoueur=="00")
    {

        ui->comboBox->setCurrentIndex(0);
        this->LineEdit2->ChangeBackColor(0);
        emit ScorePlus(1);
        _PointForUs=true;
        Match::donneInstance()->addFaute(true);
        Match::donneInstance()->addPoint();
    }
    else
    {
        ui->comboBox->setCurrentIndex(1);
        this->LineEdit2->ChangeBackColor(1);
        emit ScorePlus(0);
        _PointForUs=false;
        Match::donneInstance()->addFaute();
        Match::donneInstance()->addPoint(true);
    }
    //this->myWidget->Resize();
    //this->AfficherStat();
}

void Ecran::ActionService(int position)
{
    if(position==0)
    {
        QString stString=this->_PlacementJoueur->GetServeur();
        QStringList list=stString.split(" (");
        LineEdit2->setText(list[0]);
        LineEdit2->setFocus();
        this->LineEdit2->setCursorPosition(LineEdit2->text().size());
    }
    else
    {
        LineEdit2->clear();
        LineEdit2->setFocus();
        LineEdit2->setCursorPosition(LineEdit2->text().size());
    }
    LineEdit2->ChangeBackColor(0);
}
void Ecran::Actionpasse()
{
    QString strPasse;
    strPasse=this->_PlacementJoueur->ChercherPasseur();
    QStringList listPasse=strPasse.split(" (");
    LineEdit2->setText(listPasse[0]);
    LineEdit2->setFocus();
    LineEdit2->setCursorPosition(LineEdit2->text().size());
}

void Ecran::SlotDrag(QListWidgetItem* item)
{
    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;


    mimeData->setText(item->text());
    drag->setMimeData(mimeData);
    drag->start();
}

void Ecran::dragEnterEvent(QDragEnterEvent* event)
{
    if (event->mimeData()->hasFormat("text/plain")) {
        event->acceptProposedAction();
    }

}

void Ecran::dropEvent(QDropEvent* event)
{

    QString text;
    //int id_elt;



    text = event->mimeData()->text();
    if(this->_PlacementJoueur->SetLineEdit(event)==true)
    {

        /*for(int i=0;i<ui->listJoueur->count();i++)
        {
            if(ui->listJoueur->item(i)->text()==text)
            {
                delete ui->listJoueur->item(i);
            }
        }
        ui->listJoueur->sortItems(Qt::AscendingOrder);
    */
    }
    event->acceptProposedAction();

}


void Ecran::Slot_Scoreplus(int position)
{

    if(position!=0)
    {

        Match::donneInstance()->GetScore()->set_ScLocal(Match::donneInstance()->GetScore()->get_ScLocal()+1);

        this->_flagsup=true;
        this->ActionService (0);

    }
    else
    {

        Match::donneInstance()->GetScore()->set_ScVisiteur(Match::donneInstance()->GetScore()->get_ScVisiteur()+1);
        ui->comboBox->setCurrentIndex(1);
        this->LineEdit2->ChangeBackColor(1);
        this->_flagsup=true;
    }

    QString msgTrace;
    int score1=Match::donneInstance()->GetScore()->get_ScLocal();
    int score2=Match::donneInstance()->GetScore()->get_ScVisiteur();
    QString Strscore1,Strscore2;
    Strscore1.setNum(score1);
    Strscore2.setNum(score2);

    msgTrace=" Score:"+Strscore1+"-"+Strscore2;
    //_trace->SetTrace(msgTrace,false);
    Match::donneInstance()->MiseajourScore();
}

void Ecran::SetTactile (bool valeur)
{
    this->_Istactile=valeur;
}


void Ecran::Slot_PplusL()
{
    Match::donneInstance()->GetScore()->set_ScLocal(Match::donneInstance()->GetScore()->get_ScLocal()+1);
    Match::donneInstance()->MiseajourScore();
}
void Ecran::Slot_PplusA()
{
    Match::donneInstance()->GetScore()->set_ScVisiteur(Match::donneInstance()->GetScore()->get_ScVisiteur()+1);
    Match::donneInstance()->MiseajourScore();
}

void Ecran::Slot_PmoinsL()
{
    int score=Match::donneInstance()->GetScore()->get_ScLocal()-1;
    Match::donneInstance()->GetScore()->set_ScLocal(score);
}

void Ecran::Slot_PmoinsA()
{
    Match::donneInstance()->GetScore()->set_ScVisiteur(Match::donneInstance()->GetScore()->get_ScVisiteur()-1);
    Match::donneInstance()->MiseajourScore();}

void Ecran::Slot_RotTerrain()
{
    this->_positionEcran=_positionEcran+1;
    if(_positionEcran==4)
        _positionEcran=0;
    switch(_positionEcran)
    {
    case 0:
        ui->label_4->setPixmap (QPixmap("Image/terrain5.png"));
        break;
    case 1:
        ui->label_4-> setPixmap (QPixmap("Image/terrain1.png"));

        break;
    case 2:
        ui->label_4-> setPixmap (QPixmap("Image/terrain2.png"));
        break;

    case 3:
        ui->label_4-> setPixmap (QPixmap("Image/terrain3.png"));
        break;
    }
    this->_PlacementJoueur->createLayout(_positionEcran);

    this->_PlacementJoueur->ChercherJoueur(this->_currentposition);
    this->ActionService(0);

    // ui->label_4
}

void Ecran::SlotCombobox()
{
    LineEdit2->clear();
    int index=ui->comboBox->currentIndex();
    int max=ui->comboBox->count();
    if(index!=max-1)
    {
        index=index+1;
        ui->comboBox->setCurrentIndex(index);

    }
    else
    {
        index=0;
        ui->comboBox->setCurrentIndex(0);
    }
    this->LineEdit2->ChangeBackColor(index);
}

void Ecran::Slot_posAction()
{
    SautAction(tr("Attaque"));
}

void Ecran::Slot_posService()
{
    SautAction(tr("Service"));
}

void Ecran::Slot_posReception()
{
    SautAction(tr("R�c�ption"));
}
void Ecran::Slot_posContre()
{
    SautAction(tr("Contre"));
}

void Ecran::Slot_posPasse()
{
    SautAction(tr("Passe"));
}

void Ecran::Slot_posDefense()
{
    SautAction(tr("D�fense"));
}
void Ecran::Slot_ComplAction()
{
    /*if(ui->lineEdit_PBP->isVisible())
    {
        ui->lineEdit_PBP->setFocus();
    }*/
}

void Ecran::SautAction(QString str)
{
    QString text=this->LineEdit2->text ();
    for(int i=0;i<ui->comboBox->count ();i++)
    {
        if(ui->comboBox->itemText (i)==str)
        {
            ui->comboBox->setCurrentIndex (i);
            this->LineEdit2->ChangeBackColor(i);
        }
    }
    this->LineEdit2->setText (text);
    this->LineEdit2->setCursorPosition (text.size ());
}

void Ecran::JoueurAPlacer()
{
    ui->pushButton_7->setVisible(false);
    //ui->pushButton_8->setVisible(false);
    QList <Joueur*> listJoueur=Match::donneInstance()->GetListJoueur();
    for(int i=0;i<listJoueur.size();i++)
    {
        QString strAffiche;
        strAffiche.setNum(listJoueur.at(i)->get_NumMaillot());
        strAffiche=strAffiche+" ("+listJoueur.at(i)->get_Prenom()+")";
        if( listJoueur.at(i)->get_poste().toUpper ()=="PASSEUR")
        {
            strAffiche=strAffiche+ "*";
        }
        else if(listJoueur.at(i)->get_poste().toUpper ()=="LIBERO")
        {
            strAffiche=strAffiche+ "$";
        }
        BouttonJoueur* pushButton = new BouttonJoueur(strAffiche,ui->groupBox_4);

        pushButton->setGeometry(QRect(10, 60, 75, 23));
        ui->gridLayout_18->addWidget(pushButton, i, 0, 1, 1);
        connect(pushButton,SIGNAL(lclicked()),this,SLOT(bouttonLClicked()));
    }

}


void Ecran::JoueurBanc()
{

    QList <Joueur*> listJoueur=Match::donneInstance()->GetListJoueur();
    QList <Joueur*> listJoueurTerrain=Match::donneInstance()->GetListJoueurTerr();
    for(int i=0;i<listJoueur.size();i++)
    {
        if(listJoueurTerrain.contains(listJoueur.at(i)))
        {

        }
        else
        {
            AddJoueurBanc(listJoueur.at(i));
        }
    }

}

void Ecran::bouttonLClicked()
{
    QPushButton *button=(QPushButton*) sender();
    emit Changement (button);
}
void Ecran::closeEvent(QCloseEvent * event )
{
    // this->FinMatch();

    if(Match::GetInstance ()!=0)
    {
        //_trace->SetTrace(tr("Fin Match"));
       // QString  file=Match::donneInstance ()->GetFichierXml();
       // Match::donneInstance ()->FinSet ();
       // Match::donneInstance ()->Enregistrer ();
       // Match::donneInstance ()->EnregistrerXMl ();
    }
}

void Ecran::SlotButonRclicked()
{
    QPushButton *boutton=(QPushButton*) sender();

    boutton->showMenu();

}

void Ecran::AddJoueurBanc(Joueur* joueur)
{
    QString strAffiche;
    strAffiche.setNum(joueur->get_NumMaillot());
    strAffiche=strAffiche+" ("+joueur->get_Prenom()+")";
    if( joueur->get_poste().toUpper ()=="PASSEUR")
    {
        strAffiche=strAffiche+ "*";
    }
    else if(joueur->get_poste().toUpper ()=="LIBERO")
    {
        strAffiche=strAffiche+ "$";
    }
    BouttonJoueur* pushButton = new BouttonJoueur(strAffiche,ui->groupBox_10);
    pushButton->AjouterMenuBanc();
    pushButton->setGeometry(QRect(10, 60, 75, 23));
    ui->gridLayout_22->addWidget(pushButton, 0, _joueurBanc, 1, 1);
    connect(pushButton,SIGNAL(lclicked()),this,SLOT(bouttonLClicked()));
    connect(pushButton,SIGNAL(rclicked()),this,SLOT(SlotButonRclicked()));
    connect(pushButton,SIGNAL(ModifJoueur()),this,SLOT(SlotModifJoueur()));
    connect(pushButton,SIGNAL(AddJoueur()),this,SLOT(SlotAddJoueur()));
    connect(pushButton,SIGNAL(SupJoueur()),this,SLOT(SlotSupJoueur()));
    connect(pushButton,SIGNAL(AfficheStat()),this,SLOT(slot_Stat()));
    _joueurBanc++;
}

void Ecran::UpdateTabVue(int tab)
{
    int numSet=Match::donneInstance()->GetParametreMatch()->GetNumSet();
    switch(tab)
    {
    case 0:
        break;
    case 1:
        _VectortabEff.at(0)->clean();
        _VectortabEff.at(numSet)->clean();
        _VectortabEff.at(0)->Init();
        _VectortabEff.at(numSet)->Init();
        break;
    default:
        int num=(tab-2)*(Match::donneInstance()->GetParametreMatch()->get_NbSet()+1);
        int numAcSet=num+numSet;
        FramStats *currentfram=_VectorTabFram.at(num);
        currentfram->clean();
        currentfram->Init();
        FramStats *currentframSet=_VectorTabFram.at(numAcSet);
        currentframSet->clean();
        currentframSet->Init();

        break;
    }
}

void Ecran::slot_Stat()
{
    QPushButton* boutton=(QPushButton*) sender();
    this->slot_AfficheStat(boutton);
}

void Ecran::slot_AfficheStat(QPushButton * boutton)
{
    if(boutton==0)
    {
       boutton=(QPushButton*) sender();
    }
    QStringList strlist=boutton->text().split("(");
    if(strlist[0].toInt()==0)
    {
        FenetreJoueurStat* fstat=new FenetreJoueurStat(0,Match::donneInstance()->GetEquipeVisiteur(),this);
        fstat->show();
    }
    else
    {
    strlist=strlist[1].split(")");
    QList <Joueur*> listJoueur=Match::donneInstance()->GetListJoueur();
    for(int i=0;i<listJoueur.size();i++)
    {

        if (listJoueur.at(i)->get_Prenom()==strlist[0])
        {

            FenetreJoueurStat* fstat=new FenetreJoueurStat(listJoueur.at(i),0,this);
            fstat->show();


        }
    }
}
}

void Ecran::SlotMenupoint1(QAction * action)
{
    if(action->text()=="+1")
    {
        this->Slot_PplusL();
    }
    else if (action->text()=="-1")
    {
        this->Slot_PmoinsL();
    }
}

void Ecran::slot_UpdateListEvent()
{

}

void Ecran::SlotMenupoint2(QAction * action)
{
    if(action->text()=="+1")
    {
        this->Slot_PplusA();
    }
    else if (action->text()=="-1")
    {
        this->Slot_PmoinsA();
    }
}

void Ecran::AfficherStat()
{
    QString equipe=0;
    QString adv=0;
    Match * currentM=Match::donneInstance();
    Equipe * currentT=currentM->getTeam();
    for(int i=0;i<InitAction::donneInstance()->GetSizeAction();i++)
    {
        QString element=InitAction::donneInstance()->GetElementAction(i);
        element.truncate(1);
        //equipe=equipe+element+" "+QString::number(currentT->getStatMatch(i,0))+" | ";

    }
    equipe=equipe+"Point "+QString::number(currentM->GetPoint())+" | ";
     equipe=equipe+"Faute_Adv "+QString::number(currentM->GetFaute(true));
    ui->label_11->setText(equipe);

    for(int k=0;k<currentT->GetListeJoueur().size();k++)
    {
        if(currentT->GetListeJoueur().at(k)->get_NumMaillot()==0)
        {
            Joueur* adversaire=currentT->GetListeJoueur().at(k);
            for(int i=0;i<InitAction::donneInstance()->GetSizeAction();i++)
            {
                QString element=InitAction::donneInstance()->GetElementAction(i);
                element.truncate(1);
                adv=adv+element+" "+QString::number(adversaire->getStatMatch(i,0))+" | ";

            }
            adv=adv+"Point "+QString::number(currentM->GetPoint(true))+" | ";
            adv=adv+"Faut_Adv "+QString::number(currentM->GetFaute());

            ui->label_12->setText(adv);
        }
    }
}

void Ecran::slot_addEvent(int i)
{
    QStringList numero;
    QStringList valeur;
    for(int i=0;i<Match::donneInstance()->GetListJoueur().size();i++)
    {
        numero.append(QString::number(Match::donneInstance()->GetListJoueur().at(i)->get_NumMaillot()));
    }
    valeur<<"++"<<"+0"<<"00"<<"-0"<<"--";
    FenetreModifEvenement fenModif(numero,_ListActionInit->GetListAction(),valeur,this);
    if(fenModif.exec()==1)
    _ListEvent->insertItem(i,fenModif.ReturnText());
}

void Ecran::slot_ModifEvent(int i)
{
    QStringList numero;
    QStringList valeur;
    for(int i=0;i<Match::donneInstance()->GetListJoueur().size();i++)
    {
        numero.append(QString::number(Match::donneInstance()->GetListJoueur().at(i)->get_NumMaillot()));
    }
    valeur<<"++"<<"+0"<<"00"<<"-0"<<"--";
    FenetreModifEvenement fenModif(numero,_ListActionInit->GetListAction(),valeur,this);
    fenModif.Modif(this->_ListEvent->item(i)->text());
    if(fenModif.exec()==1)
        _ListEvent->item(i)->setText(fenModif.ReturnText());
}
void Ecran::slot_suppEvent(int i)
{
    delete _ListEvent->item(i);
}

void Ecran::InitialisationFromXml()
{
    Match::donneInstance()->GetInstance()->InfoFromXML( this->_ListeEquipe);

    //Match::donneInstance()->GetInstance()->InitFichierXml();
}

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






Ecran::Ecran(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::Ecran)
{

    ui->setupUi(this);
    _ValeurInitial=InitValeur::donneInstance();
    _position=0;
    _Istactile=false;
    _ischangement=false;
    _finSet=false;
    ui->lineEdit->setVisible(false);

    ui->lineEdit_PBP->setVisible(false);
    LineEdit2 =  new VCSLineEdit(ui->centralWidget);
    LineEdit2->setObjectName(QString::fromUtf8("lineEdit"));

    ui->gridLayout_11->addWidget(LineEdit2,2, 3, 1, 1);

    QDesktopWidget *desktop=QApplication::desktop ();
    QRect size=desktop->screenGeometry ();
    this->resize(size.width(),size.height()-100);
    this->move(0,0);

    _PlacementJoueur=new KeyJoueur(ui->label_4,12,true);
    QHBoxLayout *layout=new QHBoxLayout();
    layout->addWidget (_PlacementJoueur);
    connect(this->_PlacementJoueur,SIGNAL(Changement(QPushButton*)),this,SLOT(slot_changement(QPushButton*)));
    connect(this->_PlacementJoueur,SIGNAL(ModifPoste(QPushButton*)),this,SLOT(slot_modifpost(QPushButton*)));
    connect(this,SIGNAL(Changement(QPushButton*)),this,SLOT(slot_changement(QPushButton*)));
    connect(this->LineEdit2,SIGNAL(ChangeAction()),this,SLOT(SlotCombobox()));
    connect(this->LineEdit2,SIGNAL(Attaque()),this,SLOT(Slot_posAction()));
    connect(this->LineEdit2,SIGNAL(Reception()),this,SLOT(Slot_posReception()));
    connect(this->LineEdit2,SIGNAL(Service()),this,SLOT(Slot_posService()));
    connect(this->LineEdit2,SIGNAL(Defense()),this,SLOT(Slot_posDefense()));
    connect(this->LineEdit2,SIGNAL(Contre()),this,SLOT(Slot_posContre()));
    connect(this->LineEdit2,SIGNAL(Passe()),this,SLOT(Slot_posPasse()));
    connect(this->LineEdit2,SIGNAL(ComplementAction()),this,SLOT(Slot_ComplAction()));


    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Slot_PplusL()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Slot_PplusA()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(Slot_PmoinsL()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(Slot_PmoinsA()));

    //QMenu * menuservice=new QMenu();
    _isMatchEnCour=false;


    connect(ui->menuFichier, SIGNAL(triggered(QAction *)), this, SLOT(AffSession(QAction *)));
    connect(ui->menuMatch,SIGNAL(triggered(QAction*)),this,SLOT(AffSession(QAction*)));
    connect(ui->menuFenetre, SIGNAL(triggered(QAction *)), this, SLOT(Slot_Fenetre(QAction *)));
    _trace=new TraceLog(this);
    _TraceListAction= new ListActionXml();
    connect(this->_trace,SIGNAL(EnvoieTrace(QString)),this,SLOT(AfficherTrace(QString)));


    connect(ui->pushButton_TM,SIGNAL(clicked()),this,SLOT(TempsMort()));
    connect(ui->pushButton_FM,SIGNAL(clicked()),this,SLOT(FinMatch()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(FinSet()));
    connect(ui->pBSup,SIGNAL(clicked()),this,SLOT(Slot_SuppAction()));
    connect(ui->PBModif,SIGNAL(clicked()),this,SLOT(Slot_ModifAction()));

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(ActionService(int)));
    connect(ui->listJoueur,SIGNAL(itemPressed(QListWidgetItem*)),this,SLOT(SlotDrag(QListWidgetItem*)));

    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(Slot_RotTerrain()));
    //bouton de rotation

    connect (ui->pBRotationPlus,SIGNAL(clicked()),this,SLOT(slot_rotationP()));
    connect (ui->pBRotationMoins,SIGNAL(clicked()),this,SLOT(slot_rotationM()));

    ui->groupBox->setVisible(false);
    connect(ui->Start,SIGNAL(clicked()),this,SLOT(Slot_start()));
    ui->Start->setStyleSheet("color: white; background-color:orange; border-width: 1px; border-color: #339; border-style: solid;border-radius: 7;   padding: 3px; font-size: 14px;padding-left: 5px; padding-right: 5px;");


    _TimerChange = new QTimer (this);
    connect (_TimerChange,SIGNAL(timeout()),this,SLOT(slot_initChangement()));
    _TimerScore=new QTimer (this);
    connect (_TimerScore,SIGNAL(timeout()),this,SLOT(slot_score()));


    connect(this,SIGNAL(ScorePlus(int)),this,SLOT(Slot_Scoreplus(int)));



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
    connect(ui->Button_PP,SIGNAL(clicked()),this,SLOT(Slot_ActionPP()));
    connect(ui->Button_P,SIGNAL(clicked()),this,SLOT(Slot_ActionP()));
    connect(ui->Button_0,SIGNAL(clicked()),this,SLOT(Slot_Action0()));
    connect(ui->Button_M,SIGNAL(clicked()),this,SLOT(Slot_ActionM()));
    connect(ui->Button_MM,SIGNAL(clicked()),this,SLOT(Slot_ActionMM()));

    ui->Button_0->setVisible(false);
    ui->Button_M->setVisible(false);
    ui->Button_MM->setVisible(false);
    ui->Button_P->setVisible(false);
    ui->Button_PP->setVisible(false);
    ui->label_4->setPixmap (QPixmap("Image/terrain.png"));
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));


    ui->label_6->setPixmap((QPixmap("Icone/Yellow_card.png")));
    ui->label_7->setPixmap((QPixmap("Icone/Yellow_card.png")));
    ui->label_8->setPixmap((QPixmap("Icone/Yellow_card.png")));
    ui->label_9->setPixmap((QPixmap("Icone/Yellow_card.png")));

    ui->groupBox_4->setVisible(false);
    //ui->groupBox_10->setVisible(false);

    /// font d'ecran
    _positionEcran=0;


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
    //ui->widget->setVisible(false);
    //ui->widget_control->setVisible(false);
    ui->textEdit->setVisible(false);
    //ui->positionAdvers->setVisible(false);
    //ui->groupBoxAction->setVisible(false);

    ui->groupBox_2->setVisible(false);
    ui->groupBox_3->setVisible (false);
    ui->groupBox_6->setVisible(false);
    ui->groupBox_7->setVisible(false);
    LineEdit2->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->pushButton_FM->setVisible(false);
    ui->pushButton_TM->setVisible(false);
    ui->pushButton_6->setVisible(false);
    ui->Start->setVisible(false);
    //ui->groupBox_8->setVisible(true);
    // ui->groupBox_4->setVisible(false);
    //ui->groupBox_4->setVisible (false);
    ui->label_4->setVisible(false);

    QPalette    palette( ui->centralWidget->palette());
    QPixmap        bg("Icone/Volleyclubstats_gris.png");

    palette.setBrush(QPalette::Background, bg);
    ui->centralWidget->setPalette(palette);
    /*
    //ui->centralWidget->setStyleSheet ("background-image: url(Icone/Volleyclubstats_gris.png);");
    ui->centralWidget->setAutoFillBackground(true);*/

    _FenetreStat=new FenetreStat();
    _listActionMoins<<tr("Attaque")<<tr("Contre");
    _listActionPlus<<tr("Service")<<tr("Attaque")<<tr("Contre");


   // this->_listAction<<tr("Service")<<tr("Récéption")<<tr("Contre")<<tr("Défense")<<tr("Passe")<<tr("Attaque");
    ui->PBModif->setVisible(false);

}



void Ecran::InitialisationError()
{

    ui->textEdit->setVisible(false);
    ui->menuBar->setEnabled(false);


    QMessageBox::information(this,tr("Licence invalide"),tr("Votre licence a expirer"));
}

void Ecran::InitialisationMatch(QString team,QString advs)
{
    QPalette palette;
    _flagsup=false;
    _currentSet=1;

    palette.setColor(QPalette::Window ,QColor(167,167,167));
    ui->centralWidget->setPalette(palette);
    ui->textEdit->setVisible(true);
    ui->groupBox->setVisible(true);
    ui->label_4->setVisible(true);
    ui->groupBox_2->setVisible(true);
    ui->groupBox_4->setVisible(true);
    //ui->groupBox_3->setVisible (true);
    //ui->groupBox_6->setVisible(true);
    // ui->groupBox_7->setVisible(true);
    LineEdit2->setVisible(true);
    ui->comboBox->setVisible(true);

    ui->Start->setVisible(true);
    ui->label_4->setPixmap(QPixmap("Image/terrain.png"));
    this->_positionEcran=0;
    this->_PlacementJoueur->createLayout(0);
    _TimerScore->start(10);
    palette.setColor(QPalette::Window ,QColor(0, 0, 255));


    palette.setColor(QPalette::Window ,QColor(34, 139, 34));

    //ui->groupBoxAction->setPalette(palette);
    ui->groupBox->setPalette(palette);
    ui->groupBox_2->setPalette(palette);
    ui->groupBox_3->setPalette (palette);
    //ui->groupBox_4->setPalette(palette);

    //ui->positionAdvers->setVisible(true);
    //ui->positionAdvers->setText(advs);
    this->_PlacementJoueur->SetAdv(advs);

    ui->label_2->setText(advs);
    ui->label->setText(team);
    ui->pBScore->setText("0");
    ui->pBScore_2->setText("0");
    ui->pBSet->setText("0");
    ui->pBSet_2->setText("0");
    //ui->groupBoxAction->setVisible(true);
    ui->groupBox_2->setVisible(true);
    //ui->groupBox_3->setVisible (true);
    //ui->groupBox_4->setVisible (true);
    ui->groupBox_5->setVisible (false);

    _isMatchEnCour=false;
    //ui->comboBox->addItems(VolleyStats::GetListAction());
    //ui->textEdit_2->setVisible (false);


    QStringList joueurname;
    Match* MatchEncour=Match::donneInstance();
    QString strTrace="Match_"+MatchEncour->GetDate ();
    _trace->SetFile (strTrace);
    this->_TraceListAction->SetFile(strTrace);
    _trace->SetTrace("Debut du match");
    this->_TraceListAction->Debut();
    MatchEncour ->setAdvers(advs);
    //Match::donneInstance(this)->setCurrentEquipe(team);
    MatchEncour->getTeam()->SetListAction(this->_listAction);
    this->_PlacementJoueur->InitListJoueur(MatchEncour->getTeam()->GetListeJoueur());
    JoueurAPlacer();
    for(int i=0;i<MatchEncour->getTeam()->GetListeJoueur().size();i++)
    {
        Joueur*joue= MatchEncour->getTeam()->GetListeJoueur().at(i);
        joue->SetListAction(this->_listAction);
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
    ui->listJoueur->addItems(joueurname);
    ui->listJoueur->sortItems(Qt::AscendingOrder);
    delete ui->listJoueur->item(0);



    ui->comboBox->setEnabled(false);
    LineEdit2->setEnabled(false);
    //ui->positionAdvers->setEnabled(false);
    ChangeBouton=new QPushButton(this);
    // Initialisation de la fentre de stat
    this->myWidget->SetEquipe (MatchEncour->getTeam());
    this->_WtabEff->Init(MatchEncour->getTeam());
    this->myWidget->Initialisation ();
    this->myWidget->InitListAction(_listAction);
    this->_PlacementJoueur->InitLineEditSize ();



}

void Ecran::slot_score()
{
    Score* score= Match::donneInstance()->GetScore();
    QString stScore;
    stScore=QString("%1").arg(score->get_Score_E1());
    ui->pBScore->setText(stScore);
    stScore=QString("%1").arg(score->get_Score_E2());
    ui->pBScore_2->setText(stScore);

    stScore=QString("%1").arg(score->get_Set_E1());
    ui->pBSet->setText(stScore);
    stScore=QString("%1").arg(score->get_Set_E2());
    ui->pBSet_2->setText(stScore);
    this->_TimerScore->start(50);
    int diff=abs(score->get_Score_E1()-score->get_Score_E2());
    if((score->get_Score_E1()>=25 && diff>=2)
        ||(score->get_Score_E2()>=25 && diff>=2)
        &&_finSet==false)
        {
        this->_TimerScore->stop();

        int reponse=QMessageBox::question(this,tr("Information"),tr("Fin de set"),QMessageBox::Yes,QMessageBox::No);
        if(reponse==QMessageBox::Yes)
        {

            //_finSet=true;
            this->FinSet();

        }
        else
            ui->pushButton_6->setVisible(true);
    }

}

void Ecran::InitialisationAction(QStringList Action)
{
    this->_listActionMatch=Action;

}
/*void Ecran::InitialisationValeur(QStringList ValeurSelection)
{
    this->_listValeurStat=ValeurSelection;
}*/

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
    if(  _isMatchEnCour==false)
    {
        this->_PlacementJoueur->Initialisation();
        ui->label_4-> setPixmap (QPixmap("Image/terrain5.png"));
        ui->groupBox_3->setVisible(true);
        ui->groupBox_6->setVisible(true);
        ui->groupBox_7->setVisible(true);
        ui->groupBox_9->setVisible(true);
        ui->groupBox_4->setVisible(false);

        ui->groupBox_8->setVisible(false);
        ui->listAction->setVisible (true);
        ui->listAction->setSelectionMode (QAbstractItemView::MultiSelection);

        LineEdit2->setFocus();
        this->LineEdit2->setCursorPosition(LineEdit2->text().size());
        ui->comboBox->setEnabled(true);
        LineEdit2->setEnabled(true);
        ui->groupBox_5->setVisible (true);
        ui->label_6->setVisible(false);
        ui->label_7->setVisible(false);
        ui->label_8->setVisible(false);
        ui->label_9->setVisible(false);

        ui->pushButton_FM->setVisible(true);
        ui->pushButton_TM->setVisible(true);

        ui->Start->setVisible (false);

        FenetreService * fenetre=new FenetreService(Match::donneInstance()->getTeam()->GetNom(),Match::donneInstance()->getadvs());
        fenetre->exec();

        if(fenetre->isUS()==true)
        {
            ActionService(0);
            Match::donneInstance()->GetScore()->set_bool_adv(false);
        }
        else
        {
            ui->comboBox->setCurrentIndex(1);
            this->LineEdit2->ChangeBackColor(1);
            Match::donneInstance()->GetScore()->set_bool_adv(true);
        }
        this->_PlacementJoueur->Start();
        ChercherPasseur();

        _isMatchEnCour=true;
    }

}
void Ecran::ChercherPasseur()
{
    this->_PlacementJoueur->ChercherJoueur(this->_currentposition);


}
void Ecran::slot_changement(QPushButton *boutton)
{
    changement(boutton->text(),boutton);
}

void Ecran::slot_modifpost(QPushButton* boutton)
{
    fbjoueur* joueur=new fbjoueur(Match::donneInstance()->getTeam(),this);

    QStringList strlist=boutton->text().split("(");
    strlist=strlist[1].split(")");
    QList <Joueur*> listJoueur=Match::donneInstance()->getTeam()->GetListeJoueur();
    for(int i=0;i<listJoueur.size();i++)
    {

        if (listJoueur.at(i)->get_Prenom()==strlist[0])
        {


            joueur->Modif(listJoueur.at(i),true);
            if(joueur->exec()==1)
            {
            QString text=this->_PlacementJoueur->UpdateJoueur(listJoueur.at(i));
            boutton->setText(text);
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
        this->_trace->SetTrace(msg);
        _TimerChange->start(30000);
        ChangeBouton->setText(joueur);
        bouton->setText(ChangeJoueur);
        ChangeJoueur="";


    }

    this->ChercherPasseur();
    if(ui->comboBox->currentText()==tr("Service"))
    {
        ActionService(0);
    }
    this->_PlacementJoueur->Stat();
}
void Ecran::Slot_ModifAction()
{
    QList<QListWidgetItem *> list=ui->listAction->selectedItems ();

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

        for (int k=0;k<Match::donneInstance ()->getTeam ()->GetListeJoueur ().size ();k++)
        {
            if(num==Match::donneInstance ()->getTeam ()->GetListeJoueur ().at(k)->get_NumMaillot ())
            {
                Match::donneInstance ()->getTeam ()->GetListeJoueur ().at(k)->supStatMatch (action,valeur);
                Match::donneInstance ()->getTeam ()->GetListeJoueur ().at(k)->supStatSet (action,valeur);
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
    }
}

void Ecran::Slot_SuppAction()
{
    QList<QListWidgetItem *> list=ui->listAction->selectedItems ();

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

        for (int k=0;k<Match::donneInstance ()->getTeam ()->GetListeJoueur ().size ();k++)
        {
            if(num==Match::donneInstance ()->getTeam ()->GetListeJoueur ().at(k)->get_NumMaillot ())
            {
                Match::donneInstance ()->getTeam ()->GetListeJoueur ().at(k)->supStatMatch (action,valeur);
                Match::donneInstance ()->getTeam ()->GetListeJoueur ().at(k)->supStatSet (action,valeur);
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


}
void Ecran::RetirerPoint(bool qui)
{
    if(qui==true)
    {
        Match::donneInstance()->GetScore()->set_Score_E1(Match::donneInstance()->GetScore()->get_Score_E1()-1);
    }
    else
    {
        Match::donneInstance()->GetScore()->set_Score_E2(Match::donneInstance()->GetScore()->get_Score_E2()-1);
    }
    QString msgTrace=tr("Annulation du point");
    _trace->SetTrace(msgTrace);
    int score1=Match::donneInstance()->GetScore()->get_Score_E1();
    int score2=Match::donneInstance()->GetScore()->get_Score_E2();
    QString Strscore1,Strscore2;
    Strscore1.setNum(score1);
    Strscore2.setNum(score2);
    msgTrace=tr(" Score:")+Strscore1+"-"+Strscore2;
    _trace->SetTrace(msgTrace,false);

}

void Ecran::Slot_Fenetre(QAction *action)
{
    if(action->text()=="Score")
    {
        FenetreScore* Fenetre=new FenetreScore(this,Match::donneInstance()->GetScore());
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

    if(action->text()=="Gestion Equipes")
    {
        QDialog* equipe=new Fenetreequipe(this);

        equipe->exec();    
        this->EnregistrerXML();
    }
    else if(action->text() == "Lancer le Match")
    {
        Match* play=Match::donneInstance();
        FenetreLancement* lance=new FenetreLancement(this);
        if(lance->exec())
        {
            if(play->lancer()==true)
            {
                InitialisationMatch(play->getTeam()->GetNom(),play->getadvs());
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
        file.close(); // établit le document XML à partir des données du fichier (hiérarchie, etc.)
        return;
    }
    file.close();

    QDomElement racine = doc.documentElement(); // renvoie la balise racine
    QDomNode noeud = racine.firstChild(); // renvoie la première balise « mesure »
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
    ui->textEdit->append(message);
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
    this->_trace->SetTrace(msg);
}


void Ecran::FinSet()
{

    this->_currentSet=this->_currentSet+1;
    ui->pushButton_6->setVisible(false);
    this->_TimerScore->start(100);
    Match::donneInstance()->FinSet();
    ui->pBScore->setText("0");
    ui->pBScore_2->setText("0");
    _trace->SetTrace("Fin Set");
    FenetreService * fenetre=new FenetreService(Match::donneInstance()->getTeam()->GetNom(),Match::donneInstance()->getadvs());
    fenetre->exec();

    if(fenetre->isUS()==true)
    {
        ActionService(0);
        Match::donneInstance()->GetScore()->set_bool_adv(false);
    }
    else
    {
        ui->comboBox->setCurrentIndex(1);
        this->LineEdit2->ChangeBackColor(1);
        Match::donneInstance()->GetScore()->set_bool_adv(true);
    }


    // _finSet=false;
    //TempsMort();

}

void Ecran::FinMatch()
{
    if(QMessageBox::question(this,tr("Fin de match"),tr("Voulez vous quitter le match"),QMessageBox::Ok,QMessageBox::Cancel)==QMessageBox::Ok)
    {

        ui->textEdit->clear();
        _trace->SetTrace(tr("Fin Match"));
        _TraceListAction->Fin();
        QString  file=Match::donneInstance ()->GetFichierXml();
        Match::donneInstance ()->FinSet ();
        Match::donneInstance ()->Enregistrer ();
        Match::donneInstance ()->EnregistrerXMl ();

        // this->_FenetreStat->exec();
        Match::libereInstance();
        ui->comboBox->clear();
        this->_listActionMatch.clear();
        this->_listBanc->clear();
        this->_ListeEquipe.clear();
        ui->listJoueur->clear ();
        this->myWidget->clean();
        ui->groupBox->setVisible(false);
        Initialisation();
        this->_FenetreStat->Initialisation(file);
        ui->actionRevoir_un_match->setEnabled(true);
        ui->actionGestion_Equipes->setEnabled(true);
        ui->actionLancer_le_Match->setEnabled(true);
        this->_WtabEff->clean();
        this->_PlacementJoueur->Initialisation();


    }

}

void Ecran::keyPressEvent(QKeyEvent * event)
{
    bool isValide=false;

    if((event->key()==Qt::Key_Enter) ||
       (event->key()==Qt::Key_Return) &&
       _isMatchEnCour == true)
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
                for(int i=ui->listAction->count ();i>=0;i--)
                {
                    QListWidgetItem* item=ui->listAction->takeItem (i);
                    delete item;
                }
                this->_flagsup=false;
            }
            LineEdit2->clear();
            QString strNumPlayer=strValue.left(2);
            for(int i=0;i<Match::donneInstance ()->getTeam ()->GetListeJoueur ().size ();i++)
            {
                int num=strNumPlayer.toInt ();
                if(num==Match::donneInstance ()->getTeam ()->GetListeJoueur ().at (i)->get_NumMaillot ())
                {
                    isValide=true;
                    break;
                }
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
    int IAction=ui->comboBox->currentIndex();
    int position=1;
    QString strPosition;
    StatValeur StatAction=V0;


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
    bool error=Match::donneInstance()->GetCurrentSet()->AddAction(numjoueur,position,StatAction,IAction);
    if(error==true)
    {
        QMessageBox::warning(this,tr("Erreur"),tr("Probleme joueur"));
    }
    else
    {
        QString msgTrace=numjoueur+" "+_listAction.at(IAction)+" "+ValeurAction+" "+strPosition;

        QString MsgAction;
        QString MsgSet;
        QString MsgPos;
        MsgSet=MsgSet.setNum(_currentSet);
        MsgPos=MsgPos.setNum(_currentposition);
        MsgAction=MsgSet+"_"+MsgPos+"_"+numjoueur+"_"+_listAction.at(IAction)+"_"+ValeurAction;

        _trace->SetTrace(msgTrace);
        this->_TraceListAction->SetTrace(MsgAction);
        ui->listAction->addItem (MsgAction);
        this->_WtabEff->SlotMiseAJour();
        this->_PlacementJoueur->Stat();
    }

    //Algo de suivi des actions
    //Service;Defence;Passe;Attaque;Defence;Passe;Attaque
    IAction=_listActionMatch.size()-1;
    for(int k=0;k<_listActionMatch.size();k++)
    {
        if(Action==_listActionMatch.at(k))
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
            if(ui->comboBox->itemText(i)==this->_listActionMatch.at(2))
            {
                ui->comboBox->setCurrentIndex (i);
                this->LineEdit2->ChangeBackColor(i);
                break;
            }
        }
    }
    else if(IAction==1)
    {
        if(_listActionMatch.contains (tr("Passe")))
        {
            //ui->comboBox->setCurrentIndex (this->_listActionMatch.size()-2);
            //this->LineEdit2->ChangeBackColor(this->_listActionMatch.size()-2);
            for(int i=0;i<ui->comboBox->count();i++)
            {
                if(ui->comboBox->itemText(i)==this->_listActionMatch.at(this->_listActionMatch.size()-2))
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
                if(ui->comboBox->itemText(i)==this->_listActionMatch.at(_listActionMatch.size()-1))
                {
                    ui->comboBox->setCurrentIndex (i);
                    this->LineEdit2->ChangeBackColor(i);
                    break;
                }
            }



        }
    }
    else if(IAction==this->_listActionMatch.size()-1)
    {
        // ui->comboBox->setCurrentIndex(2);
        // this->LineEdit2->ChangeBackColor(2);
        for(int i=0;i<ui->comboBox->count();i++)
        {
            if(ui->comboBox->itemText(i)==this->_listActionMatch.at(2))
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
            if(ui->comboBox->itemText(i)==this->_listActionMatch.at(IAction+1))
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
    if(_listActionMoins.contains(_listActionMatch.at(IAction)) &&StatAction==VM)
    {
        PointMoins(numjoueur);
    }

    if(_listActionPlus.contains(_listActionMatch.at(IAction))
        && StatAction== VPP)
        {
        this->PointPlus(numjoueur);
    }

    /// Apparition de la deuxieme bar de saisi sur reception + ou ++
    if(StatAction==VP || StatAction==VPP &&
       ui->comboBox->currentText()==tr("Attaque"))

    {
        ui->lineEdit_PBP->setVisible(true);
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
    // this->_WtabEff->SlotMiseAJour();
    this->myWidget->Resize();

}

void Ecran::PointMoins(QString numjoueur)
{
    if(numjoueur=="00")
    {

        ui->comboBox->setCurrentIndex(0);
        this->LineEdit2->ChangeBackColor(0);
        emit ScorePlus(1);
        _PointForUs=true;
    }
    else
    {
        ui->comboBox->setCurrentIndex(1);
        this->LineEdit2->ChangeBackColor(1);
        emit ScorePlus(0);
        _PointForUs=false;
    }
    this->myWidget->Resize();
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
    Qt::DropAction dropAction = drag->start();
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

        for(int i=0;i<ui->listJoueur->count();i++)
        {
            if(ui->listJoueur->item(i)->text()==text)
            {
                delete ui->listJoueur->item(i);
            }
        }
        ui->listJoueur->sortItems(Qt::AscendingOrder);

    }
    event->acceptProposedAction();

}


void Ecran::Slot_Scoreplus(int position)
{

    if(position!=0)
    {
        // ui->spinBox->setValue(ui->spinBox->value()+1);
        Match::donneInstance()->GetScore()->set_Score_E1(Match::donneInstance()->GetScore()->get_Score_E1()+1);
        if( Match::donneInstance()->GetScore()->get_bool_adv()==true)
        {
            this->Rotation();
        }
        Match::donneInstance()->GetScore()->set_bool_adv(false);
        this->_flagsup=true;
        this->ActionService (0);
        //InitialiseDataFromIHM();
    }
    else
    {
        //ui->spinBox_2->setValue(ui->spinBox_2->value()+1);
        //InitialiseDataFromIHM();
        Match::donneInstance()->GetScore()->set_Score_E2(Match::donneInstance()->GetScore()->get_Score_E2()+1);
        Match::donneInstance()->GetScore()->set_bool_adv(true);
        ui->comboBox->setCurrentIndex(1);
        this->LineEdit2->ChangeBackColor(1);
        this->_flagsup=true;
    }

    QString msgTrace;
    int score1=Match::donneInstance()->GetScore()->get_Score_E1();
    int score2=Match::donneInstance()->GetScore()->get_Score_E2();
    QString Strscore1,Strscore2;
    Strscore1.setNum(score1);
    Strscore2.setNum(score2);

    msgTrace=" Score:"+Strscore1+"-"+Strscore2;
    _trace->SetTrace(msgTrace,false);

}

void Ecran::SetTactile (bool valeur)
{
    this->_Istactile=valeur;
}


void Ecran::Slot_ActionMM()
{
}

void Ecran::Slot_ActionM()
{
}
void Ecran::Slot_Action0()
{
}
void Ecran::Slot_ActionP()
{
}
void Ecran::Slot_ActionPP()
{
}

void Ecran::Slot_PplusL()
{
    Match::donneInstance()->GetScore()->set_Score_E1(Match::donneInstance()->GetScore()->get_Score_E1()+1);
}
void Ecran::Slot_PplusA()
{
    Match::donneInstance()->GetScore()->set_Score_E2(Match::donneInstance()->GetScore()->get_Score_E2()+1);
}

void Ecran::Slot_PmoinsL()
{
    Match::donneInstance()->GetScore()->set_Score_E1(Match::donneInstance()->GetScore()->get_Score_E1()-1);
}

void Ecran::Slot_PmoinsA()
{
    Match::donneInstance()->GetScore()->set_Score_E2(Match::donneInstance()->GetScore()->get_Score_E2()-1);
}

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
    SautAction(tr("Récéption"));
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
    SautAction(tr("Défense"));
}
void Ecran::Slot_ComplAction()
{
    if(ui->lineEdit_PBP->isVisible())
    {
        ui->lineEdit_PBP->setFocus();
    }
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
    ui->pushButton_8->setVisible(false);
    QList <Joueur*> listJoueur=Match::donneInstance()->getTeam()->GetListeJoueur();
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
        // pushButton->setObjectName(strAffiche);
        pushButton->setGeometry(QRect(10, 60, 75, 23));
        ui->gridLayout_18->addWidget(pushButton, i, 0, 1, 1);
        connect(pushButton,SIGNAL(lclicked()),this,SLOT(bouttonLClicked()));
    }
   // ui-> gridLayout_19->addWidget(ui->groupBox_4, 0,listJoueur.size() , 1, 1);
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
         _trace->SetTrace(tr("Fin Match"));
        QString  file=Match::donneInstance ()->GetFichierXml();
        Match::donneInstance ()->FinSet ();
        Match::donneInstance ()->Enregistrer ();
        Match::donneInstance ()->EnregistrerXMl ();
    }
}

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
#include "fenetrestat.h"
#include "ui_fenetrestat.h"
#include "lecturematch.h"


FenetreStat::FenetreStat(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::FenetreStat)
{
    ui->setupUi(this);
    myWidget=new StatWidget(ui->groupBox,parent);
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));

    connect(ui->pushButtonOK,SIGNAL(clicked()),this,SLOT(ok()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Imprimer()));



}

FenetreStat::~FenetreStat()
{
    myWidget->clean();
    delete myWidget;
    delete ui;
}
void FenetreStat::Initialisation(QString chemin)
{
    LectureMatch lect(chemin);
    lect.lectureInfoGeneral(chemin);
    QStringList listGeneral= lect.GetInfoGeneral();
    Equipe *team=new Equipe(lect.GetNomEquipe());
    team->SetStringAction(lect.GetListAction());
    team->SetStringValeur(lect.GetListValeur());
    //team->SetListAction(lect.GetListAction().split("_"));

    for(int i=0;i<lect.GetListJoueur().size();i++)
    {
        Joueur* joue=new Joueur();
        QString strjoue=lect.GetListJoueur().at(i);
        QStringList list=strjoue.split("_");
        joue->set_Prenom(list[0]);
        joue->set_NumMaillot(list[1].toInt());
        joue->set_poste(list[2]);
       // joue->SetListAction(lect.GetListAction().split("_"));
        team->AddJoueur(joue);
    }
    newMatch=Match::donneInstance();
    newMatch->setCurrentEquipe(team);
    newMatch->SetDate(listGeneral.at(0));
    newMatch->SetType(listGeneral.at(2));
    newMatch->setAdvers(listGeneral.at(4));
    newMatch->setArbitre(listGeneral.at(5));

    lect.lectureStat(chemin);
    newMatch->Enregistrer(lect.GetStatMatch());
    for(int s=0;s<listGeneral.at(7).toInt();s++)
    {
        newMatch->CreerSet(lect.GetScore(s),lect.GetStat(s));
    }

    this->Ouvrir();
}

void FenetreStat::Ouvrir()//Match * match)
{


    QString Titre;
    Titre="Match du "+newMatch->GetDate ()+"\n";
    Titre=Titre+newMatch->getTeam ()->GetNom ()+" Vs "+newMatch->getadvs ()+"\n";
    //Titre=Titre+"Temps de jeu"+newMatch->GetTemps();
    ui->label->setText (Titre);
    ui->label->setSizePolicy (QSizePolicy::Preferred,QSizePolicy::Fixed);
    //score
    QString score;
    QString num;
    /*for(int k=0;k<newMatch->GetCurentSet ();k++)
    {
        num=num.setNum (k+1);
        score="Set"+num+" "+newMatch->GetCurentSet (k+1)->ScoreSave ()+"\n";
        score=score+"Temps"+newMatch->GetOldSet (k+1)->GetTempsSet();
    }*/
    ui->label_5->setText (score);
    myWidget->SetEquipe (newMatch->getTeam ());
    myWidget->InitListAction(InitAction::donneInstance()->GetListAction());

    newMatch->Restaurer ();

    myWidget->Initialisation ();
    myWidget->SetStatEquipeMatch (newMatch->getTeam ());

    //myWidget->SetStatoldEquipeMatch();
    for(int k=1;k<newMatch->GetCurentSet ()-1;k++)
    {
        myWidget->SetOldStatEquipeSet(k);
        for(int j=0;j<newMatch->getTeam()->GetListeJoueur().size();j++)
        {
            myWidget->SetStatJoueurSet(newMatch->getTeam()->GetListeJoueur().at(j),k);
        }
    }
    myWidget->SetStatEquipeSet (newMatch->getTeam (),newMatch->GetCurentSet ());
    for(int j=0;j<newMatch->getTeam()->GetListeJoueur().size();j++)
    {
        myWidget->SetStatJoueurSet (newMatch->getTeam ()->GetListeJoueur().at(j),newMatch->GetCurentSet ());
    }
    myWidget->Resize();
    exec();
}


void FenetreStat::ok()
{
    myWidget->clean();
    Match::libereInstance ();

    this->accept ();
}
void FenetreStat::Fermer()
{
    myWidget->clean();
    Match::libereInstance ();

    this->close ();
}


void FenetreStat::Imprimer()
{
    myWidget->Imprimer();
}



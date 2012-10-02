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

#include "fenetrestat.h"
#include "ui_fenetrestat.h"
#include "lecturematch.h"


FenetreStat::FenetreStat(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::FenetreStat)
{
    ui->setupUi(this);

    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));

    connect(ui->pushButtonOK,SIGNAL(clicked()),this,SLOT(ok()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Imprimer()));



}

FenetreStat::~FenetreStat()
{


    delete ui;
}
void FenetreStat::Initialisation(QString chemin)
{
    LectureMatch lect(chemin);
    lect.lectureInfoGeneral(chemin);
    QStringList listGeneral= lect.GetInfoGeneral();
    Equipe *team=new Equipe(lect.GetNomEquipe());
    //team->SetStringAction(lect.GetListAction());
    //team->SetStringValeur(lect.GetListValeur());
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
   // newMatch->SetDate(listGeneral.at(0));
   // newMatch->SetType(listGeneral.at(2));
    newMatch->setAdvers(listGeneral.at(4));
    //newMatch->setArbitre(listGeneral.at(5));

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
/*

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
    }
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
    exec();*/
}


void FenetreStat::ok()
{
   /* myWidget->clean();
    Match::libereInstance ();

    this->accept ();*/
}
void FenetreStat::Fermer()
{
    /*myWidget->clean();
    Match::libereInstance ();

    this->close ();*/
}


void FenetreStat::Imprimer()
{
    //myWidget->Imprimer();
}



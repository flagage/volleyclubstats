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
#include "fbjoueur.h"


fbjoueur::fbjoueur(Equipe* Team,QWidget *parent) :
        QDialog(parent)

{
    _Team=Team;
    ui.setupUi(this);
    connect(ui.buttonBox,SIGNAL(accepted()),this,SLOT(SlotEnregistrer()));

    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    Init();
}

void fbjoueur::Init()
{
    QStringList listPost;
    listPost<<tr("Passeur")<<tr("Libero")<<tr("Complet")<<tr("Pointu")<<tr("Recep/Attaque")<<tr("Central");
    ui.comboBox_2->addItems (listPost);
    if(_Team!=0)
    {
        ui.comboBox->addItem(_Team->GetNom());
    }
    else
    {
        QMessageBox::warning (this,tr("erreur"),tr("Verifier que l'équipe est bien selectionné"));
        this->reject ();
        this->close ();
    }
    _modif=false;

}
Joueur* fbjoueur::Ajouter(Equipe *Team)
{
    ui.comboBox->setEnabled(false);
    Joueur* play=0;
    if(this->exec())
    {
        play=new Joueur();
        play->set_Nom(ui.lineEdit_Nom->text());
        play->set_Prenom(ui.lineEdit_prenom->text());
        play->set_Addresse(ui.lineEdit_add->text());
        play->set_Email(ui.lineEdit_Email->text());
        play->set_Tel(ui.lineEdit_tel->text().toInt());
        play->set_poste(ui.comboBox_2->currentText ());
        play->set_NLisence(ui.lineEdit_lis->text().toInt());
        play->set_Age(ui.lineEdit_age->text().toInt());
        play->set_NumMaillot(ui.spinBox->value ());
        if(Team!=0)
        {
            Team->AddJoueur(play);
        }

    }
    return play;
}

void fbjoueur::Modif(Joueur* player,bool isMathEncours)
{

    ui.lineEdit_Nom->setText(player->get_Nom());
    ui.lineEdit_prenom->setText(player->get_Prenom());
    ui.lineEdit_add->setText(player->get_Addresse());
    ui.lineEdit_Email->setText(player->get_Email());
    QString tel;
    tel=tel.setNum(player->get_Tel());
    ui.lineEdit_tel->setText(tel);
    ui.comboBox_2->setCurrentIndex (ui.comboBox_2->findText (player->get_poste ()));

    QString lisence;
    lisence=lisence.setNum(player->get_NLisence());
    ui.lineEdit_lis->setText(lisence);
    QString age;
    age=age.setNum(player->get_Age());
    ui.lineEdit_age->setText(age);

    ui.spinBox->setValue (player->get_NumMaillot());
    _curentJoueur=player;
    _modif=true;
    if(isMathEncours==true)
    {

        ui.comboBox->setEnabled(false);


    }
    else
    {


        ui.comboBox->setEnabled(true);

        this->exec();
    }

}


void fbjoueur::SlotEnregistrer()
{
    Joueur* play;
    if(_modif==true)
    {
        play=_curentJoueur;
    }
    else
    {

        play=new Joueur();
    }
    if((ui.lineEdit_prenom->text()==""))

    {
        QMessageBox::warning(this,tr("Erreur Formulaire"),tr("toute les * doivent etre reseigner"));
    }
    else if(ui.spinBox->value ()==0)
    {
        QMessageBox::warning(this,tr("Erreur Formulaire"),tr("le numero 0 est reserve"));
    }
    else
    {
        play->set_Nom(ui.lineEdit_Nom->text());
        play->set_Prenom(ui.lineEdit_prenom->text());
        play->set_Addresse(ui.lineEdit_add->text());
        play->set_Email(ui.lineEdit_Email->text());
        play->set_Tel(ui.lineEdit_tel->text().toInt());
        play->set_poste(ui.comboBox_2->currentText ());
        play->set_NLisence(ui.lineEdit_lis->text().toInt());
        play->set_Age(ui.lineEdit_age->text().toInt());
        play->set_NumMaillot(ui.spinBox->value ());
        if(_modif==false)
        {
            if(_Team!=0)
                _Team->AddJoueur(play);
            else
                QMessageBox::warning(this,tr("Erreur"),tr("Pas d'équipe séléctionné"));
        }
    }
}

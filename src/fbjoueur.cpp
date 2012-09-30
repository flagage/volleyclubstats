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
#include "fbjoueur.h"


fbjoueur::fbjoueur(Equipe* Team,Joueur* play,QWidget *parent) :
    QDialog(parent)

{
    _Team=Team;
    _curentJoueur=play;
    ui.setupUi(this);
    connect(ui.buttonBox,SIGNAL(accepted()),this,SLOT(SlotEnregistrer()));

    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    Init();
    this->exec();
}

void fbjoueur::Init()
{
    QStringList listPost;
    listPost<<tr("Passeur")<<tr("Libero")<<tr("Complet")<<tr("Pointu")<<tr("Recep/Attaque")<<tr("Central");
    ui.comboBox_2->addItems (listPost);
    if(_curentJoueur==0)
    {

        if(_Team!=0)
        {
            ui.comboBox->addItem(_Team->GetNom());
        }
        else
        {
            QMessageBox::warning (this,tr("erreur"),tr("Verifiez que l'�quipe est bien selectionn�e"));
            this->reject ();
            this->close ();
        }
    }
    else
    {
        ui.lineEdit_Nom->setText(_curentJoueur->get_Nom());
        ui.lineEdit_prenom->setText(_curentJoueur->get_Prenom());
        ui.lineEdit_add->setText(_curentJoueur->get_Addresse());
        ui.lineEdit_Email->setText(_curentJoueur->get_Email());
        QString tel;
        tel=tel.setNum(_curentJoueur->get_Tel());
        ui.lineEdit_tel->setText(tel);
        ui.comboBox_2->setCurrentIndex (ui.comboBox_2->findText (_curentJoueur->get_poste ()));

        QString lisence;
        lisence=lisence.setNum(_curentJoueur->get_NLisence());
        ui.lineEdit_lis->setText(lisence);
        QString age;
        age=_curentJoueur->get_Age();
        QStringList agedate=age.split("/");
        QDate date;
        if(agedate.size()==3)
            date.setDate(agedate[2].toInt(),agedate[1].toInt(),agedate[0].toInt());


        ui.dateEdit->setDate(date);
        //ui.lineEdit_age->setText(age);

        ui.spinBox->setValue (_curentJoueur->get_NumMaillot());

    }


}
void fbjoueur::SlotEnregistrer()
{
    if(_modif==false)
    {
       // Ajouter();
        this->Enregistrer();
    }
    else
    {
        this->Enregistrer();
    }


}

void fbjoueur::SetjoueurfromIHM(Joueur* play)
{
    play->set_Nom(ui.lineEdit_Nom->text());
    play->set_Prenom(ui.lineEdit_prenom->text());
    play->set_Addresse(ui.lineEdit_add->text());
    play->set_Email(ui.lineEdit_Email->text());
    play->set_Tel(ui.lineEdit_tel->text().toInt());
    play->set_poste(ui.comboBox_2->currentText ());
    play->set_NLisence(ui.lineEdit_lis->text().toInt());
    play->set_Age(ui.dateEdit->date().toString("dd/MM/yyyy"));
    play->set_NumMaillot(ui.spinBox->value ());
}

bool fbjoueur::isNumeroOk()
{
    bool retour=true;
    if(_Team!=0)
    {
        QList <Joueur*> listJoueur= _Team->GetListeJoueur();
        for(int l=0;l<listJoueur.size();l++)
        {
            if(ui.spinBox->value ()==listJoueur.at(l)->get_NumMaillot())
            {
                retour=false;
                break;

            }
        }
        return retour;
    }
}

void fbjoueur::Enregistrer()
{


    if(this->_curentJoueur==0)
    {

        _curentJoueur=new Joueur();
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

            bool AjoutImpossible=isNumeroOk();

            if(AjoutImpossible==true)
            {

                SetjoueurfromIHM(_curentJoueur);
                _Team->AddJoueur(_curentJoueur);
            }

            else
            {
                QMessageBox::warning(this,tr("Ajout Impossible"),tr("Numero de maillot deja present"));

            }
        }

    }

    else
    {
        if(_curentJoueur->get_NumMaillot()!=ui.spinBox->value())
        {
            if(isNumeroOk()==true)
            {
                SetjoueurfromIHM(_curentJoueur);
            }
            else
            {
                QMessageBox::warning(this,tr("Ajout Impossible"),tr("Numero de maillot deja present"));
            }
        }
        else
        {
            SetjoueurfromIHM(_curentJoueur);
        }

    }

    this->hide();

}

Joueur* fbjoueur::GetCurrentJoueur()
{
    return _curentJoueur;
}

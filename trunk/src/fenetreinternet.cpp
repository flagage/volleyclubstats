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

#include "fenetreinternet.h"
#include "ui_fenetreinternet.h"

FenetreInternet::FenetreInternet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FenetreInternet)
{
    ui->setupUi(this);
    this->setWindowIcon((QIcon("Icone/logo_vcs_transparent.png")));
    QImage image("Icone/google.png");

     // display image as icon on
     ui->pushButton_goo->setIcon(QPixmap::fromImage(image));
     // resize the icon and PushButton to fit the image
      ui->pushButton_goo->setIconSize(image.size());
       ui->pushButton_goo->resize(image.size());

       QImage image1("Icone/forward.png");

       // display image as icon on
       ui->pushButton_suiv->setIcon(QPixmap::fromImage(image1));
       // resize the icon and PushButton to fit the image
        ui->pushButton_suiv->setIconSize(image1.size());
         ui->pushButton_suiv->resize(image1.size());

         QImage image2("Icone/back.png");

         // display image as icon on
         ui->pushButton->setIcon(QPixmap::fromImage(image2));
         // resize the icon and PushButton to fit the image
          ui->pushButton->setIconSize(image2.size());
           ui->pushButton->resize(image2.size());

           QImage image3("Icone/isync.png");

           // display image as icon on
           ui->pushButton_reload->setIcon(QPixmap::fromImage(image3));
           // resize the icon and PushButton to fit the image
            ui->pushButton_reload->setIconSize(image3.size());
             ui->pushButton_reload->resize(image3.size());

             QImage image4("Icone/close.png");

             // display image as icon on
             ui->pushButton_stop->setIcon(QPixmap::fromImage(image4));
             // resize the icon and PushButton to fit the image
              ui->pushButton_stop->setIconSize(image4.size());
               ui->pushButton_stop->resize(image4.size());


 ui->webView->settings()->setAttribute( QWebSettings::JavascriptEnabled, false);


     connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_prec()));
     connect(ui->pushButton_suiv,SIGNAL(clicked()),this,SLOT(slot_suiv()));
     connect(ui->pushButton_reload,SIGNAL(clicked()),this,SLOT(slot_reload()));
     connect(ui->pushButton_stop,SIGNAL(clicked()),this,SLOT(slot_stop()));
     connect(ui->pushButton_goo,SIGNAL(clicked()),this,SLOT(slot_google()));
}

FenetreInternet::~FenetreInternet()
{
    delete ui;
}
void FenetreInternet::slot_prec()
{
    ui->webView->page()->triggerAction(QWebPage::Back);
}

void FenetreInternet::slot_suiv()
{
    ui->webView->page()->triggerAction(QWebPage::Forward);
}
void FenetreInternet::slot_reload()
{
    ui->webView->page()->triggerAction(QWebPage::Reload);
}

void FenetreInternet::slot_google()
{
    ui->webView->load(QUrl("http://www.google.fr"));
}

void FenetreInternet::slot_stop()
{
    ui->webView->page()->triggerAction(QWebPage::Stop);
}

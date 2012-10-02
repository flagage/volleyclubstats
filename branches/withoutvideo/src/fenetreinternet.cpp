/**
Copyright Frederic volleyclubstats ,2011
fred@volleyclubstats.com

This file is part of volleyclubstats.

volleyclubstats is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Volleyclubstats.  If not, see <http://www.gnu.org/licenses/>.
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
     connect(ui->FFVB,SIGNAL(clicked()),this,SLOT(slot_ffvb()));
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

void FenetreInternet::slot_ffvb()
{
    ui->webView->load(QUrl("http://www.ffvbbeach.org/ffvbapp/resu/"));
}

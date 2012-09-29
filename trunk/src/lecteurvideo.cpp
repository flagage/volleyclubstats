#include "lecteurvideo.h"
#include "ui_lecteurvideo.h"
#include "iostream"
#include "QMessageBox"
#include "QFileDialog"
#include "QInputDialog"
#include "QUrl"


lecteurVideo::lecteurVideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lecteurVideo)
{
    ui->setupUi(this);

    player = new Phonon::VideoPlayer(Phonon::VideoCategory,this);

    player->videoWidget()->setVisible(false);
   // player->videoWidget()->setFullScreen(true);
    player->mediaObject()->setTickInterval(1000);
    ui->verticalLayout_3->addWidget(player);
    player->show();

   // player->play(Phonon::MediaSource("C:\\Users\\fred\\Videos\\Glorious_Beautiful.avi"));
    connect(ui->play,SIGNAL(clicked()),this,SLOT(slot_play()));
    connect(ui->pause,SIGNAL(clicked()),this,SLOT(slot_pause()));
    connect(ui->stop,SIGNAL(clicked()),this,SLOT(slot_stop()));
    connect(player,SIGNAL(finished()),this,SLOT(slot_stop()));
    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),this,SLOT(slot_avance(int)));
    connect(ui->horizontalSlider,SIGNAL(sliderReleased()),this,SLOT(slot_play()));
    connect(ui->timeEdit,SIGNAL(editingFinished()),this,SLOT(slot_timechange()));
    connect(this,SIGNAL(finished(int)),this,SLOT(slot_stop()));
    connect(ui->ChangementVideo,SIGNAL(clicked()),this,SLOT(slot_changement()));
   // connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_changementurl()));

    ///demande de choix du fichier a ouvrir

    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "video (*.avi *.mp4 *.flv *.wmv *.m2ts *.* ..)");
     // QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);
   // QUrl url("http://www.youtube.com/watch?v=5UxaoVt5Pw8");
     player->mediaObject()->setCurrentSource(Phonon::MediaSource(fichier));
    player->play();

    volumeSlider= new Phonon::VolumeSlider(this);
    volumeSlider->setAudioOutput(player->audioOutput());
    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    ui->horizontalLayout->addWidget(volumeSlider);

    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(slot_update()));
            timer->start(1);
        //    connect(ui->timeEdit,SIGNAL(editingFinished()))
}
void lecteurVideo::slot_play()
{
     //QMessageBox::information(this,"stop","");
player->videoWidget()->setVisible(true);
    player->play();
    timer->start();
}
void lecteurVideo::slot_timechange()
{
    player->pause();
    timer->stop();
    QTime time;
    time=ui->timeEdit->time();
    int value=time.hour()*60*60*1000
              +time.minute()*60*1000
              +time.second()*1000
              +time.msec();

    player->seek(value);
    ui->horizontalSlider->setValue(value);

}
void lecteurVideo::slot_pause()
{
    player->pause();
    timer->stop();
}
void lecteurVideo::slot_stop()
{
    //QMessageBox::information(this,"stop","");
    player->stop();
    timer->stop();
    ui->horizontalSlider->setValue(0);
    QTime time;
   time= time.addMSecs(0);
    ui->timeEdit->setTime(time);
}
void lecteurVideo::slot_avance(int value)
{
    timer->stop();
    player->pause();
    player->seek(value);
    QTime time;
    time=time.addMSecs(value);
    ui->timeEdit->setTime(time);


}
void lecteurVideo::slot_update()
{
     QTime time;
     QTime time2;
    ui->horizontalSlider->setMaximum(player->totalTime());
    time2=time2.addMSecs(player->totalTime());

    ui->timeEdit_2->setTime(time2);
    ui->horizontalSlider->setValue(player->currentTime());


      time=time.addMSecs(player->currentTime());

    ui->timeEdit->setTime(time);

    timer->start(10);
}

lecteurVideo::~lecteurVideo()
{
    timer->stop();
    player->stop();
    delete player;
    delete timer;
    delete ui;
}

void lecteurVideo::keyPressEvent(QKeyEvent * event)
{


    if(event->key()==Qt::Key_F)
        {
        player->pause();
        //ui->horizontalSlider->setValue(ui->horizontalSlider->value()+1000);
        ui->timeEdit->setTime(ui->timeEdit->time().addSecs(1));
        slot_timechange();

    }
    else if(event->key()==Qt::Key_R)
    {
        player->pause();
        ui->timeEdit->setTime(ui->timeEdit->time().addSecs(-1));
        slot_timechange();
    }
    else if(event->key()==Qt::Key_P)
    {
        if(player->isPaused())
        {
            slot_play();
        }
        else
        {
            slot_pause();
        }
    }
    else if(event->key()==Qt::Key_S)
    {
        slot_stop();
    }
}

void lecteurVideo::keyReleaseEvent(QKeyEvent * event)
{
    if((event->key()==Qt::Key_F) ||
       (event->key()==Qt::Key_R))
            {
       slot_play();
    }

}

void lecteurVideo::slot_changement()
{
    this->slot_stop();
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "video (*.avi *.mp4 *.flv *.wmv *.m2ts *.* ...)");

    player->play(Phonon::MediaSource(fichier));
    timer->start(1);
}

void  lecteurVideo::slot_changementurl()
{
        this->slot_stop();
          QString url = QInputDialog::getText(this, "Url", "Quel l'adresse de la video ?");
          player->play(Phonon::MediaSource(url));
          timer->start(1);
      }

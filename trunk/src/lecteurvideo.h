#ifndef LECTEURVIDEO_H
#define LECTEURVIDEO_H

#include <QDialog>
#include <phonon>
#include <QTimer>
#include <QKeyEvent>

namespace Ui {
    class lecteurVideo;
}

class lecteurVideo : public QDialog
{
    Q_OBJECT

public:
    explicit lecteurVideo(QWidget *parent = 0);
   void  keyPressEvent(QKeyEvent * event);
   void keyReleaseEvent(QKeyEvent * event);
    ~lecteurVideo();

public slots:
    void slot_avance(int value);
    void slot_play();
    void slot_stop();
    void slot_timechange();
    void slot_pause();
    void slot_update();
    void slot_changement();
    void slot_changementurl();

private:
    Ui::lecteurVideo *ui;
    Phonon::VideoPlayer *player;
    Phonon::VolumeSlider *volumeSlider;
    QTimer *timer;
};

#endif // LECTEURVIDEO_H

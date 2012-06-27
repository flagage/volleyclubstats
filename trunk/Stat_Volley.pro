#-------------------------------------------------
#
# Project created by QtCreator 2010-11-14T19:51:34
#
#-------------------------------------------------

TARGET = Stat_Volley
TEMPLATE = app
TRANSLATIONS = VolleyClub_en.ts VolleyClub_es.ts
# Chemin vers FontConfig a mettre en premiere position
 #LIBS += -L/usr/local/lib \
  #-lfontconfig

QT+= xml webkit
QT+= phonon

RC_FILE = VolleyClubStat.rc
SOURCES += src/tracelog.cpp \
    src/statwidget.cpp \
    src/stat.cpp \
    src/Score.cpp \
    src/match.cpp \
    src/main.cpp \
    src/Joueur.cpp \
    src/fenetrevisualisation.cpp \
    src/fenetrestat.cpp \
    src/fenetreservice.cpp \
    src/fenetrescore.cpp \
    src/fenetreposition.cpp \
    src/fenetrelancement.cpp \
    src/fenetreequipe.cpp \
    src/fenetrecontact.cpp \
    src/fbjoueur.cpp \
    src/Equipe.cpp \
    src/ecran.cpp \
    src/revumatch.cpp \
    src/fenetremodifaction.cpp \
    src/bouttonjoueur.cpp \
    src/keyjoueur.cpp \
    src/tablematch.cpp \
    src/lecturematch.cpp \
    src/fenetrechoixmatch.cpp \
    src/fenetreinternet.cpp \
    src/widgettabeff.cpp \
    src/vcslineedit.cpp \
    src/club.cpp \
    src/listactionxml.cpp \
    src/lecteurvideo.cpp \
    src/statwriter.cpp \
    src/volleyInit.cpp \
    src/tracematch.cpp \
    src/matchxml.cpp \
    src/twstatjoueur.cpp


HEADERS  += src/tracelog.h \
    src/statwidget.h \
    src/stat.h \
    src/Score.h \
    src/match.h \
    src/Joueur.h \
    src/fenetrevisualisation.h \
    src/fenetrestat.h \
    src/fenetreservice.h \
    src/fenetrescore.h \
    src/fenetreposition.h \
    src/fenetrelancement.h \
    src/fenetreequipe.h \
    src/fenetrecontact.h \
    src/fbjoueur.h \
    src/Equipe.h \
    src/ecran.h \
    src/revumatch.h \
    src/fenetremodifaction.h \
    src/bouttonjoueur.h \
    src/keyjoueur.h \
    src/tablematch.h \
    src/lecturematch.h \
    src/fenetrechoixmatch.h \
    src/fenetreinternet.h \
    src/widgettabeff.h \
    src/vcslineedit.h \
    src/club.h \
    src/listactionxml.h \
    src/lecteurvideo.h \
    src/statwriter.h \
    src/volleyInit.h \
    src/tracematch.h \
    src/matchxml.h \
    src/twstatjoueur.h


FORMS    +=  ui/statwidget.ui \
    ui/fenetrevisualisation.ui \
    ui/fenetrestat.ui \
    ui/fenetreservice.ui \
    ui/fenetrescore.ui \
    ui/fenetreposition.ui \
    ui/fenetrelancement.ui \
    ui/fenetreequipe.ui \
    ui/fenetrecontact.ui \
    ui/fenetrechangement.ui \
    ui/ecran.ui \
    ui/dialog.ui \
    ui/revumatch.ui \
    ui/fenetremodifaction.ui \
    ui/fenetrechoixmatch.ui \
    ui/widgettabeff.ui \
    ui/fenetreinternet.ui \
    ui/lecteurvideo.ui \
    ui/twstatjoueur.ui



OTHER_FILES += \
    VolleyClubStat.rc \

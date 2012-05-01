#############################################################################
# Makefile for building: Stat_Volley
# Generated by qmake (2.01a) (Qt 4.8.1) on: Tue May 1 21:13:02 2012
# Project:  Stat_Volley.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile Stat_Volley.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_WEBKIT_LIB -DQT_PHONON_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtXml -I/usr/include/phonon -I/usr/include/qt4/QtWebKit -I/usr/include/qt4 -I/usr/include/qt4/phonon_compat -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtWebKit -lphonon -lQtXml -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/tracelog.cpp \
		src/statwidget.cpp \
		src/stat.cpp \
		src/set.cpp \
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
		src/volleyInit.cpp moc_tracelog.cpp \
		moc_statwidget.cpp \
		moc_fenetrevisualisation.cpp \
		moc_fenetrestat.cpp \
		moc_fenetreservice.cpp \
		moc_fenetrescore.cpp \
		moc_fenetreposition.cpp \
		moc_fenetrelancement.cpp \
		moc_fenetreequipe.cpp \
		moc_fenetrecontact.cpp \
		moc_fbjoueur.cpp \
		moc_ecran.cpp \
		moc_revumatch.cpp \
		moc_fenetremodifaction.cpp \
		moc_bouttonjoueur.cpp \
		moc_keyjoueur.cpp \
		moc_tablematch.cpp \
		moc_fenetrechoixmatch.cpp \
		moc_fenetreinternet.cpp \
		moc_widgettabeff.cpp \
		moc_vcslineedit.cpp \
		moc_lecteurvideo.cpp
OBJECTS       = tracelog.o \
		statwidget.o \
		stat.o \
		set.o \
		Score.o \
		match.o \
		main.o \
		Joueur.o \
		fenetrevisualisation.o \
		fenetrestat.o \
		fenetreservice.o \
		fenetrescore.o \
		fenetreposition.o \
		fenetrelancement.o \
		fenetreequipe.o \
		fenetrecontact.o \
		fbjoueur.o \
		Equipe.o \
		ecran.o \
		revumatch.o \
		fenetremodifaction.o \
		bouttonjoueur.o \
		keyjoueur.o \
		tablematch.o \
		lecturematch.o \
		fenetrechoixmatch.o \
		fenetreinternet.o \
		widgettabeff.o \
		vcslineedit.o \
		club.o \
		listactionxml.o \
		lecteurvideo.o \
		statwriter.o \
		volleyInit.o \
		moc_tracelog.o \
		moc_statwidget.o \
		moc_fenetrevisualisation.o \
		moc_fenetrestat.o \
		moc_fenetreservice.o \
		moc_fenetrescore.o \
		moc_fenetreposition.o \
		moc_fenetrelancement.o \
		moc_fenetreequipe.o \
		moc_fenetrecontact.o \
		moc_fbjoueur.o \
		moc_ecran.o \
		moc_revumatch.o \
		moc_fenetremodifaction.o \
		moc_bouttonjoueur.o \
		moc_keyjoueur.o \
		moc_tablematch.o \
		moc_fenetrechoixmatch.o \
		moc_fenetreinternet.o \
		moc_widgettabeff.o \
		moc_vcslineedit.o \
		moc_lecteurvideo.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		Stat_Volley.pro
QMAKE_TARGET  = Stat_Volley
DESTDIR       = 
TARGET        = Stat_Volley

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_statwidget.h ui_fenetrevisualisation.h ui_fenetrestat.h ui_fenetreservice.h ui_fenetrescore.h ui_fenetreposition.h ui_fenetrelancement.h ui_fenetreequipe.h ui_fenetrecontact.h ui_fenetrechangement.h ui_ecran.h ui_dialog.h ui_revumatch.h ui_fenetremodifaction.h ui_fenetrechoixmatch.h ui_widgettabeff.h ui_fenetreinternet.h ui_lecteurvideo.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: Stat_Volley.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtWebKit.prl \
		/usr/lib/i386-linux-gnu/libQtXml.prl \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile Stat_Volley.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/declarative_debug.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtWebKit.prl:
/usr/lib/i386-linux-gnu/libQtXml.prl:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile Stat_Volley.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Stat_Volley1.0.0 || $(MKDIR) .tmp/Stat_Volley1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Stat_Volley1.0.0/ && $(COPY_FILE) --parents src/tracelog.h src/statwidget.h src/stat.h src/set.h src/Score.h src/match.h src/Joueur.h src/fenetrevisualisation.h src/fenetrestat.h src/fenetreservice.h src/fenetrescore.h src/fenetreposition.h src/fenetrelancement.h src/fenetreequipe.h src/fenetrecontact.h src/fbjoueur.h src/Equipe.h src/ecran.h src/revumatch.h src/fenetremodifaction.h src/bouttonjoueur.h src/keyjoueur.h src/tablematch.h src/lecturematch.h src/fenetrechoixmatch.h src/fenetreinternet.h src/widgettabeff.h src/vcslineedit.h src/club.h src/listactionxml.h src/lecteurvideo.h src/statwriter.h src/volleyInit.h .tmp/Stat_Volley1.0.0/ && $(COPY_FILE) --parents src/tracelog.cpp src/statwidget.cpp src/stat.cpp src/set.cpp src/Score.cpp src/match.cpp src/main.cpp src/Joueur.cpp src/fenetrevisualisation.cpp src/fenetrestat.cpp src/fenetreservice.cpp src/fenetrescore.cpp src/fenetreposition.cpp src/fenetrelancement.cpp src/fenetreequipe.cpp src/fenetrecontact.cpp src/fbjoueur.cpp src/Equipe.cpp src/ecran.cpp src/revumatch.cpp src/fenetremodifaction.cpp src/bouttonjoueur.cpp src/keyjoueur.cpp src/tablematch.cpp src/lecturematch.cpp src/fenetrechoixmatch.cpp src/fenetreinternet.cpp src/widgettabeff.cpp src/vcslineedit.cpp src/club.cpp src/listactionxml.cpp src/lecteurvideo.cpp src/statwriter.cpp src/volleyInit.cpp .tmp/Stat_Volley1.0.0/ && $(COPY_FILE) --parents ui/statwidget.ui ui/fenetrevisualisation.ui ui/fenetrestat.ui ui/fenetreservice.ui ui/fenetrescore.ui ui/fenetreposition.ui ui/fenetrelancement.ui ui/fenetreequipe.ui ui/fenetrecontact.ui ui/fenetrechangement.ui ui/ecran.ui ui/dialog.ui ui/revumatch.ui ui/fenetremodifaction.ui ui/fenetrechoixmatch.ui ui/widgettabeff.ui ui/fenetreinternet.ui ui/lecteurvideo.ui .tmp/Stat_Volley1.0.0/ && $(COPY_FILE) --parents VolleyClub_en.ts VolleyClub_es.ts .tmp/Stat_Volley1.0.0/ && (cd `dirname .tmp/Stat_Volley1.0.0` && $(TAR) Stat_Volley1.0.0.tar Stat_Volley1.0.0 && $(COMPRESS) Stat_Volley1.0.0.tar) && $(MOVE) `dirname .tmp/Stat_Volley1.0.0`/Stat_Volley1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Stat_Volley1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_tracelog.cpp moc_statwidget.cpp moc_fenetrevisualisation.cpp moc_fenetrestat.cpp moc_fenetreservice.cpp moc_fenetrescore.cpp moc_fenetreposition.cpp moc_fenetrelancement.cpp moc_fenetreequipe.cpp moc_fenetrecontact.cpp moc_fbjoueur.cpp moc_ecran.cpp moc_revumatch.cpp moc_fenetremodifaction.cpp moc_bouttonjoueur.cpp moc_keyjoueur.cpp moc_tablematch.cpp moc_fenetrechoixmatch.cpp moc_fenetreinternet.cpp moc_widgettabeff.cpp moc_vcslineedit.cpp moc_lecteurvideo.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_tracelog.cpp moc_statwidget.cpp moc_fenetrevisualisation.cpp moc_fenetrestat.cpp moc_fenetreservice.cpp moc_fenetrescore.cpp moc_fenetreposition.cpp moc_fenetrelancement.cpp moc_fenetreequipe.cpp moc_fenetrecontact.cpp moc_fbjoueur.cpp moc_ecran.cpp moc_revumatch.cpp moc_fenetremodifaction.cpp moc_bouttonjoueur.cpp moc_keyjoueur.cpp moc_tablematch.cpp moc_fenetrechoixmatch.cpp moc_fenetreinternet.cpp moc_widgettabeff.cpp moc_vcslineedit.cpp moc_lecteurvideo.cpp
moc_tracelog.cpp: src/tracelog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/tracelog.h -o moc_tracelog.cpp

moc_statwidget.cpp: src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/statwidget.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/statwidget.h -o moc_statwidget.cpp

moc_fenetrevisualisation.cpp: src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		src/fenetrevisualisation.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fenetrevisualisation.h -o moc_fenetrevisualisation.cpp

moc_fenetrestat.cpp: src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/statwidget.h \
		src/Equipe.h \
		src/club.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrestat.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fenetrestat.h -o moc_fenetrestat.cpp

moc_fenetreservice.cpp: src/fenetreservice.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fenetreservice.h -o moc_fenetreservice.cpp

moc_fenetrescore.cpp: src/Score.h \
		src/fenetrescore.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fenetrescore.h -o moc_fenetrescore.cpp

moc_fenetreposition.cpp: src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		src/fenetreposition.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fenetreposition.h -o moc_fenetreposition.cpp

moc_fenetrelancement.cpp: src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		src/fenetrelancement.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fenetrelancement.h -o moc_fenetrelancement.cpp

moc_fenetreequipe.cpp: src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		src/fenetreequipe.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fenetreequipe.h -o moc_fenetreequipe.cpp

moc_fenetrecontact.cpp: src/fenetrecontact.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fenetrecontact.h -o moc_fenetrecontact.cpp

moc_fbjoueur.cpp: ui_dialog.h \
		src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		src/fbjoueur.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fbjoueur.h -o moc_fbjoueur.cpp

moc_ecran.cpp: src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		src/ecran.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/ecran.h -o moc_ecran.cpp

moc_revumatch.cpp: src/revumatch.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/revumatch.h -o moc_revumatch.cpp

moc_fenetremodifaction.cpp: src/fenetremodifaction.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fenetremodifaction.h -o moc_fenetremodifaction.cpp

moc_bouttonjoueur.cpp: src/bouttonjoueur.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/bouttonjoueur.h -o moc_bouttonjoueur.cpp

moc_keyjoueur.cpp: src/bouttonjoueur.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/keyjoueur.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/keyjoueur.h -o moc_keyjoueur.cpp

moc_tablematch.cpp: src/tablematch.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/tablematch.h -o moc_tablematch.cpp

moc_fenetrechoixmatch.cpp: src/tablematch.h \
		src/fenetrechoixmatch.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fenetrechoixmatch.h -o moc_fenetrechoixmatch.cpp

moc_fenetreinternet.cpp: src/fenetreinternet.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/fenetreinternet.h -o moc_fenetreinternet.cpp

moc_widgettabeff.cpp: src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/widgettabeff.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/widgettabeff.h -o moc_widgettabeff.cpp

moc_vcslineedit.cpp: src/vcslineedit.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/vcslineedit.h -o moc_vcslineedit.cpp

moc_lecteurvideo.cpp: src/lecteurvideo.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/lecteurvideo.h -o moc_lecteurvideo.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_statwidget.h ui_fenetrevisualisation.h ui_fenetrestat.h ui_fenetreservice.h ui_fenetrescore.h ui_fenetreposition.h ui_fenetrelancement.h ui_fenetreequipe.h ui_fenetrecontact.h ui_fenetrechangement.h ui_ecran.h ui_dialog.h ui_revumatch.h ui_fenetremodifaction.h ui_fenetrechoixmatch.h ui_widgettabeff.h ui_fenetreinternet.h ui_lecteurvideo.h
compiler_uic_clean:
	-$(DEL_FILE) ui_statwidget.h ui_fenetrevisualisation.h ui_fenetrestat.h ui_fenetreservice.h ui_fenetrescore.h ui_fenetreposition.h ui_fenetrelancement.h ui_fenetreequipe.h ui_fenetrecontact.h ui_fenetrechangement.h ui_ecran.h ui_dialog.h ui_revumatch.h ui_fenetremodifaction.h ui_fenetrechoixmatch.h ui_widgettabeff.h ui_fenetreinternet.h ui_lecteurvideo.h
ui_statwidget.h: ui/statwidget.ui
	/usr/bin/uic-qt4 ui/statwidget.ui -o ui_statwidget.h

ui_fenetrevisualisation.h: ui/fenetrevisualisation.ui
	/usr/bin/uic-qt4 ui/fenetrevisualisation.ui -o ui_fenetrevisualisation.h

ui_fenetrestat.h: ui/fenetrestat.ui
	/usr/bin/uic-qt4 ui/fenetrestat.ui -o ui_fenetrestat.h

ui_fenetreservice.h: ui/fenetreservice.ui
	/usr/bin/uic-qt4 ui/fenetreservice.ui -o ui_fenetreservice.h

ui_fenetrescore.h: ui/fenetrescore.ui
	/usr/bin/uic-qt4 ui/fenetrescore.ui -o ui_fenetrescore.h

ui_fenetreposition.h: ui/fenetreposition.ui
	/usr/bin/uic-qt4 ui/fenetreposition.ui -o ui_fenetreposition.h

ui_fenetrelancement.h: ui/fenetrelancement.ui
	/usr/bin/uic-qt4 ui/fenetrelancement.ui -o ui_fenetrelancement.h

ui_fenetreequipe.h: ui/fenetreequipe.ui
	/usr/bin/uic-qt4 ui/fenetreequipe.ui -o ui_fenetreequipe.h

ui_fenetrecontact.h: ui/fenetrecontact.ui
	/usr/bin/uic-qt4 ui/fenetrecontact.ui -o ui_fenetrecontact.h

ui_fenetrechangement.h: ui/fenetrechangement.ui
	/usr/bin/uic-qt4 ui/fenetrechangement.ui -o ui_fenetrechangement.h

ui_ecran.h: ui/ecran.ui
	/usr/bin/uic-qt4 ui/ecran.ui -o ui_ecran.h

ui_dialog.h: ui/dialog.ui
	/usr/bin/uic-qt4 ui/dialog.ui -o ui_dialog.h

ui_revumatch.h: ui/revumatch.ui
	/usr/bin/uic-qt4 ui/revumatch.ui -o ui_revumatch.h

ui_fenetremodifaction.h: ui/fenetremodifaction.ui
	/usr/bin/uic-qt4 ui/fenetremodifaction.ui -o ui_fenetremodifaction.h

ui_fenetrechoixmatch.h: ui/fenetrechoixmatch.ui
	/usr/bin/uic-qt4 ui/fenetrechoixmatch.ui -o ui_fenetrechoixmatch.h

ui_widgettabeff.h: ui/widgettabeff.ui
	/usr/bin/uic-qt4 ui/widgettabeff.ui -o ui_widgettabeff.h

ui_fenetreinternet.h: ui/fenetreinternet.ui
	/usr/bin/uic-qt4 ui/fenetreinternet.ui -o ui_fenetreinternet.h

ui_lecteurvideo.h: ui/lecteurvideo.ui
	/usr/bin/uic-qt4 ui/lecteurvideo.ui -o ui_lecteurvideo.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

tracelog.o: src/tracelog.cpp src/tracelog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tracelog.o src/tracelog.cpp

statwidget.o: src/statwidget.cpp src/statwidget.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		ui_statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o statwidget.o src/statwidget.cpp

stat.o: src/stat.cpp src/stat.h \
		src/volleyInit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o stat.o src/stat.cpp

set.o: src/set.cpp src/set.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o set.o src/set.cpp

Score.o: src/Score.cpp src/Score.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Score.o src/Score.cpp

match.o: src/match.cpp src/match.h \
		src/set.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/Score.h \
		src/fenetrelancement.h \
		src/ecran.h \
		src/tracelog.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		src/fenetreposition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o match.o src/match.cpp

main.o: src/main.cpp src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o src/main.cpp

Joueur.o: src/Joueur.cpp src/Joueur.h \
		src/stat.h \
		src/volleyInit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Joueur.o src/Joueur.cpp

fenetrevisualisation.o: src/fenetrevisualisation.cpp src/fenetrevisualisation.h \
		src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		ui_fenetrevisualisation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetrevisualisation.o src/fenetrevisualisation.cpp

fenetrestat.o: src/fenetrestat.cpp src/fenetrestat.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/statwidget.h \
		src/Equipe.h \
		src/club.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		ui_fenetrestat.h \
		src/lecturematch.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetrestat.o src/fenetrestat.cpp

fenetreservice.o: src/fenetreservice.cpp src/fenetreservice.h \
		ui_fenetreservice.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetreservice.o src/fenetreservice.cpp

fenetrescore.o: src/fenetrescore.cpp src/fenetrescore.h \
		src/Score.h \
		ui_fenetrescore.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetrescore.o src/fenetrescore.cpp

fenetreposition.o: src/fenetreposition.cpp src/fenetreposition.h \
		src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		ui_fenetreposition.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetreposition.o src/fenetreposition.cpp

fenetrelancement.o: src/fenetrelancement.cpp src/fenetrelancement.h \
		src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		ui_fenetrelancement.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetrelancement.o src/fenetrelancement.cpp

fenetreequipe.o: src/fenetreequipe.cpp src/fenetreequipe.h \
		src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		ui_fenetreequipe.h \
		src/fbjoueur.h \
		ui_dialog.h \
		src/fenetrevisualisation.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetreequipe.o src/fenetreequipe.cpp

fenetrecontact.o: src/fenetrecontact.cpp src/fenetrecontact.h \
		ui_fenetrecontact.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetrecontact.o src/fenetrecontact.cpp

fbjoueur.o: src/fbjoueur.cpp src/fbjoueur.h \
		ui_dialog.h \
		src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fbjoueur.o src/fbjoueur.cpp

Equipe.o: src/Equipe.cpp src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Equipe.o src/Equipe.cpp

ecran.o: src/ecran.cpp src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h \
		ui_ecran.h \
		src/fbjoueur.h \
		ui_dialog.h \
		src/fenetreequipe.h \
		src/fenetrevisualisation.h \
		src/fenetreservice.h \
		src/fenetrelancement.h \
		src/fenetremodifaction.h \
		src/fenetreinternet.h \
		src/lecteurvideo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ecran.o src/ecran.cpp

revumatch.o: src/revumatch.cpp src/revumatch.h \
		ui_revumatch.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o revumatch.o src/revumatch.cpp

fenetremodifaction.o: src/fenetremodifaction.cpp src/fenetremodifaction.h \
		ui_fenetremodifaction.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetremodifaction.o src/fenetremodifaction.cpp

bouttonjoueur.o: src/bouttonjoueur.cpp src/bouttonjoueur.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bouttonjoueur.o src/bouttonjoueur.cpp

keyjoueur.o: src/keyjoueur.cpp src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/fbjoueur.h \
		ui_dialog.h \
		src/ecran.h \
		src/tracelog.h \
		src/Equipe.h \
		src/club.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/widgettabeff.h \
		src/vcslineedit.h \
		src/listactionxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o keyjoueur.o src/keyjoueur.cpp

tablematch.o: src/tablematch.cpp src/tablematch.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tablematch.o src/tablematch.cpp

lecturematch.o: src/lecturematch.cpp src/lecturematch.h \
		src/match.h \
		src/set.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		src/Score.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lecturematch.o src/lecturematch.cpp

fenetrechoixmatch.o: src/fenetrechoixmatch.cpp src/fenetrechoixmatch.h \
		src/tablematch.h \
		ui_fenetrechoixmatch.h \
		src/lecturematch.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetrechoixmatch.o src/fenetrechoixmatch.cpp

fenetreinternet.o: src/fenetreinternet.cpp src/fenetreinternet.h \
		ui_fenetreinternet.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fenetreinternet.o src/fenetreinternet.cpp

widgettabeff.o: src/widgettabeff.cpp src/widgettabeff.h \
		src/Equipe.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h \
		src/club.h \
		ui_widgettabeff.h \
		src/ecran.h \
		src/tracelog.h \
		src/fenetrestat.h \
		src/statwidget.h \
		src/match.h \
		src/set.h \
		src/Score.h \
		src/fenetrescore.h \
		src/fenetrechoixmatch.h \
		src/tablematch.h \
		src/keyjoueur.h \
		src/bouttonjoueur.h \
		src/vcslineedit.h \
		src/listactionxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o widgettabeff.o src/widgettabeff.cpp

vcslineedit.o: src/vcslineedit.cpp src/vcslineedit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o vcslineedit.o src/vcslineedit.cpp

club.o: src/club.cpp src/club.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o club.o src/club.cpp

listactionxml.o: src/listactionxml.cpp src/listactionxml.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o listactionxml.o src/listactionxml.cpp

lecteurvideo.o: src/lecteurvideo.cpp src/lecteurvideo.h \
		ui_lecteurvideo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lecteurvideo.o src/lecteurvideo.cpp

statwriter.o: src/statwriter.cpp src/statwriter.h \
		src/Joueur.h \
		src/stat.h \
		src/volleyInit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o statwriter.o src/statwriter.cpp

volleyInit.o: src/volleyInit.cpp src/volleyInit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o volleyInit.o src/volleyInit.cpp

moc_tracelog.o: moc_tracelog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_tracelog.o moc_tracelog.cpp

moc_statwidget.o: moc_statwidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_statwidget.o moc_statwidget.cpp

moc_fenetrevisualisation.o: moc_fenetrevisualisation.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetrevisualisation.o moc_fenetrevisualisation.cpp

moc_fenetrestat.o: moc_fenetrestat.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetrestat.o moc_fenetrestat.cpp

moc_fenetreservice.o: moc_fenetreservice.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetreservice.o moc_fenetreservice.cpp

moc_fenetrescore.o: moc_fenetrescore.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetrescore.o moc_fenetrescore.cpp

moc_fenetreposition.o: moc_fenetreposition.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetreposition.o moc_fenetreposition.cpp

moc_fenetrelancement.o: moc_fenetrelancement.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetrelancement.o moc_fenetrelancement.cpp

moc_fenetreequipe.o: moc_fenetreequipe.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetreequipe.o moc_fenetreequipe.cpp

moc_fenetrecontact.o: moc_fenetrecontact.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetrecontact.o moc_fenetrecontact.cpp

moc_fbjoueur.o: moc_fbjoueur.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fbjoueur.o moc_fbjoueur.cpp

moc_ecran.o: moc_ecran.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ecran.o moc_ecran.cpp

moc_revumatch.o: moc_revumatch.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_revumatch.o moc_revumatch.cpp

moc_fenetremodifaction.o: moc_fenetremodifaction.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetremodifaction.o moc_fenetremodifaction.cpp

moc_bouttonjoueur.o: moc_bouttonjoueur.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_bouttonjoueur.o moc_bouttonjoueur.cpp

moc_keyjoueur.o: moc_keyjoueur.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_keyjoueur.o moc_keyjoueur.cpp

moc_tablematch.o: moc_tablematch.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_tablematch.o moc_tablematch.cpp

moc_fenetrechoixmatch.o: moc_fenetrechoixmatch.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetrechoixmatch.o moc_fenetrechoixmatch.cpp

moc_fenetreinternet.o: moc_fenetreinternet.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fenetreinternet.o moc_fenetreinternet.cpp

moc_widgettabeff.o: moc_widgettabeff.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_widgettabeff.o moc_widgettabeff.cpp

moc_vcslineedit.o: moc_vcslineedit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_vcslineedit.o moc_vcslineedit.cpp

moc_lecteurvideo.o: moc_lecteurvideo.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_lecteurvideo.o moc_lecteurvideo.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


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

#include <QtGui/QApplication>
#include "ecran.h"

#include "QFile"
#include "QTextCodec"
#include "QTranslator"
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /// Traduction
    QTranslator translator;
    translator.load("Traductions/VolleyClub_en.qm");
    a.installTranslator(&translator);
   /* QString locale = QLocale::system().name().section('_', 0, 0);
       QTranslator translator;
       translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
       a.installTranslator(&translator);*/

    Ecran mainWin;
    mainWin.show();

    /// Fichier de Style (CSS) pour la forme
    QFile file("Image/essai.qss");
    if (file.open(QFile::ReadOnly))
    {
        QString styleSheet = QLatin1String(file.readAll());
        a.setStyleSheet(styleSheet);
    }
    return a.exec();
}

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
#include <QtGui/QApplication>
#include "ecran.h"
#include "MainWindow.h"
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
    //QTranslator translator;
    //translator.load("");
    //a.installTranslator(&translator);
    QString locale = QLocale::system().name().section('_', 0, 0);
       QTranslator translator;
       translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
       a.installTranslator(&translator);

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

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

#include "listactionxml.h"
#include "QStringList"

ListActionXml::ListActionXml()
{
}


void ListActionXml::SetFile(QString filename)
{
_file=filename;
}

void ListActionXml::SetTrace(QString msg)
{

     QDateTime time;
     QString nomRep="Sauvegarde/Action/"+_file+".xml";
     QFile file(nomRep);
    if (!file.open(QIODevice::Append |QIODevice::WriteOnly|QIODevice::Text ))
    return;

    QTextStream out(&file);
    QStringList list=msg.split("_");
    out <<"<Action>\n";
    out <<"<Set>"<<list[0]<<"</Set>";
    out <<"<PostePasse>"<<list[1]<<"</PostePasse>";
    out<<"<Joueur>"<< list[2]<<"</Joueur>";
    out<<"<Type>"<< list[3]<<"</Type>";
    out<<"<Valeur>"<< list[4]<<"</Valeur>";
    out <<"</Action>\n";

    file.close();

}
void ListActionXml::Debut()
{
    QString nomRep="Sauvegarde/Action/"+_file+".xml";
    QFile file(nomRep);
    if (!file.open(QIODevice::Append |QIODevice::WriteOnly|QIODevice::Text ))
    return;

    QTextStream out(&file);
    out<<"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    out<<"<!--Fichier contenant l'ensemenble des informations sur les actions-->\n";
    out<<"<ListAction>\n";
    file.close();

}

void ListActionXml::Fin()
{
    QString nomRep="Sauvegarde/Action/"+_file+".xml";
    QFile file(nomRep);
    if (!file.open(QIODevice::Append |QIODevice::WriteOnly|QIODevice::Text ))
    return;


    QTextStream out(&file);
    out<<"</ListAction>";

}

void ListActionXml::SupprimerAction(int IdAction)
{
    QString nomRep="Sauvegarde/Action/"+_file+".xml";
    QStringList listeTemporaire;
    QFile file(nomRep);
    QString strRecherche;
    strRecherche=strRecherche.setNum(IdAction);
    strRecherche="<Id>"+strRecherche+"</Id>";

    file.open(QIODevice::ReadWrite | QIODevice::Text); //on ouvre le fichier en lecture

        QTextStream flux(&file);
        QString ligne;

    while (! flux.atEnd())
        {
        ligne = flux.readLine();
            if (ligne==strRecherche)
            {
              ligne.remove(strRecherche);
              while(ligne!="</Action>")
              {
                 // ligne.remove(ligne);
                  ligne=flux.readLine();
              }
            }
            else
            {
                 listeTemporaire << ligne;
            }
          }

    foreach( ligne, listeTemporaire)
    {
        flux << ligne + "\n";
    }

       file.close();

}

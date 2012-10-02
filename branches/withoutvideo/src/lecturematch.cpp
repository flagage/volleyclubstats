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


#include "lecturematch.h"
#include "match.h"
#include "QFile"



LectureMatch::LectureMatch(QString chemin)
{



    this->lectureInfoGeneral (chemin);

}

void LectureMatch::lectureStat(QString chemin)
{
    QString errorMsg;
int errorline;
int errorcolumn;
int nbSet=0;
QFile file("Sauvegarde/"+chemin);

    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!_doc.setContent(&file,true,&errorMsg,&errorline,&errorcolumn))
    {
       // QMessageBox::warning (this,QString("attention"),errorMsg);
        file.close(); // établit le document XML à partir des données du fichier (hiérarchie, etc.)
        return;
    }
    ListGeneral<<"Sauvegarde/"+chemin;
    QDomElement racine = _doc.documentElement(); // renvoie la balise racine
    QDomNode root = racine.firstChild(); // renvoie la première balise « mesure »
    while(!root.isNull())
    {
        if(root.nodeName()=="Statisitique")
        {
            QDomNode child=root.firstChild();
            while(!child.isNull())
            {


                QDomElement score=child.toElement();
                if(score.nodeName()=="MatchStat")
                {
                     QDomNode granChild=child.firstChild();

                while(!granChild.isNull())
                {
                    QDomElement stat=granChild.toElement();
                    _MatchStat<<stat.attribute("stat");
                    granChild=granChild.nextSibling();

                 }

                    ;
                }
                else
                {
                _Score[nbSet]=score.attribute("score");
                QDomNode granChild=child.firstChild();
                QStringList list;
                while(!granChild.isNull())
                {
                    QDomElement stat=granChild.toElement();
                    list<<stat.attribute("stat");
                    granChild=granChild.nextSibling();

                 }
                _Stat[nbSet]=list;
                nbSet++;
            }
                child=child.nextSibling();
            }
        }
        root=root.nextSibling ();
    }

}

void LectureMatch::lectureInfoGeneral(QString chemin)
{
QString errorMsg;
int errorline;
int errorcolumn;
QFile file("Sauvegarde/"+chemin);

    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!_doc.setContent(&file,true,&errorMsg,&errorline,&errorcolumn))
    {
       // QMessageBox::warning (this,QString("attention"),errorMsg);
        file.close(); // établit le document XML à partir des données du fichier (hiérarchie, etc.)
        return;
    }
   // ListGeneral<<"Sauvegarde/"+chemin;
    QDomElement racine = _doc.documentElement(); // renvoie la balise racine
    QDomNode root = racine.firstChild(); // renvoie la première balise « mesure »
    while(!root.isNull())
    {
        if(root.nodeName ()=="Match")
        {
        QDomElement General=root.toElement ();

         ListGeneral<<General.attribute ("Date");
         ListGeneral<<General.attribute ("Heure");
         ListGeneral<<General.attribute ("Type");
         ListGeneral<<General.attribute ("Equipe");
         ListGeneral<<General.attribute ("Contre");
         ListGeneral<<General.attribute ("Arbitre");
         ListGeneral<<General.attribute ("Duree");
         ListGeneral<<General.attribute ("NbDeSet");
         }
        else if(root.nodeName()=="Equipe")
        {
             QDomElement team=root.toElement ();
            _nomEquipe=team.attribute("Nom");
            _ListAction=team.attribute("listAction");
            _ListValeur=team.attribute("ListeValeur");
            QDomNode nodeteam=team.firstChild();
            while(!nodeteam.isNull())
            {
                QDomElement player=nodeteam.toElement ();
                QString strJoueur=player.attribute("Nom");
                strJoueur=strJoueur+"_"+player.attribute("NumMaillot");
                strJoueur=strJoueur+"_"+player.attribute("poste");
                _ListJoueur<<strJoueur;
                nodeteam=nodeteam.nextSibling();
            }
        }
        root=root.nextSibling ();
    }
}
QString LectureMatch::GetListAction()
{
    return _ListAction;
}

QString LectureMatch::GetListValeur()
{
    return _ListValeur;
}

QString LectureMatch::GetNomEquipe()
{
    return _nomEquipe;
}

QStringList LectureMatch::GetListJoueur()
{
    return _ListJoueur;
}

QStringList LectureMatch::GetInfoGeneral()
{
    return this->ListGeneral;
}
QStringList LectureMatch::GetStat(int indice)
{
    return this->_Stat[indice];
}

QString LectureMatch::GetScore(int indice)
{
    return this->_Score[indice];
}

QStringList LectureMatch::GetStatMatch()

{
    return this->_MatchStat;
}

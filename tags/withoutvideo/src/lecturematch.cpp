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
        file.close(); // �tablit le document XML � partir des donn�es du fichier (hi�rarchie, etc.)
        return;
    }
    ListGeneral<<"Sauvegarde/"+chemin;
    QDomElement racine = _doc.documentElement(); // renvoie la balise racine
    QDomNode root = racine.firstChild(); // renvoie la premi�re balise � mesure �
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
        file.close(); // �tablit le document XML � partir des donn�es du fichier (hi�rarchie, etc.)
        return;
    }
   // ListGeneral<<"Sauvegarde/"+chemin;
    QDomElement racine = _doc.documentElement(); // renvoie la balise racine
    QDomNode root = racine.firstChild(); // renvoie la premi�re balise � mesure �
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

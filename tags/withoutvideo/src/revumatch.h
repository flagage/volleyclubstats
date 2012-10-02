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

#ifndef REVUMATCH_H
#define REVUMATCH_H

#include <QDialog>
#include "parametrematch.h"
#include "Score.h"
#include "Equipe.h"
#include "matchxml.h"
#include "widgettabeff.h"
#include "framstats.h"
#include "listevenement.h"

namespace Ui {
    class RevuMatch;
}

class RevuMatch : public QDialog
{
    Q_OBJECT

public:
   explicit RevuMatch(QWidget *parent) ;
     RevuMatch(QList <Equipe*>listequipe,QString fichier,QWidget *parent = 0);
    ~RevuMatch();
    void LectureFichierXML();
    void InitialiseIhmFromFile();
    void InitialisationTabFromXML();
    void Initialisation();
    void InitialisationStats();
public slots:
    void OpenAnalyse();

private:
    Ui::RevuMatch *ui;
    ParametreMatch* _ParamMatch;
    Score* _Score;
    QList <Equipe*> _listequipe;
    QString _fichierSelection;
    Equipe* _EquipeVisiteur;
    Equipe* _currentEquipe;
    QStringList _ListEvenement;
    QList <QString> _listPosition;
    QVector <WidgetTabEff*> _VectortabEff;
    QVector<FramStats*> _VectorTabFram;
    ListEvenement* _ListEvent;
};

#endif // REVUMATCH_H

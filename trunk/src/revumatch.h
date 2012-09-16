#ifndef REVUMATCH_H
#define REVUMATCH_H

#include <QDialog>
#include "ParametreMatch.h"
#include "Score.h"
#include "Equipe.h"
#include "MatchXml.h"
#include "widgettabeff.h"
#include "framstats.h"

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
};

#endif // REVUMATCH_H

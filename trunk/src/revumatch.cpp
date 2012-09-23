#include "revumatch.h"
#include "ui_revumatch.h"
#include "matchxml.h"
#include "QSplitter"

RevuMatch::RevuMatch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RevuMatch)
{
     ui->setupUi(this);

}

RevuMatch::RevuMatch(QList <Equipe*>listequipe,QString cheminfichier,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RevuMatch)
{
    ui->setupUi(this);
    for(int i=0;i<listequipe.size();i++)
    {
        this->_listequipe.append(listequipe.at(i));
    }
    this->_fichierSelection=cheminfichier;
    _EquipeVisiteur=new Equipe();

     Initialisation();
    LectureFichierXML();
    InitialiseIhmFromFile();
    InitialisationTabFromXML();

}

RevuMatch::~RevuMatch()
{
    delete _EquipeVisiteur;
    delete ui;
}

void RevuMatch::LectureFichierXML()
{
    _ParamMatch=new ParametreMatch();
    _Score=new Score();
    MatchXml FichierXml(_ParamMatch,_Score,_EquipeVisiteur,&this->_ListEvenement,&this->_listPosition);
    FichierXml.LectureParametreMatch("Sauvegarde/"+_fichierSelection);
    if(_ParamMatch->get_NomEquipeLocal()!="")
    {
        for(int i=0;i<_listequipe.size();i++)
        {
            if(_listequipe.at(i)->GetNom()==_ParamMatch->get_NomEquipeLocal())
            {
                this->_currentEquipe=_listequipe.at(i);
                break;
            }
        }
    }
    FichierXml.setEquipe(this->_currentEquipe);
    FichierXml.LectureXML("Sauvegarde/"+_fichierSelection);
    _currentEquipe=FichierXml.GetEquipe();
}

void RevuMatch::InitialiseIhmFromFile()
{
    ui->label_NomLocal->setText(_currentEquipe->GetNom());
    ui->label_NomVisiteur->setText(_EquipeVisiteur->GetNom());
    ui->spinBox_Set->setValue(this->_ParamMatch->get_NbSet());
    ui->spinBox_NbJoueur->setValue(this->_ParamMatch->get_NbJoueur());
    int sc=_Score->ListdesScore().size();
    switch (sc)
    {
    case 1:
        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
        ui->label_6->setText(_Score->ListdesScore().at(0));
        break;
    case 2:

        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
        ui->label_7->setVisible(true);
        ui->label_12->setVisible(true);
        if(_Score->ListdesScore().size()==2)
        {
            ui->label_6->setText(_Score->ListdesScore().at(0));
            ui->label_12->setText(_Score->ListdesScore().at(1));
        }
        break;
    case 3:
        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
        ui->label_7->setVisible(true);
        ui->label_12->setVisible(true);
        ui->label_13->setVisible(true);
        ui->label_9->setVisible(true);
        ui->label_6->setText(_Score->ListdesScore().at(0));
        ui->label_12->setText(_Score->ListdesScore().at(1));
        ui->label_13->setText(_Score->ListdesScore().at(2));
        break;
    case 4:

        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
        ui->label_7->setVisible(true);
        ui->label_12->setVisible(true);
        ui->label_13->setVisible(true);
        ui->label_9->setVisible(true);
        ui->label_10->setVisible(true);
        ui->label_14->setVisible(true);
        ui->label_6->setText(_Score->ListdesScore().at(0));
        ui->label_12->setText(_Score->ListdesScore().at(1));
        ui->label_13->setText(_Score->ListdesScore().at(2));
        ui->label_14->setText(_Score->ListdesScore().at(3));
        break;
    case 5:
        ui->label_5->setVisible(true);
        ui->label_6->setVisible(true);
        ui->label_7->setVisible(true);
        ui->label_12->setVisible(true);
        ui->label_13->setVisible(true);
        ui->label_9->setVisible(true);
        ui->label_10->setVisible(true);
        ui->label_14->setVisible(true);
        ui->label_15->setVisible(true);
        ui->label_11->setVisible(true);
        ui->label_6->setText(_Score->ListdesScore().at(0));
        ui->label_12->setText(_Score->ListdesScore().at(1));
        ui->label_13->setText(_Score->ListdesScore().at(2));
        ui->label_14->setText(_Score->ListdesScore().at(3));
        ui->label_15->setText(_Score->ListdesScore().at(4));
        break;

    }

    this->show();
}

void RevuMatch::Initialisation()
{



    QSplitter *splitter=new QSplitter(this);



    splitter->addWidget(ui->widget);
    splitter->addWidget(ui->widget_2);
    splitter->setHandleWidth(10);
   ui->gridLayout_12->addWidget(splitter,1,0,1,1);

    ui->listWidget->setVisible(false);
    _ListEvent=new ListEvenement(false,ui->groupBox_9);
      ui->gridLayout_11->addWidget(_ListEvent, 0, 0, 1, 1);
    _ListEvent->setEnabled(true);



    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->label_9->setVisible(false);
    ui->label_10->setVisible(false);
    ui->label_11->setVisible(false);
    ui->label_12->setVisible(false);
    ui->label_13->setVisible(false);
    ui->label_14->setVisible(false);
    ui->label_15->setVisible(false);

}
void RevuMatch::InitialisationTabFromXML()
{
    QTabWidget* tabWidget = new QTabWidget(ui->tabWidget->widget(0));
QString NomOnglet;
for(int i=0;i<_ParamMatch->get_NbSet()+1;i++)
{
    QWidget* tabelement=new QWidget();

    if(i==0)
    {
        NomOnglet="Match";
    }
    else
    {
        NomOnglet="Set n�"+QString::number(i);
    }
    tabWidget->addTab(tabelement,NomOnglet);
    _VectortabEff.append(new WidgetTabEff(tabelement));

}
ui->gridLayout_9->addWidget(tabWidget, 0, 0, 1, 1);


/// initialisation tabAction
for(int a=0;a<_ParamMatch->get_Action().size();a++)
{
    QWidget *CreerNouveauOnglet = new QWidget;
    QGridLayout *layout = new QGridLayout;
    layout->setContentsMargins(0,0,0,0);

    CreerNouveauOnglet->setLayout(layout);

    QString strlabel=_ParamMatch->get_Action().at(a);
    ui->tabWidget->addTab(CreerNouveauOnglet,strlabel);

    QTabWidget* tabWidget = new QTabWidget(ui->tabWidget->widget(a+1));
    tabWidget->setObjectName(QString::fromUtf8("tabWidget_2"));
    for(int i=0;i<_ParamMatch->get_NbSet()+1;i++)
    {
        QWidget* tabelement=new QWidget();
        if(i==0)
        {
            NomOnglet="Match";
        }
        else
        {
            NomOnglet="Set n�"+QString::number(i);
        }
        tabWidget->addTab(tabelement,NomOnglet);
        _VectorTabFram.append(new FramStats(a,_currentEquipe,tabelement));
    }

    layout->addWidget(tabWidget, 0, 0, 1, 1);


}
InitialisationStats();
}


void RevuMatch::InitialisationStats()
{
    _VectortabEff.at(0)->clean();
    _VectortabEff.at(0)->Init(_currentEquipe->GetListeJoueur(),_ParamMatch->get_Action());
    _VectortabEff.at(0)->SlotMiseAJour(false,0);
    for(int k=0;k<_ParamMatch->get_Action().size();k++)
    {
        int valeur=_ParamMatch->get_NbSet()+1;
        _VectorTabFram.at(k*(valeur))->clean();
        _VectorTabFram.at(k*(valeur))->Init();
        _VectorTabFram.at(k*(valeur))->SlotMiseAJour(false,0);
    }

    for(int i=1;i<_ParamMatch->get_NbSet();i++)
    {
        _VectortabEff.at(i)->clean();
        _VectortabEff.at(i)->Init(_currentEquipe->GetListeJoueur(),_ParamMatch->get_Action());
        _VectortabEff.at(i)->SlotMiseAJour(true,i);
        for(int k=0;k<_ParamMatch->get_Action().size();k++)
        {
            int ActionSet=i+k*(_ParamMatch->get_NbSet()+1);
           // ActionSet++;
            _VectorTabFram.at(ActionSet)->clean();
            _VectorTabFram.at(ActionSet)->Init();
            _VectorTabFram.at(ActionSet)->SlotMiseAJour(true,i);
        }

    }
    /// Liste des evenement
    for(int i=0;i<_ListEvenement.size();i++)
    {
        this->_ListEvent->addItem(_ListEvenement.at(i));
    }
}

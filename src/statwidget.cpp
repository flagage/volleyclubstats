/**
Copyright LAGAGE Frédéric ,2011
flagage@gmail.com

Ce logiciel est un programme informatique servant à capturer en direct des statistiques des joueurs de volley-ball.

Ce logiciel est régi par la licence CeCILLsoumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe à
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL et que vous en avez accepté les
**/
#include "statwidget.h"
#include "ui_statwidget.h"
#include "QMessageBox"
#include "QPrintDialog"
#include "QPrinter"
#include "QPainter"
#include "QTextDocument"
#include "QBrush"
#include "QFileDialog"
#include "QTextStream"
#include "match.h"
#include "volleyInit.h"




StatWidget::StatWidget(QWidget *parent,QWidget *FenetreParent) :
        QWidget(parent),
        ui(new Ui::StatWidget)
{
    ui->setupUi(this);

    //  Initialisation();
    _Fenetre=FenetreParent;
    connect(FenetreParent,SIGNAL(SignalAction(int)),this,SLOT(slot_recu(int)));
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(slot_changement(int)));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slot_export()));
    if(parent->layout() != 0)
        parent->layout()->addWidget(this);
    ui->tabWidget->removeTab (1);
    delete ui->tabWidget->widget (1);


}

StatWidget::~StatWidget()
{


    delete ui;
}

void StatWidget::Initialisation()
{
    TableElementsState *tabelem;

    for(int i=0;i<_listJoueur.size ();i++)
    {
        QWidget* ajout=new QTabWidget();
        Joueur *player=_listJoueur.at (i);
        QString strnum;
        strnum=strnum.setNum (player->get_NumMaillot ());
        QString tab=player->get_Prenom ()+"_"+strnum+"_"+player->get_poste ();
        ui->tabWidget->insertTab(i+1,ajout,tab);
        QVBoxLayout *layout = new QVBoxLayout;
        QWidget *tabAjout=ui->tabWidget->widget (i+1);
        tabAjout->setLayout (layout);
        tabelem=new TableElementsState(ui->tabWidget->widget (i+1));
        StatJoueur.insert (player->get_NumMaillot (),tabelem);

    }
    _tabElts=new TableElementsState(ui->tab);

}

void StatWidget::Ouvrir()
{
    //this->_tabElts->showColumn(0);
    this->show ();
}

void StatWidget::SetEquipe(Equipe* team)
{
    _team=team;
    _listJoueur=_team->GetListeJoueur ();
}

void StatWidget::slot_recu(int pos)
{
    Joueur* player;
    for(int i=0;i<_listJoueur.count();i++)
    {
        if(pos==_listJoueur.at(i)->get_NumMaillot())
        {
            player=_listJoueur.at(i);
        }
    }

    switch (ui->tabWidget->currentIndex())
    {
    case 0:
        SetStatEquipeSet(_team,Match::donneInstance()->Getnbset ());
        SetStatEquipeMatch(_team);
        break;
    default:

        SetStatJoueurSet(player,Match::donneInstance()->Getnbset ());
        SetStatJoueurMatch(player);
        break;

    }


}

void StatWidget::SetStatJoueurSet(Joueur *player,int numSet)
{
    double stat;
    int col=1;
    QString strAffiche;
    for(int Action=0;Action<_listAction.size();Action++)
    {
        for(int valeur=0;valeur<_team->GetnbValeurStat();valeur++)
        {
            stat=player->getStatSet (Action,valeur);
            strAffiche.setNum (stat,'g',4);
            if(this->StatJoueur[player->get_NumMaillot ()]!=0)
                this->StatJoueur[player->get_NumMaillot ()]->setItem (numSet+2,col,new QTableWidgetItem(strAffiche));
            this->SetColor(Action,this->StatJoueur[player->get_NumMaillot ()]->item (numSet+2,col));
            col++;
        }

    }

}
void StatWidget::SetOldStatEquipeSet(int numSet)
{

    int col=1;
    int stat=0;
    QString strAffiche;
    Set* oldSet=Match::donneInstance ()->GetOldSet (numSet);
    QString save=oldSet->Restaurer (QString("team"));
    QStringList listsave=save.split ("_");
    for(int Action=0;Action<_listAction.size();Action++)
    {
        for(int valeur=0;valeur<_team->GetnbValeurStat();valeur++)
        {
            strAffiche=listsave[stat];
            this->_tabElts->setItem (numSet+2,col,new QTableWidgetItem(strAffiche));
            this->SetColor(Action,this->_tabElts->item (numSet+2,col));
            col++;
            stat++;

        }

    }
}
void StatWidget::InitListAction(QStringList action)
{
    this->_listAction=action;
}

void StatWidget::SetOldStatJoueurSet(Joueur *player,int numSet)
{

    int col=1;
    int stat=0;
    QString strAffiche;
    Set* oldSet=Match::donneInstance ()->GetOldSet (numSet);
    QString rech;
    rech=rech.setNum (player->get_NumMaillot ());
    QString save=oldSet->Restaurer (rech);
    QStringList listsave=save.split ("_");
    for(int Action=0;Action<_listAction.size();Action++)
    {
        for(int valeur=0;valeur<_team->GetnbValeurStat();valeur++)
        {
            strAffiche=listsave[stat];
            this->StatJoueur[player->get_NumMaillot ()]->setItem (numSet+2,col,new QTableWidgetItem(strAffiche));
            this->SetColor(Action,StatJoueur[player->get_NumMaillot ()]->item (numSet+2,col));
            col++;
            stat++;

        }

    }

}

void StatWidget::SetStatEquipeSet(Equipe *team,int numSet)
{
    double stat;
    int col=1;
    QString strAffiche;
    for(int Action=0;Action<_listAction.size();Action++)
    {
        for(int valeur=0;valeur<InitValeur::donneInstance()->GetSizeValeur();valeur++)
        {
            stat=team->getStatSet (Action,valeur);
            strAffiche.setNum (stat,'g',4);
            this->_tabElts->setItem (numSet+2,col,new QTableWidgetItem(strAffiche));
            this->SetColor(Action,this->_tabElts->item (numSet+2,col));

            col++;
        }

    }

}

void StatWidget::SetStatJoueurMatch(Joueur *player)
{
    double stat;
    int col=1;
    QString strAffiche;
    for(int Action=0;Action<_listAction.size();Action++)
    {
        for(int valeur=0;valeur<_team->GetnbValeurStat();valeur++)
        {
            stat=player->getStatMatch (Action,valeur);
            strAffiche.setNum (stat,'g',4);
            this->StatJoueur[player->get_NumMaillot ()]->setItem (2,col,new QTableWidgetItem(strAffiche));
            this->SetColor(Action,StatJoueur[player->get_NumMaillot ()]->item (2,col));
             this->StatJoueur[player->get_NumMaillot ()]->Resize ();

            col++;
        }

    }

}


void StatWidget::SetStatEquipeMatch(Equipe *team)
{
    double stat;
    int col=1;
    QString strAffiche;
    for(int Action=0;Action<_listAction.size();Action++)
    {
        for(int valeur=0;valeur<InitValeur::donneInstance()->GetSizeValeur();valeur++)
        {
            stat=team ->getStatMatch(Action,valeur);
            strAffiche.setNum (stat,'g',4);
            this->_tabElts->setItem (2,col,new QTableWidgetItem(strAffiche));
            this->SetColor(Action,this->_tabElts->item (2,col));
            col++;
        }

    }

}
void StatWidget::SetStatoldEquipeMatch()
{
    /*double stat;
    int col=1;
    QString strAffiche;
    QString save=Match::donneInstance ()->Restaurer ("team");
    QStringList listsave=save.split ("_");
    for(int Action=0;Action<_listAction.size();Action++)
    {
        for(int valeur=0;valeur<_team->GetnbValeurStat();valeur++)
        {
            strAffiche=listsave[stat];
            this->_tabElts->setItem (2,col,new QTableWidgetItem(strAffiche));
             this->SetColor(Action,this->_tabElts->item (2,col));
            col++;
        }

    }*/

}
void StatWidget::slot_export()
{
    this->ExportCVS();
}

void StatWidget::slot_changement (int i)
{
    if(i!=0)
    {
        Joueur * player;
        QString nom=ui->tabWidget->tabText (i);
        QStringList list=nom.split ("_");
        int num=list.at (1).toInt();
        for(int i=0;i<_listJoueur.count();i++)
        {
            if(num==_listJoueur.at(i)->get_NumMaillot())
            {
                player=_listJoueur.at(i);
            }
        }

        /// ancien set
        for(int k=1;k<Match::donneInstance ()->Getnbset ();k++)
        {
            SetOldStatJoueurSet(player,k);
        }
        /// set en cours
        SetStatJoueurSet(player,Match::donneInstance()->Getnbset ());
        /// match
        SetStatJoueurMatch(player);
    }
    else
    {
        /// ancien set
        for(int k=1;k<Match::donneInstance ()->Getnbset ();k++)
        {
            SetOldStatEquipeSet(k);
        }
        /// set en cours
        SetStatEquipeSet(_team,Match::donneInstance()->Getnbset ());
        /// match
        SetStatEquipeMatch(_team);
    }
}

void StatWidget::ExportCVS ()
{
    Match::donneInstance ()->Enregistrer ();
    Match::donneInstance()->GetCurrentSet()->Enregistrer();
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "*.csv");

    QFile file(fichier);

    if (file.open(QFile::WriteOnly))
    {
        QTextStream out(&file);
        out<<";;;";
        for(int i=0;i<_listAction.size();i++)
        {
            out<<_listAction.at(i)<<";;;;;;;";
        }
        out<<";;\n";
        for(int i=0;i<_listAction.size();i++)
        {
            out<<";++;+;0;-;--;tot;eff";
        }
        out<<"\n";
        QString saveMatch=Match::donneInstance ()->StatString (QString("team"));
        saveMatch.replace ("_",";");
        out<<"Equipe\n";
        out<<"Match;"<<saveMatch<<"\n";
        for(int k=1;k<Match::donneInstance ()->Getnbset ();k++)
        {
            Set* oldSet=Match::donneInstance ()->GetOldSet (k);
            QString save=oldSet->Restaurer (QString("team"));
            save.replace ("_",";");
            out<<"Set"<<k<<";"<<save<<"\n";
        }
        if(Match::donneInstance ()->Getnbset ()<=5)
        {
            QString save=Match::donneInstance ()->GetCurrentSet()->Restaurer (QString("team"));
            save.replace ("_",";");
            out<<"Set"<<Match::donneInstance ()->Getnbset ()<<";"<<save<<"\n";
        }
        out<<"\n";


        for(int i=0;i<this->_listJoueur.size ();i++)
        {
            QString id;
            id.setNum (_listJoueur.at (i)->get_NumMaillot ());
            out<<_listJoueur.at(i)->get_Prenom ()<<"( "<<_listJoueur.at (i)->get_NumMaillot ()<<" )\n";
            QString saveMatch=Match::donneInstance ()->StatString (id);
            saveMatch.replace ("_",";");
            out<<"Match;"<<saveMatch<<"\n";
            for(int k=1;k<Match::donneInstance ()->Getnbset ();k++)
            {
                Set* oldSet=Match::donneInstance ()->GetOldSet (k);

                QString save=oldSet->Restaurer (id);
                save.replace ("_",";");
                out<<"Set"<<k<<";"<<save<<"\n";
            }
            if(Match::donneInstance ()->Getnbset ()<=5)
            {
                QString save=Match::donneInstance ()->GetCurrentSet()->Restaurer (id);
                save.replace ("_",";");
                out<<"Set"<<Match::donneInstance ()->Getnbset ()<<";"<<save<<"\n";
            }

            out<<"\n";

        }
    }
}

void StatWidget::Imprimer ()
{
    QPrinter printer;
    QPrintDialog dialog(&printer);
    QTextDocument *_fichier_doc;
    _fichier_doc=new QTextDocument();
    QString html;


    html="<table width=\"100%\" border =\"1\" cellspacing=\"1\" cellpadding=\"1\"><tr BGCOLOR=\"#8CC6D7\" WIDTH=\"80%\" ><td>";

    html=html+ "<FONT SIZE=6>"+"<b>"+"Match du :"+Match::donneInstance ()->GetDate ()+" : ""<br>";
    html = html +Match::donneInstance ()->getTeam ()->GetNom ()+"  Vs  "+Match::donneInstance ()->getadvs ()+"</b>"+"</FONT>"+"<br>"+"</td></tr><tr><td>";

    html=html+"<\boby>";


    html=html+"<TABLE BORDER=\"1\">";
    html=html+"<CAPTION> Equipe </CAPTION>";

    html=ColonneHtml(html);
    QString saveMatch=Match::donneInstance ()->StatString (QString("team"));

    html=html+"<td>"+"Match"+"</td>";
    QStringList strListsaveMatch=saveMatch.split ("_");
    for(int i=0;i<strListsaveMatch.size ();i++)
    {
        html=html+"<td>"+strListsaveMatch.at (i)+"</td>";
    }
    html=html+"</TR>";
    html=html+"<TR>";
    for(int k=0;k<Match::donneInstance ()->Getnbset ();k++)
    {
        Set* oldSet=Match::donneInstance ()->GetOldSet (k+1);
        QString save=oldSet->Restaurer (QString("team"));
        QStringList strListsave=save.split ("_");
        QString strSet;
        strSet.setNum (k+1);
        strSet="Set "+strSet;
        html=html+"<td>"+strSet+"</td>";
        for(int i=0;i<strListsave.size ();i++)
        {

            html=html+"<td>"+strListsave.at (i)+"</td>";
        }
    }
    html=html+"</TR>";
    html=html+"</TABLE>";
    for(int i=0;i<this->_listJoueur.size ();i++)
    {
        QString id;
        id.setNum (_listJoueur.at (i)->get_NumMaillot ());
        QString strJou=_listJoueur.at(i)->get_Prenom ()+"( "+id+" )";
        html=html+"<TABLE BORDER=\"1\">";
        html=html+"<CAPTION>"+strJou +"</CAPTION>";
        html=ColonneHtml(html);





        QString saveMatch=Match::donneInstance ()->StatString (id);
        QStringList strListsaveMatch=saveMatch.split ("_");
        html=html+"<td>"+"Match"+"</td>";
        for(int i=0;i<strListsaveMatch.size ();i++)
        {
            html=html+"<td>"+strListsaveMatch.at (i)+"</td>";
        }
        html=html+"</TR>";
        html=html+"<TR>";
        for(int k=0;k<Match::donneInstance ()->Getnbset ();k++)
        {
            Set* oldSet=Match::donneInstance ()->GetOldSet (k+1);
            QString save=oldSet->Restaurer (id);
            QStringList strListsave=save.split ("_");
            QString strSet;
            strSet.setNum (k+1);
            strSet="Set "+strSet;
            html=html+"<td>"+strSet+"</td>";
            for(int i=0;i<strListsave.size ();i++)
            {

                html=html+"<td>"+strListsave.at (i)+"</td>";
            }
        }
        html=html+"</TR>";
        html=html+"</TABLE>";
    }
    html=html+"</TR>";
    html=html+"<TR>";

    html=html+"</TR>";
    html=html+"</TABLE>";

  html=html +"</td></table>";

    _fichier_doc->setHtml(html);
    if(dialog.exec() == QDialog::Accepted)
    {

        printer.setOrientation(QPrinter::Landscape);


        _fichier_doc->setPageSize(printer.pageRect().size());
        QRect innerRect = printer.pageRect();


        innerRect.setBottom(innerRect.bottom()+ 2);
        QRect contentRect = QRect(QPoint(0,0), _fichier_doc->size().toSize());
        QRect currentRect = QRect(QPoint(0,0), innerRect.size());
        QPainter painter(&printer);
        int count = 0;
        int nbpage=0;
        while (currentRect.intersects(contentRect))
        {
            nbpage++;
            currentRect.translate(0, currentRect.height());
        }
        contentRect = QRect(QPoint(0,0), _fichier_doc->size().toSize());
        currentRect = QRect(QPoint(0,0), innerRect.size());
        painter.save();

        while (currentRect.intersects(contentRect))
        {
            _fichier_doc->drawContents(&painter, currentRect);
            count++;
            currentRect.translate(0, currentRect.height());
            painter.restore();
            painter.drawText(10, printer.pageRect().bottom() - 10, QString("Page %1/%2").arg(count).arg(nbpage));
            painter.save();
            painter.translate(0, -currentRect.height() * count + 30);
            if (currentRect.intersects(contentRect))
                printer.newPage();
        }
        painter.restore();
        painter.end();

    }
}

void StatWidget::Resize ()
{
    this->_tabElts->Resize();
}

QString StatWidget::ColonneHtml(QString html)
{
    html=html+"<TR>";
    html=html+"<td></td>"+"<td></td>"+"<td></td>";


    for(int i=0;i<_listAction.size();i++)
    {
        html=html+"<td>"+_listAction.at(i)+"</td>"+"<td></td>"+"<td></td>"+"<td></td>"+"<td></td>"+"<td></td>"+"<td></td>";
    }
    html=html+"</TR>";
    html=html+"<TR>";
    html=html+"<td></td>";
    for(int i=0;i<_listAction.size();i++)
    {
        for(int k=0;k<InitValeur::donneInstance()->GetSizeValeur();k++)
        {

            html=html+"<td>"+InitValeur::donneInstance()->GetElementValeur(k)+"</td>";

        }

    }
        html=html+"</TR>";
        html=html+"<TR>";
    return html;
}
void StatWidget::clean ()
{

   /**/

   /* QMap <int,TableElementsState *>::Iterator  it = StatJoueur.begin();
    while(it != StatJoueur.end())
    {
        if(it.value()!=0)
        {
            delete it.value();
        }
        ++it;
    }*/

    ui->tabWidget->setCurrentIndex(0);
    int count=ui->tabWidget->count();
    for(int k=count+1;k>0;k--)
       {

           ui->tabWidget->removeTab (k);
           delete ui->tabWidget->widget(k);

       }
    // ui->tabWidget->clear();
    StatJoueur.clear();

   delete this->_tabElts;

    count=ui->tabWidget->count();

    this->_listJoueur.clear();
    this->_listAction.clear();


}
void StatWidget::SetColor(int Action,QTableWidgetItem *item)
{
    QColor color;
    switch(Action)
    {
    case 0:
        color.setRgb (255,153,153);
        break;
    case 1:
        color.setRgb (64,224,208);
        break;
    case 2:
        color.setRgb (153,255,153);
        break;
    case 3:
        color.setRgb (204,204,255);
        break;
    case 4:
        color.setRgb (255,102,255);
        break;
    case 5:
        color.setRgb (238,203,173);
        break;
    }
    item->setBackground (color);
}

TableElementsState::TableElementsState(QWidget * parent)
{
    int sizeValeur=InitValeur::donneInstance()->GetSizeValeur();
    int sizeAction=InitAction::donneInstance()->GetSizeAction();
    this->setColumnCount (sizeAction*sizeValeur+1);
    this->setRowCount (8);
    //this->setSpan (0,1,0,5);


    //this->setHorizontalHeaderItem(0,new QTableWidgetItem(QString( "Attaque" ) ));
    // this->hideRow (0);
    this->horizontalHeader ()->hide();
    this->verticalHeader ()->hide();
    /*QTableWidgetItem * item=new QTableWidgetItem(QString( "Attaque"));
    item->setTextAlignment (Qt::AlignCenter);*/
    this->setItem (0,0,new QTableWidgetItem(QString( "Phases")));
    this->setItem (2,0,new QTableWidgetItem(QString( "Match")));
    this->setItem (3,0,new QTableWidgetItem(QString( "Set1")));
    this->setItem (4,0,new QTableWidgetItem(QString( "Set2")));
    this->setItem (5,0,new QTableWidgetItem(QString( "Set3")));
    this->setItem (6,0,new QTableWidgetItem(QString( "Set4")));
    this->setItem (7,0,new QTableWidgetItem(QString( "Set5")));

    QColor color;
    for(int i=0;i<sizeAction;i++)
    {
        switch(i)
        {
        case 0:
            color.setRgb (255,153,153);
            break;
        case 1:
            color.setRgb (64,224,208);
            break;
        case 2:
            color.setRgb (153,255,153);
            break;
        case 3:
            color.setRgb (204,204,255);
            break;
        case 4:
            color.setRgb (255,102,255);
            break;
        case 5:
            color.setRgb (238,203,173);
            break;
        }

        int col=sizeValeur/2;
        QString valeurAction=InitAction::donneInstance()->GetElementAction(i);
        this->setItem (0,(i*sizeValeur)+col,new QTableWidgetItem(valeurAction));
        for(int k=0;k<sizeValeur;k++)
        {
            this->setItem (1,(i*sizeValeur)+k+1,new QTableWidgetItem(InitValeur::donneInstance()->GetElementValeur((k))));
            QTableWidgetItem * Item;
            Item=this->item (1,(i*sizeValeur)+k+1);
            Item->setBackground (color);
            Item->setToolTip("(Vpp-Vmm)/tot");
            Item=this->item (0,(i*sizeValeur)+k+1);
            if(Item!=0)
                Item->setBackground (color);
        }



    }

    if(parent->layout() != 0)
        parent->layout()->addWidget(this);


    this->resizeColumnsToContents();
    this->resizeRowsToContents();

}


void TableElementsState::Resize()
{
this->resizeColumnsToContents ();
this->resizeRowsToContents ();
}

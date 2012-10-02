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

#ifndef WIDGETTABEFF_H
#define WIDGETTABEFF_H

#include <QWidget>
#include <QTableWidget>
#include "Equipe.h"

class TableEff: public QTableWidget
{
Q_OBJECT
public:

    TableEff(QWidget * parent,QList <Joueur*> list,QStringList Listaction);
public slots:
    void SlotDDClick(int row,int col);
private:
    QList <Joueur*> _list;
};

namespace Ui {
    class WidgetTabEff;
}

class WidgetTabEff : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTabEff(QWidget *parent = 0);
    ~WidgetTabEff();
    void Init(  QList <Joueur*> listjoueur,QStringList listaction);
    void Ouvrir();
    void clean();
    Joueur* PlayerfromNum(QString num);
public slots:
    void SlotMiseAJour(bool isSet=false,int numSet=0);

private:
    Ui::WidgetTabEff *ui;
    TableEff* _tabElts;
    QStringList _listaction;
    QList <Joueur*>_listJoueur;


};

#endif // WIDGETTABEFF_H

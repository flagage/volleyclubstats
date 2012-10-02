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

#ifndef LISTEVENEMENT_H
#define LISTEVENEMENT_H

#include <QListWidget>
#include "QMenu"

class ListEvenement : public QListWidget
{
    Q_OBJECT
public:
    explicit ListEvenement(bool menu=true,QWidget *parent = 0);
    ~ListEvenement();
    void AjouterItem();
    void addItem( QString label);

private:
  QMenu* _menu;
  QMenu* _menuTm;
  QMenu* _menuFirst;
  bool _MenuActif;
  void Connection();
  void Initialisation();

signals:
    void add(int);
    void modif(int);
    void sup(int);
    void supTm(int);

public slots:
    void Slot_DClick();
    void Slot_Action(QAction *);
    void Slot_ActionTm(QAction * action);
};

#endif // LISTEVENEMENT_H

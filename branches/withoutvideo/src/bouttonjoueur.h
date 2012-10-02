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

#ifndef BOUTTONJOUEUR_H
#define BOUTTONJOUEUR_H

#include <QPushButton>
#include <QMouseEvent>

class BouttonJoueur : public QPushButton
{
    Q_OBJECT
    void mousePressEvent(QMouseEvent *e);
    //void mousePressEvent (QMouseEvent Qt::RightButton);
public:
    explicit BouttonJoueur( QString text, QWidget *parent=0);
    void AjouterMenuBanc();

signals:
    void lclicked();
    void rclicked();
    void ModifJoueur();
    void AddJoueur();
    void SupJoueur();
    void AfficheStat();

public slots:
    void SlotMenuJoueur(QAction *);
};

#endif // BOUTTONJOUEUR_H

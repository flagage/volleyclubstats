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

#ifndef FENETREMODIFACTION_H
#define FENETREMODIFACTION_H

#include <QDialog>

namespace Ui {
    class FenetreModifAction;
}

class FenetreModifAction : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreModifAction(QWidget *parent = 0);
    ~FenetreModifAction();
    void Initialisation(QStringList list,int numJoueur,QString action);
    QString GetValeur();

private:
    Ui::FenetreModifAction *ui;
};

#endif // FENETREMODIFACTION_H

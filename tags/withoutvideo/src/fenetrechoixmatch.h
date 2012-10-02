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

#ifndef FENETRECHOIXMATCH_H
#define FENETRECHOIXMATCH_H

#include <QDialog>
#include "tablematch.h"

namespace Ui {
    class FenetreChoixMatch;
}

class FenetreChoixMatch : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreChoixMatch(QWidget *parent = 0);
    ~FenetreChoixMatch();
    bool Ouvrir();
    QString GetFichierSelectionner();
    void Actualiser();

private:
    Ui::FenetreChoixMatch *ui;
    //WidgRevMatch *Widget;
    TableMatch* _table;
    QString _FichierSelectionner;

public slots:
    void Slot_ok();
    void Slot_sup();
    void Slot_importer();
    void Slot_exporter();
};

#endif // FENETRECHOIXMATCH_H

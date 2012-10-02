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

#include "vcslineedit.h"

VCSLineEdit::VCSLineEdit(QWidget *parent) :
        QLineEdit(parent)
{
    this->setAutoFillBackground(true);
    this->setToolTip("Joueur Valeur");
}


void VCSLineEdit::keyPressEvent ( QKeyEvent * event )
{
    switch(event->key())
    {
    case Qt::Key_Asterisk:
        this->clear();
        break;

    case Qt::Key_Slash:
        this->clear ();
        emit ChangeAction();
        break;

    case Qt::Key_S:
        emit Service();
        break;

    case Qt::Key_A:
        emit Attaque();
        break;
    case Qt::Key_R:
        emit Reception();
        break;
    case Qt::Key_D:
        emit Defense();
        break;
    case Qt::Key_P:
        emit Passe();
        break;
    case Qt::Key_C:
        emit Contre();
        break;
    case Qt::Key_N:
        emit ComplementAction();
        break;
    case Qt::Key_Space:
        emit ComplementAction();
        break;
    case Qt::Key_L:
        emit Relance();
        break;
    default:
        QLineEdit::keyPressEvent (event);
        break;

    }


}

void VCSLineEdit::ChangeBackColor(int action)
{
    QPalette palette=this->palette ();

    switch(action)
    {
    case 0:
        palette.setColor (QPalette::Base,QColor(255,153,153));
        break;
    case 1:
        palette.setColor (QPalette::Base,QColor(64,224,208));
        break;
    case 2:
        palette.setColor (QPalette::Base,QColor(153,255,153));
        break;
    case 3:
        palette.setColor (QPalette::Base,QColor(204,204,255));
        break;
    case 4:
        palette.setColor (QPalette::Base,QColor(255,102,255));
        break;
    case 5:
        palette.setColor (QPalette::Base,QColor(238,203,173));
        break;

    default:
        palette.setColor (QPalette::Base,QColor(Qt::white));
        break;
    }

    this->setPalette(palette);

}

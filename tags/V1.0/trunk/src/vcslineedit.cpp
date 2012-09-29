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

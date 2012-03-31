/**
Copyright LAGAGE Fr�d�ric ,2011
flagage@gmail.com

Ce logiciel est un programme informatique servant � capturer en direct des statistiques des joueurs de volley-ball.

Ce logiciel est r�gi par la licence CeCILLsoumise au droit fran�ais et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL telle que diffus�e par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilit� au code source et des droits de copie,
de modification et de redistribution accord�s par cette licence, il n'est
offert aux utilisateurs qu'une garantie limit�e.  Pour les m�mes raisons,
seule une responsabilit� restreinte p�se sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les conc�dants successifs.

A cet �gard  l'attention de l'utilisateur est attir�e sur les risques
associ�s au chargement,  � l'utilisation,  � la modification et/ou au
d�veloppement et � la reproduction du logiciel par l'utilisateur �tant
donn� sa sp�cificit� de logiciel libre, qui peut le rendre complexe �
manipuler et qui le r�serve donc � des d�veloppeurs et des professionnels
avertis poss�dant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invit�s � charger  et  tester  l'ad�quation  du
logiciel � leurs besoins dans des conditions permettant d'assurer la
s�curit� de leurs syst�mes et ou de leurs donn�es et, plus g�n�ralement,
� l'utiliser et l'exploiter dans les m�mes conditions de s�curit�.

Le fait que vous puissiez acc�der � cet en-t�te signifie que vous avez
pris connaissance de la licence CeCILL et que vous en avez accept� les
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

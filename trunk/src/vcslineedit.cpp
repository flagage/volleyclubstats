#include "vcslineedit.h"

VCSLineEdit::VCSLineEdit(QWidget *parent) :
        QLineEdit(parent)
{
    this->setAutoFillBackground(true);
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

    default:
        palette.setColor (QPalette::Base,QColor(Qt::white));
        break;
    }

    this->setPalette(palette);

}

#ifndef VCSLINEEDIT_H
#define VCSLINEEDIT_H

#include <QLineEdit>
#include "QKeyEvent"
class VCSLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit VCSLineEdit(QWidget * parent = 0);
    void keyPressEvent ( QKeyEvent * event );
    void ChangeBackColor(int action);
signals:
    void ChangeAction();
    void Attaque();
    void Service();
    void Reception();
    void Defense();
    void Contre();
    void Passe();

public slots:

};

#endif // VCSLINEEDIT_H

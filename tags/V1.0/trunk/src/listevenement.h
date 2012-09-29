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

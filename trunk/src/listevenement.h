#ifndef LISTEVENEMENT_H
#define LISTEVENEMENT_H

#include <QListWidget>
#include "QMenu"

class ListEvenement : public QListWidget
{
    Q_OBJECT
public:
    explicit ListEvenement(QWidget *parent = 0);
    ~ListEvenement();
    void AjouterItem();

private:
  QMenu* _menu;
  //QListWidgetItem* _ItemSelect;
  //QWidget *_parentcur;

  void Connection();
  void Initialisation();

signals:
    void add(int);
    void modif(int);
    void sup(int);
public slots:
   // void Slot_Click();
    void Slot_DClick();
    void Slot_Action(QAction *);
};

#endif // LISTEVENEMENT_H

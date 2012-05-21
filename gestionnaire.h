#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include "monstre.h"
#include "projectile.h"
#include "tower.h"
#include <QList>
#include <QPixmap>
#include <QObject>

class gestionnaire: public QWidget
{
    Q_OBJECT
public:
    gestionnaire(QImage map,QList<QPoint> *chemin);
    void paint(QPainter *painter, QPaintEvent *event,long elapsed);
        QList<Tower*> ListeTower;
        QList<Monstre*> ListeMonstre;
private:
   // int MapX, MapY;
 //   QList<Monstre*> ListeMonstre;
   // QList<Tower*> ListeTower;
    QList<Projectile*> ListeProjectile;
    QBrush background;
    Tower *t;

    char *m_chemin;
//public slots:
  //  void ajouttour(int type,int x,int y,QRect ecran)
signals:
    void updatelabelmoney(int);
    void updatelabelvie(int);


};

#endif // GESTIONNAIRE_H

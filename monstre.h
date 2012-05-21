#ifndef MONSTRE_H
#define MONSTRE_H

#include <QObject>
#include <QVector2D>
#include <QColor>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QColor>

class Monstre
{
public:
    explicit Monstre(QVector2D monstre,float vitesse,float vie,int type,float taille,QColor carapace,long temps,QList<QPoint> *chemin);
    void paint(QPainter * painter);
    void avancer(long elapsed);
   QVector2D monstre;
   float vitesse;
    int vie;
     int type;
    float taille;
    void Delete();
    QColor carapace;
    bool isDelete;
    void hit(float damage);
    long temps;
    int etape;
    QList<QPoint*>* chemin;
    //QVector2D nextchemin;
private:
    int terraintype;
        
};

#endif // MONSTRE_H

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QObject>
#include <monstre.h>
#include <QVector2D>
#include <QColor>
#include <QPainter>
#include <QStyleOptionGraphicsItem>


class Projectile
{
public:
    explicit Projectile(QVector2D source, QVector2D cible,float taille, float vitesse,int type, float degat,QColor couleur,long temps);
    void paint(QPainter * painter);
    void avancer(long elapsed);
    Monstre *monstre;
    QVector2D source, cible, pos, direction;
    long temps;
    bool cibletoucher;
    float taille,vitesse,degat;
    int type;
    QColor couleur;
    
};

#endif // PROJECTILE_H

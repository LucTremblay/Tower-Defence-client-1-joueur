#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QVector2D>
#include <QColor>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <projectile.h>

class Tower
{
public:
    Tower(int x,int y,float cadence,float portee,int prixbase,float damage,int type,float tailleprojectile,QColor canon,QColor base,int lh);

    int m_x;
    int m_y;
    float m_cadence;
    float m_portee;
    int m_prixbase;
    float m_damage;
    int m_type;
    float   m_tailleprojectile;
    QColor    m_canon;
    QColor    m_base;
    int   m_lh;
    QVector2D m_center;
    bool havetarget;
    int m_rotation;
    long m_derniertire;
    int m_level;
    QVector2D m_direction;

  //  QVector2D GetInterSect(  QVector2D source,
    //                         QVector2D destination,
    //                         float vitesseprojectile,
    //                         float vitessemonstre,
     //                        QVector2D projectile_pos,
     //                        QVector2D monstre_pos);

    void suivre(QVector2D posmonstre);

    int revendre();

    void paint(QPainter *painter);
    Projectile* Shoot(Monstre *monstre, long elapsed);
};

#endif // TOWER_H

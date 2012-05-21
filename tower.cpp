#include "tower.h"
#include <qmath.h>
#include "projectile.h"



Tower::Tower(int x,int y,float cadence,float portee,int prixbase,float damage,int type,float tailleprojectile,QColor canon,QColor base,int lh)
{
    m_x=x;
    m_y=y;
    m_cadence=cadence;
    m_portee=portee;
    m_level=1;
    m_prixbase=prixbase;
    m_damage=damage;
    m_type=type;
    m_canon=canon;
    m_tailleprojectile=tailleprojectile;
    m_canon=canon;
    havetarget=false;
    m_base=base;
    m_lh=lh;
    m_derniertire=0;
    m_rotation=0;
    m_center.setX(x+lh/2);
    m_center.setY(y+lh/2);
    m_direction.setX(m_center.x());
    m_direction.setY(m_center.y()+lh/2);
}
int Tower::revendre()
{
    return (this->m_level/10)*m_prixbase+m_prixbase;
}
void Tower::suivre(QVector2D posmonstre)
{
    QVector2D tmm=posmonstre-m_center;

    tmm=tmm/sqrt(tmm.lengthSquared());
    tmm=tmm*m_lh/2;
    //int angle=acos(QVector2D::dotProduct(m_direction,tmm)/(sqrt(m_direction.lengthSquared())*sqrt(tmm.lengthSquared())));
    //m_rotation=angle;
    m_direction.setX(tmm.x()+m_center.x());
    m_direction.setY(tmm.y()+m_center.y());
}
void Tower::paint(QPainter *painter)
{
   // painter->drawLine(10,10,100,199);
    painter->setPen(QPen(Qt::NoPen));
    painter->setBrush(m_base);
    painter->drawEllipse(m_x,m_y,m_lh,m_lh);
    painter->setBrush(m_canon);
    painter->setPen(QPen(QBrush(Qt::black),5));
    painter->drawLine(m_x+m_lh/2,m_y+m_lh/2,m_direction.x(),m_direction.y());
    //painter->drawPath();
   //painter->drawRect(m_x+m_lh/2,m_y+m_lh/2,m_lh/10,m_lh);
  // painter->rotate(m_rotation);
}
Projectile* Tower::Shoot(Monstre *monstre, long elapsed)
{
    if (elapsed - m_derniertire < m_cadence) return 0;
    QVector2D tcenter(m_center.x(), m_center.y());
    QVector2D target(monstre->monstre.x(),monstre->monstre.y());
    if (target.isNull() || (this->m_center - target).length() > this->m_portee)
        return 0;
    m_derniertire = elapsed;
    Projectile *projectile = new Projectile(tcenter, target,m_tailleprojectile,2,1,m_damage*m_level,Qt::black,elapsed);
    projectile->monstre = monstre;
    return projectile;
}

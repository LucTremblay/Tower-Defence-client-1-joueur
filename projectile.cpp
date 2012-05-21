#include "projectile.h"

Projectile::Projectile(QVector2D source, QVector2D cible,float taille, float vitesse,int type, float degat,QColor couleur,long temps)
{
    this->source = source;
    this->cible = cible;
    this->taille=taille;
    this->vitesse=vitesse;
    this->type=type;
    this->degat=degat;
    this->couleur=couleur;
    this->direction = cible - source;
    this->direction.normalize();
    this->cibletoucher = false;
    this->temps=temps;

}
void Projectile::paint ( QPainter * painter)
{
    if (!cibletoucher)
    {
    painter->setPen(QPen(Qt::NoPen));
    painter->setBrush(couleur);
    painter->drawEllipse(this->pos.x(), this->pos.y(), taille, taille);
    }
}
\
void Projectile::avancer(long elapsed)
{
    float t = elapsed - this->temps;
    this->pos = source + t * this->vitesse * direction;
    if ((pos - source).lengthSquared() > (cible - source).lengthSquared())
        this->cibletoucher = true;
}

#include "monstre.h"
#include <QApplication>
#include <QDesktopWidget>
#include <Q3SortedList>
#include <gestionnaire.h>
Monstre::Monstre(QVector2D monstre,float vitesse,float vie,int type,float taille,QColor carapace,long temps,QList<QPoint> *chemin)
{
    this->monstre=monstre;
    this->vitesse=vitesse;
    this->vie=vie;
    this->type=type;
    this->taille=taille;
    this->carapace=carapace;
    this->temps=temps;
    this->isDelete=false;
    this->etape=0;
    this->chemin = new QList<QPoint*>();
    for(int i=0;i<chemin->length();i++)
    {
        this->chemin->append(new QPoint(chemin->at(i).x()*(int)(QApplication::desktop()->width()/24),chemin->at(i).y()*(int)(QApplication::desktop()->height()/24)));
    }
//    int last=0;

    for(int i=0;i<this->chemin->length();i++)
    {
        this->chemin->at(i)->setY(this->chemin->at(i)->y() + 20);
        this->chemin->at(i)->setX(this->chemin->at(i)->x() + 40);
//        if(chemin->at(i).x()>last)
//        {
//            last=chemin->at(i).x();
//            chemin->move(i,chemin->length()-1);
//            i--;
//        }
       // qSort(chemin->at(0),chemin->at(chemin->size()));


    }


    this->monstre = QVector2D(*this->chemin->at(0));
}

void Monstre::paint ( QPainter * painter)
{
    painter->setPen(QPen(Qt::NoPen));
    painter->setBrush(carapace);
    painter->drawEllipse(this->monstre.x()-(taille/2), this->monstre.y()-(taille/2), taille, taille);
}
void Monstre::avancer(long elapsed)
{

    QVector2D depart(*chemin->at(etape));
    QVector2D nextchemin(*chemin->at(etape+1));
    QVector2D longueur=nextchemin-depart;
    QVector2D Monstrelongueur=monstre-depart;
    QVector2D Monstrearriver = nextchemin-monstre;
    if(Monstrelongueur.lengthSquared()>=longueur.lengthSquared())
    {
        etape++;
        if(etape<chemin->size()-1)
        {
        nextchemin = QVector2D(*chemin->at(etape+1));
        Monstrearriver = nextchemin-monstre;
        }
        else
        {
            isDelete=true;
        }
    }
        monstre= monstre+ Monstrearriver/Monstrearriver.length() * 2;


}
void Monstre::hit(float damage)
{
    vie-=damage;
}
void Monstre::Delete()
{
    delete this;
}

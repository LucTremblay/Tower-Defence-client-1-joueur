#include "mapgrid.h"
#include <QtGui>
#include "gestionnaire.h"
#include "towerdefence.h"

MapGrid::MapGrid(QRect ecran,QList<QPoint> *chemin,gestionnaire *gest,QWidget *parent) :
    QWidget(parent), gesti(gest)
{
    elapsed=0;
  //  setFixedSize((ecran.width()-(ecran.width()/10)),ecran.height());
    setFixedSize(ecran.width(),ecran.height());
    this->showFullScreen();
    setAutoFillBackground(false);
    m_ecran=ecran;
    m_chemin=chemin;
    phaseini=true;
   // mapx=(ecran.width()-(ecran.width()/10))/24;
    mapx=(int)(ecran.width()/24);
    mapy=(int)(ecran.height()/24);
    //connect(this,SIGNAL(AjoutTour(int,int,int,QRect)),gesti,SLOT(ajouttour(int,int,int,QRect)));

    for(int i=0;i<24;i++)
    {
        for(int j=0;j<24;j++)
        {
             if(i<=12 && j<=24)
             {             
                grido[i][j]=1;
             }
             else
             {
                grido[i][j]=0;
             }
        }
    }

    for(int i=0;i<24;i++)
    {
           grido[i][24]=0;
    }
    for(int i=0;i<m_chemin->size();i++)
    {
           grido[m_chemin->at(i).x()][m_chemin->at(i).y()]=0;
    }
}

void MapGrid::animate()
{
   // if (gestionnaire->gameresult == 1)
   // {
   //     gameOverW();
  //      return;
  // else if (gestionnaire->gameresult == 2)
  //  {
  //      gameOverL();
  //      return;
  //  }
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval());
    repaint();
}
void MapGrid::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    gesti->paint(&painter,event,elapsed);
   // painter.end();
}
void MapGrid::mousePressEvent(QMouseEvent *event)
{
    int x=event->x()/mapx;
    int y=event->y()/mapy;
    if(grido[x][y])
    {
    if(event->button()==Qt::RightButton)
    {
        Monstre *m;
        QVector2D me(event->x(),event->y());
        m=new Monstre(me,0.10,20,1,20,Qt::green,elapsed,m_chemin);
        gesti->ListeMonstre.append(m);
       // int valide=grido[x][y];
       // emit mousepress(x,y,valide);
    }
    }

}
void MapGrid::mouseDoubleClickEvent(QMouseEvent *e)
{
    int x=(int)(e->x()/mapx);
    int y=(int)(e->y()/mapy);
    if(grido[x][y]==1)
    {

        Tower *t;
        t=new Tower(x*mapx+mapx/4,y*mapy+mapy/4,1000,250,50,10,1,10,Qt::black,Qt::blue,mapx/2);
        //if(TowerDefence::money>=t->m_prixbase)
       // {
            gesti->ListeTower.append(t);
            emit updatelabelmoney(t->m_prixbase*-1);
            grido[x][y]=0;
      //  }
    }
}


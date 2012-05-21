#include "towerdefence.h"
#include "ui_towerdefence.h"
#include <QPainter>
#include "mapgrid.h"
#include <QPaintEvent>
#include <QApplication>
#include <QDesktopWidget>
#include "mapgrid.h"
#include <iostream>
#include "gestionnaire.h"
#include "controlpannel.h"
#include <QRgb>
#include <QImage>
#include <QList>

TowerDefence::TowerDefence(QString carte, int vie, int credit):QMainWindow(),
    ui(new Ui::TowerDefence)
{

    this->vie=vie;
    this->money=credit;
    ui->setupUi(this);
    QRect ecran=QApplication::desktop()->rect();
    this->setFixedSize(ecran.width(),ecran.height());
    QImage map=construiremap(carte,ecran);
    gest=new gestionnaire(map,&chemin);

    mavue=new MapGrid(ecran,&chemin,gest,this);
    moncontrole=new ControlPannel(ecran,this->vie,this->money,this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),moncontrole,SLOT(animate()));
    connect(timer, SIGNAL(timeout()), mavue, SLOT(animate()));  
    connect(mavue, SIGNAL(updatelabelmoney(int)), this, SLOT(SetLabelmoney(int)));
    connect(gest, SIGNAL(updatelabelvie(int)), this, SLOT(SetLabelvie(int)));
    connect(gest, SIGNAL(updatelabelmoney(int)), this, SLOT(SetLabelmoney(int)));
    timer->start(30);
}

TowerDefence::~TowerDefence()
{
    delete ui;
}

void TowerDefence::SetLabelmoney(int money)
{
    this->money+=money;
    this->moncontrole->money=this->money;
}
void TowerDefence::SetLabelvie(int vie)
{
    this->vie+=vie;
    this->moncontrole->vie=this->vie;
}
QImage TowerDefence::construiremap(QString map,QRect ecran)
{


    QFile f(map);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QImage *p;
    QImage *ima;
    int z=0;

    QByteArray a;
    ima=new QImage(ecran.width(),ecran.height(),QImage::Format_ARGB32_Premultiplied);
    int mapx=(int)(ecran.width()/24);
    int mapy=(int)(ecran.height()/24);
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<24;j++)
        {

                a=f.read(1);
                if(a=="\n")
                {
                    a=f.read(1);
                }
                    switch(a[0])
                    {
                    case 'h':
                        p=new QImage("image/herbe.jpg");
                        break;
                    case 'n':
                        p=new QImage("image/Nord.jpg");
                        break;
                    case 's':
                        p=new QImage("image/Sud.jpg");
                        break;
                    case 'e':
                        p=new QImage("image/Est.jpg");
                        break;
                    case 'o':
                        p=new QImage("image/Ouest.jpg");
                        break;
                    case 'w':
                        p=new QImage("image/Nord_Ouest.jpg");
                        break;
                   case  'x':
                        p=new QImage("image/Sud_E.jpg");
                        break;
                    case 'y':
                        p=new QImage("image/Sud_Ouest.jpg");
                        break;
                    case 'z':
                        p=new QImage("image/Nord_Est.jpg");
                        break;
                    case '1':
                        p=new QImage("image/Mabase.jpg");
                        break;
                    case '2':
                        p=new QImage("image/Cabase.jpg");
                        break;
                    default:
                        p=new QImage("image/herbe.jpg");
                        break;


                    }
                    p=new QImage(p->scaled(mapx,mapy));
                    if(a[0]=='n' || a[0]=='s' ||a[0]=='e' ||a[0]=='o' ||a[0]=='w' ||a[0]=='x' ||a[0]=='y' ||a[0]=='z'||a[0]=='1'||a[0]=='2' )
                    {

                    int index = 0;
                    if (chemin.count() - 1 >= index)
                    {
                            while (j>=chemin.at(index).x())
                            {
                                index++;
                            }
                    }

                    QPoint im(j,i);
                    if (a[0] == 'y' || a[0] == 'n')
                    {
                        index--;
                        if (test.count() -1>=index && index-1>=0)
                        {
                            while (test.at(index-1) == "y" || test.at(index-1) == "n")
                            {
                                index --;
                            }
                        }
                    }

                    test.insert(index,a.left(1));
                    chemin.insert(index,im);

                    //chemin.at(z)[2]=a[0];
                  //  z++;

                    }
                    for(int f=0;f<mapx;f++)
                    {
                        for(int k=0;k<mapy;k++)
                        {
                           QRgb r=p->pixel(f,k);
                           ima->setPixel(j*mapx+f,i*mapy+k,r);
                        }
                    }
        }
    }
    f.close();
    return *ima;
}

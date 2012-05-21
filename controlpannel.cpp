#include "controlpannel.h"
#include <QtGui>
#include <QFrame>

ControlPannel::ControlPannel(QRect ecran,int vie,int money,QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(ecran.width()/2,ecran.height()-ecran.height()*0.95);

    this->setGeometry(0,ecran.height()*0.95,ecran.width()/2,ecran.height()*0.95);
    setAutoFillBackground(false);
    ecranpannel=ecran;
    this->money=money;
    this->vie=vie;
    q = new QFrame(this);
    q->setGeometry(this->x()+10,this->y()+10,100,100);
    q->setPalette(QPalette(Qt::red));
    q->show();
    tour1=QImage("image/tourB1.png");
    tour1 = tour1.scaled(this->width()/20,this->height()-this->height()*0.1);
    tour2=QImage("image/tourR1.png");
    tour2 = tour2.scaled(this->width()/20,this->height()-this->height()*0.1);
}
void ControlPannel::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval());
    repaint();
}
void ControlPannel::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black,2));
    painter.fillRect(this->rect(),Qt::white);
    painter.drawRect(this->rect());
    painter.setPen(QPen(Qt::black,2));
    //q.drawFrame(&painter);
    //painter.drawRect(50,5,100,100);
    //painter.setBrush(QBrush(Qt::blue));
    painter.drawImage(this->width()*0.15,this->height()*0.05,tour1);
    painter.drawImage(this->width()*0.15+this->width()/20+this->height()*0.05,this->height()*0.05,tour2);
    //painter.drawImage();
    painter.drawText(this->rect().x()+5,this->rect().y()+15,QString::number(elapsed),sizeof(elapsed));
    painter.drawText(this->rect().x()+5,this->rect().y()+25,"vie: "+QString::number(vie),sizeof(vie)+sizeof("vie: "));
    painter.drawText(this->rect().x()+5,this->rect().y()+35,"argent: "+QString::number(money),sizeof(money)+sizeof("argent: "));
    painter.end();

}

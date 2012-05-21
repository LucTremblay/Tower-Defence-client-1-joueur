#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QMessageBox>
#include "lobby.h"
#include <QDialog>
#include <QPainter>

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);
    indicemm=1;
    table[0]=ui->Lbl_single;
    table[1]=ui->Lbl_Multi;
    table[2]=ui->Lbl_options;
    table[3]=ui->Lbl_Help;
    table[4]=ui->Lbl_credits;
    table[5]=ui->Lbl_exit;

}

MainMenu::~MainMenu()
{
    delete ui;
}
void MainMenu::keyPressEvent(QKeyEvent *event)
{
    QPalette* palette = new QPalette();
    switch(event->key())
    {

       case Qt::Key_Up:
       {
        palette->setColor(QPalette::WindowText,Qt::black);
        table[indicemm-1]->setPalette(*palette);
        palette->setColor(QPalette::WindowText,Qt::white);
        if(indicemm>1)
        {
            indicemm-=1;
        }
        else
        {
            indicemm=6;
        }
        table[indicemm-1]->setPalette(*palette);
        }
        break;

        case Qt::Key_Down:
        {
        palette->setColor(QPalette::WindowText,Qt::black);
        table[indicemm-1]->setPalette(*palette);
        palette->setColor(QPalette::WindowText,Qt::white);
             if(indicemm<6)
             {
                 indicemm+=1;

             }
             else
             {
                 indicemm=1;
             }
               table[indicemm-1]->setPalette(*palette);
         }
         break;
    case Qt::Key_Return:
        {
            switch(indicemm)
            {
                case 2:
                {
                    Lobby *lobby=new Lobby();
                    lobby->showFullScreen();
                    this->close();
                }
                break;
                case 6:
                {
                    this->close();
                }
                break;

            }

        }
        break;
       default:
           break;
      }

}

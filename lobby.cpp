#include "lobby.h"
#include "ui_lobby.h"
#include "mainmenu.h"
#include "towerdefence.h"
#include "newpartie.h"
#include <QtNetwork>
#include <QMessageBox>


Lobby::Lobby(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lobby)
{
    ui->setupUi(this);
    m_socket = new QTcpSocket();
}

Lobby::~Lobby()
{
    delete ui;
}

void Lobby::on_btn_retour_clicked()
{

    MainMenu *dmainmenu=new MainMenu();
    dmainmenu->show();
    this->close();
}

void Lobby::on_btn_Creer_clicked()
{
    //vérifie si le socket est connecter avec un serveur
    //if (m_socket->state() != QAbstractSocket::ConnectedState)
    //{
        //connecte le socket au serveur
     //   connectionServeur();
    //}

    //afficher la page de création de partie lorsque connecter
   // if (m_socket->state() == QAbstractSocket::ConnectedState)
   // {
        newpartie *dmainmenu = new newpartie(m_socket, ui->txt_Joueur->text(), ui->txt_Partie->text());
        dmainmenu->show();
        this->close();
  //  }
}

void Lobby::on_btn_rafraichir_clicked()
{
    //vérifie si le socket est connecter avec un serveur
    if (m_socket->state() != QAbstractSocket::ConnectedState)
    {
        //connecte le socket au serveur
        connectionServeur();
    }
    //éffectu la recherche des parite lorsque connecté
    if (m_socket->state() == QAbstractSocket::ConnectedState)
    {
        //le code "2" demande des parties au serveur
        m_socket->write(QString("2").toAscii());
        if (m_socket->waitForReadyRead(7000))
        {
            QByteArray bParam = m_socket->read(m_socket->bytesAvailable());
            QStringList parties = QString(bParam).split("#");
            foreach (QString partie, parties)
            {
                ui->listPartie->addItem(partie);
            }
        }
        else
        {
            QMessageBox::critical(this, "Recherche des parties", QString::fromUtf8("Echec de la recherche des parties, le serveur ne répond pas"),QMessageBox::Ok);
        }
    }
}

void Lobby::connectionServeur()
{
    m_socket->connectToHost(QHostAddress::LocalHost, 87878);
    m_socket->waitForConnected(10000);
    if (m_socket->state() == QAbstractSocket::ConnectedState)
    {
        QMessageBox::information(this, "Connection",QString::fromUtf8("La connection au serveur c'est effectuer avec succès"),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::critical(this, "Connection", QString::fromUtf8("La connection au serveur à échoué"),QMessageBox::Ok);
    }
}

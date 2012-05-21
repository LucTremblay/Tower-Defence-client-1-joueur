#include "attentejoueur.h"
#include "ui_attentejoueur.h"

AttenteJoueur::AttenteJoueur(int socketDescriptor) :
    ui(new Ui::AttenteJoueur)
{
    ui->setupUi(this);
    ui->setupUi(this);

    ui->lblInfo2->setVisible(false);
    ui->lblinfo3->setVisible(false);
    ui->label->setVisible(false);
    ui->lblTemps->setVisible(false);
    ui->lblNomJoueur->setVisible(false);

    m_joueurConnecte = false;

    m_socket = new QTcpSocket(this);
    m_socket->setSocketDescriptor(socketDescriptor);
    connect(m_socket,SIGNAL(readyRead()),this, SLOT(slLectureSocket()));
}

void AttenteJoueur::slLectureSocket()
{
    QByteArray bChaine = m_socket->readAll();
    QStringList Param = QString(bChaine).split("#");
    if (Param.at(0).toInt() == 2 && m_joueurConnecte == true)
    {
        ui->lblTemps->setText(Param.at(1));
    }
    else if (Param.at(0).toInt() == 3 && m_joueurConnecte == false)
    {
        m_joueurConnecte = true;
        ui->lblInfo->setText("Un deuxième joueur est maintenant connecté");
        ui->lblInfo2->setVisible(true);
        ui->lblinfo3->setVisible(true);
        ui->label->setVisible(true);
        ui->lblTemps->setVisible(true);
        ui->lblNomJoueur->setVisible(true);
        ui->lblNomJoueur->setText(Param.at(1));
    }
}

AttenteJoueur::~AttenteJoueur()
{
    delete ui;
}

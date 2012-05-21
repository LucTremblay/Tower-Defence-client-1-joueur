#ifndef ATTENTEJOUEUR_H
#define ATTENTEJOUEUR_H

#include <QWidget>
#include <QTcpSocket>
#include <QStringList>

namespace Ui {
class AttenteJoueur;
}

class AttenteJoueur : public QWidget
{
    Q_OBJECT
    
public:
    explicit AttenteJoueur(int socketDescriptor);
    ~AttenteJoueur();
    
private:
    Ui::AttenteJoueur *ui;
    bool m_joueurConnecte;
    QTcpSocket *m_socket;

private slots:
    void slLectureSocket();


};

#endif // ATTENTEJOUEUR_H

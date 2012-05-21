#ifndef LOBBY_H
#define LOBBY_H

#include <QWidget>
#include <QtNetwork/QTcpSocket>

namespace Ui {
class Lobby;
}

class Lobby : public QWidget
{
    Q_OBJECT
    
public:
    explicit Lobby(QWidget *parent = 0);
    ~Lobby();

private slots:
    void on_btn_retour_clicked();
    void on_btn_Creer_clicked();
    void on_btn_rafraichir_clicked();
    void connectionServeur();

private:
    Ui::Lobby *ui;
    QTcpSocket *m_socket;
};

#endif // LOBBY_H

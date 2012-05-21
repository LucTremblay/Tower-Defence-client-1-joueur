#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QKeyEvent>
#include <QLabel>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
private:
    Ui::MainMenu *ui;
    int indicemm;
    QLabel* table[6];
protected:
    void keyPressEvent(QKeyEvent *event);

};

#endif // MAINMENU_H

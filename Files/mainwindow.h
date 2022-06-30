#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"selectingwindow.h"
#include"widget.h"
#include <QtMultimedia/QMediaPlayer>

namespace Ui {
class MainWindow;
}
extern int coin_num;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Widget *wi = NULL;
    SelectingWindow * sw = NULL;

    QMediaPlayer *player;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

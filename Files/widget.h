#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMainWindow>
#include<QLabel>
namespace Ui {
class Widget;
}

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    static int money;
    void paintEvent(QPaintEvent *);
    QLabel * coin = NULL;
    void showInfo();
    QLabel * word = NULL;
signals:
    void back();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

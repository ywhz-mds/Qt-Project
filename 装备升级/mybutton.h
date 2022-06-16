#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class Mybutton : public QPushButton
{
    Q_OBJECT
public:
//    explicit Mybutton(QWidget *parent = 0);
    //构造函数，参数一 正常图片的路径，参数2 按下后显示图片的路径
    Mybutton(QString normal, QString press = "");
    QString normalimg;
    QString pressimg;
    //弹跳特效
    void zoom1();
    void zoom2();
    static int x1;
    static int y1;

signals:

public slots:
};

#endif // MYBUTTON_H

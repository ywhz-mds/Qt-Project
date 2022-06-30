#include "mybutton.h"
#include<QDebug>
#include<QPropertyAnimation>
//Mybutton::Mybutton(QWidget *parent) : QWidget(parent)
//{

//}


Mybutton::Mybutton(QString normal, QString press){
    this->normalimg = normal;
    this->pressimg = press;
    QPixmap pix;
    bool re = pix.load(normalimg);
    if(!re)
    {
        qDebug() << "图片加载失败";
        return;
    }
    //设置图片固定大小
    this->setFixedSize(pix.width()*0.2,pix.height()*0.2);
    //设置不规则图片样式
    this->setStyleSheet("QPushButton(border:0px;)");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width()*0.2,pix.height()*0.2));

  //  connect()


}
void Mybutton::zoom1()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结果
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();

}

void Mybutton::zoom2()
{
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y() + 10,this->width(),this->height()));
    //结果
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();


}



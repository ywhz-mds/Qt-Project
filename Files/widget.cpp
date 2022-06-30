#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include"mybutton.h"
#include<QDebug>
#include<QSpinBox>
#include"slider.h"
#include"QTimer"
#include<QPalette>
#include<QFont>
#include<QLabel>
#include<mapp.h>
Widget::Widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //配置主场景

//    extern int temp;
    //设置固定大小
    setFixedSize(702,923);
    //设置图标
    setWindowIcon(QIcon(":/soliders/s1.PNG"));
    //设置标题
    setWindowTitle("装备升级界面");
    //开始按钮
    Mybutton * update = new Mybutton(":/soliders/btn4.jpg");
    update->setParent(this);
    update->move(this->width()*0.5 - update->width()*0.5,this->height()*0.9);
    connect(update,&Mybutton::clicked,[=](){
        //qDebug() << "按下了";
       // x1 = update->x();
      //  y1 = update->y();
        update->zoom1();
        update->zoom2();
        QTimer::singleShot(200,this,[=](){
            emit this->back();
        });
    });
    //设置副标题颜色
    QPalette pb;
    pb.setColor(QPalette::WindowText,Qt::white);
    ui->label_5->setPalette(pb);
    ui->label_6->setPalette(pb);
    ui->label_7->setPalette(pb);
    //设置标题颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    ui->label_4->setPalette(pa);
    //设置士兵图标
    ui->label->setPixmap(QPixmap(":/soliders/s1.PNG"));
    ui->label_2->setPixmap(QPixmap(":/soliders/s2.PNG"));
    ui->label_3->setPixmap(QPixmap(":/soliders/s3.PNG"));
    //初始化
    ui->widget_5->initial(0);
    ui->widget_6->initial(0);
    ui->widget_7->initial(0);
    extern int coin_num;
//    coin_num = temp;
    //设置按钮控制spinbox和slider的数值，此处声明，对spinbox和slider的操作不能改变
    //这里需要对具有的金币值进行判断来决定是否执行下列命令，如果金币值不足则需有弹窗？
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::white);
    // 设置字体大小
    QFont font;
    font.setPointSize(20);
    //显示金币
    coin = new QLabel(this);
//        coin->adjustSize();
    coin->move(300,700);
    coin->setPalette(palette);
    coin->setFont(font);
    coin->show();
    word = new QLabel(this);
//        coin->adjustSize();
    word->move(150,700);
    word->setPalette(palette);
    word->setFont(font);
    word->show();
    extern int coin_num;
    showInfo();
        connect(ui->btn1,&QPushButton::clicked,[=](){
            if(coin_num < 10)
            {
                disconnect(ui->btn1,0,this,0);
            }
            int tep = ui->widget_5->getnum();
            switch(tep)
            {
            case 10:ui->widget_5->setnum(20);coin_num -= 10;break;
            case 20:ui->widget_5->setnum(30);coin_num -= 10;break;
            case 30:ui->widget_5->setnum(40);coin_num -= 10;break;
            default:break;
            }
            showInfo();

        });
        connect(ui->btn2,&QPushButton::clicked,[=](){
            if(coin_num < 20)
            {
                disconnect(ui->btn1,0,this,0);
            }
            int tep = ui->widget_6->getnum();
            switch(tep)
            {
            case 20:ui->widget_6->setnum(40);coin_num -= 20;break;
            case 40:ui->widget_6->setnum(60);coin_num -= 20;break;
            case 60:ui->widget_6->setnum(80);coin_num -= 20;break;
            default:break;
            }
            showInfo();
        });

        connect(ui->btn3,&QPushButton::clicked,[=](){
            if(coin_num < 30)
            {
                disconnect(ui->btn1,0,this,0);
            }
            int tep = ui->widget_7->getnum();
            switch(tep)
            {
            case 30:ui->widget_7->setnum(60);coin_num -= 30;break;
            case 60:ui->widget_7->setnum(90);coin_num -= 30;break;
            case 90:ui->widget_7->setnum(120);coin_num -= 30;break;
            default:break;
            }
            showInfo();
        });



}
void Widget::showInfo()
{
    extern int coin_num;
    coin->setText(QString::number(coin_num));
    coin->adjustSize();
    word->setText(QString("金币数："));
    word->adjustSize();
}
 void Widget::paintEvent(QPaintEvent *)
{
     QPainter painter(this);
     QPixmap pix;
     pix.load(":/soliders/bgs.jpg");
     painter.drawPixmap(0,0,this->width(),this->height(),pix);
}


Widget::~Widget()
{
    delete ui;
}

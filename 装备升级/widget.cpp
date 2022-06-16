#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include"mybutton.h"
#include<QDebug>
#include<QSpinBox>
#include"slider.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //配置主场景


    //设置固定大小
    setFixedSize(709,923);
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
    static int money = 100;
    //设置按钮控制spinbox和slider的数值，此处声明，对spinbox和slider的操作不能改变
    //这里需要对具有的金币值进行判断来决定是否执行下列命令，如果金币值不足则需有弹窗？
    if(money >= 10)
    {
        connect(ui->btn1,&QPushButton::clicked,[=](){
            int tep = ui->widget_5->getnum();
            switch(tep)
            {
            case 10:ui->widget_5->setnum(20);money -= 10;break;
            case 20:ui->widget_5->setnum(30);money -= 10;break;
            case 30:ui->widget_5->setnum(40);money -= 10;break;
            default:break;
            }
        });
    }
    if(money >= 20)
    {
        connect(ui->btn2,&QPushButton::clicked,[=](){
            int tep = ui->widget_6->getnum();
            switch(tep)
            {
            case 20:ui->widget_6->setnum(40);money -= 20;break;
            case 40:ui->widget_6->setnum(60);money -= 20;break;
            case 60:ui->widget_6->setnum(80);money -= 20;break;
            default:break;
            }
        });
    }
    if(money >= 30)
    {
        connect(ui->btn3,&QPushButton::clicked,[=](){
            int tep = ui->widget_7->getnum();
            switch(tep)
            {
            case 30:ui->widget_7->setnum(60);money -= 30;break;
            case 60:ui->widget_7->setnum(90);money -= 30;break;
            case 90:ui->widget_7->setnum(120);money -= 30;break;
            default:break;
            }
        });
    }


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

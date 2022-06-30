#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QPushButton"
#include<QDebug>
#include<ui_mainwindow.h>
#include<QObject>
#include<QWidget>
#include"widget.h"
#include<mybutton.h>
#include"selectingwindow.h"
int coin_num = 100;
MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wi = new Widget;
    this->setFixedSize(702,923);
    connect(ui->pushButton_3,&QPushButton::clicked,[=]{
        this->hide();
        qDebug() << "press it";
        wi->show();
        connect(wi,&Widget::back,this,[=](){
            wi->hide();
            this->show();
        });
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
       emit this->close();
    });
    sw = new SelectingWindow;
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        this->hide();
        sw->show();
        connect(sw,&SelectingWindow::back,this,[=](){
            sw->hide();
            this->show();
        });
    });

    player=new QMediaPlayer;
    player->setMedia(QUrl("qrc:/music.mp3"));
    player->setVolume(30);

    connect(ui->music,&QPushButton::clicked,[=](){
        if(player->state() == QMediaPlayer::PlayingState)
            player->pause();
        else player->play();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "selectingwindow.h"
#include "ui_selectingwindow.h"
#include<QPushButton>
#include<mapp.h>
SelectingWindow::SelectingWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SelectingWindow)
{
    ui->setupUi(this);
    this->resize(702,923);
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){
        emit this->back();
    });
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        Map * m = new Map;
        m->show();
        this->hide();
    });
}

SelectingWindow::~SelectingWindow()
{
    delete ui;
}

void SelectingWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/SelectPage/bck.jpeg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}



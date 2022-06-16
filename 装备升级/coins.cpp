#include "coins.h"
#include "ui_coins.h"

Coins::Coins(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Coins)
{
    static int money = 100;
    ui->setupUi(this);
    ui->spinBox->setRange(0,10000);
    //ui->label->setPixmap(QPixmap(":/soliders/coin.jpeg"));
    ui->spinBox->setValue(money);
    ui->spinBox->setButtonSymbols(QSpinBox::NoButtons);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    ui->label->setPalette(pa);
}

Coins::~Coins()
{
    delete ui;
}

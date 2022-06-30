#include "slider2.h"
#include "ui_slider2.h"

Slider2::Slider2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Slider2)
{
    ui->setupUi(this);
    ui->spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    //通过改变spinbox的值来改变slider的值
    void (QSpinBox:: * sg)(int) = & QSpinBox::valueChanged;
    connect(ui->spinBox,sg,ui->horizontalSlider,&QSlider::setValue);

}

Slider2::~Slider2()
{
    delete ui;
}
void Slider2::initial(int num)
{
    ui->horizontalSlider->setRange(20,80);
    ui->spinBox->setRange(20,80);
    if(num >= 20 && num <= 80)
        ui->spinBox->setValue(num);
    else if(num < 20)
        ui->spinBox->setValue(20);
    else if(num > 80)
        ui->spinBox->setValue(80);
}
//设置数字
void Slider2::setnum(int num)
{
    ui->spinBox->setValue(num);
}

//获取当前值
int Slider2::getnum()
{
    return ui->spinBox->value();
}

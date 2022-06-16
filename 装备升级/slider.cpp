#include "slider.h"
#include "ui_slider.h"

Slider::Slider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Slider)
{
    ui->setupUi(this);

    ui->spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    //通过改变spinbox的值来改变slider的值
    void (QSpinBox:: * sg)(int) = & QSpinBox::valueChanged;
    connect(ui->spinBox,sg,ui->horizontalSlider,&QSlider::setValue);

}
void Slider::initial(int num)
{
    ui->horizontalSlider->setRange(10,40);
    ui->spinBox->setRange(10,40);
    if(num >= 10 && num <= 40)
        ui->spinBox->setValue(num);
    else if(num < 10)
        ui->spinBox->setValue(10);
    else if(num > 40)
        ui->spinBox->setValue(40);
}

//设置数字
void Slider::setnum(int num)
{
    ui->spinBox->setValue(num);
}

//获取当前值
int Slider::getnum()
{
    return ui->spinBox->value();
}



Slider::~Slider()
{
    delete ui;
}

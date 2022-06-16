#include "slider3.h"
#include "ui_slider3.h"

Slider3::Slider3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Slider3)
{
    ui->setupUi(this);
    ui->spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    //通过改变spinbox的值来改变slider的值
    void (QSpinBox:: * sg)(int) = & QSpinBox::valueChanged;
    connect(ui->spinBox,sg,ui->horizontalSlider,&QSlider::setValue);

}

Slider3::~Slider3()
{
    delete ui;
}
void Slider3::initial(int num)
{
    ui->horizontalSlider->setRange(30,120);
    ui->spinBox->setRange(30,120);
    if(num >= 30 && num <= 120)
        ui->spinBox->setValue(num);
    else if(num < 30)
        ui->spinBox->setValue(30);
    else if(num > 120)
        ui->spinBox->setValue(120);
}
void Slider3::setnum(int num)
{
    ui->spinBox->setValue(num);
}

//获取当前值
int Slider3::getnum()
{
    return ui->spinBox->value();
}

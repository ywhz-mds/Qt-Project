#ifndef SLIDER3_H
#define SLIDER3_H

#include <QWidget>

namespace Ui {
class Slider3;
}

class Slider3 : public QWidget
{
    Q_OBJECT

public:
    explicit Slider3(QWidget *parent = 0);
    ~Slider3();
    //设置数字
    void setnum(int num);
    //获取当前值
    int getnum();
    void initial(int num);
private:
    Ui::Slider3 *ui;
};

#endif // SLIDER3_H

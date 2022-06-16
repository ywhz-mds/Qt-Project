#ifndef SLIDER2_H
#define SLIDER2_H

#include <QWidget>

namespace Ui {
class Slider2;
}

class Slider2 : public QWidget
{
    Q_OBJECT

public:
    explicit Slider2(QWidget *parent = 0);
    ~Slider2();
    //设置数字
    void setnum(int num);
    //获取当前值
    int getnum();
    void initial(int num);
private:
    Ui::Slider2 *ui;
};

#endif // SLIDER2_H

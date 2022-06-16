#ifndef SLIDER_H
#define SLIDER_H

#include <QWidget>

namespace Ui {
class Slider;
}

class Slider : public QWidget
{
    Q_OBJECT

public:
    explicit Slider(QWidget *parent = 0);
    ~Slider();

    void initial(int num);

    //设置数字
    void setnum(int num);
    //获取当前值
    int getnum();
private:
    Ui::Slider *ui;
};

#endif // SLIDER_H

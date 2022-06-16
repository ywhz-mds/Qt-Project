#ifndef COINS_H
#define COINS_H

#include <QWidget>

namespace Ui {
class Coins;
}

class Coins : public QWidget
{
    Q_OBJECT

public:
    explicit Coins(QWidget *parent = 0);
    ~Coins();\


private:
    Ui::Coins *ui;
};

#endif // COINS_H

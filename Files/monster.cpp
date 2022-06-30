#include "monster.h"
#include<QDebug>
#include <QPainter>
#include<mapp.h>
//Monster::Monster(QWidget *parent) : QWidget(parent)
//{

//}

//Monster::Monster(int xx,int yy,int hpp,int tp)
//{
//    x=xx; y=yy; hp=hpp; type=tp;
//    setFixedSize(54,54);
//    switch(tp)
//    {
//    case 1:
//        setPixmap(QPixmap(":/soliders/bug/m2.PNG"));
//        break;
//    case 2:
//        setPixmap(QPixmap(":/soliders/bug/m2.PNG"));
//        break;
//    case 3:
//        setPixmap(QPixmap(":/soliders/bug/m2.PNG"));
//        break;
//     }

//    setScaledContents(true);
//    move(x,y);
//}


Monster::Monster(int direction, int life): direction(direction), sum_life(life), now_life(life), pos(0), in_base(false){
    if(direction == 0){
        x = 0, y = 0;
    } else if(direction == 1) {
        x = 6, y = 0;
    } else if(direction == 2) {
        x = 12, y = 0;
    }
    if(life == 60) {
        hurt = 20;
        monster.setFixedSize(54,54);
        monster.setPixmap(QPixmap(":/soliders/bug/m1.PNG"));
        monster.setScaledContents(true);
        monster.move(x*54,y*54);
    } else if(life == 90) {
        hurt = 40;
        monster.setFixedSize(54,54);
        monster.setPixmap(QPixmap(":/soliders/bug/m2.PNG"));
        monster.setScaledContents(true);
        monster.move(x*54,y*54);
    } else if(life == 120) {
        hurt = 60;
        monster.setFixedSize(54,54);
        monster.setPixmap(QPixmap(":/soliders/bug/m3.PNG"));
        monster.setScaledContents(true);
        monster.move(x*54,y*54);
    }
    show();
}

void Monster::show() {
    monster.show();
    QPainter painter;
    QBrush red_brush( QColor("#F20900") );//把刷子设置为红色
    painter.setBrush(red_brush);//应用刷子
    float rate = 1.0 * now_life/ sum_life;//计算比例
    painter.drawRect(x, y, rate * 54, 54 * 0.2);//绘制矩形
}

bool Monster::run_into_base() const {
    return in_base;
}

bool Monster::is_dead() const {
    return now_life <= 0;
}

void Monster::update_position() {
    if(!is_dead())
    {
        if(in_base) return;
        ++pos;
        y = path[direction][pos][0];
        x = path[direction][pos][1];
        monster.move(x*54,y*54);

        if(pos == 17) {
            qDebug() << y << ' ' << x << ' ' << pos << ' ' << head_life;
            in_base = true;
            extern int head_life;
            head_life-=hurt;
        }
    }
    return;
}

void Monster::get_attack(int num) {
    now_life -= num;
}

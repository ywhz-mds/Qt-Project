#ifndef HEROLABEL_H
#define HEROLABEL_H

#include <QLabel>
#include<monster.h>
class HeroLabel : public QLabel
{
    Q_OBJECT
public:
    //explicit HeroLabel(QWidget *parent = 0);
    //该士兵追踪的目标
    Monster* enemy=nullptr;
    //heroid是种类 heroAd攻击力
    int herox,heroy,heroid,heroAd;
    //攻击范围
    int padding;

    HeroLabel(int,int,int,int);
    //士兵移动
    void heroMove(int);
    //点击选择要操作的士兵
    void mouseReleaseEvent(QMouseEvent * ev);   //鼠标释放事件

signals:
       void clicked();


public slots:
};



#endif // HEROLABEL_H

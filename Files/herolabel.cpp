#include "herolabel.h"
#include<QString>
#include<QMouseEvent>
//HeroLabel::HeroLabel(QWidget *parent) : QWidget(parent)
//{

//}

HeroLabel::HeroLabel(int x,int y,int i,int ad)
{
    herox=x; heroy=y; heroid=i; heroAd=ad;
    setFixedSize(54,54);
    switch(i)
    {
    case 1:
        setPixmap(QPixmap(":/soliders/1/s11111.JPG"));
        padding=2;
        break;
    case 2:
        setPixmap(QPixmap(":/soliders/1/s3.PNG"));
        padding=3;
        break;

    case 3:
        setPixmap(QPixmap(":/soliders/1/s2.PNG"));
        padding=2;
        break;

     }

    setScaledContents(true);
    move(herox*54,heroy*54);
}

void HeroLabel::heroMove(int type)
{
    switch (type) {
    case 0:

        move(herox*54,(heroy-1)*54);
        heroy--;
        break;
    case 1:

        move(herox*54,(heroy+1)*54);
        heroy++;
        break;
    case 2:
        move((herox-1)*54,heroy*54);
        herox--;
        break;
    case 3:

        move((herox+1)*54,heroy*54);
        herox++;
        break;
    default:
        break;
    }
}

void HeroLabel::mouseReleaseEvent(QMouseEvent * ev)   //鼠标释放事件
 {
        if(ev != nullptr)

        //判断事件是否为鼠标左键
         if(ev->button() == Qt::LeftButton)
         {
             emit clicked();	// 发射信号
         }
 }

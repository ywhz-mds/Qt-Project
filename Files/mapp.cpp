#include "mapp.h"
#include "ui_map.h"

#include<QPushButton>
#include<mainwindow.h>
#include<mybutton.h>
#include<widget.h>
#include<selectingwindow.h>
#include<QTimer>
#include<initial_map.h>
#include<QPixmap>
#include<QDebug>
#include<monster.h>
#include<herolabel.h>
#include<QIcon>
#include<QSize>
//#include<winlose.h>
int head_life = 100;
Map::Map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
    this->resize(702,923);
    setWindowIcon(QIcon(":/soliders/bg.jpg"));
    //设置标题
    setWindowTitle("游戏界面");
    this->grabKeyboard();

    initMap();




    //新加
     soilderNum=0;

     extern int coin_num;

     QTimer* monsterProduce=new QTimer(this);
     monsterProduce->start(1000);
     tmp = 0;
     connect(monsterProduce,&QTimer::timeout,[=]()
     {

         Monster* m=new Monster(tmp % 3,seq[tmp]);
         tmp++;

         m->monster.setParent(this);
         m->show();
         allMonster.push_back(m);
         if(tmp == 20)
         {
             ed = m;
             disconnect(monsterProduce,0,0,0);
         }
     });

     QTimer* monsterMoveTimer=new QTimer(this);
     fl2 = false;
     monsterMoveTimer->start(1000);
     connect(monsterMoveTimer,&QTimer::timeout,[=]()
     {
         for(auto i=allMonster.begin();i<allMonster.end();i++)
         {
            (*i)->update_position();
             ShowInfo();
            qDebug() << head_life;
             if(head_life<=0)
             {

    //             qDebug() << "jiechu1";
                 disconnect(monsterMoveTimer,0,0,0);
    //             qDebug() << "jiechu12";
                back = new QPushButton(this);
                connect(back,&QPushButton::clicked,[=](){
                    wi.show();
                    this->hide();
                });
                    back->resize(500,300);
                 back->move(100,310);
                 back->setIcon(QIcon(":/WinORLose/l.jpg"));
                 back->setIconSize(QSize(500,290));
                 back->show();
                 head_life = 100;
             }
          }
     });

     QTimer* attackTimer=new QTimer(this);
     attackTimer->start(500);
     fla = false;
     connect(attackTimer,&QTimer::timeout,[=](){
         soiderAttack();

          for(auto i = allMonster.begin();i < allMonster.end();i++)
          {
              fla = true;
              if(!(*i)->is_dead())
              {
                  fla = false;
              }
          }

         if(fla)
         {
//            w2 = new WinLose("true");
//             w2->show();
//             this->hide();

             disconnect(attackTimer,0,0,0);
             back = new QPushButton(this);
             connect(back,&QPushButton::clicked,[=](){
                 wi.show();
                 this->hide();
             });
             back->resize(500,300);
              back->move(100,310);
              back->setIcon(QIcon(":/WinORLose/w.jpg"));
              back->setIconSize(QSize(500,290));
              back->show();
              coin_num += 50;
//              int temp = coin_num;
         }
     });

    //以下为三个按钮用来制造士兵
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        if(coin_num >= 10)
        {

            HeroLabel* hrlb=new HeroLabel(6,12,1,100);
            connect(hrlb,&HeroLabel::clicked,[=]()
            {
                mainSoilder=hrlb;
            });
            mainSoilder=hrlb;
            mainSoilder->setParent(this);
            allSoilder.push_back(mainSoilder);
            qDebug()<<"生成";
            coin_num -= 10;
            mainSoilder->show();
            QString str=QString("位置 %1 %2  攻击 %3  范围 %4 ").arg(hrlb->herox).arg(hrlb->heroy).arg(hrlb->heroAd).arg(hrlb->padding);
            qDebug()<<str;
        }
    });

    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        if(coin_num >= 20)
        {
            HeroLabel* hrlb=new HeroLabel(6,12,2,200);
            connect(hrlb,&HeroLabel::clicked,[=]()
            {
                mainSoilder=hrlb;
            });
            mainSoilder=hrlb;
            mainSoilder->setParent(this);
            coin_num -= 20;
            allSoilder.push_back(mainSoilder);
            qDebug()<<"生成";
            mainSoilder->show();
            QString str=QString("位置 %1 %2  攻击 %3  范围 %4 ").arg(hrlb->herox).arg(hrlb->heroy).arg(hrlb->heroAd).arg(hrlb->padding);
            qDebug()<<str;
        }
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        if(coin_num >= 30)
        {
            HeroLabel* hrlb=new HeroLabel(6,12,3,300);
            connect(hrlb,&HeroLabel::clicked,[=]()
            {
                mainSoilder=hrlb;
            });
            mainSoilder=hrlb;
            mainSoilder->setParent(this);
            allSoilder.push_back(mainSoilder);
            coin_num -= 30;
            qDebug()<<"生成";
            mainSoilder->show();
            QString str=QString("位置 %1 %2  攻击 %3  范围 %4 ").arg(hrlb->herox).arg(hrlb->heroy).arg(hrlb->heroAd).arg(hrlb->padding);
            qDebug()<<str;
        }
    });
}
void Map::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/素材/blue.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void Map::initMap()
{
    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            map1[i][j] = Map1[i][j];
            switch(map1[i][j])
            {//这里没写炮弹的图片
            case -1:labels[i][j] = new QLabel(this);
                labels[i][j]->setFixedSize(54,54);
                labels[i][j]->setPixmap(QPixmap(":/GamePage/water.png"));
                labels[i][j]->setScaledContents(true);
                labels[i][j]->move(j*54,i*54);
                labels[i][j]->show();break;
            case 0:labels[i][j] = new QLabel(this);
                labels[i][j]->setFixedSize(54,54);
                labels[i][j]->setPixmap(QPixmap(":/GamePage/grass.png"));
                labels[i][j]->setScaledContents(true);
                labels[i][j]->move(j*54,i*54);
                labels[i][j]->show();break;
            case 100:labels[i][j] = new QLabel(this);
                labels[i][j]->setFixedSize(54,54);
                labels[i][j]->setPixmap(QPixmap(":/GamePage/head.png"));
                labels[i][j]->setScaledContents(true);
                labels[i][j]->move(j*54,i*54);
                labels[i][j]->show();break;
            case 1:labels[i][j] = new QLabel(this);
                labels[i][j]->setFixedSize(54,54);
                labels[i][j]->setPixmap(QPixmap(":/soliders/bug/m1.PNG"));
                labels[i][j]->setScaledContents(true);
                labels[i][j]->move(j*54,i*54);
                labels[i][j]->show();break;
            case 2:labels[i][j] = new QLabel(this);
                labels[i][j]->setFixedSize(54,54);
                labels[i][j]->setPixmap(QPixmap(":/soliders/bug/m2.PNG"));
                labels[i][j]->setScaledContents(true);
                labels[i][j]->move(j*54,i*54);
                labels[i][j]->show();break;
            case 3:labels[i][j] = new QLabel(this);
                labels[i][j]->setFixedSize(54,54);
                labels[i][j]->setPixmap(QPixmap(":/soliders/bug/m3.PNG"));
                labels[i][j]->setScaledContents(true);
                labels[i][j]->move(j*54,i*54);
                labels[i][j]->show();break;
            case 4:labels[i][j] = new QLabel(this);
                labels[i][j]->setFixedSize(54,54);
                labels[i][j]->setPixmap(QPixmap(":/soliders/1/s1.PNG"));
                labels[i][j]->setScaledContents(true);
                labels[i][j]->move(j*54,i*54);
                labels[i][j]->show();break;
            case 5:labels[i][j] = new QLabel(this);
                labels[i][j]->setFixedSize(54,54);
                labels[i][j]->setPixmap(QPixmap(":/soliders/1/s2.PNG"));
                labels[i][j]->setScaledContents(true);
                labels[i][j]->move(j*54,i*54);
                labels[i][j]->show();break;
            case 6:labels[i][j] = new QLabel(this);
                labels[i][j]->setFixedSize(54,54);
                labels[i][j]->setPixmap(QPixmap(":/soliders/1/s3.PNG"));
                labels[i][j]->setScaledContents(true);
                labels[i][j]->move(j*54,i*54);
                labels[i][j]->show();break;
            }
        }
    }
    // 显示英雄信息label
        // 设置字体颜色
        QPalette palette;
        palette.setColor(QPalette::WindowText,Qt::black);
        // 设置字体大小
        QFont font;
        font.setPointSize(20);
        //显示金币
        coin = new QLabel(this);
//        coin->adjustSize();
        coin->move(300,700);
        coin->setPalette(palette);
        coin->setFont(font);
        coin->show();
        //金币显示
        coinnum = new QLabel(this);
//        coinnum->adjustSize();
        coinnum->move(130,740);
        coinnum->setPalette(palette);
        coinnum->setFont(font);
        coinnum->show();
        //士兵序号显示
        solider = new QLabel(this);
        solider->move(550,730);
        solider->setPalette(palette);
        solider->setFont(font);
        solider->show();
        //小怪生命值显示
        monster = new QLabel(this);
        monster->move(500,850);
        monster->setPalette(palette);
        monster->setFont(font);
        monster->show();
//        this->ShowInfo();
        h_life = new QLabel(this);
        h_life->move(220,850);
        h_life->setPalette(palette);
        h_life->setFont(font);
        h_life->show();
}

void Map::keyPressEvent(QKeyEvent *event)
{
//    qDebug() << "q";
    // 重载按键事件，实现角色行动
            // 记录类型
            int type = 4;
            // 记录即将行走的位置是什么
            //int preValue = 0;
            switch (event->key())
            {
            case Qt::Key_Up: // 上
            case Qt::Key_W:
                if(map1[mainSoilder->heroy-1][mainSoilder->herox]==0)
                {
                    int tmpx=mainSoilder->heroy-1,tmpy=mainSoilder->herox;

                    if(tmpx>=0&&tmpx<=12&&tmpy>=0&&tmpy<=12)
                    {
                        type = 0;
                        mainSoilder->heroMove(type);

                        map1[tmpx][tmpy]=1;
                        map1[tmpx+1][tmpy]=0;
                    }
                }
//                preValue = map[hero->heroFloor][heroX - 1][heroY];
//                heroMove(type,preValue);
                break;
            case Qt::Key_Down:  // 下
            case Qt::Key_S:
//                type = 1;
                if(map1[mainSoilder->heroy+1][mainSoilder->herox]==0)
                {
                    int tmpx=mainSoilder->heroy+1,tmpy=mainSoilder->herox;

                    if(tmpx>=0&&tmpx<=12&&tmpy>=0&&tmpy<=12)
                    {
                        type = 1;
                        mainSoilder->heroMove(type);
                        map1[tmpx][tmpy]=1;
                        map1[tmpx-1][tmpy]=0;
                    }
                }
//                preValue = map[hero->heroFloor][heroX + 1][heroY];
//                heroMove(type,preValue);
                break;
            case Qt::Key_Left:  // 左
            case Qt::Key_A:
                if(map1[mainSoilder->heroy][mainSoilder->herox-1]==0)
                {
                    int tmpx=mainSoilder->heroy,tmpy=mainSoilder->herox-1;

                    if(tmpx>=0&&tmpx<=12&&tmpy>=0&&tmpy<=12)
                    {
                        type = 2;
                        mainSoilder->heroMove(type);
                        map1[tmpx][tmpy]=1;
                        map1[tmpx][tmpy+1]=0;
                    }
                }
//                type = 2;
//                preValue = map[hero->heroFloor][heroX][heroY - 1];
//                heroMove(type,preValue);
                break;
            case Qt::Key_Right:  // 右
            case Qt::Key_D:
                if(map1[mainSoilder->heroy][mainSoilder->herox+1]==0)
                {
                    int tmpx=mainSoilder->heroy,tmpy=mainSoilder->herox+1;

                    if(tmpx>=0&&tmpx<=12&&tmpy>=0&&tmpy<=12)
                    {
                        type = 3;
                        mainSoilder->heroMove(type);
                        map1[tmpx][tmpy]=1;
                        map1[tmpx][tmpy-1]=0;
                    }
                }
//                type = 3;
//                preValue = map[hero->heroFloor][heroX][heroY + 1];
//                heroMove(type,preValue);
                break;
            default:
                break;
            }
            //显示信息
//            ShowInfo();
}
void Map::ShowInfo()
{
    coinnum->setText(QString::number(coin_num));
    coinnum->adjustSize();
    //显示司令部生命值
    h_life->setText(QString::number(head_life));
    h_life->adjustSize();
    //显示士兵序号
//    solider->setText(QString::number(soli_id));

}

Map::~Map()
{
    delete ui;
}


bool underAttack(Monster* mon,HeroLabel* h)
{
    //qDebug()<<"检测";
    //qDebug()<<mon->x<<' '<<mon->y<<"怪";
    if(mon->x>=h->herox-h->padding&&mon->x<=h->herox+h->padding&&mon->y>=h->heroy-h->padding&&mon->y<=h->heroy+h->padding)
    {
        return true;
    }
    else return false;
}

void Map::soiderAttack()
{

    for(auto i=allSoilder.begin();i<allSoilder.end();i++)
    {

//        //已经有目标且在范围内
        if((*i)->enemy!=nullptr&&underAttack((*i)->enemy,(*i)))
        {
            //qDebug()<<"有目标";
              //qDebug()<<"攻击";
                (*i)->enemy->get_attack((*i)->heroAd);
                if((*i)->enemy->is_dead())
                {
                    //qDebug()<<"击杀";
                    (*i)->enemy->monster.close();
                    (*i)->enemy=nullptr;
                }

        }

//        //目标脱离范围或者死掉 寻找目标
        else
        {


            for(auto ii=allMonster.begin();ii<allMonster.end();ii++)
            {
                if((*ii)->is_dead()) continue;


               for(int tmpx=(*i)->herox-(*i)->padding;tmpx<=(*i)->herox+(*i)->padding;tmpx++)
                for(int tmpy=(*i)->heroy-(*i)->padding;tmpy<=(*i)->heroy+(*i)->padding;tmpy++)
                {
                       if((*ii)->x==tmpx&&(*ii)->y==tmpy)
                       {
                           (*i)->enemy=(*ii);
                            //qDebug()<<"ok";
                       }
                }
            }
         }
    }
}

#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include<QLabel>
#include<QString>
#include<herolabel.h>
#include<monster.h>
#include<mainwindow.h>
#include<QPushButton>
//#include<winlose.h>
//class Solider
//{
//public:
//    //攻击力
//    int force;
//    //价格
//    int price;
//    //攻击范围
//    int padding;
//    //坐标
//    int x, y;
//    //序号
//    int id;
//    //name
//    QString name;
//    Solider(int grade, int sx, int sy, int id1):x(sx),y(sy),id(id1)
//    {
//        switch(grade)
//        {//id表示士兵的序号，grade表示等级
//        case 1:force = 10, price = 10, padding = 1;
//            name = "Primary Solider";break;
//        case 2:force = 20, price = 20, padding = 2;
//            name = "Middle Solider";break;
//        case 3:force = 30, price = 30, padding = 1;
//            name = "Superior Solider";break;
//        }
//    }
//};
//class Monster
//{
//public:
//    //固定轨迹数组
//    //存储小怪的轨迹
//    int path[3][18][2] = {{{0,0},{1,0},{2,0},{3,0},{4,0},{4,1},{4,2},{5,2},{6,2},{7,2},
//                           {8,2},{9,2},{10,2},{11,2},{11,3},{11,4},{11,5},{11,6}},//左路
//                          {{0,6},{1,6},{2,6},{3,6},{4,6},{4,5},{4,4},{4,3},{5,3},{6,3},
//                           {7,3},{8,3},{9,3},{10,3},{10,4},{10,5},{10,6},{11,6}},//中路
//                          {{0,12},{1,12},{2,12},{3,12},{4,12},{4,11},{4,10},{5,10},{6,10},//右路
//                           {7,10},{8,10},{9,10},{10,10},{11,10},{11,9},{11,8},{11,7},{11,6}}};
//    //判断从哪个方位生成（0代表左，1代表中路，2代表右）
//    int pos;
//    //代表小怪的生命值
//    int life;
//    //name
//    QLabel name;
//    Monster(int pos1, int life1,QString s):life(life1),name(s),pos(pos1)
//    {

//    }
//};

//HeroLabel* mainSoilder;
//QVector<HeroLabel*> allSoilder;
//int soilderNum;

namespace Ui {
class Map;
}
   extern int head_life;
//   extern int temp;
class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = 0);
    ~Map();
    /*初始地图数组，
     * 0-空地，
     * 1-3为怪（血量依次设置为60,90,120（暂定）,若走到司令部则分别造成20,40,60的伤害），行动路线可以装到一个数组里（先设置一个关卡）
     * 4-6为士兵（士兵有三种，
     * 4号设置为初级，攻击力初始值为10（范围10-30），攻击范围padding=1，购买价格设为10；
     * 5号设置为中级，攻击力初始值为20（范围20-60），攻击范围padding=2,购买价格设为20；
     * 6号设置为最高级，攻击力设为30（30-90），攻击范围padding=1，购买价格为30），
     * -1为墙，
     * -“force”是士兵所在范围的攻击值（范围暂定为-10-（-100）），
     * 100表示司令部即每购买一个士兵都从这里生成动画,同时100也是司令部的初始生命值
     *

*/

   // void timerEvent(QTimerEvent *event);
int Map1[13][13] = {{ 0, 0,-1,-1,-1, 0, 0, 0,-1,-1,-1, 0, 0},
                   { 0, 0,-1,-1,-1, 0, 0, 0,-1,-1,-1, 0, 0},
                   { 0, 0,-1,-1,-1, 0, 0, 0,-1,-1,-1, 0, 0},
                   { 0, 0,-1,-1,-1, 0, 0, 0,-1,-1,-1, 0, 0},
                   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {-1,-1, 0, 0, 0,-1,-1,-1, 0, 0, 0,-1,-1},
                   {-1,-1, 0, 0, 0,-1,-1,-1, 0, 0, 0,-1,-1},
                   {-1,-1, 0, 0, 0,-1,-1,-1, 0, 0, 0,-1,-1},\
                   {-1,-1, 0, 0, 0,-1,-1,-1, 0, 0, 0,-1,-1},
                   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                   { 0, 0, 0, 0, 0, 0,100,0, 0, 0, 0, 0, 0},
                   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    void paintEvent(QPaintEvent *event);
    void soiderAttack();
    bool underAttak(HeroLabel* h,Monster* mon);
    void keyPressEvent(QKeyEvent *event) ;
//    WinLose * w1 = NULL;
//    WinLose * w2 = NULL;
    //图片
    QLabel *pix = NULL;
    //背景
//    QLabel *bg;
    //文字
     MainWindow wi;
    QLabel *word = NULL;
    //返回按钮
    QPushButton *back = NULL;
private:
    Ui::Map *ui;
    //游戏过程中所用到的存储地图
    int map1[13][13];
    //用来展示地图（绿色为草地，蓝色为水）
    QLabel *labels[13][13];
    //用来表示司令部
    QLabel *head;
    //司令部生命值
    QLabel *h_life;

    //当前键盘所控制的士兵的序号
    QLabel *solider;
    //小怪的生命值
    QLabel *monster;
    //炮弹图片
    QLabel *bullet;
    //金币展示
    QLabel *coin;
    QLabel *coinnum;
    //小怪生命值
    QLabel *life;
    //定义士兵数组
    //Solider *soli[50];
    //定义小怪指针
    //Monster *mons[50];
    //初始化地图
    void initMap();
    //更新地图
    void updateMap(int type, int prevalue = 0);
    //展示信息
    void ShowInfo();

    Monster* m;
    Monster* ed;
    HeroLabel* mainSoilder;
    QVector<HeroLabel*> allSoilder;
    QVector<Monster*> allMonster;

    int soilderNum;
    int monsterNum;
    //记录小怪的个数，上限为20
    int tmp;
    //定义一个小怪出场顺序
    int seq[20] = {60,60,60,90,90,60,120,120,60,90,90,90,120,120,60,90,120,60,120,120};
    //bool
    bool fla;
    bool fl2;
};


#endif // MAP_H

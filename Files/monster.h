#ifndef MONSTER_H
#define MONSTER_H

#include <QLabel>

//class Monster : public QLabel
//{
//    Q_OBJECT
//public:
//    //explicit Monster(QWidget *parent = 0);
//    Monster(int,int,int,int);
//    int x,y,hp,type;
//signals:

//public slots:
//};


class Monster
{
public:
    //固定轨迹数组
    //存储小怪的轨迹
    const int path[3][18][2] = {{{0,0},{1,0},{2,0},{3,0},{4,0},{4,1},{4,2},{5,2},{6,2},{7,2},
                           {8,2},{9,2},{10,2},{11,2},{11,3},{11,4},{11,5},{11,6}},//左路
                          {{0,6},{1,6},{2,6},{3,6},{4,6},{4,5},{4,4},{4,3},{5,3},{6,3},
                           {7,3},{8,3},{9,3},{10,3},{10,4},{10,5},{10,6},{11,6}},//中路
                          {{0,12},{1,12},{2,12},{3,12},{4,12},{4,11},{4,10},{5,10},{6,10},//右路
                           {7,10},{8,10},{9,10},{10,10},{11,10},{11,9},{11,8},{11,7},{11,6}}};
    //判断从哪个方位生成（0代表左，1代表中路，2代表右）
    int direction;
    //代表小怪的生命值
    int sum_life;
    int now_life;
    // the picture
    QLabel monster;
    // its position
    int x, y;
    int pos;
    bool in_base;
    //伤害
    int hurt;
public:
    Monster(int pos, int life);
    void get_attack(int num);
    void update_position();
    bool run_into_base() const;
    void show();
    bool is_dead() const;
};

#endif // MONSTER_H

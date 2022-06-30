#ifndef SELECTINGWINDOW_H
#define SELECTINGWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class SelectingWindow; }
QT_END_NAMESPACE

class SelectingWindow : public QMainWindow
{
    Q_OBJECT

public:
    SelectingWindow(QWidget *parent = nullptr);
    ~SelectingWindow();
    void paintEvent(QPaintEvent*);
signals:
    void back();
private:
    Ui::SelectingWindow *ui;
};
#endif // SELECTINGWINDOW_H

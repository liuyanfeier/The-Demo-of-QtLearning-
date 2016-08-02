#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QMouseEvent>

class EventLabel : public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    //EventLabel继承了QLabel,覆盖了这三个函数
};

void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Move: (%1,%2)</h1></center>")
                  .arg(QString::number(event->x()),
                       QString::number(event->y())));
}

void EventLabel::mousePressEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Press: (%1,%2)</h1></center>")
                  .arg(QString::number(event->x()),
                       QString::number(event->y())));
}

void EventLabel::mouseReleaseEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("<center><h1>Release: (%d,%d)</h1></center>",
                event->x(),event->y());
    this->setText(msg);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EventLabel *label = new EventLabel;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300,200);
    label->setMouseTracking(true);
    //设置是否追踪鼠标，默认是false，当是false的时候，按下一次鼠标时候才显示
    label->show();

    return a.exec();
}

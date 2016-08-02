#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QObject>
#include <QEvent>
#include <QDebug>

class Label : public QWidget
{
public:
    Label()
    {
        installEventFilter(this);   //安装事件过滤器
    }
    bool eventFilter(QObject *watched , QEvent *event)
    {    //事件过滤器
        //watched目标对象
        if(watched == this){
            if(event->type() == QEvent::MouseButtonPress){
                qDebug() << "eventFilter!";
            }
            return true;
        }
        return false;
    }

protected:
    void mousePressEvent(QMouseEvent *)
    {
        qDebug() << "mousePressEvent!";
    }
    bool event(QEvent *event)
    {
        if(event->type() == QEvent::MouseButtonPress){
            qDebug() << "event!";
        }
        return QWidget::event(event);
    }
};

class EventFilter : public QObject
{
public:
    EventFilter(QObject *watched, QObject *parent = 0):
        QObject(parent),
        m_watched(watched)
    {

    }
    bool eventFilter(QObject *watched, QEvent *event)
    {
        if(watched == m_watched){
            if(event->type() == QEvent::MouseButtonPress){
                qDebug() << "QApplication!";
            }
            //return false;
            //return true;
        }
        return false;
    }

private:
    QObject *m_watched;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Label label;
    a.installEventFilter(new EventFilter(&label,&label));
    label.show();

    return a.exec();
}
//全局事件过滤器被第一个调用，之后是该对象上面的事件过滤器，
//其次是event()函数，最后是特定的事件处理函数。

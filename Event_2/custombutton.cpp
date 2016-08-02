#include <QDebug>
#include <QMouseEvent>

#include <custombutton.h>

CustomButton::CustomButton(QWidget *parent) :
    QPushButton(parent)
{
    connect(this,&CustomButton::clicked,
            this,&CustomButton::onButtonCliecked);
}

void CustomButton::onButtonCliecked()
{
    qDebug() << "You clicked this!" ;
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //QPushButton::mousePressEvent(event);
        //这个父类函数里面实现了clicked()信号，覆盖了之后就不会
        //实现函数槽里面的函数了
        qDebug() << "left";
    }
    else
    {
        QPushButton::mousePressEvent(event);
        //父类的同名函数
    }
}

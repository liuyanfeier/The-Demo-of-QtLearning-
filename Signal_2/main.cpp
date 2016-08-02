//!!! Qt 5
#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton button("Quit");  //按钮
    QObject::connect(&button,&QPushButton::clicked,[](bool){
        qDebug()<<"You clicked me:";
    });
    //Lambda 表达式中的qDebug()类似于cout
    button.show();

    return app.exec();
}

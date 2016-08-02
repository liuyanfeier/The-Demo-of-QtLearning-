#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel *l  = new QLabel;

    l->setTextInteractionFlags(Qt::TextSelectableByMouse);//设置文本内容可选
    l->setText("HBIJNMOL");
    l->show();

    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PaintedWidget painter ;//= new PaintedWidget(this);
    painter.show();

    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPainter painter;
    painter.setRenderHint(QPainter::Antialiasing);

    QGraphicsScene scene;   //创建一个场景
    //scene.setSceneRect(0,0,300,300);
    scene.addLine(0,0,150,150);//向场景中添加直线

    QGraphicsView view(&scene);   //观察窗口，绑定场景
    view.setWindowTitle("Graphics View");
    //view.resize(500,500);
    view.show();

    return a.exec();
}

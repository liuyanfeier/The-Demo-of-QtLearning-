#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyListView *myListView = new MyListView;
    myListView->show();

    return a.exec();
}

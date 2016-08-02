#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SortView sortView;
    sortView.show();

    return a.exec();
}

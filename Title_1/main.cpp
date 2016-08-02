
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomFrame frame(this, "CustomFrame");
    frame.show();

    return a.exec();
}

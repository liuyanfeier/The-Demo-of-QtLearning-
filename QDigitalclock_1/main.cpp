#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog dialog;
    dialog.setWindowTitle("Clock");
    dialog.show();

    return a.exec();
}

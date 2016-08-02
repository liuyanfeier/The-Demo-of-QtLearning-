#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FileSystemWidget fileSystem ;
    fileSystem.show();

    return a.exec();
}

#include <mainwindow.h>

#include <QApplication>
#include <QTextCodec>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Chat w;
    w.show();

    return a.exec();
}

#include "chat.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    chat w;
    w.show();

    return a.exec();
}

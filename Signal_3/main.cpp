#include <QCoreApplication>
#include <QApplication>

#include "newspaper.h"
#include "reader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Newspaper newspaper("Newspaper A");
    Reader reader ;

    QObject::connect(&newspaper,&Newspaper::newPaper,
                     &reader , &Reader::receiveNewspaper);

    newspaper.send();
    //由于我们的连接，当这个信号发出时，自动调用 reader 的槽函数，打印出语句。

    return a.exec();
}

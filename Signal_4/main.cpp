#include "mainwindow.h"
#include <QApplication>
#include <QDate>
#include <QCoreApplication>

#include <newspaper.h>
#include <reader.h>

int main(int argc, char *argv[])
{
    QDate date = QDate::currentDate();
    //QDebug()<<date;
    QCoreApplication a(argc, argv);
    Newspaper newspaper("Newspaper A",date);
    Reader reader;

    //void (Newspaper:: *newPaperNameDate)(const QString &, const QDate &) =
           // &Newspaper::newPaper;
    QObject::connect(&newspaper,&Newspaper::newPaper,
                     &reader,&Reader::receiveNewspaper);

    newspaper.send();

    return a.exec();
}

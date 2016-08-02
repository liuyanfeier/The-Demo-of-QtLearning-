#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QIODevice>
#include <QDebug>
#include <QFileInfo>
#include <QDataStream>

//QDataStream读写二进制文件
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QFile file("file.txt");
//    file.open(QIODevice::WriteOnly);

//    QDataStream out(&file);
//    out << QString("The answer is ");
//    out << (qint32)42;o
//    //Qt整型qint32

//    file.close();

//    QFile file("file.txt");
//    file.open(QIODevice::ReadOnly);
//    QDataStream in(&file);
//    QString str;
//    qint32 a;
//    in >> str >> a;

    QFile file("file.txt");
    file.open(QIODevice::ReadWrite);

    QDataStream stream(&file);
    QString str = "the answer is 42";
    QString strout;

    stream << str;    //此时游标已经到了最后了
    //向文件中写入数据
    //file.flush();
    stream.device()->seek(0);
    //将游标设置为0的位置
    stream >> strout ;

    return app.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>
#include <QFile>
#include <QIODevice>
#include <QTextEdit>

//QTextStream类，文本文件读写
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //写入数据
//    QFile data("file.txt");
//    if(data.open(QFile::WriteOnly | QIODevice::Truncate)){
//        QTextStream out(&data);
//        out << "The answer is " << 42;
//    }

    //读取数据
    QFile data("file.txt");
    if(data.open(QFile::ReadOnly)){
        QTextStream in(&data);
        QString str;
        int ans = 0 ;
        in >> str >> ans;

    }




//    //QTextStream的编码格式是Unicode，可以使用下面的方式来改变
//    QTextStream stream;
//    stream.setCodec("UTF-8";);

    return a.exec();
}

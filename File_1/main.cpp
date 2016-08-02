#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QIODevice>
#include <QDebug>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //qDebug() <<a.applicationFilePath();

    QFile file("in.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed." ;
        return -1;
    }
    else{
        while(!file.atEnd()){
            qDebug() << file.readLine();
        }
    }

    QFileInfo info(file);
    qDebug() << info.isDir();   //检查文件是否是目录
    qDebug() << info.isExecutable();//检查文件是否是可执行文件
    qDebug() << info.baseName();//直接获得文件名
    qDebug() << info.completeBaseName();//全民
    qDebug() << info.suffix();//获取文件后缀名
    qDebug() << info.completeSuffix();//全部后缀名
    //区别在于当后缀不止一个的时候

    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QProcess>
#include <QTextCodec>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString program = "C:/Windows/System32/cmd.exe";
    QStringList arguments;
    arguments << "/c" << "dir" << "C:\\";

    QProcess *cmdProcess = new QProcess;
    cmdProcess->start(program,arguments);
    //将外部程序名字（program）和程序启动参数（arguments）作为参数传给QProcess::start()函数
    //开启进程
    QObject::connect(cmdProcess,&QProcess::readyRead,[=](){
       QTextCodec *codec = QTextCodec::codecForName("GBK");
       //Windows 控制台的默认编码是 GBK
       QString dir = codec->toUnicode(cmdProcess->readAll());
       qDebug() << dir;
    });

    return a.exec();
}

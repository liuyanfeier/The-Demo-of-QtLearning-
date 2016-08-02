#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDataStream>
#include <QList>
#include <QDate>
#include <QStringList>
#include <QString>
#include <QLinkedList>

//QStringList *list = new QStringList();
//QStringList list;

struct Movie
{
    int id;
    QString title;
    QDate releaseDate;
};

QList<Movie> movs;

//Qt 容器类可以直接使用QDataStream进行存取。
//此时，容器中所存储的类型必须也能够使用QDataStream进行存储。
//这意味着，我们需要重载operator<<()和operator>>()运算符

QDataStream &operator <<(QDataStream &out,const Movie &movie){
    out << (qint32)movie.id << movie.title
        << movie.releaseDate;
    return out;
}

QDataStream &operator >>(QDataStream &in,Movie &movie){
    qint32 id;
    QDate date;

    in >> id >> movie.title >> date;
    movie.id = (int)id;
    movie.releaseDate = date;

    return in;
}

//QList<QString> list;
////list << "A" << "B" << "C" << "D";

//QListIterator<QString> i(list);
//while(i.hasNext()){
//    qDebug() << i.next();
//}


//QMap<int,int> map;

//QMap<int,int>::const_iterator i;
//for(i = map.constBegin() ; i != map.constEnd() ; ++i){
//    qDebug() << i.key() << ":" << i.value();
//}

QLinkedList<QString> list;
QString str;
foreach (str, list) {
    qDebug() << str;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

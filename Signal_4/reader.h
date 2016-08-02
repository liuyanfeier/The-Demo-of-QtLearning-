#ifndef READER_H
#define READER_H

#include <QObject>
#include <QDebug>
#include <QDate>

class Reader : public QObject
{
    Q_OBJECT

public:
    Reader() {}
    //与信号函数不同，槽函数必须自己完成实现代码
//    void receiveNewspaper(const QString & name)
//    {
//        qDebug() << "Receives Newspaper: " << name;
//    }
    void receiveNewspaper(const QString & name , const QDate & date)const
    {
        qDebug() << "Receive Newspaper: " << name << " Date: " << date;
    }
};


#endif // READER_H




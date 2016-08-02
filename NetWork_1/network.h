#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QString>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

class QNetWorkReply;

class NetWorkr : public QObject
{
    Q_OBJECT

public:
    static NetWorkr * instance();
    //获取实例
    ~NetWorkr();

    void get(const QString &url);
    //执行 HTTP GET 操作

signals:
    void finished(QNetWorkReply *reply);
    //获取到服务器响应后发出

private:
    class Private;
    friend class Private;
    Private *d;

    explicit NetWorkr(QObject *parent = 0);
    NetWorkr(const NetWorkr &) Q_DECL_EQ_DELETE;
    NetWorkr& operator =(NetWorkr rhs) Q_DECL_EQ_DELETE;
    //作为单例模式，要求构造函数、拷贝构造函数和赋值运算符都是私有的
    //Q_DECL_EQ_DELETE宏
    //这个宏是 Qt5 新增加的，意思是将它所修饰的函数声明为 deleted
};

#endif // NETWORK_H

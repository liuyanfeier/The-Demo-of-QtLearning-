#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include <QObject>

class Newspaper : public QObject
{
    //只有继承了QObject类的类，才具有信号槽的能力
    Q_OBJECT
    /*
     * 凡是QObject类（不管是直接子类还是间接子类），
     * 都应该在第一行代码写上Q_OBJECT。不管是不是使用信号槽，
     * 都应该添加这个宏。这个宏的展开将为我们的类提供信号槽机制、
     * 国际化机制以及 Qt 提供的不基于 C++ RTTI 的反射能力。
     */

public:
    Newspaper(const QString & name) :
        m_name(name)
    {
    }
    void send()
    {
        emit newPaper(m_name);
        /*
         * emit 是 Qt 对 C++ 的扩展，
         * 是一个关键字（其实也是一个宏）。
         * emit 的含义是发出，也就是发出newPaper()信号
         */
    }

signals:
    void newPaper(const QString &name);
    /*
     * signals 块所列出的，就是该类的信号。
     * 信号就是一个个的函数名，返回值是 void
     * （因为无法获得信号的返回值，所以也就无需返回任何值），
     * 参数是该类需要让外界知道的数据。信号作为函数名，
     * 不需要在 cpp 函数中添加任何实现
     */

private: QString m_name; };

#endif // NEWSPAPER_H

#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include <QObject>
#include <QDate>

class Newspaper : public QObject
{
    Q_OBJECT
public:
    Newspaper(const QString & name , const QDate & date):
        m_name(name),m_date(date)
    {
    }

    void send () const
    {
        //emit newPaper(m_name);
        emit newPaper(m_name,m_date);
    }

signals:
    //void newPaper(const QString &name)const;
    void newPaper(const QString &name,const QDate &date)const;
    //重载的信号

private:
    QString m_name;
    QDate m_date;
};

#endif // NEWSPAPER_H

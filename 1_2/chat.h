#ifndef CHAT_H
#define CHAT_H

#include <QWidget>

enum MessageType {
    Message,//消息
    FileName,//文件名
};


class Chat : public QWidget
{
    Q_OBJECT

public:
    explicit Chat(QWidget *parent = 0);
    ~Chat();
};

#endif // CHAT_H

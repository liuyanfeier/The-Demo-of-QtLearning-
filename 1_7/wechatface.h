#ifndef WECHATFACE_H
#define WECHATFACE_H

#include <QWidget>

namespace Ui {
class weChatFace;
}

class weChatFace : public QWidget
{
    Q_OBJECT

public:
    explicit weChatFace(QWidget *parent = 0);
    ~weChatFace();

private:
    Ui::weChatFace *ui;
};

#endif // WECHATFACE_H

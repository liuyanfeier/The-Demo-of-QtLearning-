#include "wechatface.h"
#include "ui_wechatface.h"

weChatFace::weChatFace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::weChatFace)
{
    ui->setupUi(this);
}

weChatFace::~weChatFace()
{
    delete ui;
}

#include "weixin_1.h"

weiXin::weiXin(QWidget *parent)
    : QDialog(parent)
{

}


void weiXin::fontEvent()
{
    bool ok;
    QFont font1 = QFontDialog::getFont(
                &ok,QFont("1",10),this);
    if(ok){
//        setFont(font);
       font = font1;
    }
}

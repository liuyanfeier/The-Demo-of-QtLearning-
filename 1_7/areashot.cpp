#include "areashot.h"

areashot::areashot(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);

      //取得屏幕大小，初始化 cutScreen

    //  this->show();
      //保存全屏
      this->hide();
      fullScreen = new QPixmap();


      //设置透明度实现模糊背景
      QPixmap pix(cutScreen->width(),cutScreen->height());
      pix.fill((QColor(160,160,165,192)));
      bgScreen = new QPixmap(*fullScreen);
      QPainter p(bgScreen);
      p.drawPixmap(0,0,pix);

   //   截图信息显示区域背景
      infoPix = new QPixmap(WIDTH_SHOW,HEIGHT_SHOW);
      QPainter infoP(infoPix);
      infoP.setBrush(QBrush(QColor(Qt::black),Qt::SolidPattern));
      infoP.drawRect(0,0,WIDTH_SHOW,HEIGHT_SHOW);

    //  input = new myInputDialog(this);
      //show init screen
     this->show();
}

areashot::~areashot()
{

}


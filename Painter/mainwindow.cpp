#include <QPainter>

#include "mainwindow.h"
#include "ui_mainwindow.h"

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



PaintedWidget::PaintedWidget(QWidget *parent) :
    QWidget(parent)
{
    resize(700,300);  //设置窗口大小
    setWindowTitle(tr("Paint Demo"));
}

//void PaintedWidget::paintEvent(QPaintEvent *)
//{
//    //paintEvent()函数里面是绘制的代码
//    QPainter painter(this);
//    //painter.setPen(Qt::black);   //默认就是黑色的
//    //painter.setPen(QPen(Qt::black,5));
//    painter.drawLine(80,100,650,500);

//    painter.setPen(Qt::red);
//    //painter.setPen(QPen(Qt::green,5));
//    painter.drawRect(10,10,100,500);

//    painter.setPen(QPen(Qt::green,5));//5像素的轮廓线
//    painter.setBrush(Qt::blue);      //填充
//    painter.drawEllipse(50,150,400,200);
//    //QPen画笔，QBrush画刷



//    /*
//     *
//     * QBrush()实例
//     *
//     */
//    QRadialGradient gradident(50,50,50,50,50);
//    gradident.setColorAt(0,QColor::fromRgbF(0,1,0,1));;
//    gradident.setColorAt(1,QColor::fromRgbF(0,0,0,0));

//    QBrush brush(gradident);

//    /*
//     *
//     * QBrush()实例
//     *
//     */

//    QPen pen(Qt::green,3,Qt::DashDotDotLine,Qt::RoundCap,Qt::RoundJoin);
//    painter.setPen(pen);
//    painter.drawLine(180,100,650,600);
//    //等价于下面的代码
////    QPen pen;

////    pen.setStyle(Qt::DashDotDotLine);   //定义了线的样式
////    pen.setWidth(3);                      //定义了画笔的宽
////    pen.setBrush(Qt::green);              //填充画笔所绘制的线条
////    pen.setCapStyle(Qt::RoundCap);        //定义了绘制的线的末端
////    pen.setJoinStyle(Qt::RoundJoin);      //定义了两条线如何相连

////    painter.setPen(pen);
//}


////反走样
//void PaintedWidget::paintEvent(QPaintEvent *)
//{
//    QPainter  painter(this);

//    painter.setPen(QPen(Qt::black,15,Qt::DashDotDotLine,Qt::RoundCap));
//    painter.setBrush(Qt::yellow);
//    painter.drawEllipse(50,150,200,150);

//    painter.setRenderHint(QPainter::Antialiasing,true);
//    //将Antialiasing属性(反走样)设置为true，打开了QPainter的反走样功能
//    painter.setPen(QPen(Qt::black,15,Qt::DashDotDotLine,Qt::RoundCap));
//    painter.setBrush(Qt::yellow);
//    painter.drawEllipse(300,150,200,150);
//}


////渐变，在QBrush()里面定义
//void PaintedWidget::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);

//    painter.setRenderHint(QPainter::Antialiasing,true);
//    painter.setPen(QPen(Qt::black,3,Qt::DashDotDotLine,Qt::RoundCap));
////    //线性渐变
////    QLinearGradient linearGradient(60,50,200,200);
////    //创建了一个QLinearGradient对象实例，参数为起点和终点坐标，可作为颜色渐变的方向
////    linearGradient.setColorAt(0.2,Qt::white);
////    linearGradient.setColorAt(0.6,Qt::green);
////    linearGradient.setColorAt(1.0,Qt::black);  //渐变
////    painter.setBrush(QBrush(linearGradient));
////    painter.drawEllipse(50,50,200,150);


//     //辐射渐变
//     QRadialGradient radialGradient(310,110,100,310,110);
//     //创建了一个QRadialGradient对象实例，参数分别为中心坐标，
//     //半径长度和焦点坐标,如果需要对称那么中心坐标和焦点坐标要一致
//     radialGradient.setColorAt(0,Qt::green);
//     radialGradient.setColorAt(0.4,Qt::blue);
//     radialGradient.setColorAt(1.0,Qt::yellow);
//     painter.setBrush(QBrush(radialGradient));
//     painter.drawEllipse(210,10,200,200);
//}

////实例，色轮
//void PaintedWidget::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing);

//    const int r = 150;
//    //弧度渐变
//    QConicalGradient conicalGradient(0,0,0);
//    // //创建了一个QConicalGradient对象实例，参数分别为中心坐标和初始角度

//    conicalGradient.setColorAt(0.0,Qt::red);
//    conicalGradient.setColorAt(60.0/360.0,Qt::yellow);
//    conicalGradient.setColorAt(120.0/360.0,Qt::green);
//    conicalGradient.setColorAt(180.0/360.0,Qt::cyan);
//    conicalGradient.setColorAt(240.0/360.0,Qt::blue);
//    conicalGradient.setColorAt(300.0/360.0,Qt::magenta);
//    conicalGradient.setColorAt(1.0,Qt::red);

//    painter.translate(r,r);
//    //QPainter::translate(x, y)函数意思是，将坐标系的原点设置到 (x, y) 点。

//    painter.setPen(Qt::NoPen);
//    painter.setBrush(QBrush(conicalGradient));
//    painter.drawEllipse(QPoint(0,0),r,r);
//}


////实例，坐标
//void PaintedWidget::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);

//    painter.fillRect(10,10,50,100,Qt::red);
//    painter.save();  //保存

//    painter.translate(100,0);//向右移动100px

//    painter.fillRect(10,10,50,100,Qt::yellow);
//    painter.restore();//回复保存的内容，也就是把坐标系恢复成默认的情况
//    painter.save();

//    painter.translate(300,0);
//    painter.rotate(30);//顺时针旋转30度

//    painter.fillRect(10,10,50,100,Qt::green);
//    painter.restore();
//    painter.save();

//    painter.translate(400,0);
//    painter.scale(2,3);//横坐标单位放大两倍，纵坐标放大三倍

//    painter.fillRect(10,10,50,100,Qt::blue);
//    painter.restore();
//    painter.save();

//    painter.translate(600,0);
//    painter.shear(0,1);//横向不变，纵向扭曲一倍

//    painter.fillRect(10,10,50,100,Qt::cyan);
//    painter.restore();

//    //painter.setWindow(0,0,200,200);  //设置窗口矩形
//    //逻辑坐标被重新分配
//    //painter.fillRect(0,0,200,200,Qt::black);

////    painter.setViewport(0,0,200,200);
////    //viewport代表物理坐标
////    painter.fillRect(0,0,200,200,Qt::black);
//}


//实例，QPixmap和QBitmap
void PaintedWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/1/qt-logo");
    QBitmap bitmap;
    bitmap.load(":/1/qt-logo");
    painter.drawPixmap(10,10,250,125,pixmap);
    painter.drawPixmap(270,10,250,125,bitmap);

    QPixmap whitePixmap(":/1/qt-logo-white");
    QBitmap whiteBitmap(":/1/qt-logo-white");
    painter.drawPixmap(10,140,250,125,whitePixmap);
    painter.drawPixmap(270,140,150,125,whiteBitmap);
}


////QPicture实例
//void PaintedWidget::paintEvent(QPaintEvent *)
//{
//    QPicture picture;
//    QPainter painter;
//    painter.begin(&picture);//在picture上进行绘制
//    painter.drawEllipse(10,20,80,70);
//    painter.end();
//    picture.save("drawing.pic"); //保存picture图片
//}

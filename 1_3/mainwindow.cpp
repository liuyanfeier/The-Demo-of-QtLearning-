#include "mainwindow.h"
#include "ui_mainwindow.h"

Qt1::Qt1(QWidget *parent)
    : QDialog(parent)
{
    tbfont = new QPushButton;
    tbcolor = new QPushButton;
    tbtru = new QPushButton;
    tbbq = new QPushButton;
    tbsend = new QPushButton;
    tbfont->setIcon(QIcon(":/2"));
    tbcolor->setIcon(QIcon(":/2"));
    tbtru->setIcon(QIcon(":/2"));
    tbbq->setIcon(QIcon(":/2"));
    tbsend->setIcon(QIcon(":/2"));

    te1 = new QTextEdit;
    te2 = new QTextEdit;

    QString str = te2->toPlainText();
    qDebug() << str;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(te1);
//    layout->addWidget(tbfont,8,0,1,1);
//    layout->addWidget(tbcolor,8,1,1,1);
//    layout->addWidget(tbtru,8,2,1,1);
//    layout->addWidget(tbbq,8,3,1,1);
    layout->addWidget(tbsend);
    layout->addWidget(te2);

    setLayout(layout);

//    connect(tbfont,SIGNAL(clicked()),this,SLOT(fontfun()));   //字体类型
//    connect(tbcolor,SIGNAL(clicked()),this,SLOT(colorfun())); //字体颜色
//    connect(tbtru,SIGNAL(clicked()),this,SLOT(trumfun()));    //震动
//    connect(tbbq,SIGNAL(clicked()),this,SLOT(insertImage()));//插入图片
    connect(tbsend,SIGNAL(clicked()),);//发送消息

//    connect(tbsend,SIGNAL(clicked()),te2,SLOT(clear()));//发送消息
}

//void Qt1::fontfun()//设置字体类型
//{
//    bool ok;
//    QFont font = QFontDialog::getFont(
//                 &ok, QFont("Helvetica [Cronyx]", 10), this);
//    if (ok)
//    {
//        te2->setFont(font);
//        f = font;
//    }
//}

//void Qt1::colorfun() //设置字体颜色
//{
//    QColor color = QColorDialog::getColor ( Qt::red, this );
//    te2->setTextColor(color);
//    c = color;
//}

//void Qt1::trumfun() //震动效果实现
//{
//    QPoint p = getPos(this);//获取当前窗口坐标
//    int x = p.x();
//    int y = p.y();
//    int i = 0;

//    for(i=0;i<10;i++)//改变窗口位置实现震动效果
//    {
//        this->move(x+5,y+5);
//        usleep(300);
//        this->move(x,y);
//        usleep(300);
//        this->move(x-5,y-5);
//        usleep(300);
//        this->move(x,y);
//    }

//    this->move(x-1,y-28);
//}

void Qt1::sendfun()
{
//    QFont ff (QFont( "AR PL UKai CN,10,-1,5,50,0,0,0,0,0" )) ;
//    QColor cc (0,0,0);
//    setInsertTextColor(cc);//设置系统时间字体颜色
//    setInsertTextFont(ff);//设置系统时间字体类型
//    te1->append(showTime());
//    setInsertTextColor(c);//设置插入字体颜色
//    setInsertTextFont(f);//设置插入字体字体类型
//    QString str= te1->toHtml();

//    te2->setText(str);
//    te2->show();

//    QString str = te2->toPlainText();
//    te1->append(str);
    te2->clear();
}

//void Qt1::setInsertTextColor(const QColor &col)//把col颜色作为字体颜色
//{
//    QTextCharFormat fmt;//文本字符格式
//    fmt.setForeground(col);// 前景色(即字体色)设为col色
//    QTextCursor cursor = te1->textCursor();//获取文本光标
//    cursor.mergeCharFormat(fmt);//光标后的文字就用该格式显示
//    te1->mergeCurrentCharFormat(fmt);//textEdit使用当前的字符格式
//}

//void Qt1::setInsertTextFont(const QFont &col)//把col颜色作为字体颜色
//{
//    QTextCharFormat fmt;//文本字符格式
//    fmt.setFont(col);//字体
//    QTextCursor cursor = te1->textCursor();//获取文本光标
//    cursor.mergeCharFormat(fmt);//光标后的文字就用该格式显示
//    te1->mergeCurrentCharFormat(fmt);//textEdit使用当前的字符格式
//}

//void Qt1::insertImage() //文本编辑框中插入图片
//{
//    QString file = QFileDialog::getOpenFileName(this, tr("Open File"),"pic/",\
//                                            tr("Images (*.png *.jpg)"));
//    QUrl Uri ( QString ( "file://%1" ).arg ( file ) );
////    QImage image = QImageReader ( file ).read();

//    QTextDocument * textDocument = te2->document();
////    textDocument->addResource( QTextDocument::ImageResource, Uri, QVariant ( image ) );
//    QTextCursor cursor = te2->textCursor();
//    QTextImageFormat imageFormat;
////    imageFormat.setWidth( image.width() );
////    imageFormat.setHeight( image.height() );
//    imageFormat.setName( Uri.toString() );
//    cursor.insertImage(imageFormat);
// }

//QPoint Qt1::getPos(QWidget* widget)//获取窗体位置坐标
//{
//     if (NULL == widget)
//     {
//        return QPoint(-1,-1);
//     }

//     float px = 0;
//     float py = 0;
//     QWidget *parent = widget;
//     QWidget *preParent= NULL;
//     do
//     {
//          QPoint p = parent->pos();
//          px += p.x();
//          py += p.y();
//          preParent = parent ;
//          parent = parent->parentWidget();
//     } while (NULL != parent);

//     QSize size = preParent->frameSize();
//     QSize size2 = preParent->size();
//     px = px + (size.width() - size2.width())/2;
//     py = py + (size.height() - size2.height() - (size.width() - size2.width())/2);
//     QPoint pr(px, py);

//     return pr;
//}

//QString Qt1::showTime()//获取系统时间
//{
//    QTime time = QTime::currentTime();
//    QString text = time.toString("hh:mm:ss");

//    return text;
//}



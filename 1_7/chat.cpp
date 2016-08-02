#include <QPalette>
#include <QDir>

#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);

//    ui->front_size->insertItem(0,tr("8"));
//    ui->front_size->insertItem(1,tr("9"));
//    ui->front_size->insertItem(2,tr("10"));
//    ui->front_size->insertItem(3,tr("11"));
//    ui->front_size->insertItem(4,tr("12"));
//    ui->front_size->insertItem(5,tr("13"));
//    ui->front_size->insertItem(6,tr("14"));
//    ui->front_size->insertItem(7,tr("15"));
//    ui->front_size->insertItem(8,tr("16"));
//    ui->front_size->insertItem(9,tr("17"));
//    ui->front_size->insertItem(10,tr("18"));
//    ui->front_size->insertItem(11,tr("19"));
//    ui->front_size->insertItem(12,tr("20"));

  //  ui->textEdit->append("<img src='./resorces/1.bmp'>");/////可以用来获取图片资源么有问题

    this->setStyleSheet("background-color:white");  //背景色


    connect(ui->send_chat,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));

    connect(ui->QQface,SIGNAL(clicked()),this,SLOT(on_QQface_clicked));


}


chat::~chat()
{
    delete ui;
}


void chat::on_pushButton_clicked()
{
    QString time = QDateTime::currentDateTime().toString("hh:mm");
 // QString msg=ui->textEdit->toPlainText();//获取要发送的信息，只能获取文本
    QString msg=ui->textEdit->toHtml();//////这样获取的是整个html页面的格式

    ui->textBrowser->setTextColor(Qt::green);
    ui->textBrowser->setCurrentFont(QFont("Times New Roman",11));//设置发送的字体
    ui->textBrowser->append(time+"\n");
    ui->textBrowser->insertHtml(msg);

    ui->textEdit->clear();
}

void chat::on_QQface_clicked()
{
    qDebug()<<"in the on_QQface_clicked";
    chatEmotion *mychat_face=new chatEmotion();
    qDebug()<<"on_QQface_clicked() is press";

    mychat_face->show();
    connect(mychat_face,SIGNAL(load_face(QString)),this,SLOT(loadface(QString)));
    qDebug()<<"on_QQface_clicked after";
}

void chat::loadface(QString clickedname)
{
    qDebug()<<"in the loadface------127";
    QString beclick_name=clickedname;
   // beclick_name.split("_")
    int num_name=beclick_name.size();

    QStringList array;
    QString second_name;

    if(num_name==5)
        ui->textEdit->append("<img src='./1.gif'>");
    else
    {
        array=beclick_name.split("_");////字符串分割，将对应的图片资源加载到聊天窗口
        second_name=array.at(1);
        ui->textEdit->append("<img src='./"+second_name+".gif'>");
    }
}


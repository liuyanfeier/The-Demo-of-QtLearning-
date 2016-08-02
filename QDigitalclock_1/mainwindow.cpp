#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLCDNumber>
#include <QTimer>
#include <QTime>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    lcdNumber = new QLCDNumber();
    lcdNumber->setDigitCount(8);
    //设置晶体管控件QLCDNumber能显示的位数
    lcdNumber->setMode(QLCDNumber::Dec);
    //显示的模式为十进制
    lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    //设置显示方式

    timer = new QTimer();
    timer->start(1000);

    layout = new QVBoxLayout();
    layout->addWidget(lcdNumber);

    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    onTimeOut();

    resize(150, 60);
    this->setLayout(layout);
}

void Dialog::onTimeOut()
{
    QTime time = QTime::currentTime();
    lcdNumber->display(time.toString("hh:mm:ss"));
}

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

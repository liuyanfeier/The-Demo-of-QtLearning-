#include "mainwindow.h"
#include "ui_mainwindow.h"

LineEdit::LineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    setFixedSize(100,20);
    //上面的横条
}

void LineEdit::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        emit clicked();
    }
    QLineEdit::mousePressEvent(event);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(400, 400);
    //设置这个窗口部件的大小，这样就可以防止它变大或者变小。
    calendar = new QCalendarWidget(this);
    lineedit = new LineEdit(this);
    com = new QFontComboBox(this);

    lineedit->setGeometry(100,70,100,20);
    calendar->setGeometry(100,100,200,200);

    com->clear();
    com->insertItem(0,"00:00");
    com->insertItem(1,"00:30");
    com->insertItem(2,"01:00");
    com->insertItem(3,"01:30");
    com->setGeometry(200,70,100,20);
    calendar->hide();

    connect(lineedit,SIGNAL(clicked()),calendar,SLOT(show()));
//    connect(lineedit,SIGNAL(textChanged(QString)),calendar,SLOT(show()));
    connect(calendar,SIGNAL(clicked(QDate)),this,SLOT(ok()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ok()
{
    QDate date = calendar->selectedDate();
    qDebug() << date.year() << date.month() << date.day();
    int y = date.year();
    int m = date.month();
    int d = date.day();

    QString str1;
    str1 = QString::number(y)+"-"+QString::number(m)+"-"+QString::number(d);
    lineedit->setText(str1);
    //calendar->hide();
}



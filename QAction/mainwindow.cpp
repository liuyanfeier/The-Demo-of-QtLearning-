#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
  //构造函数
{
    //setWindowTitle(tr("Main Window"));
    //设置主窗口的标题，文本使用tr()函数，这是一个用于Qt国际化的函数
    setWindowTitle(tr("主窗口"));

    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);   //图标好像显示不出来
    //，以:开始，意味着从资源文件中查找资源。:/images/doc-open就是找到了这里的document-open.png这个文件。
    //是不是没有添加相应的资源文件？？？？？

    /*
     * 上面的问题解决了，确实是因为没有添加相应的资源文件，可以选择“添加新文件…”，可以在Qt分类下找到“Qt Resource File”，添加就可以了
     * 然后将自己的图标文件添加到相应的文件夹中，添加到资源文件中就可以了
     *
     */

    //openAction = new QAction(QIcon(":\\folder\\image"), tr("&Open..."), this);    //图标也显示不出来
    //openAction = new QAction(QIcon("d:\\QtPicture\\1.JPEG"), tr("&Open..."), this);//图标还是显示不出来
    //openAction = new QAction(QIcon("d:\\QtPicture\\1.PNG"), tr("&Open..."), this);  //不知道为什么JPEG文件显示不出来，PNG就可以
    //懂了，png格式的图片，这是Qt内置支持的图片格式。其他格式的图片，比如jpg、gif则需要插件支持。
    //传入一个图标，一个文本和一个this指针，this指针的作用？？？？,
    //this指针代表的是一个parent指针，可以看构造函数的实现
    //tr("&Open..."),文本值前面有一个&，意味着这将成为一个快捷键。虽然还不懂为什么，先记着
    openAction->setShortcuts(QKeySequence::Open);
    //setShortcuts()函数，用于说明这个QAction的快捷键
    //openAction->setShortcuts(tr("ctrl+O"));  //错误，no matching function for call to 'QAction::setShortcuts(QString)'
    openAction->setStatusTip(tr("Open an existing file"));
    //setStatusTip()实现了当用户鼠标滑过这个 action 时，会在主窗口下方的状态栏显示相应的提示。
    connect(openAction,&QAction::triggered,this,&MainWindow::open);

    //QMenu *file = menuBar()->addMenu(QIcon("d:\\QtPicture\\1.PNG"),tr("&File"));
    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

//    QMenu *file1 = menuBar()->addMenu(tr("&File1"));
//    file1->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    statusBar();   //创建状态栏

}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    QMessageBox::information(this,tr("Information"),tr("Open"));
}

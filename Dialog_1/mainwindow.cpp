#include <QAction>
#include <QMenuBar>
#include <QDebug>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("主窗口"));

    //openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    openAction = new QAction(QIcon("d:\\QtPicture\\1.PNG"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction,&QAction::triggered,this,&MainWindow::open);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    statusBar();   //创建状态栏

}

MainWindow::~MainWindow()
{

}

//void MainWindow::open()
//{
//    QDialog dialog(this);    //使用QDialog创建了一个对话框
//    dialog.setWindowTitle(tr("hello Dialog"));//设置标题
//    dialog.exec();  //显示
//    qDebug() << dialog.result();
//    //使用了之前的代码
//}
////模态

//void MainWindow::open()
//{
//    //QDialog dialog(this);   //有parent指针
//    QDialog *dialog = new QDialog(this);
//    dialog->setAttribute(Qt::WA_DeleteOnClose);
//    //setAttribute()函数设置对话框关闭时，自动销毁对话框。
//    dialog->setWindowTitle("Hello");
//    //dialog.exec();
//    dialog->show();
//}
////非模态

//void MainWindow::open()
//{
//    if (QMessageBox::Yes ==
//            QMessageBox::question(
//                this, tr("Question"),
//                tr("Are you OK?"),
//                QMessageBox::Yes | QMessageBox::No,
//                QMessageBox::Yes))
//    {
//        QMessageBox::information(
//                    this, tr("Hmmm..."),
//                    tr("I'm glad to hear that!"));
//    }
//    else
//    {
//        QMessageBox::information(
//                    this, tr("Hmmm..."),
//                    tr("I'm sorry!"));
//    }
//}
////模态

void MainWindow::open()
{
    QMessageBox msgBox;
    msgBox.setText(tr("The document has been modified."));
    //主要文本信息
    msgBox.setInformativeText(tr("Do you want to save your changes?"));
    //InformativeText()会在对话框中显示简单说明文字
    msgBox.setDetailedText(tr("Differences.."));
    //详细信息，当我们点击详细信息按钮是给出更多信息
    msgBox.setStandardButtons(QMessageBox::Save
                              | QMessageBox::Discard
                              | QMessageBox::Cancel);
    //自定义的三个按钮
    msgBox.setDefaultButton(QMessageBox::Save);
    //默认
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save:
        qDebug()<<"Save!";
        break;
    case QMessageBox::Discard:
        qDebug()<<"Discard!";
        break;
    case QMessageBox::Cancel:
        qDebug()<<"Cancel!";
        break;
    default:
        break;
    }
}
//模态

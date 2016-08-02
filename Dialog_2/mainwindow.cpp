#include <QAction>
#include <QMenuBar>
#include <QDebug>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QTextEdit>
#include <QFileDialog>
#include <QIODevice>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("文本编辑"));

    openAction = new QAction(QIcon(":/images/file-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an file"));

    saveAction = new QAction(QIcon(":/images/file-save"), tr("&Open..."), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));

    connect(openAction,&QAction::triggered,this,&MainWindow::openFile);
    connect(saveAction,&QAction::triggered,this,&MainWindow::saveFile);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    textEdit = new QTextEdit(this);
    //QTextEdit用于显示富文本，可以显示文本，图片，表格等
    setCentralWidget(textEdit);
    //QMainWindow里面的setCentralWidget()函数，可以将组建放在窗口的中央
    connect(textEdit,&QTextEdit::textChanged,[=](){
       this->setWindowModified(true);
    });
//    setWindowTitle("TextPad [*]");

    statusBar();   //创建状态栏

}

MainWindow::~MainWindow()
{

}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,    //父指针
                                                tr("Open File"),//对话框标题
                                                "/",//对话框打开时的默认目录"."
                                                //代表程序运行目录，"/"当前盘符根目录
                                                tr("Text Files(*.txt)")//过滤器
                                                );
    //getOpenFileName得到需要获取的文件的路径
    if(!path.isEmpty()){
        QFile file(path);  //将文件的路径传递给QFile对象
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            //使用只读和文本方式打开，打开成功返回true
            QMessageBox::warning(this,tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return ;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        //使用QTextStream::readAll()读取文件所有内容，
        //然后将其赋值给QTextEdit显示出来。
        file.close();
    }
    else {
        QMessageBox::warning(this,tr("Path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,
                                                tr("Open File"),
                                                ".",tr("Text File(*.txt)"));
    if(!path.isEmpty()){
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
            QMessageBox::warning(this,tr("Write File"),
                                 tr("Cannot open File:\n%1").arg(path));
            return ;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();//<<重定向
        file.close();
    }
    else{
        QMessageBox::warning(this,tr("Path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(isWindowModified()){
        bool exit = QMessageBox::question(this,
                                          tr("Quit"),
                                          tr("Are you sure?"),
                                          QMessageBox::Yes | QMessageBox::No)
                == QMessageBox::Yes;
        if(exit){
            event->accept();
        }
        else {
            event->ignore();      //此时窗口保留不关闭
        }
    }
    else{
        event->accept();
    }
}

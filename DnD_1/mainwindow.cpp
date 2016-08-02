#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    textEdit = new QTextEdit;
    //默认情况下，QTextEdit可以接受从其它应用程序拖放过来的文本类型的数据
    //默认会把文件名插入到光标位置
    setCentralWidget(textEdit);

    textEdit->setAcceptDrops(false);
    setAcceptDrops(true);
    //把QTextEdit的setAcceptDrops()函数置为 false，
    //并且把MainWindow的setAcceptDrops()置为 true，
    //这样我们就能够让MainWindow截获拖放事件，而不是交给QTextEdit处理。

    setWindowTitle(tr("Text Editor"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("text/uri-list")){
        event->acceptProposedAction();
        //。默认情况下，组件是不会接受拖放的。如果我们调用了这个函数，
        //那么 Qt 会自动以光标样式的变化来提示用户是否可以将对象放在组件上。
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty()){
        return ;
    }

    QString fileName = urls.first().toLocalFile();
    if(fileName.isEmpty()){
        return ;
    }

    if(readFile(fileName)){
        setWindowTitle(tr("%1 %2").arg(fileName,tr("Drag File")));
    }
}

bool MainWindow::readFile(const QString &fileName)
{
    bool r = false;
    QFile file(fileName);
    QString content;
    if(file.open(QIODevice::ReadOnly)){
        content = file.readAll();
        r = true;
    }
    textEdit->setText(content);
    return r;
}

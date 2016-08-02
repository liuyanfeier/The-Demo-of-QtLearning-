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

FileSystemWidget::FileSystemWidget(QWidget *parent):
    QWidget(parent)
{
    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    //使用了setRootIndex()对模型进行过滤,实际是设置显示哪个目录

    treeView = new QTreeView(this);
    treeView->setModel(model);
    treeView->setRootIndex(model->index(QDir::currentPath()));
    //程序所在文件的根路径

    QPushButton *mkdirButton = new QPushButton(tr("Make Dir.."),this);
    QPushButton *rmButton = new QPushButton(tr("Remove"),this);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(mkdirButton);
    buttonLayout->addWidget(rmButton);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(treeView);
    layout->addLayout(buttonLayout);

    setLayout(layout);
    setWindowTitle("File System Model");

    connect(mkdirButton,SIGNAL(clicked()),this,SLOT(mkdir()));
    connect(rmButton,SIGNAL(clicked()),this,SLOT(rm()));
}

void FileSystemWidget::mkdir()
{
    QModelIndex index = treeView->currentIndex();
    //获取目录
    if(!index.isValid()) return;
    //避免路径非法

    QString dirName = QInputDialog::getText(this,
                                            tr("Create Dir"),
                                            tr("Dir Name"));
    //弹出对话框询问新的文件夹的名字

    if(!dirName.isEmpty()){
        if(!model->mkdir(index,dirName).isValid()){
            QMessageBox::information(this,
                                     tr("Create Dir"),
                                     tr("Failed!"));
        }
    }
}

void FileSystemWidget::rm()
{
    QModelIndex index = treeView->currentIndex();
    if(!index.isValid()) return;

    bool ok;
    if(model->fileInfo(index).isDir()){
        ok = model->rmdir(index);
        //调用isDir()是否是目录还是文件
    }
    else{
        ok = model->remove(index);
    }

    if(!ok){
        QMessageBox::information(this,
                                 tr("Remove"),
                                 tr("Failed %1").arg(model->fileName(index)));
    }
}



#include "mainwindow.h"
#include "ui_mainwindow.h"

const char *KEY_SHARED_MEMORY = "Shared";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sharedMemory(new QSharedMemory(KEY_SHARED_MEMORY,this))
{
    ui->setupUi(this);
    QWidget *mainWidget = new QWidget(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    setCentralWidget(mainWidget);

    QPushButton *saveButton = new QPushButton(tr("Save"),this);
    mainLayout->addWidget(saveButton);
    QLabel *picLabel = new QLabel(this);  //标签
    mainLayout->addWidget(picLabel);
    QPushButton *loadButton = new QPushButton(tr("Load"),this);
    mainLayout->addWidget(loadButton);

    //加载图片的按钮
    QObject::connect(saveButton,&QPushButton::clicked,[=](){
       if(sharedMemory->isAttached()){
           sharedMemory->detach();
       }
       QString filename = QFileDialog::getOpenFileName(this);
       QPixmap pixmap(filename);
       picLabel->setPixmap(pixmap);

       QBuffer buffer;
       QDataStream out(&buffer);
       buffer.open(QBuffer::ReadWrite);
       out << pixmap;

       int size = buffer.size();
       if(!sharedMemory->create(size)){
           //请求系统创建一个共享内存段
           qDebug() << tr("Create Error:") << sharedMemory->errorString();
       }
       else{
           sharedMemory->lock();
           char *to = static_cast<char *>(sharedMemory->data());
           const char *from = buffer.data().constData();
           memcpy(to,from,qMin(size,sharedMemory->size()));
           sharedMemory->unlock();
       }
    });

    QObject::connect(loadButton,&QPushButton::clicked,[=](){
        if(!sharedMemory->attach()){
            qDebug() << tr("Attach Error: ") << sharedMemory->errorString();
        }
        else{
            QBuffer buffer;
            QDataStream in(&buffer);
            QPixmap pixmap;
            sharedMemory->lock();
            buffer.setData(static_cast<const char*>(sharedMemory->constData()),
                           sharedMemory->size());
            buffer.open(QBuffer::ReadWrite);
            in >> pixmap;
            sharedMemory->unlock();
            sharedMemory->detach();
            picLabel->setPixmap(pixmap);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

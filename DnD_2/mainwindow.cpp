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


ProjectListWidget::ProjectListWidget(QWidget *parent)
    : QListWidget(parent)
{
    setAcceptDrops(true);
}

void ProjectListWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        //检查鼠标右侧点击
        startPos = event->pos();
        //记录当前位置
    }
    QListWidget::mousePressEvent(event);
    //系统自带的处理函数
}

void ProjectListWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button() && Qt::LeftButton){
        //鼠标在移动的时候一直按住左键
        int distance = (event->pos() - startPos).manhattanLength();
        //曼哈顿长度
        if(distance >= QApplication::startDragDistance()){
            performDrag();
        }
    }
    QListWidget::mouseMoveEvent(event);
}

//处理拖放的过程
void ProjectListWidget::performDrag()
{
    QListWidgetItem *item = currentItem();
    if(item){
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(item->text());

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap(":/images/person"));
        if(drag->exec(Qt::MoveAction) == Qt::MoveAction)
        {
            //QDrag::exec()会阻塞拖动的操作，直到用户完成操作或者取消操作
            delete item;
        }
    }
}

void ProjectListWidget::dragEnterEvent(QDragEnterEvent *event)
{
    ProjectListWidget *source = qobject_cast
            <ProjectListWidget *>(event->source());
    if(source && source!= this){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ProjectListWidget::dragMoveEvent(QDragMoveEvent *event)
{
    ProjectListWidget *source = qobject_cast
            <ProjectListWidget *>(event->source());
    if(source && source!= this){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ProjectListWidget::dropEvent(QDropEvent *event)
{
    ProjectListWidget *source = qobject_cast
            <ProjectListWidget *>(event->source());
    if(source && source != this){
        addItem(event->mimeData()->text());
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

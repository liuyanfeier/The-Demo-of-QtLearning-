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

MyListView::MyListView()
{
    QStringList data;
    data << "1" << "2" << "3";

    model = new QStringListModel;
    model->setStringList(data);

    listView = new QListView;
    listView->setModel(model);

    QPushButton *insertBtn = new QPushButton(QObject::tr("insert"));
    QObject::connect(insertBtn,SIGNAL(clicked()),this,SLOT(insertData()));

    QPushButton *delBtn = new QPushButton(QObject::tr("Delete"));
    QObject::connect(delBtn,SIGNAL(clicked()),this,SLOT(deleteData()));

    QPushButton *showBtn = new QPushButton(QObject::tr("Show"));
    QObject::connect(showBtn,SIGNAL(clicked()),this,SLOT(showData()));

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->addWidget(insertBtn);
    btnLayout->addWidget(delBtn);
    btnLayout->addWidget(showBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(listView);
    mainLayout->addLayout(btnLayout);

    listView->setItemDelegate(new SpinBoxDelegate(listView));
    //将委托设置为QListView所使用的委托
    setLayout(mainLayout);
}

MyListView::~MyListView()
{

}

//相应槽函数
//void MyListView::insertData()
//{
//    bool ok;
//    QString text = QInputDialog::getText(this,"Insert",
//                                         "Please input: ",
//                                         QLineEdit::Normal,
//                                         "Yes.",&ok);
//    //QInputDialog::getText,Qt标准对话框，用于获取用户输入的字符串
//    if(ok && !text.isEmpty()){
//        int row = listView->currentIndex().row();
//        //获取QListView当前行，调用其row()函数返回当前是第几行
//        model->insertRows(row,1);
//        //在当前的位置row插入1行
//        QModelIndex index = model->index(row);
//        model->setData(index,text);//将text设置为当前行数据
//        listView->setCurrentIndex(index);
//        //把当前行设置为新插入的一行
//        listView->edit(index);//使这一行可以编辑
//    }
//}


void MyListView::insertData()
{
    bool ok;
    QString text = QInputDialog::getText(this,"Insert",
                                         "Please input: ",
                                         QLineEdit::Normal,
                                         "Yes.",&ok);
    //QInputDialog::getText,Qt标准对话框，用于获取用户输入的字符串
    if(ok && !text.isEmpty()){
        QModelIndex currIndex = listView->currentIndex();
        model->insertRows(currIndex.row(),1);
        model->setData(currIndex,text);//将text设置为当前行数据
        listView->edit(currIndex);//使这一行可以编辑
    }
}

void MyListView::deleteData()
{
    if(model->rowCount() > 1){
        model->removeRows(listView->currentIndex().row(),1);
    }
}

void MyListView::showData()
{
    QStringList data = model->stringList();
    QString str;
    foreach (QString s, data) {
        str += s + "\n";
    }
    QMessageBox::information(this,"Data",str);
}



QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
                                       const QStyleOptionViewItem &/* option */,
                                       const QModelIndex &/* index */) const
{
    QSpinBox *editor = new QSpinBox(parent);
    //parent 参数会作为新的编辑器的父组件。
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    int value = index.model()->data(index,Qt::EditRole).toInt();
    //从模型中获取需要编辑的数据
    QSpinBox *spinBox = static_cast<QSpinBox *>(editor);
    //editor，所生成的编辑器实例，强制转换成QSpinBox实例
    spinBox->setValue(value);
}

void SpinBoxDelegate::setModelData(QWidget *editor,
                                   QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData(index,value,Qt::EditRole);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor,
                                           const QStyleOptionViewItem &option,
                                           const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}



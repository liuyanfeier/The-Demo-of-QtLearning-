#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QStringList>
#include <QTreeWidget>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    QTreeWidget treeWidget;
//    treeWidget.setColumnCount(1);
//    //setColumnCount()函数设定栏数

//    //创建了作为根的root
//    QTreeWidgetItem *root = new QTreeWidgetItem(&treeWidget,
//                                                QStringList(QString("Root")));
//    //QTreeWidgetItem(QTreeWidget *parent, const QStringList &strings, int type = Type);
//    //第一个参数，指定这个项属于哪一个树，第二个参数指定显示的文字；第三个参数指定其类型
//    new QTreeWidgetItem(root,QStringList(QString("Leaf 1")));
//    QTreeWidgetItem *leaf2 = new QTreeWidgetItem(root,QStringList(QString("Leaf 2")));
//    leaf2->setCheckState(0,Qt::Checked);  //设置的可选标记

//    QList<QTreeWidgetItem *>rootList;
//    rootList << root;
//    //将root添加到了QTreeWidgetItem的列表
//    treeWidget.insertTopLevelItems(0,rootList);

//    treeWidget.setWindowTitle(QObject::tr("QTreeWidget Dome"));
//    treeWidget.show();

//    return a.exec();
//}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTreeWidget treeWidget;

    QStringList handers;
    //设置树的表头
    handers << "Name" << "Number";
    treeWidget.setHeaderLabels(handers);
    //treeWidget.setHeaderHidden(handers);

    QStringList rootTextList;
    rootTextList << "Root" << "0";

    QTreeWidgetItem *root = new QTreeWidgetItem(&treeWidget,rootTextList);
    new QTreeWidgetItem(root,QStringList() << QString("Leaf 1") << "1");
    QTreeWidgetItem *leaf2 = new QTreeWidgetItem(root,
                                                 QStringList() << QString("Leaf 2") << "2");
    leaf2->setCheckState(0,Qt::Checked);

    QList<QTreeWidgetItem *> rootList;
    rootList << root;
    treeWidget.insertTopLevelItems(0,rootList);

    treeWidget.show();

    return a.exec();
}

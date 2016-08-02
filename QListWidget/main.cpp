#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QListWidget>
#include <QHBoxLayout>
#include <QObject>
#include <QWidget>
#include <QLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel *label = new QLabel;
    label->setFixedWidth(70);

    QListWidget *listWidget = new QListWidget;

    //方法一，向列表组件listWidget添加列表项
    new QListWidgetItem(QIcon(":/Chrome"),QObject::tr("Chrome"),listWidget);
    new QListWidgetItem(QIcon(":/Firefox.png"),QObject::tr("Firefox"),listWidget);

    //方法二，向列表组件listWidget添加列表项
    listWidget->addItem(new QListWidgetItem(QIcon(":/IE"),
                                            QObject::tr("IE")));
    listWidget->addItem(new QListWidgetItem(QIcon(":/Netscape"),
                                            QObject::tr("Netscape")));
    listWidget->addItem(new QListWidgetItem(QIcon(":/Safari.png"),
                                            QObject::tr("Safari")));
    listWidget->addItem(new QListWidgetItem(QIcon(":/TheWorld"),
                                            QObject::tr("TheWorld")));
    listWidget->addItem(new QListWidgetItem(QIcon(":/Traveler"),
                                            QObject::tr("Traveler")));

    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setIcon(QIcon(":/Maxthon.png"));
    newItem->setText(QObject::tr("Maxthon"));

    listWidget->insertItem(3,newItem); //第一个参数表示的是，图标显示的顺序

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(listWidget);

    QObject::connect(listWidget,SIGNAL(currentTextChanged(QString)),
            label,SLOT(setText(QString)));

    //横向表示
    //listWidget->setViewMode(QListView::IconMode);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    widget->setWindowTitle(QObject::tr("QListWidget Demo"));
    widget->show();

    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QTableWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTableWidget tableWidget;
    tableWidget.setColumnCount(3);//设置列
    tableWidget.setRowCount(5);//设置行

    QStringList handers;
    handers << "ID" << "Name" << "Age" << "Sex";
    tableWidget.setHorizontalHeaderLabels(handers);

    tableWidget.setItem(0,0,new QTableWidgetItem(QString("0001")));
    tableWidget.setItem(1,0,new QTableWidgetItem(QString("0002")));
    tableWidget.setItem(2,0,new QTableWidgetItem(QString("0003")));
    tableWidget.setItem(3,0,new QTableWidgetItem(QString("0004")));
    tableWidget.setItem(4,0,new QTableWidgetItem(QString("0005")));
    tableWidget.setItem(0,1,new QTableWidgetItem(QString("0006")));
    tableWidget.setItem(0,2,new QTableWidgetItem(QString("0007")));

    tableWidget.show();

    return a.exec();
}

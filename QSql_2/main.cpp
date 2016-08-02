#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSql>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QAbstractItemView>
#include <QHeaderView>

//<bookindex>
//<entry term="sidebearings">
//        <page>10</page>
//        <page>34-35</page>
//        <page>307-308</page>
//    </entry>
//    <entry term="subtraction">
//        <entry term="of pictures">
//            <page>115</page>
//            <page>244</page>
//        </entry>
//        <entry term="of vectors">
//            <page>9</page>
//        </entry>
//    </entry>
//</bookindex>

enum ColumnIndex
{
    column_ID = 0,
    column_Name = 1,
    column_Age = 2
};

bool connect(const QString &dbName){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if(!db.open()){
//        QMessageBox::critical(0,QObject::tr("Database Error"),
//                              db.lastError().text());

        //astError()函数，用于检查最新出现的错误
        return false;
    }
    return true;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(connect("demo.db")){

//        CREATE TABLE city (
//                    id INTEGER PRIMARY KEY AUTOINCREMENT,
//                    name VARCHAR);
//        INSERT INTO city (name) VALUES ('Beijing');
//        INSERT INTO city (name) VALUES ('Shanghai');
//        INSERT INTO city (name) VALUES ('Nanjing');
//        INSERT INTO city (name) VALUES ('Tianjin');
//        INSERT INTO city (name) VALUES ('Wuhan');
//        INSERT INTO city (name) VALUES ('Hangzhou');
//        INSERT INTO city (name) VALUES ('Suzhou');
//        INSERT INTO city (name) VALUES ('Guangzhou');

//        PRAGMA foreign_keys = ON;
        //Qt默认将外键屏蔽掉了,启用外键

        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("student");
        model->setSort(column_Age,Qt::AscendingOrder);
        //按照数字所在的列进行排序
        model->setHeaderData(column_ID,Qt::Horizontal,"ID");
        model->setHeaderData(column_Name,Qt::Horizontal,"Name");
        model->setHeaderData(column_Age,Qt::Horizontal,"Age");
        //设置列名
        model->select();
        //选择，进行显示

        QTableView *view = new QTableView;
        view->setModel(model);
        view->setSelectionMode(QAbstractItemView::SingleSelection);
        //单行选择
        view->setSelectionBehavior(QAbstractItemView::SelectRows);
        //按行选择
        //        view->setColumnHidden(0,true);
        //设置第一列不显示
        view->resizeColumnsToContents();
        //resizeColumnsToContents()说明每列宽度适配其内容
        view->setEditTriggers(QAbstractItemView::NoEditTriggers);
        //禁用编辑功能

        QHeaderView *header = view->horizontalHeader();
        header->setStretchLastSection(true);

        view->show();
    }
    else{
        return 1;
    }

    return a.exec();
}

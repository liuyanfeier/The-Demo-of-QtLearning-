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

        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("student");
        model->setSort(2,Qt::AscendingOrder);
        //按照数字所在的列进行排序
        model->setHeaderData(0,Qt::Horizontal,"ID");
        model->setHeaderData(1,Qt::Horizontal,"Name");
        model->setHeaderData(2,Qt::Horizontal,"Age");
        //设置列名
        model->select();
        //选择，进行显示

        QSqlQuery query;

        query.prepare("INSERT INTO student (name, age) VALUES (?, ?)");
        QVariantList names;
        names << "Tom" << "Jack" << "Jane" << "Jerry";
        query.addBindValue(names);
        QVariantList ages;
        ages << 20 << 23 << 22 << 25;
        query.addBindValue(ages);
        if (!query.execBatch()) {
//            QMessageBox::critical(0, QObject::tr("Database Error"),
//                                  query.lastError().text());
        }
        query.finish();
        query.exec("SELECT name, age FROM student");

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

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    if(connect("demo.db")){
//        QSqlQuery query;
//        if(query.exec("CREATE TABLE student("
//                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
//                      "NAME VARCHAR,"
//                      "AGE INT")){
////            QMessageBox::critical(0,QObject::tr("Database Error"),query.lastError());
//            return 1;
//        }
//    }
//    else{
//        return 1;
//    }

//    return a.exec();
//}

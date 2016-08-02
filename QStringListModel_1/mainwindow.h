#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QListView>
#include <QHBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QVBoxLayout>
#include <QDialog>
#include <QLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QStyledItemDelegate>
#include <QSpinBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class MyListView : public QDialog
{
    Q_OBJECT

public:
    MyListView();
    ~MyListView();

private slots:
    void insertData();
    void deleteData();
    void showData();

private:
    QStringListModel *model;
    QListView *listView;
};


//委托,使修改的时候只能输入0到100之内的数字
class SpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    SpinBoxDelegate(QObject *parent = 0) : QStyledItemDelegate(parent){}

    //返回一个组件。该组件会被作为用户编辑数据时所使用的编辑器，
    //从模型中接受数据，返回用户修改的数据。
    QWidget *createEditor(QWidget *parent,const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    //提供上述组件在显示时所需要的默认值。
    void setEditorData(QWidget *editor,const QModelIndex &index)const;
    //返回给模型用户修改过的数据。
    void setModelData(QWidget *editor,QAbstractItemModel *model,
                      const QModelIndex &index) const;
    //确保上述组件作为编辑器时能够完整地显示出来。
    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const;
};

#endif // MAINWINDOW_H

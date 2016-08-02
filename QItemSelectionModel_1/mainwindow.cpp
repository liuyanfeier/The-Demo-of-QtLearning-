#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    model = new QStandardItemModel(8,4,this);
    tableView = new QTableView(this);
    tableView->setModel(model);
    QItemSelectionModel *selectionModel = tableView->selectionModel();

    QObject::connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this,SLOT(updateSelection(QItemSelection,QItemSelection)));

    resize(600,400);
    setCentralWidget(tableView);
}

MainWindow::~MainWindow()
{

}

void MainWindow::updateSelection(const QItemSelection &selected,
                                 const QItemSelection &deselected)
{
    QModelIndexList items = selected.indexes();
    //items.size()：若当前选择和上一次选择有交集，返回非交集的项数；无交集返回此次选择的项索引列表
    QModelIndex index;
    foreach (index, items) {
        QString text = QString("(%1,%2)").arg(index.row()+1)
                .arg(index.column()+1);
        model->setData(index,text);
    }

    items = deselected.indexes(); //返回当前未选择的项的索引列表
    foreach (index, items) {
        model->setData(index,"");
    }

    QItemSelectionModel *selectionModel = tableView->selectionModel();
    QModelIndexList whole_list = selectionModel->selectedIndexes();
    setWindowTitle(QString("%1 item selected").arg(whole_list.size()));
}

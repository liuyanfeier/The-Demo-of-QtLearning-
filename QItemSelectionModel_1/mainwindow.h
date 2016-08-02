#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelection>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QTableView>
#include <QObject>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateSelection(const QItemSelection &selected,
                         const QItemSelection &deselected);

private:
    QStandardItemModel *model;
    QTableView *tableView;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QFileSystemModel>
#include <QTreeView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QInputDialog>
#include <QMessageBox>

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

class FileSystemWidget : public QWidget
{
    Q_OBJECT

public:
    FileSystemWidget(QWidget *parent = 0);

private slots:
    void mkdir();
    void rm();

private:
    QFileSystemModel *model;
    QTreeView *treeView;
};

#endif // MAINWINDOW_H

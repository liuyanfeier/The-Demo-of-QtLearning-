#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedMemory>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QPixmap>
#include <QBuffer>
#include <QDataStream>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class QSharedMemory;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QSharedMemory *sharedMemory;
    //共享内存段
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

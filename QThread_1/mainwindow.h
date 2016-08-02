#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QPushButton>
#include <QObject>
#include <QTimer>
#include <QThread>

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

class WorkerThread : public QThread
{
    Q_OBJECT

public:
    WorkerThread(QObject *parent = 0)
        : QThread(parent)
    {

    }

protected:
    void run()
    {
        QThread::sleep(1);
//        for(int i = 0 ; i < 100000000 ; i++);
//        QTimer::stop;
        emit done();
    }

signals:
    void done();
};

#endif // MAINWINDOW_H

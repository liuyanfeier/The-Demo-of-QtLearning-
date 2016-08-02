#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QGraphicsItem>

class MainWindow : public QObject,public QGraphicsItem
{
    Q_OBJECT

public:
    explicit MainWindow(QObject *parent = 0){};
//    ~MainWindow(){};

};

#endif // MAINWINDOW_H

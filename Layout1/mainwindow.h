#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void addWidget();
    ~MainWindow();

private:
    QPushButton *pAddButton;
    QVBoxLayout *pVlayout;

};

#endif // MAINWINDOW_H

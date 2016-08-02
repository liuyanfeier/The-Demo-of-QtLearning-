#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

class QSlider;

class LCDRange : public QVBoxLayout
{
    Q_OBJECT

public:
    LCDRange(QWidget *parent = 0);
    int value() const;

public slots:
    void setValue(int);

signals:
    void valueChanged(int);

private:
    QSlider *slider;
};


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

#endif // MAINWINDOW_H

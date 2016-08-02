#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QMouseEvent>
#include <QFontComboBox>
#include <QCalendarWidget>
#include <QDebug>


class LineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit LineEdit(QWidget *parent = 0);
    virtual void mousePressEvent(QMouseEvent *event);

signals:
    void clicked();
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
    QCalendarWidget *calendar;
    LineEdit *lineedit;
    QFontComboBox *com;
    QString str;

public slots:
    void ok();

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H

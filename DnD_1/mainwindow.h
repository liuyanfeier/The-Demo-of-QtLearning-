#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDragEnterEvent>
#include <QTextEdit>
#include <QList>
#include <QUrl>
#include <QFile>
#include <QMimeData>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    //拖放进入时间
    void dropEvent(QDropEvent *event);
    //释放鼠标事件

private:
    bool readFile(const QString &fileName);
    QTextEdit *textEdit;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0,QString myname=0,QString name_tosend=0,int ispositive=0);
    inline QString get_myname(){return myname;}
    inline QString get_sendname(){return name_tosend;}

    int setport();
    inline int getport(){return port;}

    Ui::MainWindow *ui;
    QColor mycolor;

    ~MainWindow();

private slots:

    void on_chatFace_clicked();

    void on_file_clicked();

    void on_send_chat_clicked();

private:
    QString myname;
    QString name_tosend;
    int ispositive;

    int port;
};

#endif // MAINWINDOW_H

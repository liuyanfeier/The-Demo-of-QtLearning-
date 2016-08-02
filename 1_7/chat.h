#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QDateTime>
#include <QColor>
#include <QDebug>
#include <QColorDialog>
#include <QProgressBar>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "chatemotion.h"

namespace Ui {
    class chat;
}

class chat : public QDialog
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = 0);

    Ui::chat *ui;
    QColor mycolor;
    ~chat();

public slots:
    void on_pushButton_clicked();
    void loadface(QString clickedname);

private slots:
   void on_QQface_clicked();

};

#endif // CHAT_H

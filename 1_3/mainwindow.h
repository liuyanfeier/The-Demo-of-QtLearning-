#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QDebug>
#include <QPoint>
#include <QColorDialog>
#include <QPushButton>
#include <QFileDialog>
#include <QFontDialog>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QTextEdit>
#include <QTime>
#include <QGridLayout>
#include <QPlainTextEdit>
#include <QTextDocument>
#include <unistd.h>

class Qt1 : public QDialog
{
    Q_OBJECT

public:
    explicit Qt1(QWidget *parent = 0);
//    QPoint getPos(QWidget* widget);
//    void setInsertTextColor(const QColor &col);
//    void setInsertTextFont(const QFont &col);
//    QString showTime();

private:
    QPushButton *tbfont;
    QPushButton *tbcolor;
    QPushButton *tbtru;
    QPushButton *tbbq;
    QPushButton *tbsend;
    QFont f;
    QColor c;
    QTextEdit *te1;
    QTextEdit *te2;

//private slots:
//    void fontfun();
//    void colorfun();
//    void trumfun();
//    void insertImage();
    void sendfun();
};

#endif // MAINWINDOW_H

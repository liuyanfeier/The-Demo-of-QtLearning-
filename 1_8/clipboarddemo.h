



#ifndef CLIPBOARDDEMO_H
#define CLIPBOARDDEMO_H

#include <QWidget>

class ClipboardDemo : public QWidget
{
    Q_OBJECT

public:
    ClipboardDemo(QWidget *parent = 0);

private slots:
    void setClipboard();
    void getClipboard();
};

#endif // CLIPBOARDDEMO_H

#include <QtGui>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include <QMessageBox>

#include "clipboarddemo.h"

ClipboardDemo::ClipboardDemo(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *northLayout = new QHBoxLayout;
    QHBoxLayout *southLayout = new QHBoxLayout;

    QTextEdit *editor = new QTextEdit;
    QLabel *label = new QLabel;
    label->setText("Text Input: ");
    label->setBuddy(editor);
    QPushButton *copyButton = new QPushButton;
    copyButton->setText("Set Clipboard");
    QPushButton *pasteButton = new QPushButton;
    pasteButton->setText("Get Clipboard");

    northLayout->addWidget(label);
    northLayout->addWidget(editor);
    southLayout->addWidget(copyButton);
    southLayout->addWidget(pasteButton);
    mainLayout->addLayout(northLayout);
    mainLayout->addLayout(southLayout);

    connect(copyButton, SIGNAL(clicked()), this, SLOT(setClipboard()));
    connect(pasteButton, SIGNAL(clicked()), this, SLOT(getClipboard()));
}

void ClipboardDemo::setClipboard()
{
    QClipboard *board = QApplication::clipboard();
    board->setText("Text from Qt Application");
}

void ClipboardDemo::getClipboard()
{
    QClipboard *board = QApplication::clipboard();
    QString str = board->text();
    QMessageBox::information(NULL, "From clipboard", str);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qlcdnumber.h>

LCDRange::LCDRange(QWidget *parent)
    : QVBoxLayout(parent)
{
    QLCDNumber *lcd = new QLCDNumber(3);

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(-100,100);
    slider->setValue(0);

    QObject::connect(slider,SIGNAL(valueChanged(int)),lcd,SLOT(display(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)),SIGNAL(valueChanged(int)));

}

int LCDRange::value() const
{
    return slider->value();
}

void LCDRange::setValue(int value)
{
    slider->setValue(value);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

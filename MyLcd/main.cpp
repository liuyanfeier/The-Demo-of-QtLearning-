#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;

    QPushButton *quitButton = new QPushButton("Quit");
    quitButton->setFont(QFont("Times",18,QFont::Bold));

    QObject::connect(quitButton,&QPushButton::clicked,&QApplication::quit);

    QLCDNumber *lcd = new QLCDNumber(4);

    QSlider *slider = new QSlider(Qt::Horizontal,&w);
    slider->setRange(-100,100);
    slider->setValue(0);

    QObject::connect(slider,SIGNAL(valueChanged(int)),lcd,SLOT(display(int)));


    QGridLayout *layout = new QGridLayout;
    layout->addWidget(quitButton,0,0,1,2);
    layout->addWidget(lcd,1,0,1,1);
    layout->addWidget(slider,1,1,1,1);


    w.setLayout(layout);
    w.show();

    return a.exec();
}

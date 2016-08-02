#include "mainwindow.h"
#include <QApplication>

#include <custombutton.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CustomButton button;
    button.setText("Button!");
    button.show();

    return a.exec();
}

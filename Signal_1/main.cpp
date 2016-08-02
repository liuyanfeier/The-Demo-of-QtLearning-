//!!! Qt 5
#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton button("Quit");  //按钮
    QObject::connect(&button,&QPushButton::clicked,&QApplication::quit);
    button.show();

    return app.exec();
}

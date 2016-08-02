//  !!! Qt 5
#include <QApplication>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv); //创建QApplication对象

    QWidget window ;  //顶级窗口
    window.setWindowTitle("LY");

    QPushButton *button1 = new QPushButton("Clik");
    QPushButton *button2 = new QPushButton("Quit");

    QSlider *slider1 = new QSlider(Qt::Horizontal,&window);
    //slider1->setRange(0,100);
    QSlider *slider2 = new QSlider(Qt::Vertical,&window);
    //slider2->setRange(0,100);
    //Qt::Vertical;   //竖直的
    //Qt::Horizontal; //水平的

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(button1,0,0,1,3);
    layout->addWidget(button2,1,0);
    layout->addWidget(slider1,1,1,1,2);
    layout->addWidget(slider2,2,0,1,3);

    window.setLayout(layout);
    window.show();

    return app.exec();
}

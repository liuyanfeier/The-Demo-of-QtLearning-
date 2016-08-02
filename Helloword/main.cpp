#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QApplication对象用于管理QT程序的生命周期

    QLabel label("Hello,World!");
    label.show();
    /*
     * QLabel *label = new QLabel("Hello,World");
     * label->show();
     *
     * 可以，但是不建议这样做，窗口关闭的时候label是没有办法
     * delete的，会造成内存泄漏
     */

    return a.exec();
}

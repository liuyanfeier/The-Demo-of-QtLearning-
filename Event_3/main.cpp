#include <QApplication>
#include <QPushButton>
#include <QMouseEvent>
#include <QDebug>
#include <QLayout>
#include <QWidget>
#include <QMainWindow>

class CustomButton : public QPushButton
{
    //Q_OBJECT

public:
    CustomButton(QWidget *parent)
        : QPushButton(parent)
    {

    }
protected:
    void mousePressEvent(QMouseEvent *event)
    {
        qDebug() << "CustomButton!" ;
    }
};

class CustomButtonEx : public CustomButton
{
    //Q_OBJECT

public:
    CustomButtonEx(QWidget *parent)
        : CustomButton(parent)
    {

    }
protected:
    void mousePressEvent(QMouseEvent *event)
    {
        event->ignore();
        qDebug() << "CustomButtonEx!" ;
        //事件的传播是在组件层次上面的，而不是依靠类继承机制。
    }
};

class CustomWidget : public QWidget
{
    //Q_OBJECT

public:
    CustomWidget(QWidget *parent)
        : QWidget(parent)
    {

    }
protected:
    void mousePressEvent(QMouseEvent *event)
    {
        QWidget::mousePressEvent(event);
        qDebug() << "CustomWidget!" ;
    }
};

class MainWindow : public QMainWindow
{
    //Q_OBJECT

public:
    MainWindow(QWidget *parent = 0)
        : QMainWindow(parent)
    {
        CustomWidget *widget = new CustomWidget(this);
        CustomButton *cbex = new CustomButton(widget);
        cbex->setText(tr("CustomButton"));
        CustomButtonEx *cb = new CustomButtonEx(widget);
        cb->setText(tr("CustomButtonEx"));

        QVBoxLayout *layout = new QVBoxLayout(widget);//竖直布局
        layout->addWidget(cbex);
        layout->addWidget(cb);
        this->setCentralWidget(widget);
    }
protected:
    void mousePressEvent(QMouseEvent *event)
    {
        qDebug() << "MainWindow!" ;
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

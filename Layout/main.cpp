//  !!! Qt 5
#include <QApplication>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv); //创建QApplication对象

    QWidget window ;  //顶级窗口
    window.setWindowTitle("Enter your age");

    QSpinBox *spinBox = new QSpinBox(&window);
    QSlider *slider = new QSlider(Qt::Horizontal,&window);
    //Qt::Vertical,树立
    spinBox->setRange(-100,100);   //使用setRange函数设置了值的范围
    slider->setRange(10,130);  //滑动
    //QSpinBox和QSlider。QSpinBox就是只能输入数字的输入框，
    //并且带有上下箭头的步进按钮。QSlider则是带有滑块的滑竿

    QObject::connect(slider,&QSlider::valueChanged,spinBox,
                     &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
    QObject::connect(spinBox,spinBoxSignal,slider,&QSlider::setValue);
    //QObject::connect(spinBox, &QSpinBox::valueChanged, slider, &QSlider::setValue);
    //直接写上面的语句会报错，这是因为，QSpinBox有两个信号：
    //void valueChanged(int)
    //void valueChanged(const QString &)
    //当我们使用&QSpinBox::valueChanged取函数指针时，
    //编译器不知道应该取哪一个函数
    //（记住前面我们介绍过的，经过 moc 预处理后，signal 也是一个普通的函数。）的地址，
    //因此报错。解决的方法很简单，编译器不是不能确定哪一个函数吗？
    //那么我们就显式指定一个函数。方法就是，我们创建一个函数指针，
    //这个函数指针参数指定为int
    //void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
    //信号槽的链接
    spinBox->setValue(0);   //setValue函数设置了初始显示的值

    QHBoxLayout *layout = new QHBoxLayout;
    //水平布局管理器，按照从左到右的顺序进行添加
    //QVBoxLayout *layout = new QVBoxLayout;
    //QGridLayout *layout = new QGridLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);

    window.setLayout(layout);
    //将水平布局管理器作为窗口的布局管理器
    window.show();

    return app.exec();
}

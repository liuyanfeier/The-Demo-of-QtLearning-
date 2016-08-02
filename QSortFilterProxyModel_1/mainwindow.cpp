#include "mainwindow.h"
#include "ui_mainwindow.h"

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

SortView::SortView()
{
    model = new QStringListModel(QColor::colorNames(),this);
    //Qt 预定义的所有颜色的名字

    modelProxy = new QSortFilterProxyModel(this);
    modelProxy->setSourceModel(model);
    //要为这个 model 进行代理
    modelProxy->setFilterKeyColumn(0);
    //参数为0，也就是只对第一行进行过滤

    view = new QListView(this);
    view->setModel(modelProxy);
    //QListView的数据源必须设置为QSortFilterProxyModel

    QLineEdit *filterInput = new QLineEdit;
    QLabel *filterLabel = new QLabel(tr("Filter"));

    QHBoxLayout *filterLayout = new QHBoxLayout;
    filterLayout->addWidget(filterLabel);
    filterLayout->addWidget(filterInput);

    syntaxBox = new QComboBox;
    syntaxBox->setSizePolicy(QSizePolicy::Expanding,
                                   QSizePolicy::Preferred);
    syntaxBox->addItem(tr("Regular"),QRegExp::RegExp);
    //QregExp::RegExp提供了最一般的正则表达式语法，但这个语法不支持贪婪限定符。
    //这也是 Qt 默认的规则；如果需要使用贪婪限定符，需要使用QRegExp::RegExp2
    syntaxBox->addItem(tr("Wildcard"),QRegExp::Wildcard);
    //这个提供的是 Unix shell 常见的一种规则，使用通配符处理
    syntaxBox->addItem(tr("Fixed"),QRegExp::FixedString);
    //这个是固定表达式，也就是说基本上不使用正则表达式

    QLabel *syntaxLabel = new QLabel(tr("Syntax"));
    QHBoxLayout *syntaxLayout = new QHBoxLayout;
    syntaxLayout->addWidget(syntaxLabel);
    syntaxLayout->addWidget(syntaxBox);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    layout->addLayout(filterLayout);
    layout->addLayout(syntaxLayout);

    connect(filterInput,SIGNAL(textChanged(QString)),
            this,SLOT(filterChanged(QString)));

}

void SortView::filterChanged(const QString &text)
{
    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(
                syntaxBox->itemData(syntaxBox->currentIndex()).toInt());
    QRegExp regExp(text,Qt::CaseInsensitive,syntax);
    modelProxy->setFilterRegExp(regExp);
}

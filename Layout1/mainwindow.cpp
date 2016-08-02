#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{

    QScrollArea *pArea = new QScrollArea();
    pAddButton = new QPushButton();

    QWidget *pWidget = new QWidget();
    pWidget->setStyleSheet("QWidget"
                           "{background:red;}");
    pVlayout = new QVBoxLayout();
    pVlayout->addSpacerItem(new QSpacerItem(100, 30, QSizePolicy::Expanding, QSizePolicy::Expanding));
    pWidget->setLayout(pVlayout);

    pArea->setWidget(pWidget);
    pArea->setWidgetResizable(true);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(pArea);
    mainLayout->addWidget(pAddButton);
    this->setLayout(mainLayout);

    connect(pAddButton, &QPushButton::clicked, this, &MainWindow::addWidget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::addWidget()
{
    QLabel *label = new QLabel();
    label->setText("123lew,l;fd,b;lvd,\n gf;lb,f;g,b;'g\n f,n;lfg,n;lfg;'");
//    label->setMinimumSize(100,30);
    label->setScaledContents(true);
    pVlayout->insertWidget(pVlayout->count()-1, label);

    qDebug() << pVlayout->count();
}

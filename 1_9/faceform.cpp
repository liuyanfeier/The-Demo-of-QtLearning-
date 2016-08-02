#include "faceform.h"
//#include "ui_faceform.h"

faceform::faceform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::faceform)
{
    ui->setupUi(this);
}

faceform::~faceform()
{
    delete ui;
}

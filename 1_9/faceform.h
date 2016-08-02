#ifndef FACEFORM_H
#define FACEFORM_H

#include <QWidget>

namespace Ui {
class faceform;
}

class faceform : public QWidget
{
    Q_OBJECT

public:
    explicit faceform(QWidget *parent = 0);
    ~faceform();

private:
    Ui::faceform *ui;
};

#endif // FACEFORM_H

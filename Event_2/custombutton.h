#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>

class CustomButton : public QPushButton
{
    Q_OBJECT

public:
    CustomButton(QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *e);
private:
    void onButtonCliecked();
};

#endif // CUSTOMBUTTON_H

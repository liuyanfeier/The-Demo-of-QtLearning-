#ifndef AREASHOT_H
#define AREASHOT_H
#define WIDTH_SHOW 340
#define HEIGHT_SHOW 30


#include <QWidget>
#include<QtGui>
#include<QPixmap>
#include<QPainter>
#include<QPoint>
#include<QLabel>
#include<QPixmap>
#include<QLineEdit>

class areashot : public QWidget
{
    Q_OBJECT

public:
    explicit areashot(QWidget *parent = 0);
    ~areashot();

signals:
   void fullshot(QPixmap *p);

private:

    QPixmap *infoPix;         // 截图信息显示背景
    QPixmap *fullScreen;      // 保存全屏图像
    QPixmap *areaScreen;//保存区域截图
    QPixmap *bgScreen;        // 模糊背景图
    QPoint movPos;

};

#endif // AREASHOT_H

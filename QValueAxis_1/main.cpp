#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QValueAxis>
QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLineSeries *series = new QLineSeries();
    series->setPen(QPen(Qt::blue,1,Qt::SolidLine));
    *series << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
            << QPointF(16, 7) << QPointF(18, 5);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple example");
    chart->setAnimationOptions(QChart::SeriesAnimations);//设置曲线呈动画显示

    QValueAxis *axisX = new QValueAxis; //定义X轴
    axisX->setRange(0, 20); //设置范围
    axisX->setLabelFormat("%g"); //设置刻度的格式
    axisX->setTitleText("X Axis"); //设置X轴的标题
//    axisX->setGridLineVisible(true); //设置是否显示网格线
//    axisX->setMinorTickCount(4); //设置小刻度线的数目
//    axisX->setLabelsVisible(false); //设置刻度是否显示

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 10);
    axisY->setTitleText("Y Axis");
    axisY->setLabelFormat("%.2f");
//    axisY->setGridLineVisible(true);
    axisY->setGridLineVisible(true);

    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);
    chart->legend()->hide();   //这里是把图例隐藏

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);   //抗锯齿渲染

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
    return a.exec();
}

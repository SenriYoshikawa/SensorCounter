#include "chartcontrolor.hpp"
#include <QtCharts/QLineSeries>
#include <QChart>
#include <QLayout>
#include <QDebug>


chartcontrolor::chartcontrolor(QWidget *parent) : QWidget(parent)
{
    series = new QtCharts::QLineSeries();
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    //chart->setTitle("Simple line chart example");

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QLayout *chartLayout = new QHBoxLayout;
    chartLayout->addWidget(chartView);

    this->setLayout(chartLayout);

}

chartcontrolor::dataPlotSlt(int data, int msec)
{
    series->append(data, msec);
    update();
    return 0;
}



chartcontrolor::~chartcontrolor()
{

}

#include "chartcontrolor.hpp"
#include <QtCharts/QLineSeries>
#include <QChart>
#include <QLayout>
#include <QDebug>


chartcontrolor::chartcontrolor(QWidget *parent) : QWidget(parent)
{
    generateChart();
}

void chartcontrolor::generateChart()
{
    series = new QtCharts::QLineSeries();

    QtCharts::QChart *chart = new QtCharts::QChart();

    chart->legend()->hide();
    chart->addSeries(series);

    QtCharts::QValueAxis *axisX = new QtCharts::QValueAxis;
    axisX->setRange(0,60000);
    axisX->setTickCount(1000);
    chart->setAxisX(axisX, series);

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis;
    axisY->setRange(0, 500);
    axisY->setTickCount(100);
    chart->setAxisY(axisY, series);

    chart->createDefaultAxes();

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QLayout *chartLayout = new QHBoxLayout;
    chartLayout->addWidget(chartView);

    this->setLayout(chartLayout);
}

chartcontrolor::dataPlotSlt(int data, int msec)
{
    series->append(msec, data);
    qDebug() << data << msec;
    update();
    return 0;
}

void chartcontrolor::reset()
{
    series->clear();
    update();
}

chartcontrolor::~chartcontrolor()
{

}



#ifndef CHARTCONTROLOR_HPP
#define CHARTCONTROLOR_HPP

#include <QWidget>
#include <QChart>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtWidgets/QVBoxLayout>
#include <QtCharts/QValueAxis>


class chartcontrolor : public QWidget
{
    Q_OBJECT
public:
    chartcontrolor(QWidget *parent);
    ~chartcontrolor();

    void reset();

private:
    QtCharts::QLineSeries *series;

    void generateChart();
signals:

public slots:
    dataPlotSlt(int data, int msec);

};

#endif // CHARTCONTROLOR_HPP

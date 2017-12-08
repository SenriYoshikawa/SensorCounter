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
    explicit chartcontrolor(QWidget *parent = 0);
    ~chartcontrolor();

    void paintEvent(QPaintEvent *event) override;

signals:

public slots:
};

#endif // CHARTCONTROLOR_HPP

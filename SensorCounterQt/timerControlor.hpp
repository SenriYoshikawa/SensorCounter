#ifndef TIMERCONTROLOR_HPP
#define TIMERCONTROLOR_HPP

#include <QWidget>
#include <QTime>

class timerControlor : public QWidget
{
    Q_OBJECT
public:
    timerControlor(QWidget *parent);

    void start();
    void reset();
    void paintEvent(QPaintEvent *event) override;

    QTimer *timer;

private:
    QTime time;

signals:
    void dataPlotSgl(int data, int msec);

public slots:
    dataArrive(int data);
};

#endif // TIMERCONTROLOR_HPP

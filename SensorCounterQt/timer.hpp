#ifndef TIMER_HPP
#define TIMER_HPP

#include "QWidget"
#include <QTime>

class Timer : public QWidget
{
    Q_OBJECT
public:
    Timer(QWidget *parent);

    void start();
    void reset();
    void paintEvent(QPaintEvent *event) override;

private:
    QTimer *timer;
    QTime time;
};

#endif // TIMER_HPP

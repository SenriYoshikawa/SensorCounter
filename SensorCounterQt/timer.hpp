#ifndef TIMER_HPP
#define TIMER_HPP

#include "QWidget"

class Timer : public QWidget
{
    Q_OBJECT
public:
    Timer(QWidget *parent);

//    void start();
//    void stop();
    void paintEvent(QPaintEvent *event) override;

private:
    QTimer *qtimer;
    std::size_t time;
};

#endif // TIMER_HPP

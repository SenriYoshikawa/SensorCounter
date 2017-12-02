#include "timer.hpp"

#include "QtWidgets"

Timer::Timer(QWidget *parent) : QWidget(parent)
{
    qtimer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(1000);
    //setWindowTitle(tr("Analog Clock"));
    //resize(200, 200);
}



void Timer::paintEvent(QPaintEvent *)
{
    static const QPoint needle[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };

    QColor needleColor(127, 0, 127);

    int side = qMin(width(), height());
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);
    painter.setPen(Qt::NoPen);
    painter.setBrush(needleColor);
    painter.save();
    painter.rotate(time * 60);
    painter.drawConvexPolygon(needle, 3);
    painter.restore();

    painter.setPen(needleColor);

    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }
/*
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();
    painter.setPen(minuteColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }
*/
    if(time == 60)
    {
        // TODO: カウントを記録してリセットする
    }
}
/*
void Timer::start()
{
    qtimer->start(1000);
}

void Timer::stop()
{
    qtimer->stop();
}
*/
/*
void Timer::reset()
{
    qtimer->stop();
    qtimer->set = 0;
}
*/

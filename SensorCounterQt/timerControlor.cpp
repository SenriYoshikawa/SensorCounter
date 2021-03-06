#include "timerControlor.hpp"
#include <QtWidgets>

timerControlor::timerControlor(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    time = QTime(0,0,0);
}



void timerControlor::paintEvent(QPaintEvent *)
{
    static const QPoint needle[3] = {
        QPoint(5, 8),
        QPoint(-5, 8),
        QPoint(0, -80)
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
    painter.rotate(time.second() * 6);
    painter.drawConvexPolygon(needle, 3);
    painter.restore();

    painter.setPen(needleColor);

    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }

    if(time.minute() == 1)
    {
        time.setHMS(0,0,0);
        timer->stop();
    }

    if(timer->isActive())
    {
        time = time.addMSecs(100);
    }
}

timerControlor::dataArrive(int data)
{
    if(timer->isActive() && time.minute() == 0)
    {
        emit dataPlotSgl(data, time.second() * 1000 + time.msec());
        return 0;
    }
    return 1;
}

void timerControlor::start()
{
    timer->start(100);
}

void timerControlor::reset()
{
    timer->stop();
    time.setHMS(0,0,0);
    update();
}


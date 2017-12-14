#include "lcdcontrolor.hpp"
#include <QDebug>

lcdcontrolor::lcdcontrolor(QObject *parent) : QObject(parent)
{

}

lcdcontrolor::lcdcontrolor(QObject *parent, QLCDNumber* &_lcd, QTimer *&_timer) : QObject(parent), lcd(_lcd),timer(_timer)
{

}

lcdcontrolor::dataArrive(int data)
{
    if(timer->isActive() && pre_data < 400 && data > 400)
    {
        count += 1;
        lcd->display(count);
    }
    pre_data = data;
    return 0;
}

void lcdcontrolor::reset()
{
    count = 0;
}

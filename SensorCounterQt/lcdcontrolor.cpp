#include "lcdcontrolor.hpp"
#include <QDebug>

lcdcontrolor::lcdcontrolor(QObject *parent) : QObject(parent)
{

}

lcdcontrolor::lcdcontrolor(QObject *parent, QLCDNumber* &_lcd, QTimer *&_timer) : QObject(parent), lcd(_lcd),timer(_timer)
{

}

lcdcontrolor::dataArrive(int n)
{
    if(timer->isActive())
    {
        lcd->display(n);
    }
    return 0;
}

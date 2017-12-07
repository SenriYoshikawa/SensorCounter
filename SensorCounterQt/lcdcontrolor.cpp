#include "lcdcontrolor.hpp"
#include <QDebug>

lcdcontrolor::lcdcontrolor(QObject *parent) : QObject(parent)
{

}

lcdcontrolor::lcdcontrolor(QObject *parent, QLCDNumber* &_lcd) : QObject(parent), lcd(_lcd)
{

}

lcdcontrolor::dataArrive(int n)
{
    lcd->display(n);
    return 0;
}

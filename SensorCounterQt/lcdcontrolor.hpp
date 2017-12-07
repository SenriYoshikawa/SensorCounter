#ifndef LCDCONTROLOR_H
#define LCDCONTROLOR_H

#include <QObject>
#include <QLCDNumber>
#include <QTimer>

class lcdcontrolor : public QObject
{
    Q_OBJECT
public:
    explicit lcdcontrolor(QObject *parent = 0);
    lcdcontrolor(QObject *parent, QLCDNumber* &_lcd, QTimer *&_timer);

private:
    QLCDNumber *lcd;
    QTimer *timer;
    int count = 0;
    int pre_data = 0;

signals:

public slots:
    dataArrive(int data);
};

#endif // LCDCONTROLOR_H

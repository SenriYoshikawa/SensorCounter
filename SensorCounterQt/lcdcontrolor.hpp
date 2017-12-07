#ifndef LCDCONTROLOR_H
#define LCDCONTROLOR_H

#include <QObject>
#include <QLCDNumber>

class lcdcontrolor : public QObject
{
    Q_OBJECT
public:
    explicit lcdcontrolor(QObject *parent = 0);
    lcdcontrolor(QObject *parent, QLCDNumber *&_lcd);

private:
    QLCDNumber *lcd;
signals:

public slots:
    dataArrive(int n);
};

#endif // LCDCONTROLOR_H

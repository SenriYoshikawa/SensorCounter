#ifndef SERIALCOMMUNICATOR_HPP
#define SERIALCOMMUNICATOR_HPP

#include <QObject>
#include <QSerialPortInfo>
#include <QSerialPort>

class serialcommunicator : public QObject
{
    Q_OBJECT
public:
    explicit serialcommunicator(QObject *parent = 0);

    serialcommunicator();
    ~serialcommunicator();

private:
    QSerialPort serial_port;

signals:
    void dataArrived(int);

public slots:
    void ready_read_line();

};

#endif // SERIALCOMMUNICATOR_HPP

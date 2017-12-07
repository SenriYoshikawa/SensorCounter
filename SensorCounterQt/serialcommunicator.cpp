#include "serialcommunicator.hpp"
#include <QDebug>

serialcommunicator::serialcommunicator(QObject *parent) : QObject(parent)
{
    QSerialPortInfo info = QSerialPortInfo::availablePorts().at(0);
    serial_port.setPortName(info.portName());
    serial_port.setBaudRate(QSerialPort::Baud38400);
    serial_port.setDataBits(QSerialPort::Data8);
    serial_port.setParity(QSerialPort::NoParity);
    serial_port.setStopBits(QSerialPort::OneStop);
    serial_port.setFlowControl(QSerialPort::NoFlowControl);
    serial_port.open(QIODevice::ReadWrite);

    connect(&serial_port, &QSerialPort::readyRead, this, &serialcommunicator::ready_read_line);

    qDebug() << serial_port.portName();

}

serialcommunicator::~serialcommunicator()
{
    qDebug() << "serial communicator destractor called";
    serial_port.close();
}

void serialcommunicator::ready_read_line()
{
    QString raw_str = serial_port.readLine(64);
    emit dataArrived(raw_str.toInt());
    //qDebug() << "reciev raw data = " << raw_str;
}

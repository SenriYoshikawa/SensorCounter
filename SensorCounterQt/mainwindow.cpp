#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "timerControlor.hpp"
#include "serialcommunicator.hpp"
#include "lcdcontrolor.hpp"
#include "chartcontrolor.hpp"

#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serialcommunicator *serial = new serialcommunicator(this);
    lcdcontrolor *lcd = new lcdcontrolor(this, ui->lcdNumber, ui->timerWidget->timer);

    connect(serial, &serialcommunicator::dataArrived, lcd, lcdcontrolor::dataArrive);
    connect(serial, &serialcommunicator::dataArrived, ui->timerWidget, timerControlor::dataArrive);
    connect(ui->timerWidget, timerControlor::dataPlotSgl, ui->chartWidget, chartcontrolor::dataPlotSlt);

    connect(ui->startButton, &QPushButton::clicked, [=](){
        ui->timerWidget->start();
        qDebug() << "start pushed";
    });

    connect(ui->resetButton, &QPushButton::clicked, [=](){
        ui->timerWidget->reset();
        qDebug() << "reset pushed";
    });

   // chart->update();


}

MainWindow::~MainWindow()
{
    delete ui;
}

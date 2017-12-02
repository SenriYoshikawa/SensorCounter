#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "timer.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Timer timer(parent);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

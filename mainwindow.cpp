#include "mainwindow.h"
#include "currencyConverter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent},
    currencyConverter(new CurrencyConverter)
{
    setCentralWidget(currencyConverter);
}

MainWindow::~MainWindow()
{
    delete currencyConverter;
}

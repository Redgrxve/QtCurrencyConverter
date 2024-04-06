#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class CurrencyConverter;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    CurrencyConverter* currencyConverter;
};

#endif // MAINWINDOW_H

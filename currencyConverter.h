#ifndef CURRENCYCONVERTER_H
#define CURRENCYCONVERTER_H

#include <QWidget>

class QLineEdit;
class QPushButton;
class QComboBox;

class CurrencyConverter : public QWidget
{
    Q_OBJECT

public:
    explicit CurrencyConverter(QWidget *parent = nullptr);
    ~CurrencyConverter();

private:
    QLineEdit* lineToConvert1;
    QLineEdit* convertedLine;
    QComboBox* currenciesComboBox1;
    QComboBox* currenciesComboBox2;
    QPushButton* convertButton;

    QMap<QString, double> currencies;

private:
    void connectSlots();
    void initCurrenciesComboBoxes();
    void setupLayout();

private slots:
    void convert();
};
#endif // CURRENCYCONVERTER_H

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
    QLineEdit* lineToConvert;
    QLineEdit* convertedLine;
    QComboBox* currenciesComboBox1;
    QComboBox* currenciesComboBox2;
    QPushButton* convertButton;
    QPushButton* closeButton;

    QVector<QString> currencies = {
       "RUB",
       "USD",
       "TL"
    };
};
#endif // CURRENCYCONVERTER_H

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
    QComboBox* currencyToConvert;
    QComboBox* convertedCurrency;
    QPushButton* convertButton;
    QPushButton* closeButton;
};
#endif // CURRENCYCONVERTER_H

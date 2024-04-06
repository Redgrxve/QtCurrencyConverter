#include "currencyConverter.h"
#include <QtWidgets>

CurrencyConverter::CurrencyConverter(QWidget *parent)
    : QWidget(parent),
    lineToConvert(new QLineEdit),
    convertedLine(new QLineEdit),
    currencyToConvert(new QComboBox),
    convertedCurrency(new QComboBox),
    convertButton(new QPushButton("Convert")),
    closeButton(new QPushButton("Close"))
{
    QHBoxLayout* layoutToConvert = new QHBoxLayout;
    layoutToConvert->addWidget(lineToConvert);
    layoutToConvert->addWidget(currencyToConvert);

    QHBoxLayout* convertedLayout = new QHBoxLayout;
    convertedLayout->addWidget(convertedLine);
    convertedLayout->addWidget(convertedCurrency);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutToConvert);
    mainLayout->addLayout(convertedLayout);
    mainLayout->addWidget(convertButton);
    mainLayout->addWidget(closeButton);

    setLayout(mainLayout);
    setWindowTitle(tr("Currency converter"));
    setFixedHeight(sizeHint().height());
}

CurrencyConverter::~CurrencyConverter()
{
    delete lineToConvert;
    delete convertedLine;
    delete currencyToConvert;
    delete convertedCurrency;
    delete convertButton;
    delete closeButton;
}

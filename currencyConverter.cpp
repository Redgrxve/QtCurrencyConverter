#include "currencyConverter.h"
#include <QtWidgets>

CurrencyConverter::CurrencyConverter(QWidget *parent)
    : QWidget(parent),
    lineToConvert(new QLineEdit),
    convertedLine(new QLineEdit),
    currenciesComboBox1(new QComboBox),
    currenciesComboBox2(new QComboBox),
    convertButton(new QPushButton("Convert")),
    closeButton(new QPushButton("Close"))
{
    convertedLine->setReadOnly(true);

    for (size_t i = 0; i < currencies.size(); ++i) {
        currenciesComboBox1->addItem(currencies[i]);
        currenciesComboBox2->addItem(currencies[i]);
    }

    QHBoxLayout* layoutToConvert = new QHBoxLayout;
    layoutToConvert->addWidget(lineToConvert);
    layoutToConvert->addWidget(currenciesComboBox1);

    QHBoxLayout* convertedLayout = new QHBoxLayout;
    convertedLayout->addWidget(convertedLine);
    convertedLayout->addWidget(currenciesComboBox2);

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
    delete currenciesComboBox1;
    delete currenciesComboBox2;
    delete convertButton;
    delete closeButton;
}

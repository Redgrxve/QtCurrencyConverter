#include "currencyConverter.h"
#include <QtWidgets>

CurrencyConverter::CurrencyConverter(QWidget *parent)
    : QWidget(parent),
    lineToConvert1(new QLineEdit),
    convertedLine(new QLineEdit),
    currenciesComboBox1(new QComboBox),
    currenciesComboBox2(new QComboBox),
    convertButton(new QPushButton("Convert"))
{
    lineToConvert1->setValidator(new QDoubleValidator(0.0, 25.0, 2));
    convertedLine->setReadOnly(true);

    initCurrenciesComboBoxes();
    connectSlots();
    setupLayout();
}

CurrencyConverter::~CurrencyConverter()
{
}

void CurrencyConverter::connectSlots()
{
    connect(convertButton, SIGNAL(clicked(bool)), this, SLOT(convert()));
}

void CurrencyConverter::initCurrenciesComboBoxes()
{
    currencies.insert("RUB", 93.72);
    currencies.insert("USD", 1.0);
    currencies.insert("TL", 0.031005);

    for (auto it = currencies.begin(); it != currencies.end(); ++it) {
        currenciesComboBox1->addItem(it.key());
        currenciesComboBox2->addItem(it.key());
    }
    currenciesComboBox1->setCurrentIndex(0);
    currenciesComboBox2->setCurrentIndex(1);
}

void CurrencyConverter::setupLayout()
{
    QHBoxLayout* layoutToConvert = new QHBoxLayout;
    layoutToConvert->addWidget(lineToConvert1);
    layoutToConvert->addWidget(currenciesComboBox1);

    QHBoxLayout* convertedLayout = new QHBoxLayout;
    convertedLayout->addWidget(convertedLine);
    convertedLayout->addWidget(currenciesComboBox2);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutToConvert);
    mainLayout->addLayout(convertedLayout);
    mainLayout->addWidget(convertButton);

    setLayout(mainLayout);
    setWindowTitle(tr("Currency converter"));
    setFixedHeight(sizeHint().height());
}

void CurrencyConverter::convert()
{
    if (lineToConvert1->text().isEmpty()) return;

    double value = lineToConvert1->text().toDouble();
    double inDollars = value * currencies[currenciesComboBox1->currentText()];
    double result = inDollars * currencies[currenciesComboBox2->currentText()];
    convertedLine->setText(QString::number(result));
}

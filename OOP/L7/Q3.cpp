#include <iostream>
#include <string>

using namespace std;

class Currency
{
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRateToBase;

public:
    Currency(double amt, string code, string symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRateToBase(rate) {}

    virtual double convertToBase()
    {
        return amount * exchangeRateToBase;
    }

    virtual double convertTo(Currency *targetCurrency)
    {
        double amountInBaseCurrency = convertToBase();
        return amountInBaseCurrency / targetCurrency->convertToBase() * 100;
    }

    virtual void displayCurrency()
    {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency
{
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() override
    {
        cout << "$" << amount << " (USD)" << endl;
    }
};

class Euro : public Currency
{
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.0 / 0.85) {} // 1 EUR = 1 / 0.85 USD

    void displayCurrency() override
    {
        cout << "€" << amount << " (EUR)" << endl;
    }
};

class Rupee : public Currency
{
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs. ", 1.0 / 280.0) {} // 1 PKR = 1 / 280 USD

    void displayCurrency() override
    {
        cout << "Rs. " << amount << " (PKR)" << endl;
    }
};

int main()
{
    Dollar d(100);
    Euro e(100);
    Rupee r(100);

    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    double euroToDollar = e.convertTo(&d);
    cout << "100 EUR = " << euroToDollar << " USD" << endl;

    double rupeeToDollar = r.convertTo(&d);
    cout << "100 PKR = " << rupeeToDollar << " USD" << endl;

    return 0;
}

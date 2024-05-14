#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H
#include <QObject>
#include <QThread>

class InvestmentCalculator : public QObject
{
    Q_OBJECT

public:
    InvestmentCalculator();
    void setinitialAmount(double);
    void setInterest(double);
    void setYears(int);
    int getYears();
    double getSum();

    ~InvestmentCalculator();

public slots:
    void process();

signals:
    void finished(double);
    void numberChange(double);
private:
    double initialAmount;
    double interest;
    int years;
    double sum;

};

#endif // INVESTMENTCALCULATOR_H

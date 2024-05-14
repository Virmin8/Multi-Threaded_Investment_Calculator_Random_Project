#include "investmentcalculator.h"
#include <QThread>
#include <QDebug>

InvestmentCalculator::InvestmentCalculator()
{
    initialAmount = 0.0;
    interest = 0.0;
    years = 0;
    sum = 0.0;

}
void InvestmentCalculator::setinitialAmount(double i)
{
    initialAmount = i;
}
void InvestmentCalculator::setInterest(double t)
{
    interest = t;
}
void InvestmentCalculator::setYears(int y)
{
    years = y;

}
void InvestmentCalculator::process()
{
       for(int k = 0; k < years; k++)
       {
            initialAmount = initialAmount + (interest/100 * initialAmount);
            emit numberChange(initialAmount);
            QThread::msleep(300);

       }
        sum = initialAmount;
       emit finished(sum);
}

double InvestmentCalculator::getSum()
{
    return sum;
}
InvestmentCalculator::~InvestmentCalculator()
{

}
int InvestmentCalculator::getYears()
{
    return years;
}


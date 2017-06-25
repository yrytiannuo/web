#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    int id;
    double balance;
    double rate;
    int years;
    double accumulation;
    static double total;
    double accumulate(int year);
    double record(double change);
public:
    SavingsAccount(int id,double rate);
    void show() const;
    void deposit();
    void withdraw();
    void settle();

    const double getBalance();
    const int getId();
    const double getRate();
    static double getTotal();
};


#endif // ACCOUNT_H_INCLUDED

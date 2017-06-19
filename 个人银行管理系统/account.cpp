#include "account.h"
#include<cmath>
#include <iostream>
using namespace std;
double SavingsAccount::total=0;

double SavingsAccount::accumulate(int year){
    accumulation+=year*total*rate;
    return accumulation;
}
double SavingsAccount::record(double change){
    total+=change;
    cout<<"当前账户余额："<<total<<endl;
    return total;
}

SavingsAccount::SavingsAccount(int id,double rate){
    this->id=id;
    this->rate=rate;
    balance=0;
    accumulation=0;
    years=0;
}
void SavingsAccount::show() const{
    cout<<"----------------------------------"<<endl;
    cout<<"账号ID："<<id<<endl;
    cout<<"年利率："<<rate<<endl;
    cout<<"账户余额："<<balance<<endl;
    cout<<"----------------------------------";
}
void SavingsAccount::deposit(){
    double change;
    int year;
    cout<<"请输入存款金额：";
    cin>>change;
    cout<<endl<<"请输入你要存款的年数:"<<endl;
    cin>>year;
    years=year;
    record(change);
}
void SavingsAccount::withdraw(){
    double change;
    cout<<"请输入取款金额：";
 shuru:  cin>>change;
    if(change<=total)
    {
        record(-change);
    }
    else
    {
        cout<<"很抱歉，你输入的金额出错"<<endl;
        cout<<"请重新输入："<<endl;
        goto shuru;
    }

}
void SavingsAccount::settle(){

    double balance;
    balance=accumulate(years);
    cout<<"你在"<<years<<"年里面共得利息:"<<balance<<endl;
    accumulation=0;
    balance=0;
}

const double SavingsAccount::getBalance(){
    return balance;
}
const int SavingsAccount::getId(){
    return id;
}
const double SavingsAccount::getRate(){
    return rate;
}
double SavingsAccount::getTotal(){
    cout<<"当前的总金额为："<<total<<endl;
    return total;
}

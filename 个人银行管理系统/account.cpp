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
    cout<<"��ǰ�˻���"<<total<<endl;
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
    cout<<"�˺�ID��"<<id<<endl;
    cout<<"�����ʣ�"<<rate<<endl;
    cout<<"�˻���"<<balance<<endl;
    cout<<"----------------------------------";
}
void SavingsAccount::deposit(){
    double change;
    int year;
    cout<<"���������";
    cin>>change;
    cout<<endl<<"��������Ҫ��������:"<<endl;
    cin>>year;
    years=year;
    record(change);
}
void SavingsAccount::withdraw(){
    double change;
    cout<<"������ȡ���";
 shuru:  cin>>change;
    if(change<=total)
    {
        record(-change);
    }
    else
    {
        cout<<"�ܱ�Ǹ��������Ľ�����"<<endl;
        cout<<"���������룺"<<endl;
        goto shuru;
    }

}
void SavingsAccount::settle(){

    double balance;
    balance=accumulate(years);
    cout<<"����"<<years<<"�����湲����Ϣ:"<<balance<<endl;
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
    cout<<"��ǰ���ܽ��Ϊ��"<<total<<endl;
    return total;
}

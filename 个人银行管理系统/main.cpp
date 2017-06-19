#include"account.h"
#include <cstdlib>
#include <iostream>
using namespace std;
//created by 缑通旺
//软件1604 1607020412
//2017.6.3
int main()
{
   int operation;
    cout<<"请输入你的相关信息！"<<endl;
    int number;
    double rate;
change_id:
    cout<<"请输入你的ID号：";
    cin>>number;
    cout<<"请输入你的年利率：";
    cin>>rate;
    SavingsAccount account(number,rate);

meau:
    cout<<endl<<"欢迎光临银行，请选择你所需的服务！"<<endl;
    cout<<"1.查询"<<endl;
    cout<<"2.存款"<<endl;
    cout<<"3.取款"<<endl;
    cout<<"4.结算"<<endl;
    cout<<"5.银行总金额"<<endl;
    cout<<"6.切换账号"<<endl;
    cout<<"7.退出"<<endl;
    cout<<"我要选择：";
    cin>>operation;
    switch (operation) {
        case 1:
            account.show();
            break;
        case 2:
            account.deposit();
            break;
        case 3:
            account.withdraw();
            break;
        case 4:
            account.settle();
        case 5:
            account.getTotal();
            break;
        case 6:
            goto change_id;
            break;
        case 7:
            cout<<endl<<"请问您是否离开银行？(Y/Any Key)"<<endl;
            char anwser;
            cin>>anwser;
            if (anwser=='Y'||anwser=='y')
            {
                cout<<"退出成功！"<<endl;
                exit(1);
            }
            break;
        default:
            break;
    }
    goto meau;
    return 0;
}

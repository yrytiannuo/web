#include"account.h"
#include <cstdlib>
#include <iostream>
using namespace std;
//created by ��ͨ��
//���1604 1607020412
//2017.6.3
int main()
{
   int operation;
    cout<<"��������������Ϣ��"<<endl;
    int number;
    double rate;
change_id:
    cout<<"���������ID�ţ�";
    cin>>number;
    cout<<"��������������ʣ�";
    cin>>rate;
    SavingsAccount account(number,rate);

meau:
    cout<<endl<<"��ӭ�������У���ѡ��������ķ���"<<endl;
    cout<<"1.��ѯ"<<endl;
    cout<<"2.���"<<endl;
    cout<<"3.ȡ��"<<endl;
    cout<<"4.����"<<endl;
    cout<<"5.�����ܽ��"<<endl;
    cout<<"6.�л��˺�"<<endl;
    cout<<"7.�˳�"<<endl;
    cout<<"��Ҫѡ��";
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
            cout<<endl<<"�������Ƿ��뿪���У�(Y/Any Key)"<<endl;
            char anwser;
            cin>>anwser;
            if (anwser=='Y'||anwser=='y')
            {
                cout<<"�˳��ɹ���"<<endl;
                exit(1);
            }
            break;
        default:
            break;
    }
    goto meau;
    return 0;
}

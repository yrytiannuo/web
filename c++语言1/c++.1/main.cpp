#include "account.cpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    cout<<"-------------------------------"<<endl;
    cout<<"��ӭ����ͼ��ݣ�"<<endl;
    cout<<"-------------------------------"<<endl;
meau:
    cout<<"1.���߹���"<<endl;
    cout<<"2.�������"<<endl;
    cout<<"3.�������"<<endl;
    cout<<"4.ͼ�����"<<endl;
    cout<<"5.�ļ�����"<<endl;
    cout<<"6.�˳�"<<endl;
    cout<<"��Ҫѡ��"<<endl;
    int op;
    cin>>op;
    switch(op)
    {
         case 1:
                cout<<"------���߹���ϵͳ��------"<<endl;
                cout<<"��������������Ϣ��"<<endl;
                int num1;
                char name1[20];
                cout<<"����������û���ţ�";
                cin>>num1;
                cout<<"����������û�������";
                cin>>name1;
                CUser user(num1,name1);
         meau1:
                cout<<"1.�����û����"<<endl;
                cout<<"2.�����û�����"<<endl;
                cout<<"3.�û��Ļ�����Ϣ"<<endl;
                cout<<"4.�˳�"<<endl;
                cout<<"��Ҫѡ��"<<endl;
                int op1;
                cin>>op1;
                switch(op1)
                {
                case 1:
                    void setcode(int n);
                    break;
                case 2:
                     void setname(char na[]);
                     break;
                case 3:
                    void show();
                    break;
                case 4:
                    cout<<endl<<"�������Ƿ��뿪��(Y/Any Key)"<<endl;
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
                goto meau1;
            break;
        case 2:
            {
                cout<<"------�������ϵͳ��------"<<endl;
                cout<<"��������������Ϣ��"<<endl;
                int num2;
                char name2[20];
                cout<<"����������û���ţ�";
                cin>>num2;
                cout<<"����������û�������";
                cin>>name2;
                CReader(num2,name2);
        meau2:
                cout<<"1.���߽������"<<endl;
                cout<<"2.���߽�����Ϣ"<<endl;
                cout<<"3.���ߵĻ�����Ϣ����ͽ������"<<endl;
                cout<<"4.�˳�"<<endl;
                cout<<"��Ҫѡ��"<<endl;
                int op2;
                cin>>op2;
                switch(op2)
                {
                case 1:
                    void set_Borrowing(bool);
                    break;
                case 2:
                     CBook getbrbook();
                     break;
                case 3:
                    void show();
                    break;
                case 4:
                    cout<<endl<<"�������Ƿ��뿪��(Y/Any Key)"<<endl;
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
                goto meau2;
            break;
            }
        case 3:
            cout<<"------�������ϵͳ��------"<<endl;
                cout<<"��������������Ϣ��"<<endl;
                int num3;
                char name3[20];
                cout<<"����������û���ţ�";
                cin>>num3;
                cout<<"����������û�������";
                cin>>name3;
                CBook(num3,name3);
        meau3:
                cout<<"1.ͼ����"<<endl;
                cout<<"2.ͼ������"<<endl;
                cout<<"3.ͼ���Ƿ��ڿ���Ϣ"<<endl;
                cout<<"4.�˳�"<<endl;
                cout<<"��Ҫѡ��"<<endl;
                int op3;
                cin>>op3;
                switch(op3)
                {
                case 1:
                    void setcode(int n);
                    break;
                case 2:
                     void setname(char na[]);
                     break;
                case 3:
                    void set_Stock(bool);
                    break;
                case 4:
                    cout<<endl<<"�������Ƿ��뿪��(Y/Any Key)"<<endl;
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
                goto meau3;
            break;
        case 4:
            cout<<"------ͼ�����ϵͳ��------"<<endl;
                cout<<"��������������Ϣ��"<<endl;
        meau4:
                cout<<"1.���ͼ��"<<endl;
                cout<<"2.����ͼ��"<<endl;
                cout<<"3.�༭ͼ��"<<endl;
                cout<<"4.ɾ��ͼ��"<<endl;
                cout<<"5.�˳�"<<endl;
                cout<<"��Ҫѡ��"<<endl;
                int op4;
                cin>>op4;
                switch(op4)
                {
                case 1:
                     void addbooks() ;
                    break;
                case 2:
                     int findbooks(int suffix);
                     break;
                case 3:
                    void editbooks();   // ����ͼ���Ƿ��ڿ���Ϣ
                    break;
                case 4:
                    void delbooks();
                    break;
                case 5:
                    cout<<endl<<"�������Ƿ��뿪��(Y/Any Key)"<<endl;
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
                goto meau4;
        case 5:
            cout<<"------�ļ�����ϵͳ��------"<<endl;
                cout<<"��������������Ϣ��"<<endl;

        meau5:
                cout<<"1.��Ӷ���"<<endl;
                cout<<"2.���Ҷ���"<<endl;
                cout<<"3.�༭������Ϣ"<<endl;
                cout<<"4.ɾ������"<<endl;
                cout<<"5.��ʾ���ж���"<<endl;
                cout<<"6.�˳�"<<endl;
                cout<<"��Ҫѡ��"<<endl;
                int op5;
                cin>>op5;
                switch(op5)
                {
                case 1:
                     void addreaders();
                    break;
                case 2:
                      int findreaders(int suffix);
                     break;
                case 3:
                    void editreaders();
                    break;
                case 4:
                    void delreaders();
                    break;
                case 5:
                     void listreaders();
                     break;
                case 6:
                    cout<<endl<<"�������Ƿ��뿪��(Y/Any Key)"<<endl;
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
                goto meau5;
            break;
        case 6:
            cout<<endl<<"�������Ƿ��뿪��(Y/Any Key)"<<endl;
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

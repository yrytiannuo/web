#include "account.cpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    cout<<"-------------------------------"<<endl;
    cout<<"欢迎来到图书馆！"<<endl;
    cout<<"-------------------------------"<<endl;
meau:
    cout<<"1.读者管理"<<endl;
    cout<<"2.借书管理"<<endl;
    cout<<"3.还书管理"<<endl;
    cout<<"4.图书管理"<<endl;
    cout<<"5.文件储存"<<endl;
    cout<<"6.退出"<<endl;
    cout<<"我要选择："<<endl;
    int op;
    cin>>op;
    switch(op)
    {
         case 1:
                cout<<"------读者管理系统！------"<<endl;
                cout<<"请输入你的相关信息！"<<endl;
                int num1;
                char name1[20];
                cout<<"请输入你的用户编号：";
                cin>>num1;
                cout<<"请输入你的用户姓名：";
                cin>>name1;
                CUser user(num1,name1);
         meau1:
                cout<<"1.设置用户编号"<<endl;
                cout<<"2.设置用户姓名"<<endl;
                cout<<"3.用户的基本信息"<<endl;
                cout<<"4.退出"<<endl;
                cout<<"我要选择："<<endl;
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
                    cout<<endl<<"请问您是否离开？(Y/Any Key)"<<endl;
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
                goto meau1;
            break;
        case 2:
            {
                cout<<"------借书管理系统！------"<<endl;
                cout<<"请输入你的相关信息！"<<endl;
                int num2;
                char name2[20];
                cout<<"请输入你的用户编号：";
                cin>>num2;
                cout<<"请输入你的用户姓名：";
                cin>>name2;
                CReader(num2,name2);
        meau2:
                cout<<"1.读者借阅情况"<<endl;
                cout<<"2.读者结束信息"<<endl;
                cout<<"3.读者的基本信息情况和借书情况"<<endl;
                cout<<"4.退出"<<endl;
                cout<<"我要选择："<<endl;
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
                    cout<<endl<<"请问您是否离开？(Y/Any Key)"<<endl;
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
                goto meau2;
            break;
            }
        case 3:
            cout<<"------还书管理系统！------"<<endl;
                cout<<"请输入你的相关信息！"<<endl;
                int num3;
                char name3[20];
                cout<<"请输入你的用户编号：";
                cin>>num3;
                cout<<"请输入你的用户姓名：";
                cin>>name3;
                CBook(num3,name3);
        meau3:
                cout<<"1.图书编号"<<endl;
                cout<<"2.图书名称"<<endl;
                cout<<"3.图书是否在库信息"<<endl;
                cout<<"4.退出"<<endl;
                cout<<"我要选择："<<endl;
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
                    cout<<endl<<"请问您是否离开？(Y/Any Key)"<<endl;
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
                goto meau3;
            break;
        case 4:
            cout<<"------图书管理系统！------"<<endl;
                cout<<"请输入你的相关信息！"<<endl;
        meau4:
                cout<<"1.添加图书"<<endl;
                cout<<"2.查找图书"<<endl;
                cout<<"3.编辑图书"<<endl;
                cout<<"4.删除图书"<<endl;
                cout<<"5.退出"<<endl;
                cout<<"我要选择："<<endl;
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
                    void editbooks();   // 设置图书是否在库信息
                    break;
                case 4:
                    void delbooks();
                    break;
                case 5:
                    cout<<endl<<"请问您是否离开？(Y/Any Key)"<<endl;
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
                goto meau4;
        case 5:
            cout<<"------文件管理系统！------"<<endl;
                cout<<"请输入你的相关信息！"<<endl;

        meau5:
                cout<<"1.添加读者"<<endl;
                cout<<"2.查找读者"<<endl;
                cout<<"3.编辑读者信息"<<endl;
                cout<<"4.删除读者"<<endl;
                cout<<"5.显示所有读者"<<endl;
                cout<<"6.退出"<<endl;
                cout<<"我要选择："<<endl;
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
                    cout<<endl<<"请问您是否离开？(Y/Any Key)"<<endl;
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
                goto meau5;
            break;
        case 6:
            cout<<endl<<"请问您是否离开？(Y/Any Key)"<<endl;
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

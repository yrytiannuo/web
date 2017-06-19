#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include <iostream>
using namespace std;

class CUser
{
public:
        int code;      //表示用户编号；
        char name[20];  //表示用户姓名
        CUser();   // 默认构造函数
        CUser(int id, char na[]);   //构造函数，初始化用户信息
        void setcode(int n);      //用来设置用户编号
        int getcode();          //用来获取用户编号
        void setname(char na[]);  //用来设置用户姓名
        char* getname();        //用来获取用户姓名
        void show();           //用来显示用户的基本信息
};

class CBook
{
public:
          int code;              //图书编号
          char name[20];      //图书名称
          bool Is_Stock;          //true为在架，false为借出
          bool Is_Existing;       //true为存在, false为删除
          CBook(); //默认构造函数
          CBook(int no,char na[]);    //构造函数，初始化图书信息
          void setcode(int n);   //设置图书编号
          int getcode();    //获取图书编号
          void setname(char na[]);    //设置图书名称
          char* getname();  //获取图书名称
          bool  get_Stock();  //获取图书是否在库信息
          void set_Stock(bool);// 设置图书是否在库信息
          bool  get_Existing();//获取存在标志
          void set_Existing(bool);//设置存在标志
};
class CReader
{
public:
          bool Is_Existing;  //true存在，false删除
          bool Is_Borrowing;  //true借过书，false没有借书
          CBook brbook;     //表示读者所借的图书
          CReader();               //默认的构造函数
          CReader(int id, char na[]);   //构造函数，初始化读者信息
          bool get_Existing();        //用来获取删除标志
          void set_Existing(bool);     //用来设置删除标志
          bool get_Borrowing();      //用来获取读者借阅情况
          void set_Borrowing(bool);   //用来设置读者借阅情况
          void setbrbook(CBook bt);  //用来记录读者结束信息
          CBook getbrbook();     //用来获取读者结束信息
          void show();                 //重写基类成员，显示读者的基本信息情况和借书情况
};



class CReaderManager
{
public:
          CReader rdarray[50];// 存储读者信息的集合
          int top;      //当前数组中存储的读者数量
          CReaderManager();  // 构造函数
           ~CReaderManager();   //析构函数
           void addreaders();          //添加读者
           int findreaders(int suffix);     //查找读者，这个函数用于借书还书操作。
           int findreaders();            //查找读者，这个函数用于读者维护操作
           void editreaders();          //编辑读者信息
           void delreaders();          //删除读者，读者如果借书要还书后才能删除
           void listreaders();           //显示所有读者

};

class CBookManager
{
         CBook btarray[50];                   //图书集合
         int top;                         //当前数组中存储的图书数量
          CBookManager();
         ~CBookManager();
         void addbooks() ;    //添加图书
         int findbooks(int suffix);  //查找图书，这个函数用于借书还书操作
         int findbooks() ;  //查找图书，用于图书维护操作
         void editbooks();     //编辑图书
         void delbooks();   //  删除图书
         void listbooks() ;  //显示全部图书
};
#endif // ACCOUNT_H_INCLUDED

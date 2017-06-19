#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include <iostream>
using namespace std;

class CUser
{
public:
        int code;      //��ʾ�û���ţ�
        char name[20];  //��ʾ�û�����
        CUser();   // Ĭ�Ϲ��캯��
        CUser(int id, char na[]);   //���캯������ʼ���û���Ϣ
        void setcode(int n);      //���������û����
        int getcode();          //������ȡ�û����
        void setname(char na[]);  //���������û�����
        char* getname();        //������ȡ�û�����
        void show();           //������ʾ�û��Ļ�����Ϣ
};

class CBook
{
public:
          int code;              //ͼ����
          char name[20];      //ͼ������
          bool Is_Stock;          //trueΪ�ڼܣ�falseΪ���
          bool Is_Existing;       //trueΪ����, falseΪɾ��
          CBook(); //Ĭ�Ϲ��캯��
          CBook(int no,char na[]);    //���캯������ʼ��ͼ����Ϣ
          void setcode(int n);   //����ͼ����
          int getcode();    //��ȡͼ����
          void setname(char na[]);    //����ͼ������
          char* getname();  //��ȡͼ������
          bool  get_Stock();  //��ȡͼ���Ƿ��ڿ���Ϣ
          void set_Stock(bool);// ����ͼ���Ƿ��ڿ���Ϣ
          bool  get_Existing();//��ȡ���ڱ�־
          void set_Existing(bool);//���ô��ڱ�־
};
class CReader
{
public:
          bool Is_Existing;  //true���ڣ�falseɾ��
          bool Is_Borrowing;  //true����飬falseû�н���
          CBook brbook;     //��ʾ���������ͼ��
          CReader();               //Ĭ�ϵĹ��캯��
          CReader(int id, char na[]);   //���캯������ʼ��������Ϣ
          bool get_Existing();        //������ȡɾ����־
          void set_Existing(bool);     //��������ɾ����־
          bool get_Borrowing();      //������ȡ���߽������
          void set_Borrowing(bool);   //�������ö��߽������
          void setbrbook(CBook bt);  //������¼���߽�����Ϣ
          CBook getbrbook();     //������ȡ���߽�����Ϣ
          void show();                 //��д�����Ա����ʾ���ߵĻ�����Ϣ����ͽ������
};



class CReaderManager
{
public:
          CReader rdarray[50];// �洢������Ϣ�ļ���
          int top;      //��ǰ�����д洢�Ķ�������
          CReaderManager();  // ���캯��
           ~CReaderManager();   //��������
           void addreaders();          //��Ӷ���
           int findreaders(int suffix);     //���Ҷ��ߣ�����������ڽ��黹�������
           int findreaders();            //���Ҷ��ߣ�����������ڶ���ά������
           void editreaders();          //�༭������Ϣ
           void delreaders();          //ɾ�����ߣ������������Ҫ��������ɾ��
           void listreaders();           //��ʾ���ж���

};

class CBookManager
{
         CBook btarray[50];                   //ͼ�鼯��
         int top;                         //��ǰ�����д洢��ͼ������
          CBookManager();
         ~CBookManager();
         void addbooks() ;    //���ͼ��
         int findbooks(int suffix);  //����ͼ�飬����������ڽ��黹�����
         int findbooks() ;  //����ͼ�飬����ͼ��ά������
         void editbooks();     //�༭ͼ��
         void delbooks();   //  ɾ��ͼ��
         void listbooks() ;  //��ʾȫ��ͼ��
};
#endif // ACCOUNT_H_INCLUDED

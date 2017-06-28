#include <iostream>
#include<stdlib.h>
#include "queue.h"
using namespace std;

int main()
{
    MyQueue *p =new MyQueue(4);

    p->EnQueue(10);
    p->EnQueue(12);
    p->EnQueue(23);
    p->EnQueue(11);

    p->QueueTraverse();

    delete p;
    p=NULL;
    return 0;
}

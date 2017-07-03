#include <iostream>

using namespace std;
#include <stdlib.h>
#include "account.h"
int main()
{
    MyStack *pstack=new MyStack(5);

    delete pstack;
    pstack=NULL;
    return 0;
}

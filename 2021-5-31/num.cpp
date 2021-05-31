#include <iostream>
using namespace std;
#include "math.h"

//题目原意-> 找出所有的因子并且打印出来

void Print(int n)
{
    int num=2;
    while(n>3&&num<=sqrt(n))//n>3保证最后一个数不是1
    {
        if(n%num==0)
        {
            n=n/num;
            printf("%d * ",num);
        }
        else
            num++;
    }
    
    printf("%d\n",n);
}
int main()
{
    int n;
    while(cin>>n)
    {
        printf("%d = ",n);// x = ' ' 
        Print(n);
    }
    
    return 0;
}
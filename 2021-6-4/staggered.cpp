#include <iostream>
using namespace std;

double GetSum(int n)//获得所有的排列数
{
    if(n<3)
        return n;
    return n*GetSum(n-1);
}

double GetNum(int n)//获得排错的总数
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    return (n-1)*(GetNum(n-2)+GetNum(n-1));
}

int main()
{
    double n;
    while(cin>>n)
    {
       double num=GetNum(n)/GetSum(n)*100;
        printf("%.2f%\n",num);
    }
    
    
    return 0;
}
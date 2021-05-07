#include <iostream>
using namespace std;
#include<math.h>

bool Judge(int  val)//判断是否是素数
{
    int n=sqrt(val);
    for(int i=2;i<=n;i++)
    {
        if(val%i==0)
           return false;
    }
    return true;
}

int main()
{
    int n;
    while(cin>>n)
    {
        int val1=n/2;
        int val2=val1;
        
        while(!Judge(val1)||!Judge(val2)||val1+val2!=n)
        {
            val1--;
            val2++;
        }
        


        cout<<val1<<endl<<val2<<endl;       
    }
}
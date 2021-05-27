#include <iostream>
using namespace std;
#include <math.h>
//设原来的桃为x个，并且再借其4个，那么每次都能均分
//第一只猴，拿完剩下的是 (x+4)* (4/5)
//第二只猴， (x+4)* (4/5)^2
//第n只猴拿完剩下的是  (x+4)* （4/5）^N

//又最后剩下的是整数 -> x+4=5^n -> x=5^n-4
//剩下的都是老猴子的，老猴子得到的 = 4^N + N(每个猴子给一个) -4(借的)



int main()
{
    int n ;
    
    while(cin>>n)
    {
        if(n==0)
            break;
        cout<<(long long )(pow(5,n)-4)<<" ";
        cout<<(long long )(pow(4,n)+n-4)<<endl;
    }

    return 0;
}
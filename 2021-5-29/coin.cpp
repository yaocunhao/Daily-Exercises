/从一堆硬币中找出一个假币，假的比真的轻
// 1枚硬币 0次
//2枚硬币 1次
//3枚 1次
//4枚 2次
//5枚 2次
//6枚 2次
//7枚 2次
//8枚 3次
//9枚 3次
//10 3次   3 + 3 +4
// =》  count=n/2 +1 



#include <iostream>
using namespace std;



int main()
{
 int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        
        int count=0;
        
        if(n==1)
            cout<<0<<endl;
        else
        {
            while(n>1)//分成三堆
            {
                n=n/3+(n%3>0);
                count++;
            }
            cout<<count<<endl;
        }
    }
            return 0;
}
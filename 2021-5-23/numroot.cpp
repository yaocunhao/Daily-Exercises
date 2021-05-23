#include <iostream>
using namespace std;
#include <vector>
#include <string>
int main()
{
    string str;
    while(cin>>str)
    {
        long long num=0;
        long long count=0;
        for(auto &e:str)
        {
            num+=e-'0';
        }
        while(num/10!=0||count!=0)
        {
            count+=num%10;
            num/=10;
            if(num==0)
            {
                num=count;
                count=0;
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
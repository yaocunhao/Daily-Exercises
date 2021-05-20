//能力值a -> 依次遇见n个怪物 -> 怪物防御力 b1 b2 b3 ...bn 
//bi<=a a=a+bi   bi>a a=a+(a.bi)最后大约数

using namespace std;
#include <iostream>
#include <vector>
#include <string>


int GetNum(int x,int y)
{
    while(x%y)
    {
        int temp=x%y;
        x=y;
        y=temp;
    }
    return y;
}
int main()
{
    int n;
    int a;
    while(cin>>n)
    {
        cin>>a;
        vector<int> arr(n,0);
        int sub=0;
        while(sub<n)
        {
            int count=0;
            cin>>count;
            arr[sub++]=count;
        }
        
        for(int i=0;i<arr.size();i++)
        {
            if(a>=arr[i])
                a+=arr[i];
            else
                a+=GetNum(a,arr[i]);
        }
        cout<<a<<endl;
    }
    return 0;
}
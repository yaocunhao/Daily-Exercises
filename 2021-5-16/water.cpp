// 3瓶子-> 1汽水
//最后两个瓶子还可以和老板借一瓶汽水

#include <iostream>
using namespace std;
#include <vector>

int Get(int num)
{
    int count=0;//统计喝了多少汽水
    while(num>2)
    {
        count+=num/3;//除以3得到可以喝多少汽水
        num=num%3+num/3;//剩余瓶子=换了多少汽水+剩下的瓶子
    }
    if(num==2)//还可以换一瓶
        count++;
    
    return count;
}
int main()
{
    vector<int> arr;
    int n=0;
    for(int i=0;i<11;i++)
    {
        cin>>n;
        arr.push_back(n);
        if(n==0)//以0结尾
            break;
    }
    
    for(auto &e:arr)//e表示当前有多少空瓶子
    {
        if(e!=0)
        cout<<Get(e)<<endl;
    }
    
    return 0;
}
//回溯法
#include <iostream>
using namespace std;
#include <vector>

//组合不是排列，要求按照字典序

void GetNum(vector<int>&arr,int n,int m,int sum,int sub)
{
    if(sum>m)//剪枝
        return;
    
    if(sum==m)
    {
        for(auto&e:arr)
            cout<<e<<" ";
        cout<<endl;
        return ;
    }
    for(int i=sub;i<=n;i++)//起点
    {
        sum+=i;
        arr.push_back(i);
        GetNum(arr, n, m, sum, i+1);
        arr.pop_back();
        sum-=i;
    }
}

int main()
{
    int n;// 1_n
    int m;//和等于m
    while(cin>>n)
    {
        cin>>m;
        vector<int> arr;
        GetNum(arr, n, m, 0, 1);
    }
    return 0;
}
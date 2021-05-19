洗牌
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
    int t;
    cin>>t;//数据组成
    int n;//牌数
    int k;//洗牌次数
    while(t--)
    {
        cin>>n;
        cin>>k;
        vector<int> arr;
        int count=2*n;
        while(count--)//添加元素
        {
            int num=0;
            cin>>num;
            arr.push_back(num);
        }
        
        vector<int>temp;
         
         while(k--)//洗牌k次
         {
             int n1=n-1;//前半部分的最后一张牌
             int n2=2*n-1;//后半部分的最后一张牌
             while(n2>=n||n1>=0)
             {
                if(n2>=n)//先放后半部分
                 {
                     temp.push_back(arr[n2]);
                     n2--;
                 }
                 if(n1>=0)
                 {
                     temp.push_back(arr[n1]);
                     n1--;
                 }
             }
             arr.swap(temp);
             reverse(arr.begin(),arr.end());//洗完牌后进行颠倒
             temp.clear();
         }
        
        for(int i=0;i<arr.size();i++)
        {
                cout<<arr[i];
            if(t!=0||i!=arr.size()-1)
                cout<<" ";
        }
        cout<<endl;
        
    }
}
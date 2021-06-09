//题意转换 -> 如果是子串，则将子串去除掉

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    int n;
    while(cin>>n)
    {
        vector<string> arr;
        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            arr.push_back(temp);
        }
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size()-1;i++)
        {
            auto pos=arr[i+1].find(arr[i]);
            if(pos==string::npos||pos+1==arr[i+1].size()||arr[i+1][arr[i].size()]!='/' )//找不到，输出
            {
                cout<<"mkdir -p "<<arr[i]<<endl;
            }
        }
        //最后一个肯定没有输出
        cout<<"mkdir -p "<<arr[arr.size()-1]<<endl;
        cout<<endl;
        
    }
}
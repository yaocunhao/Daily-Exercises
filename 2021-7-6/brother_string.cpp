//兄弟单词：所有的字符是相同的，排列不一样
//给定n个单词，再给一个str，寻找str的兄弟单词里面，按字典排序后的第K个单词是什么

//先找出所有的兄弟单词，然后进行排序，然后输出第K个


#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

bool Judge(string &str,string &str2)//判断是否是兄弟单词
{
    if(str.size()!=str2.size())
        return false;
    if(str==str2)
        return false;
    
    unordered_map<char, int>mp;
    for(auto&e:str)
    {
        mp[e]++;
    }
    for(auto&e:str2)
    {
        if(mp[e]<=0)
            return false;
        mp[e]--;
    }
    return true;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<string> arr(n);
        for(int i=0;i<n;i++)//输入n个字符串
        {
            cin>>arr[i];
        }
        
        string str;
        cin>>str;
        int n;
        cin>>n;
        
        vector<string> br;
        for(auto&e:arr)
        {
            if(Judge(str,e))
                br.push_back(e);
        }
        sort(br.begin(),br.end());
        cout<<br.size()<<endl;
        if(n>br.size())
            cout<<""<<endl;
        else
            cout<<br[n-1]<<endl;
    }
    return 0;
}
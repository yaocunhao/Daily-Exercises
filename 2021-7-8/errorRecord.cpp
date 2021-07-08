//记录字符串，并且只能记录8条
//同时只能记录最后一个斜杠后面的字符串
//如果超过8条，则将前面的字符串出队列

#include <iostream>
using namespace std;
#include <string>
#include <queue>
#include <vector>
#include<unordered_map>
#include <algorithm>
bool Getstring(string &str,string &s,unordered_map<string,int> &map)//获取最后的字符串
{
    int count=0;//记录字符的个数
    int flag=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='\\')//遇到‘\’就停止了
           break;
        if(flag)
            count++;
        if(count==17)
            break;
        if(s[i]==' ')//开始计算字符的长度了
            flag=1;
        str+=s[i];
    }
    reverse(str.begin(),str.end());
    map[str]++;
    if(map[str]==1)//第一次出现
        return true;
    return false;//不是第一次出现
}

int main()
{
    string str;
    queue<string> qe;
    unordered_map<string,int> map;
    while(getline(cin,str))
    {
        string s;
        if(Getstring(s,str,map))//第一次出现
        {
            if(qe.size()<8)
                qe.push(s);
            else
            {
                qe.pop();
                qe.push(s);
            }
        }
    }
    //进行输出
    while(!qe.empty())
    {
        string s=qe.front();
        qe.pop();
        int n=map[s];
        s+=' ';
        s+=to_string(n);
        cout<<s<<endl;
    }
    
    return 0;
}
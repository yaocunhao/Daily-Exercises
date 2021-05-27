//首先将句子中的所有单词转换成小写
//然后用map统计出现的次数
//再用multimap进行排序

#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <functional>


void Count(string &str,map<string,int>& count_map)//进行字符统计
{
   int begin=0;
    while(begin<str.size())
    {
      string temp;
      while(begin<str.size()&&str[begin] !=' ')
      {
        if(str[begin]>'Z')
            temp+=str[begin];
        else//转换大小写
            temp+=str[begin]+32;
        
        begin++;
      }
      while(begin<str.size()&&str[begin]==' ')//去除空格
      {
        begin++;
      }
      
      count_map[temp]++;//进行统计
    }
}

int main()
{
  string str;
  
  while(getline(cin,str))
  {
    str.erase(str.end()-1);//删除最后的句号
    map<string,int> count_map;
    
    Count(str,count_map);///进行字符出现次数统计
    
    multimap<int,string,greater<int>> sort_map;//进行排序
    
    for(auto&e:count_map)
    {
      sort_map.insert(make_pair(e.second,e.first));
    }
    
    for(auto&e:sort_map)
    {
      cout<<e.second<<":"<<e.first<<endl;
    }
    
  }

  return 0;
}
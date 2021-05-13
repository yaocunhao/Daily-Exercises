参数解析

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        int count=0;//参数个数
        vector<string> ret;//保存参数
        
        for(int i=0;i<str.size();i++)
        {
            string temp;
            int sub=i;
            while(sub<str.size()&&str[sub]==' ')
            {
                sub++;//去除多个空格
            }
            if(str[sub]!='"')//不是引号时
            {  
                while(sub<str.size()&&str[sub]!=' ')
               {
                   temp+=str[sub];
                   sub++;
               }
                i=sub;
                if(!temp.empty())
                {
                    ret.push_back(temp);
                    count++;
                }
            }
            else//遇到“
            {
                sub++;
                while(sub<str.size()&&str[sub]!='"')
                      {
                          temp+=str[sub];
                          sub++;
                      }
                i=sub;
                if(!temp.empty())
               {
                   ret.push_back(temp);
                   count++;
               }
            }
        }
                      
     cout<<count<<endl;
     for(int i=0;i<ret.size();i++)
     {
        cout<<ret[i]<<endl;
     }
                      
    }
    
    return 0;
}

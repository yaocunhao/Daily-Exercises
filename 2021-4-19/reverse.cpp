#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int main()
{
    //输入字符串
    string str;
    string ret;
    getline(cin,str);
    
    reverse(str.begin(),str.end());//反转全部字符串
    
    size_t left=0;
    while(left<str.size())
    {
        while(left<str.size()&&str[left]==' ')//消除全部空格
        {
            left++;
        }   
        
        size_t right=str.find(' ',left);//寻找空格
        
        if(!(right<string::npos))//没有找到
        {
            reverse(str.begin()+left,str.end());//反转
            string temp(str.begin()+left,str.end());
            ret+=temp;
            break;//此时全部字符串反转完毕
        }
        else
        {
            reverse(str.begin()+left,str.begin()+right);
            string temp(str.begin()+left,str.begin()+right);
            ret+=temp;
            ret+=" ";//补上空格分隔
            left=right;//更新left坐标
        }
    }
    
    if(ret[ret.size()-1]==' ')//最后一个为空格
        ret.erase(ret.size()-1);
    
    cout<<ret<<endl;

    
    return 0;
}
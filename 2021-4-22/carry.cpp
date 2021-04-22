//进制转换

#include <iostream>
using namespace std;
#include <algorithm>
#include <string>

int main()
{
    int m,n;
    cin>>m>>n;
    string str;
    int flag=1;
    if(m<0)
    {
        flag=-1;
        m*=-1;
    }
    
    while(m)
    {
        int num=m%n;
        if(num<10)
            str+=(num+'0');
        else
            str+=(num-10+'A');
        
        m/=n;
    }
    //消除后面的0
    int sub=str.size()-1;
    while(sub>=0&&str[sub]=='0')
    {
        str.erase(sub);
            sub--;
    }
    
    reverse(str.begin(),str.end());//颠倒
    
    //m为零
   if(str.size()==0)
       cout<<"0"<<endl;
   else
   {
       if(flag==1)
           cout<<str<<endl;
       else
           cout<<("-"+str)<<endl;
   }
    
    
    
    
    
    
    return 0;
}
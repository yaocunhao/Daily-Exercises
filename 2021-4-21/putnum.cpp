#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    string ret;
    
    for(int i=0;i<str.size();i++)
    {
        int  start=i; 
        while(start<str.size()&&str[start]>='0'&&str[start]<='9')
        {
            start++;
        }
        if(start!=i)
        {
            string temp(str.begin()+i,str.begin()+start);
            if(temp.size()>ret.size())
                ret=temp;
            i=start;
        }
    }
    cout<<ret<<endl;
   
     
    return 0;
}
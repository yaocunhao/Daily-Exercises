#include <iostream>
#include <string>
using namespace std;

void change(string &str,string &ret)
{
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='_'&&i+1<str.size())
        {
            ret+=str[i+1]-32;
            i++;
        }
        else
            ret+=str[i];
    }
}

int main()
{
    string str;
    string ret;
    while(cin>>str)
    {
        change(str,ret);
        cout<<ret<<endl;
        ret.clear();
    }
    return 0;
}
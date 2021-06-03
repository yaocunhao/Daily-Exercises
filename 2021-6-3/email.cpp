#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
       while (getchar() != '\n');//吃掉多余的字符以及空格
        string ret;
        for(int i=0;i<n;i++)
        {
            string temp;
            getline(cin,temp);
            
            if(temp.find(',')!=string::npos||temp.find(' ')!=string::npos)//有逗号或者空格
            {
                ret+='"';
                ret+=temp;
                ret+='"';
            }
            else//不需要双引号
                ret+=temp;
            
            if(i!=n-1)//在末尾添加，和空格
                ret+=", ";
        }
        cout<<ret<<endl;
    }
    return 0;
}
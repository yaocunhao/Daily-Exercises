#include <iostream>
using namespace std;
#include <string>
#include <vector>
int main()
{
    int n;
    while(cin>>n)
    {
        getchar();//吃掉空格
        vector<string> arr;
        for(int i=0;i<n;i++)//进行数组内容填充
        {
            string temp;
            getline(cin,temp);
            arr.push_back(temp);
        }
        
        int prev=0;//记录是否还有链接
        int count=0;//记录创建新链接的数
        
        for(auto &e:arr)
        {
            if(e[2]=='c')//创建连接
            {
                if(prev==0)//链接为0
                    count++;//创建一个连接
                else//还有链接
                    prev--;
            }
            else
                prev++;//断开链接
        }
        cout<<count<<endl;
        
    }
    
    return 0;
}
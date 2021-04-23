插入回文串

#include <iostream>
#include <string>
using namespace std;
#include <algorithm>


int main()
{
    string A;
    string B;
    
    getline(cin,A);
    getline(cin,B);
    int count=0;
    for(int i=0;i<=A.size();i++)
    {
        string str(A.begin(),A.begin()+i);
        str+=B;//插入B
        string temp(A.begin()+i,A.end());
        str+=temp;
        temp=str;
        reverse(str.begin(),str.end());
        if(temp==str)
            count++;
    }
    cout<<count<<endl;
    
    
}
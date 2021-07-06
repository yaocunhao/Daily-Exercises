#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

int main()
{
    string s1;
    string s2;
    while(cin>>s1)
    {
        cin>>s2;
        unordered_map<char,int> mp;
        for(auto&e:s1)
        {
            mp[e]++;
        }
        int flag=1;
        for(auto&e:s2)
        {
            if(mp[e]==0)
            {
                flag=0;
                break;
            }
            mp[e]--;
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
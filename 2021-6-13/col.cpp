#include <iostream>
using namespace std;
#include <stack>
#include <string>

int main()
{
    int n;
    while(cin>>n)
    {
        string ch;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            cin>>ch;
            if(ch=="+")
            {
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n1+n2);                    
            }
            else if(ch=="-")
            {
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n2-n1);  
            }
             else if(ch=="*")
            {
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n1*n2);  
            }
             else if(ch=="/")
            {
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                st.push(n2/n1);  
            }
            else
                st.push(stoi(ch));
        }
        cout<<st.top()<<endl;
    }
    return 0;
}
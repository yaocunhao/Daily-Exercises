#include <iostream>
using namespace std;
#include<math.h>

int main()
{
    
    double n;
    double r;
    while(cin>>n)
    {
        cin>>r;
        if(n<=2*r*3.14)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    
    return 0;
}
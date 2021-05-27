#include <iostream>
using namespace std;
#include <math.h>

int main()
{
    double a,b,c;
    while(cin>>a)
    {
        cin>>b;
        cin>>c;
        
       double max=fmax(a,fmax(b,c));
       double min=fmin(a,fmax(b,c));
       double  mid=a+b+c-max-min;
        
        if(max>=min+mid)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}
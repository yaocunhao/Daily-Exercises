#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    int n;
    cin>>n;

   int first=0;
   int second=1;
   int thried=0;
   int count=n-thried;
    
    while(thried<n)
    {
        count=fmin(count,n-thried);
       
        first=second;
        second=thried;
        thried=first+second;
    }
    count=fmin(count,thried-n);
    cout<<count<<endl;
    
return 0;
}
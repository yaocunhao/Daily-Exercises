//求糖果

#include <iostream>
using namespace std;


int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    
    int A=(a+c)/2;
    int B=(b+d)/2;
    int C=(d-b)/2;

    
    if(A-B!=a||B-C!=b||A+B!=c||B+C!=d)
       cout<<"No"<<endl;
    else
        cout<<A<<" "<<B<<" "<<C<<endl;
    
    
    
    
    
    return 0;
}
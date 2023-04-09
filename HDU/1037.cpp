#include<iostream>
using namespace std;
int main()
{
    int a,b,c,min;
    cin>>a>>b>>c;
    if(a<=b && a<=c)
        min=a;
    else if(b<=a && b<=c)
        min=b;
    else
        min=c;
    if(min<168)
        cout<<"CRASH "<<min<<endl;
    else
        cout<<"NO CRASH"<<endl;
}

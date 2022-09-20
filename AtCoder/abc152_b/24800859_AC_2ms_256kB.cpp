#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int x=a;
    if(a>b)
        a=b;
    else
        x=b;
    while(x--)
        cout<<a;
}

#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        if((a%2==0 && b%2==0 && a==b) || (a==b+2 && a%2==0 && b%2==0))
            cout<<a+b<<endl;
        else if( (a%2!=0 && b%2!=0 && a==b)||(a==b+2 && a%2!=0 && b%2!=0))
            cout<<(a+b)-1<<endl;
        else
            cout<<"No Number"<<endl;
    }


    return 0;
}

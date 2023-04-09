#include<iostream>
using namespace std;
int main()
{
    long long a,b,cnt=0;
    cin>>a>>b;
    while(a>0)
    {
        a/=b;
        cnt++;
    }
    cout<<cnt<<endl;
}

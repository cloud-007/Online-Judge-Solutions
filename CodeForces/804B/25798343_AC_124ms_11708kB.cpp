#include<bits/stdc++.h>
using namespace std;

const int sz=1e6+100;
long long a[sz];
const int mod=1e9+7;
void init()
{
    a[1]=1;
    for(int i=2;i<sz;i++)
    {
        a[i]=a[i-1]*2+1;
        a[i]%=mod;
    }
}

int main()
{
    init();
    string s;
    cin>>s;
    int cnt=0;
    long long sum=0;
    for(auto i : s)
    {
        if(i=='a')cnt++;
        else
        {
            sum+=a[cnt];
            sum%=mod;
        }
    }
    cout<<sum<<endl;
}
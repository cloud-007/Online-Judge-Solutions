#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{
    if(n<2)
        return false;
    else if(n==2)
        return true;
    long int l=sqrt(n);
    if(n%2==0)
        return false;
    for(int j=3; j<=l; j+=2)
    {
        if(n%j==0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        long long int x;
        cin>>x;
        long long s=sqrt(x);
        if(isPrime(s) && s*s==x)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

#include<iostream>
#include<math.h>
using namespace std;
long long prime[3000000],nprime;
int mark[10000002];
int count=0;
bool isprime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int x=n-1;
    if(n==2 || n==3)
    {
        cout<<-1<<endl;
        return 0;
    }
    while(true)
    {
        if(isprime(x))
            break;
        x--;
    }
    if(2+x==n)
        cout<<2<<' '<<x<<endl;
    else
        cout<<-1<<endl;
}

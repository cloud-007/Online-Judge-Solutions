#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
int mark[1060]; ///we can generate till 10^8
int n=1050;
void sieve()
{
    prime.push_back(1);
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(!mark[i])
        {
            prime.push_back(i);
            if(i*i<=n)
            {
                for(int j=i*i;j<=n;j+=i*2)
                    mark[j]=i;
            }
        }
    }
}

int main()
{
    sieve();
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        for(int i=0; prime[i]<=a; i++)
        {
            cout<<prime[i]<<endl;
        }
        cout<<endl;

    }
}


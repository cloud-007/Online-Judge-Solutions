#include<bits/stdc++.h>
using namespace std;

vector<bool>nprime(10000);
int checked[10002]= {1}; ///we can generate till 10^8
int n=10000;
void sieve()
{
    checked[1]=1;
    nprime[1]=true;
    nprime[2]=false;
    for(int i=4; i<=n; i+=2)
    {
        checked[i]=1;
        nprime[i]=1;
    }
    for(int i=3; i<=n; i+=2)
    {
        if(checked[i]==0)
        {
            nprime[i]=false;
            if(i*i<=n)
            {
                for(int j=i*i; j<=n; j+=i*2)
                {
                    checked[j]=1;
                    nprime[j]=true;
                }
            }
        }
    }
}

int main()
{
    sieve();
    int a;
    cin>>a;
    int n=1;
    bool flag=false;
    while(flag==false)
    {
        int t=a*n+1;
        if(nprime[t]==1)
        {
            cout<<n<<endl;
            flag=true;
        }
        n++;
    }

}

#include<bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define pb push_back
#define FastRead ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
int main()
{
    FastRead;
    ll a,b,t,n,k,i,j,c=0,sum=0,m,mx=0;
    cin>>t;
    while(t--)
    {
        sum=0;
        c++;
        ll d=0,ans=0;
        cin>>n>>k;
        for(i=2; i*i<=k; i++)
        {
            if(k%i==0)
            {
                d=0;
                while(k%i==0)
                {
                    k/=i;
                    d++;
                }
                sum=0;
                for(j=i; j<=n; j*=i)
                {
                    sum+=(n/j);
                }
                sum=sum/d;
                ans=min(ans,sum);
            }
        }

        if(k>1)
        {
            sum=0;
            for(i=k; i<=n; i*=k)
            {
                sum+=(n/i);
            }
            ans=min(ans,sum);
        }
        cout<<"Case "<<c<<": "<<sum<<endl;
    }

    return 0;
}

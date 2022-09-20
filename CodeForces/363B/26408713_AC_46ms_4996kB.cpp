#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

const int sz=2e5+50;
int cumsum[sz];

int main()
{
    cloud_007;
    int n,k,mx=INT_MAX,ans=-1,a;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(i>1)
        {
            cumsum[i]=cumsum[i-1];
        }
        cumsum[i]+=a;
        if(i>=k)
        {
            if(cumsum[i]-cumsum[i-k]<mx)
            {
                ans=i-k+1;
                mx=cumsum[i]-cumsum[i-k];
            }
        }
    }
    cout<<ans<<endl;
}

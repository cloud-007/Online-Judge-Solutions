#include<bits/stdc++.h>
using namespace std;

long long ans[1000000];
int main()
{
    memset(ans,0,sizeof ans);
    cin.tie(0),cout.tie(0);
    int n,q,a;
    cin>>n>>q;
    vector < pair < int, int >> vp(q),v;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        v.push_back({a,i});
    }
    for(auto &x: vp)
        cin>>x.first>>x.second;
    sort(vp.begin(),vp.end());
    sort(v.begin(),v.end());
    long long sum=0;int j=0;
    for(auto i : v)
    {
        int pos=i.second,item=i.first;
        for(j;j<q;j++)
        {
            if(vp[j].first<=item)sum+=vp[j].second;
            else break;
        }
        ans[pos]=sum;
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    cout<<endl;
}

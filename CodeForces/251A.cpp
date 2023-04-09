#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ll n,k,cnt=0;
    cin>>n>>k;
    vector < ll > v(n);
    for(auto &x : v)cin>>x;
    sort(v.begin(),v.end());
    if(n<3)
    {
        puts("0");
        return 0;
    }
    for(int i=0;i<n-2;i++)
    {
        ll now=v[i]+k;
        ll pos=lower_bound(v.begin(),v.end(),now)-v.begin();
        if(pos>=n)pos=n-1;
        else if(v[pos]>now)pos--;
        //cout<<i<<" "<<pos<<endl;
        pos=abs(i-pos);
        pos-=2;
        pos++;
        cnt+=(pos*(pos+1))/2;
    }
    cout<<cnt<<endl;
}

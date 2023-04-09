#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int sz=120;
ll a[sz];
map < ll, ll > mp,temp;
vector < ll > v;
int cnt=0;

void solve(int i)
{
    cnt++;
    v.push_back(a[i]);
    if(temp[a[i]*2])
    {
        temp[a[i]*2]--;
        solve(mp[a[i]*2]);
    }
    if(a[i]%3==0 && temp[a[i]/3])
    {
        temp[a[i]/3]--;
        solve(mp[a[i]/3]);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        mp[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        temp.clear(),v.clear();
        for(auto i : mp)
        {
            temp[i.first]=i.second;
        }
        cnt=0;
        temp[a[i]]--;
        solve(i);
        if(cnt==n)
        {
            for(auto j : v)printf("%lld ",j);
            return 0;
        }
    }
}

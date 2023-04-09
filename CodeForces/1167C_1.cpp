#include<bits/stdc++.h>
using namespace std;

const int sz=1e6+50;
int par[sz],mp[sz];

int find(int u)
{
    return par[u]==u?u:par[u]=find(par[u]);
}
void union_(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b)
        par[a]=b;
}

int main()
{
    int n,k,a;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)par[i]=i;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&a);
        vector < int > v(a);
        for(auto &x : v)scanf("%d",&x);
        for(int i=0;i<a-1;i++)
        {
            union_(v[i],v[i+1]);
        }
    }
    memset(mp,0,sizeof mp);
    for(int i=1;i<=n;i++)
        mp[find(i)]++;
    for(int i=1;i<=n;i++)printf("%d ",mp[par[i]]);
}

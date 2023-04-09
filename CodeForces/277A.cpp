#include<bits/stdc++.h>
using namespace std;

const int sz=250;
int par[sz],cnt=0;
bool check[sz];

int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
void union_(int a,int b)
{
    a=find(par[a]);
    b=find(par[b]);
    if(a!=b)
        par[a]=b;
}

int main()
{
    int n,m,k,a;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=sz;i++)par[i]=i;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        if(k)cnt=-1;
        for(int j=1;j<=k;j++)
        {
            scanf("%d",&a);
            union_(i,a+n);
        }
    }
    memset(check, false, sizeof check);
    for(int i=1;i<=n;i++)
    {
        int x=find(i);
        if(!check[x])
        {
            check[x]=true;
            cnt++;
        }
    }
    printf("%d\n",cnt);
}

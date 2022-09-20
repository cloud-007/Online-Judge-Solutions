#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n+5];
    memset(a,0,sizeof a);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        a[u]++,a[v]++;
    }
    int st=-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            st=i;
            break;
        }
    }
    printf("%d\n",n-1);
    for(int i=1;i<=n;i++)
    {
        if(i!=st)
            printf("%d %d\n",i,st);
    }
}

#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
int k,ans[sz],cnt=0,a[sz],mp[sz];

struct query
{
    int index, l, r;
    bool operator< (const query &other)const
    {
        int block_own=l/k;
        int block_other=other.l/k;
        if(block_own==block_other)
            return r< other.r;
        return block_own < block_other;
    }
} q[sz];

void add(int idx)
{
    if(mp[a[idx]]<=0)cnt++;
    mp[a[idx]]++;
}

void remove(int idx)
{
    mp[a[idx]]--;
    if(mp[a[idx]]<=0)cnt--;
}

int main()
{
    int tc,casee=1;
    cin>>tc;
    while(tc--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        k=sqrt(n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&q[i].l,&q[i].r);
            q[i].l--,q[i].r--;
            q[i].index=i;
        }
        sort(q,q+m);
        int l=0,r=-1;
        cnt=0;
        memset(ans, 0, sizeof ans);
        memset(mp , 0 , sizeof mp);
        for(int i=0; i<m; i++)
        {
            while(r<q[i].r)
                add(++r);
            while(l<q[i].l)
                remove(l++);
            while(r>q[i].r)
                remove(r--);
            while(l>q[i].l)
                add(--l);
            ans[q[i].index]=cnt;
        }
        printf("Case %d:\n",casee++);
        for(int i=0; i<m; i++)
            printf("%d\n",ans[i]);
    }
}

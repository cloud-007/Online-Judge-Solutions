#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
int a[sz],tree[sz*3];

void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return ;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b+e)/2;
    build(left, b, mid);
    build(right, mid+1, e);
    tree[node]=tree[left]+tree[right];
}

void update(int node, int b, int e, int i, int nw)
{
    if(i>e || i < b)
        return;
    if(b>=i && e<=i)
    {
        if(nw==0)
            tree[node]=0;
        else
            tree[node]+=nw;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b+e)/2;
    update(left, b, mid, i, nw);
    update(right, mid+1, e, i, nw);
    tree[node]=tree[left]+tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j )
        return tree[node];
    int left=node*2;
    int right = node * 2 + 1;
    int mid=(b+e)/2;
    int p=query(left,b, mid, i, min(j,mid));
    int q=query(right, mid + 1, e, max(i,mid+1), j);
    return p+q;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc,casee=1;
    cin>>tc;
    while(tc--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        build(1,1,n);
        printf("Case %d:\n",casee++);
        while(q--)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                int v;
                cin>>v;
                v++;
                printf("%d\n",query(1,1,n,v,v));
                update(1,1,n,v,0);
            }
            else if(x==2)
            {
                int u, v;
                cin>>u>>v;
                u++;
                update(1,1,n,u,v);
            }
            else
            {
                int u, v;
                cin>>u>>v;
                u++,v++;
                printf("%d\n",query(1,1,n,u,v));
            }
        }
    }
}

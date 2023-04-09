#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
int a[sz],tree[sz*3];

void build(int node, int b , int e)
{
    if(b==e){
        tree[node]=a[b];
        return ;
    }
    int left = node << 1;
    int right = left + 1 ;
    int mid = ( b + e )>> 1;
    build( left , b , mid);
    build(right , mid +1 , e);
    tree[node]=tree[left]+tree[right];
}

int query(int node, int b , int e , int i , int j)
{
    if(i>e || j<b)return 0;
    if(b>=i && e<=j)return tree[node];
    int left = node << 1;
    int right = left + 1 ;
    int mid = ( b + e )>> 1;
    int p=query(left, b , mid, i , j);
    int q=query(right , mid+1, e,i,j);
    return p+q;
}

void update(int node , int b, int e, int i , int nw)
{
    if(i>e || i<b)return;
    if(b>=i && e<=i)
    {
        if(nw)tree[node]+=nw;
        else
        tree[node]=nw;
        return;
    }
    int left = node << 1;
    int right = left + 1 ;
    int mid = ( b + e )>> 1;
    update(left, b, mid, i, nw);
    update(right, mid+1, e, i, nw);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int tc,casee=1;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(a,0,sizeof a);
        memset(tree,0, sizeof tree);
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        build(1,1,n);
        printf("Case %d:\n",casee++);
        while(q--)
        {
            int id,d;
            scanf("%d%d",&id,&d);
            d++;
            if(id==1)
            {
                printf("%d\n",query(1,1,n,d,d));
                update(1,1,n,d,0);
            }
            else if(id==2)
            {
                int money;
                scanf("%d",&money);
                update(1,1,n,d,money);
            }
            else
            {
                int r;
                scanf("%d",&r);
                r++;
                printf("%d\n",query(1,1,n,d,r));
            }
        }
    }
}

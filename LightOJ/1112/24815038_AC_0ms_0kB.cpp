#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
int a[sz],tree[sz*3];

void build(int node,int b, int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right , mid+1,e);
    tree[node]=tree[left]+tree[right];
}

void update(int node , int b , int e,int i, int nw, int x)
{
    if(i>e || i< b)
        return;
    if(b>=i && e<=i)
    {
        if(x==1)
            tree[node]=0;
        else
            tree[node]+=nw;
        return;
    }
    int left = node * 2;
    int right = left +1;
    int mid=(b+e)/2;
    update(left , b , mid , i, nw, x);
    update(right , mid+1 , e , i , nw , x);
    tree[node]=tree[left]+tree[right];
}

int query(int node, int b, int e , int i , int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int left = node * 2;
    int right = node * 2 + 1;
    int mid=(b+e)/2;
    int p=query(left , b , mid , i , j);
    int q=query(right , mid+1 , e , i , j);
    return p+q;
}

int main()
{
    int tc,casee=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,q,t,l=0,r=0;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)cin>>a[i];
        build(1,1,n);
        printf("Case %d:\n",casee++);
        while(q--)
        {
            scanf("%d",&t);
            if(t==1)
            {
                scanf("%d",&r);
                r++;
                printf("%d\n",query(1,1,n,r,r));
                update(1,1,n,r,0,1);
            }
            else if(t==2)
            {
                scanf("%d%d",&l,&r);
                l++;
                update(1,1,n,l,r,2);
            }
            else
            {
                scanf("%d%d",&l,&r);
                l++,r++;
                printf("%d\n",query(1,1,n,l,r));
            }
        }
    }
}

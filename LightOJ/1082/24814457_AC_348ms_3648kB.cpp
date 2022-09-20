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
    tree[node]=min(tree[left],tree[right]);
}

int query(int node, int b, int e , int i , int j)
{
    if(i>e || j<b)
        return 1e7;
    if(b>=i && e<=j)
        return tree[node];
    int left = node * 2;
    int right = node * 2 + 1;
    int mid=(b+e)/2;
    int p=query(left , b , mid , i , j);
    int q=query(right , mid+1 , e , i , j);
    return min(p,q);
}

int main()
{
    int tc,casee=1,l,r;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        build(1,1,n);
        printf("Case %d:\n",casee++);
        while(m--)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",query(1,1,n,l,r));
        }
    }
}

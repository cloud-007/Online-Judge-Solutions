#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
int tree[sz*3],tree1[sz*3],a[sz];
void build(int node, int b , int e)
{
    if(b==e)
    {
        tree[node]=tree1[node]=a[b];
        return;
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
    tree1[node]=max(tree1[left],tree1[right]);
}

int query(int node, int b,int e, int i , int j)
{
    if(i>e || j<b)return INT_MAX;
    if(b>=i && e<=j)return tree[node];
    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1;
    int p=query(left,b,mid,i,j);
    int q=query(right,mid+1,e,i,j);
    return min(p,q);
}

int query1(int node, int b,int e, int i , int j)
{
    if(i>e || j<b)return 0;
    if(b>=i && e<=j)return tree1[node];
    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1;
    int p=query1(left,b,mid,i,j);
    int q=query1(right,mid+1,e,i,j);
    return max(p,q);
}

int main()
{
    int tc,casee=1;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,d;
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        build(1,1,n);
        int mx=0;
        for(int i=1;i<=n-d+1;i++)
        {
            int p=query(1,1,n,i,i+d-1);
            int q=query1(1,1,n,i,i+d-1);
            //printf("%d %d\n",p,q);
            mx=max(mx,abs(p-q));
        }
        printf("Case %d: %d\n",casee++,mx);
    }
}

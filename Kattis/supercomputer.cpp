#include<bits/stdc++.h>
using namespace std;

const int sz=1e6+50;
int tree[sz*3];
void update(int node, int b, int e, int i , int j)
{
    if(i>e || j<b)return ;
    if(b>=i && e<=b)
    {
        tree[node]^=1;
        return;
    }
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    update(left, b, mid, i ,j);
    update(right, mid+1,e,i,j);
    tree[node]=tree[left]+tree[right];
}
int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)return 0;
    if(b>=i && e<=j)return tree[node];
    int left=node<<1;
    int right=left+1;
    int mid=(b+e)>>1;
    int p=query(left,b,mid,i,j);
    int q=query(right,mid+1,e,i,j);
    return p+q;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    while(k--)
    {
        char c;
        while(true)
        {
            scanf("%c",&c);
            if(isalpha(c))
                break;
        }
        if(c=='F')
        {
            int x;
            scanf("%d",&x);
            update(1,1,n,x,x);
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",query(1,1,n,l,r));
        }
    }
}

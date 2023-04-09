#include<bits/stdc++.h>
using namespace std;
#define ll long long

void reduceFraction(int x, int y)
{
    int d;
    d = __gcd(x, y);

    x = x / d;
    y = y / d;
    printf("%d/%d\n",x,y);
}

const int sz=1e5+50;
struct R{
    ll prop,sum;
}tree[sz*3];
void init()
{
    for(ll i=0;i<3*sz;i++)
        tree[i].sum=tree[i].prop=0;
}
void update(int node, int b , int e, int i , int j, ll x)
{
    if(i>e || j<b)return;
    if(b>=i && e<=j)
    {
        tree[node].sum+=(e-b+1)*x;
        tree[node].prop+=x;
        return;
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+tree[node].prop*(e-b+1);
}

ll query(int node, int b , int e, int i, int j , ll carry=0)
{
    if(i>e || j<b)return 0;
    if(b>=i && e<=j)
        return tree[node].sum+carry*(e-b+1);
    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1;
    ll p=query(left,b,mid,i,j,carry+tree[node].prop);
    ll q=query(right,mid+1,e,i,j,tree[node].prop+carry);
    return p+q;
}

int main()
{
    int tc,casee=1;
    scanf("%d",&tc);
    while(tc--)
    {
        init();
        int n,q,id,l,r,up;
        scanf("%d%d",&n,&q);
        printf("Case %d:\n",casee++);
        while(q--)
        {
            scanf("%d%d%d",&id,&l,&r);
            l++,r++;
            if(!id)
            {
                scanf("%d",&up);
                update(1,1,n,l,r,up);
            }
            else
            {
                ll x=query(1,1,n,l,r);
                printf("%lld\n",x);
            }
        }
    }
}

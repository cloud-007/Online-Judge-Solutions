#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
struct R{
    int prop,sum;
}tree[sz*3];
void init()
{
    for(int i=0;i<3*sz;i++)
        tree[i].sum=tree[i].prop=0;
}

void update(int node, int b , int e, int i , int j , int x)
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
    int mid = ( b+ e )>>1;
    update(left , b , mid ,i , j , x);
    update(right , mid+1 , e , i ,j ,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

int query(int node, int b , int e, int i , int j , int carry=0)
{
    if(i>e || j < b)return 0;
    if(b>=i && e<=j)return tree[node].sum+carry*(e-b+1);
    int left = node << 1;
    int right = left+1;
    int mid=(b+e)>>1;
    int p=query(left, b,mid,i,j,carry+tree[node].prop);
    int q=query(right , mid+1 , e, i,j,carry+tree[node].prop);
    return p+q;
}

int main()
{
    int tc,casee=1;
    scanf("%d",&tc);
    while(tc--)
    {
        init();
        string s;
        cin>>s;
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",casee++);
        while(q--)
        {
            char c;
            while(true)
            {
                scanf("%c",&c);
                if(isalpha(c))
                    break;
            }
            if(c=='I')
            {
                int l , r;
                scanf("%d%d",&l,&r);
                update(1,1,(int)s.size(),l,r,1);
            }
            else
            {
                int l;
                scanf("%d",&l);
                int x=query(1,1,(int)s.size(),l,l);
                if(x%2==0)
                    printf("%c\n",s[l-1]);
                else
                {
                    int m=s[l-1]-'0';
                    m^=1;
                    printf("%d\n",m);
                }
            }
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz=2e5+100;
ll ans[sz],tree[sz*3];
int temp[sz],l[sz+5],r[sz+5];

void build(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=ans[b];
        return;
    }
    int left = node << 1;
    int right = left + 1;
    int mid = (b+e) >> 1;
    build(left, b, mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

ll query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int a;
    memset(ans,0,sizeof ans);
    map < int , int > mp;
    priority_queue< int > pq;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        pq.push(a);
    }
    memset(temp,0,sizeof temp);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        temp[l[i]]+=1;
        temp[r[i]+1]-=1;
    }
    temp[0]=0;
    vector < pair < int , int >> vp;
    for(int i=1;i<=n;i++)
    {
        temp[i]+=temp[i-1];
        vp.push_back({temp[i],i});
    }
    sort(vp.rbegin(),vp.rend());
    for(auto i : vp)
    {
        ans[i.second]=pq.top();
        mp[i.second]=1;
        pq.pop();
    }
    for(int i=1;i<=n;i++)
    {
        if(!mp[i])
        {
            ans[i]=pq.top();
            pq.pop();
        }
    }
    build(1,1,n);
    ll sum=0;
    for(int i=1;i<=q;i++)
    {
        sum+=query(1,1,n,l[i],r[i]);
    }
    cout<<sum<<endl;
}

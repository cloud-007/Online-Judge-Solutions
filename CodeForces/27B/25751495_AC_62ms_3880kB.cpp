#include<bits/stdc++.h>
using namespace std;

map < int , set < int >> st;
map < int , int > mp,my,vis;
bool fl=false;

void dfs(int u,int des)
{
    vis[u]=1;
    for(auto i : st[u])
    {
        if(!vis[i])
        {
            if(i==des)
            {
                fl=true;
                return;
            }
            dfs(i,des);
        }
    }
}


int main()
{
    int n,l,r,mx=0;
    scanf("%d",&n);
    mx=n-1;
    int round=(n*(n-1))/2;
    round--;
    for(int i=1;i<=round;i++)
    {
        scanf("%d%d",&l,&r);
        mp[l]++;
        mp[r]++;
        st[r].insert(l);
    }
    priority_queue < int > pq;
    for(auto i : mp)
    {
        if(i.second!=mx)
            pq.push(-i.first);
    }
    l=0,r=0;
    while(!pq.empty())
    {
        if(l)
            r=-pq.top();
        else
            l=-pq.top();
        pq.pop();
    }
    dfs(l,r);
    if(fl)
    {
        printf("%d %d\n",r,l);
    }
    else printf("%d %d\n",l,r);
}

#include<bits/stdc++.h>
using namespace std;

const int sz=3000;
vector < int > x[sz];
int vis[sz];
map < pair < int , int > , int > mp;
set < int > st,all;

void dfs(int u)
{
    st.insert(u);
    vis[u]=1;
    for(auto i : x[u])
    {
        if(!vis[i] && (!mp[{u,i}] ||!mp[{i,u}]))
        {
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,u,v;
    vector < pair < int , int >> vp;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        vp.push_back({u,v});
        x[u].push_back(v);
        x[v].push_back(u);
        all.insert(u),all.insert(v);
    }
    int cnt=0;
    for(auto i : vp)
    {
        memset(vis,0,sizeof vis);
        u=i.first,v=i.second;
        mp.clear();
        st.clear();
        mp[{u,v}]=1;
        mp[{v,u}]=1;
        for(int i=1;i<=n;i++)
        {
            if(i!=u && i!=v)
            {
                dfs(i);
                break;
            }
        }
        if(st.size()!=all.size())cnt++;
    }
    cout<<cnt<<endl;
}

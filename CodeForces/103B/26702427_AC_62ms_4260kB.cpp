#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

vector < int > x[102];
int vis[102], par[102], cycle = 0, u, v, n, m, ans=0;
map < pair < int, int >, bool> mp;
set < int > st;

void dfs(int u)
{
    ans++;
    vis[u] = 1;
    for(auto i : x[u])
    {
        if(!vis[i])
        {
            par[i] = u;
            dfs(i);
        }
        else if(vis[i] && par[u] != i)
        {
            if(mp[ {i, u}] == 0 && mp[ {u, i}] == 0)
                cycle++;
            mp[{i,u}]=1,mp[{u,i}]=1;
        }
    }
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
        st.insert(u),st.insert(v);
    }
    par[*st.begin()]=*st.begin();
    dfs(*st.begin());
    if(cycle==1)
    {
        if(ans !=n)cycle=0;
    }
    puts(cycle == 1 ? "FHTAGN!" : "NO");
}

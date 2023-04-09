#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

const int sz = 2e4 + 5;
vector < int > x[sz];
int tc, n, u, v, casee = 1, type1, type2,  vis[sz], ans;
set < int > st;

void clr()
{
    st.clear();
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < sz; i++)x[i].clear();
}

void dfs(int u, int ty)
{
    ty == 0 ? type1++ : type2++;
    vis[u] = 1;
    for(auto i : x[u])
    {
        if(!vis[i])
        {
            dfs(i, ty == 1 ? 0 : 1);
        }
    }
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--)
    {
        clr();
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> u >> v;
            x[u].emplace_back(v);
            x[v].emplace_back(u);
            st. insert(u), st.insert(v);
        }
        ans = 0;
        for(auto i : st)
        {
            if(!vis[i])
            {
                type1 = type2 = 0;
                dfs(i, 0);
                ans += max(type1, type2);
            }
        }
        cout << "Case " << casee++ << ": " << ans << endl;
    }
}


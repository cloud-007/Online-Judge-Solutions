/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, m, a[sz], vis[sz];
vector < int > x[sz];

set < int > idx, value;

void dfs(int u) {
    vis[u] = 1;
    idx.insert(u);
    value.insert(a[u]);
    for(auto i : x[u]) {
        if(vis[i])continue;
        dfs(i);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    while(m--) {
        int u, v; cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }

    int Ans = 0;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            idx.clear(), value.clear();
            dfs(i);
            for(auto j : idx)Ans += value.count(j);
        }
    }

    cout<<Ans<<endl;

    return 0;
}

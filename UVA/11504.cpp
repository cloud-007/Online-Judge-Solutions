/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];
vector < int > x[N], vec;
bool vis[N];

void dfs(int u, int type) {
    vis[u] = true;
    for(auto i : x[u]) {
        if(!vis[i])dfs(i, type);
    }
    if(type)vec.push_back(u);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int m; cin >> n >> m;
        while(m--) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
        }
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; i++) {
            if(!vis[i])dfs(i, 1);
        }
        reverse(vec.begin(), vec.end());
        memset(vis, false, sizeof vis);
        int Ans = 0;
        for(auto i : vec) {
            if(vis[i])continue;
            dfs(i, 0); ++Ans;
        }

        cout << Ans << endl;

        for(int i = 1; i <= n; i++)x[i].clear();
        vec.clear();
    }


    return 0;
}

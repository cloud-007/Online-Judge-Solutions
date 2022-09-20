/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, cnt = 0;
bool vis[N];
vector <int> x[N];

void dfs(int u) {
    vis[u] = true; ++cnt;
    for(auto i : x[u]) {
        if(vis[i])continue;
        dfs(i);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }

    int Ans = 0;

    for(int i = 1; i <= n; i++) {
        if(vis[i])continue;
        cnt = 0; dfs(i);
        Ans = max(Ans, cnt);
    }

    cout << Ans << endl;


    return 0;
}

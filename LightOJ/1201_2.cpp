/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, casee = 1, dp[N][2];
vector < int > x[N];

int dfs(int u, int p, int taken) {
    int &ret = dp[u][taken];
    if(~ret)return ret;
    ret = 0;
    for(auto i : x[u]) {
        if(i == p)continue;
        if(taken) {
            ret += dfs(i, u, false);
        } else {
            ret += max(1 + dfs(i, u, true), dfs(i, u, false));
        }
    }
    return ret;
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
            x[v].push_back(u);
        }
        memset(dp, -1, sizeof dp);
        int Ans = 0;
        for(int i = 1; i <= n; i++) {
            if(~dp[i][0] || ~dp[i][1])continue;
            Ans += max(1 + dfs(i, 0, 1), dfs(i, 0, 0));
        }
        cout << "Case " << casee++ << ": " << Ans << endl;
        for(int i = 1; i <= n; i++)x[i].clear();
    }


    return 0;
}

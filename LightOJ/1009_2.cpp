/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e4 + 5;
int tc, n, casee = 1, a[N], cnt[2];
bool vis[N];
vector < int > x[N];

void dfs(int u, int type) {
    vis[u] = true;
    cnt[type]++;
    for(auto i : x[u]) {
        if(vis[i])continue;
        dfs(i, !type);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }

        int Ans = 0;

        for(int i = 1; i < N; i++) {
            if(x[i].size() == 0 || vis[i])continue;
            cnt[0] = cnt[1] = 0;
            dfs(i, 1);
            Ans += max(cnt[0], cnt[1]);
        }

        cout << "Case " << casee++ << ": " << Ans << endl;


        memset(vis, false, sizeof vis);
        for(int i = 1; i < N; i++)x[i].clear();
    }


    return 0;
}

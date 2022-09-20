/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 100 + 5;
int tc, n, casee = 1, Ans, Ans1, st;
vector < pair<int, int>>x [N], rev[N];
bool vis[N];

void dfs(int u, int p = -1) {
    vis[u] = true;
    for(auto [i, cost] : x[u]) {
        if(!vis[i]) {
            Ans1 += cost;
            dfs(i, u);
        } else if(i == st && i != p)Ans1 += cost;
    }

    for(auto [i, cost] : rev[u]) {
        if(!vis[i]) {
            Ans += cost;
            dfs(i, u);
        } else if(i == st && i != p)Ans += cost;
    }

}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int u, v, c; cin >> u >>  v >> c;
            x[u].push_back({v, c});
            rev[v].push_back({u, c});
        }

        Ans = Ans1 = 0;

        for(int i = 1; i <= n; i++) {
            if(x[i].size() == 1 && !vis[i]) {
                st = i ; dfs(i);
            }
        }

        cout << "Case " << casee++ << ": " << min(Ans, Ans1) << endl;
        memset(vis, false, sizeof vis);

        for(int i = 1; i <= n; i++) {
            x[i].clear(); rev[i].clear();
        }
    }


    return 0;
}

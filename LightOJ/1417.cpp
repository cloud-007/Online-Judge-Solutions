/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, dis[N], cnt = 0;
vector < int > x[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for(auto i : x[u]) {
        if(vis[i])continue;
        ++cnt;
        dfs(i);
    }
    dis[u] = cnt;
    vis[u] = false;
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
            int u, v; cin >> u >> v;
            x[u].push_back(v);
        }

        memset(vis, false, sizeof vis);
        memset(dis, -1, sizeof dis);

        int mx = 0, Ans = -1;

        for(int i = 1; i <= n; i++) {
            if(vis[i])continue;
            cnt = 1;
            if(dis[i] == -1) {
                dfs(i);
                dis[i] = cnt;
            }
            if(dis[i] > mx) {
                mx = dis[i];
                Ans = i;
            }
        }

        cout << "Case " << casee++ << ": " << Ans << endl;
        for(int i = 1; i <= n; i++)x[i].clear();
    }


    return 0;
}

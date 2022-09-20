/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, m, casee = 1, a[N], sum = 0, cnt = 0;
vector < int > x[N];
set < int > st;
bool vis[N];

void dfs(int u) {
    sum += a[u]; ++cnt; vis[u] = true;
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
    cin >> tc;
    while(tc--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++)cin >> a[i];
        while(m--) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }

        bool ok = true;

        for(int i = 1; i <= n; i++) {
            if(vis[i])continue;
            sum = cnt = 0;
            dfs(i);
            if(sum % cnt) {
                ok = false;
                break;
            }
            st.insert(sum / cnt);
        }
        if(st.size() > 1)ok = false;
        cout << "Case " << casee++ << ": " << (ok ? "Yes" : "No") << endl;
        memset(vis, false, sizeof vis); st.clear();
        for(int i = 1; i <= n; i++)x[i].clear();
    }


    return 0;
}

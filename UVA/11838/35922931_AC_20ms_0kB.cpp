/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, m, casee = 1, a[N];
vector < int > x[N], rev[N], vec, comp;
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for(auto i : x[u])if(!vis[i])dfs(i);
    vec.push_back(u);
}

void dfs1(int u) {
    vis[u] = true;
    for(auto i : rev[u])if(!vis[i])dfs1(i);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> n >> m && (n + m)) {
        while(m--) {
            int u, v, c; cin >> u >> v >> c;
            x[u].push_back(v);
            rev[v].push_back(u);
            if(c == 2) {
                x[v].push_back(u);
                rev[u].push_back(v);
            }
        }

        for(int i = 1; i <= n; i++)if(!vis[i])dfs(i);
        reverse(vec.begin(), vec.end());
        memset(vis, false, sizeof vis);
        int totalSCC = 0;
        for(auto i : vec) {
            if(vis[i])continue;
            totalSCC++;
            dfs1(i);
        }

       // cout <<"Total scc is: "<< totalSCC <<endl;

        cout << (totalSCC == 1 ? 1 : 0) << endl;

        vec.clear();
        for(int i = 1; i <= n; i++) {
            rev[i].clear(); x[i].clear(); vis[i] = false;
        }

    }


    return 0;
}

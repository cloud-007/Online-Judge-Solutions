/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 100 + 5;
int casee = 1, n, currentNode = 0, tin[N], low[N];
int timer = 0, Ans;
vector < int > x[N];
bool vis[N];

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0, cnt = 0;
    for(int to : x[v]) {
        if(to == p) continue;
        if(vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] >= tin[v] && p != -1)cnt = 1;
            ++children;
        }
    }
    if(p == -1 && children > 1)cnt = 1;
    Ans += cnt;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> n && n) {
        while(true) {
            int u; cin >> u;
            if(!u)break;
            string s;
            getline(cin, s);
            istringstream ss(s);
            int v;
            while(ss >> v) {
                x[u].push_back(v);
                x[v].push_back(u);
            }
        }

        memset(vis, false, sizeof vis);
        memset(tin, -1, sizeof tin);
        memset(low, -1, sizeof low);

        Ans = timer = 0;

        for(int i = 1; i <= n; i++) {
            if(vis[i])continue;
            dfs(i);
        }

        cout << Ans << endl;

        for(int i = 1; i <= n; i++)x[i].clear();

    }


    return 0;
}

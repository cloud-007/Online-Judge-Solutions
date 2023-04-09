/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, in[N], out[N];
vector < int > x[N], rev[N], vec, comp;
map < int, int > mp;
bool vis[N];

void dfs(int u, int type) {
    vis[u] = true;
    if(!type) {
        for(auto i : x[u]) {
            if(!vis[i])dfs(i, type);
        }
    } else {
        for(auto i : rev[u]) {
            if(!vis[i])dfs(i, type);
        }
    }
    if(type == 0)vec.push_back(u);
    else comp.push_back(u);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int m;
    while(cin >> n >> m) {
        while(m--) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
            rev[v].push_back(u);
        }

        memset(vis, false, sizeof vis);

        for(int i = 1; i <= n; i++)if(!vis[i])dfs(i, 0);

        reverse(vec.begin(), vec.end());
        memset(vis, false, sizeof vis);

        int cnt = 1, totalSCC = 0;

        for(auto i : vec) {
            if(vis[i])continue;
            comp.clear();
            dfs(i, 1); totalSCC++;
            for(auto j : comp) {
                mp[j] = cnt;
            }
            ++cnt;
        }

        map < pair < int, int >, bool > edge;

        for(int i = 1; i <= n; i++) {
            for(auto j : x[i]) {
                int u = mp[i], v = mp[j];
                if(u != v && !edge[ {u, v}]) {
                    edge[ {u, v}] = true;
                    in[v]++; out[u]++;
                }
            }
        }

        int totalIn = 0, totalOut = 0;

        for(int i = 1; i < cnt; i++) {
            totalIn += (in[i] > 0);
            totalOut += (out[i] > 0);
        }

        --cnt;

        int Ans = max(cnt - totalIn, cnt - totalOut);
        if(totalSCC == 1)Ans = 0;

        cout << Ans << endl;


        for(int i = 1; i <= n; i++) {
            x[i].clear(); rev[i].clear();
        }
        mp.clear(); vec.clear();
        memset(in, false, sizeof in);
        memset(out, false, sizeof out);

    }


    return 0;
}

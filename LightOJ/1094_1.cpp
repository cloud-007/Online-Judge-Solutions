/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 3e4 + 5;
int tc, n, casee = 1, dis[N];

vector < pair < int, int >> x[N];

void dfs(int u, int par) {
    for(auto i : x[u]) {
        if(i.F == par)continue;
        dis[i.F] = dis[u] + i.S;
        dfs(i.F, u);
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
        for(int i = 1; i < n; i++) {
            int u, v, w; cin >> u >> v >> w;
            ++u, ++v;
            x[u].push_back({v, w});
            x[v].push_back({u, w});
        }

        dfs(1, -1);

        int maxDis = -1, startingNode = -1;
        for(int i = 1; i <= n; i++) {
            if(dis[i] > maxDis) {
                maxDis = dis[i];
                startingNode = i;
            }
        }

        memset(dis, 0, sizeof dis);

        dfs(startingNode, -1);

        cout << "Case " << casee++ << ": " << *max_element(dis + 1, dis + n + 1) << endl;

        for(int i = 1; i <= n; i++)x[i].clear();
    }


    return 0;
}

/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, sz[N];
ll q[N];
vector < int > x[N];

void dfs(int u, int par) {
    sz[u] = 1; q[u] = 0;
    for(auto i : x[u]) {
        if(i == par)continue;
        dfs(i, u);
        q[u] = max(q[u], q[i]);
        sz[u] += sz[i];
    }
    q[u] += sz[u];
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
        for(int i = 2; i <= n; i++) {
            int v; cin >> v;
            x[v].push_back(i);
            x[i].push_back(v);
        }

        dfs(1, -1);

        cout << q[1] << endl;


        for(int i = 1; i <= n; i++)x[i].clear();
    }


    return 0;
}

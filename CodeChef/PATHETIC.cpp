/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 100 + 5;
ll tc, n, casee = 1, a[N];
vector < int > x[N];

void dfs(int u, int par, ll val) {
    a[u] = val * (val + 1);
    for(auto i : x[u]) {
        if(i == par)continue;
        dfs(i, u, val + 2);
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
        for(int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }
        dfs(1, -1, 1);

        for(int i = 1; i <= n; i++) {
            cout << a[i] << " ";
            x[i].clear();
        }

        cout << endl;

    }


    return 0;
}

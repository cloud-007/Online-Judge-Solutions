/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, even = 0, odd = 0, a[N];
vector < int > x[N];

void dfs(int u, int par, bool type) {
    even += (type == false);
    odd += (type == true);
    for(auto i : x[u]) {
        if(i == par)continue;
        dfs(i, u, !type);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }

    dfs(1, -1, 0);

    cout << ((ll)even * (ll)odd) - (n - 1) << endl;


    return 0;
}

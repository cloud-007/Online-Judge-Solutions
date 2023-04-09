/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 3e5 + 5;
int tc, n, casee = 1, a[N], newSt;
vector < pair < int, int >> x[N];
ll dp[N], Ans = 0;
set < int > par[N];

void dfs(int u, int p, ll cur) {
    cur += a[u];
    if(cur > Ans) {
        Ans = cur;
        newSt = u;
    }
    for(auto i : x[u]) {
        if(i.F == p)continue;
        dfs(i.F, u, (cur - i.S) < 0 ? 0 : cur - i.S);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v, c; cin >> u >> v  >> c;
        x[u].push_back({v, c});
        x[v].push_back({u, c});
    }

    dfs(1, 0, 0);
    dfs(newSt, 0, 0);

    cout << Ans << endl;


    return 0;
}

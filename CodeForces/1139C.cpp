/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5, mod = 1e9 + 7;
int tc, n, cnt, k, casee = 1, a[N];
vector <int> x[N];
bool vis[N], ok = true;

ll bigmod(ll a, ll p, ll m) {
    ll res = 1;
    ll x = a;
    while(p) {
        if(p & 1)res = (res * x) % m;
        x = (x * x) % m;
        p /= 2;
    }
    return res;
}

void dfs(int u) {
    vis[u] = true; ++cnt;
    for(auto i : x[u]) {
        if(vis[i])continue;
        dfs(i);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        if(c) {
            ok = false;
            continue;
        }
        x[u].push_back(v);
        x[v].push_back(u);
    }

    ll del = 0;

    for(int i = 1; i <= n; i++) {
        if(vis[i])continue;
        cnt = 0; dfs(i);
        ll cur = (ll)bigmod(cnt, k, mod);
        del += cur;
        del %= mod;
    }

    ll Ans = bigmod(n, k, mod);
    Ans -= del;
    Ans %= mod;
    if(Ans < 0)Ans += mod;
    if(ok)Ans = 0;

    cout << Ans << endl;


    return 0;
}


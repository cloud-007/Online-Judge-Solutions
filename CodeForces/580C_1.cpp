/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, m, u, v, a[sz], ans = 0;
vector < int > x[sz];

void dfs(int u, int par, int cnt) {
    if(cnt > m)return;
    if(x[u].size() == 1 && u != 1) {
        ans++;
        return;
    } for(auto i : x[u]) {
        if(i != par) {
            if(a[i] == 0)dfs(i, u, 0);
            else dfs(i, u, cnt + 1);
        }
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    while(n>1) {
        cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
        --n;
    }

    dfs(1, -1, a[1] == 1);

    cout << ans << endl;


    return 0;
}

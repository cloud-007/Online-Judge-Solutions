/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 5e5 + 5;
int n, q, u, v, vis[sz];
vector < int > x[sz];
ll mp[sz], a[sz];

void dfs(int u, ll sum) {
    sum += mp[u];
    a[u] += sum;
    vis[u] = 1;
    for(auto i : x[u]) {
        if(!vis[i]) {
            dfs(i, sum);
        }
    }
}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }
    while(q--) {
        cin >> u >> v;
        mp[u] += v;
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++)cout << a[i] << " ";

    return 0;
}

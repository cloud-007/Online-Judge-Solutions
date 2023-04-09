/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], Ans;
vector < int > x[N];
vector < pair < int, int >> vp;
map < pair<int, int>, int> mp;

void dfs(int u, int par, int color) {
    int currentColor = 1;
    for(auto i : x[u]) {
        if(i == par)continue;
        if(currentColor == color)++currentColor;
        mp[ {i, u}] = mp[ {u, i}] = currentColor;
        Ans = max(Ans, currentColor);
        dfs(i, u, currentColor);
        ++currentColor;
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
        vp.push_back({u, v});
    }

    dfs(1, -1, -1);

    cout << Ans << endl;
    for(auto i : vp)cout << mp[ {i.F, i.S}] << endl;


    return 0;
}

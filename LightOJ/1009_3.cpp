/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[2];
vector < int > x[N];
bool vis[N];

void dfs(int u, bool type) {
    a[type]++; vis[u] = true;
    for(auto i : x[u]) {
        if(!vis[i])dfs(i, !type);
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
        set < int > st;
        while(n--) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
            st.insert(u);
            st.insert(v);
        }
        int Ans = 0;
        for(auto i : st) {
            if(vis[i])continue;
            dfs(i, true);
            Ans += max(a[0], a[1]);
            a[0] = a[1] = 0;
        }
        cout << "Case " << casee++ << ": " << Ans << Endl;
        for(auto i : st) {
            vis[i] = false;
            x[i].clear();
        }
    }


    return 0;
}

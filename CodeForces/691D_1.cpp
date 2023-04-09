/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e6 + 5;
ll tc, n, casee = 1, a[N];
vector < int > x[N];
set < int > st;
priority_queue < int > pq;
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    st.insert(u); pq.push(a[u]);
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
    int q; cin >> n >> q;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(vis[i])continue;
        st.clear();
        dfs(i);
        for(auto i : st) {
            a[i] = pq.top();
            pq.pop();
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
        x[i].clear(); vis[i] = false;
    }
    cout << endl;


    return 0;
}

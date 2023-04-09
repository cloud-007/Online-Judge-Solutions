/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, m, q, k, casee = 1, dis[N], cnt = 0;
int maxDepth, startingNode, maxNode, tree[N * 3], vis[N];

vector < int > x[N], totalCount;
vector < pair < int, int >> vp;

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = vp[b].S;
        return;
    }
    int left = node * 2; int right = node * 2 + 1;
    int mid = (b + e) >> 1;

    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node] = max(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j) {
    if(i > e || j < b)
        return 0;
    if(b >= i && e <= j)return tree[node];
    int left = node * 2;
    int right = left + 1;
    int mid = (b + e) / 2;
    int p = query(left, b, mid, i, j);
    int q = query(right, mid + 1, e, i, j);
    return max(p, q);
}

void dfs(int u, int depth, int time) {
    vis[u]++; cnt++;
    if(depth > maxDepth) {
        maxDepth = depth;
        startingNode = u;
    }
    for(auto i : x[u]) {
        if(vis[i] == time) {
            dfs(i, depth + 1, time);
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n >> m;

        while(m--) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }

        for(int i = 1; i <= n; i++) {
            if(vis[i] == 0) {
                maxDepth = 1, startingNode = i;
                dfs(i, 1, 0);

                maxDepth = 1, cnt = 0;
                dfs(startingNode, 1, 1);
                maxNode = max(maxNode, cnt);

                totalCount.push_back(cnt);
                vp.push_back({cnt, maxDepth});
            }

        }

        vp.push_back({0, 0});
        totalCount.push_back(0);

        sort(vp.begin(), vp.end());
        sort(totalCount.begin(), totalCount.end());

        int range = vp.size() - 1;
        build(1, 1, range);

        cin >> q;

        cout << "Case " << casee++ << ":" << endl;

        while(q--) {
            cin >> k;
            if(k > maxNode) {
                cout << "impossible" << endl;
            } else {
                int id = lower_bound(totalCount.begin(), totalCount.end(), k) - totalCount.begin();
                int mx = query(1, 1, range, id, range);
                if(k <= mx) cout << k - 1 << endl;
                else cout << mx + ((k - mx) * 2) - 1 << endl;
            }
        }

        vp.clear(), totalCount.clear();
        memset(tree, 0, sizeof tree);
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < N; i++) {
            x[i].clear();
        }
        maxNode = cnt = maxDepth = 0;

    }


    return 0;
}

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
int tc, n, m, u, v, vis[sz];
vector < int > x[sz];

void bfs() {
    priority_queue < int > pq;
    vis[1] = 1;
    pq.push(-1);
    while(!pq.empty()) {
        u = -pq.top(), pq.pop();
        cout << u << " ";
        for(auto i : x[u]) {
            if(!vis[i]) {
                vis[i] = 1;
                pq.push(-i);
            }
        }
    }
    cout << endl;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }

    bfs();

    return 0;
}

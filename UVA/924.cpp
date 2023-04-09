/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, level[N], dis[N], mxLevel = 0, day;
bool vis[N];
vector < int > x[N];

void bfs(int u) {
    queue < int > q;
    q.push(u);
    vis[u] = true;
    dis[u] = 0;
    while(!q.empty()) {
        u = q.front(); q.pop();
        for(auto i : x[u]) {
            if(vis[i])continue;
            q.push(i);
            vis[i] = true;
            dis[i] =  dis[u] + 1;
            ++level[dis[i]];
            if(level[dis[i]] > mxLevel) {
                mxLevel = level[dis[i]];
                day = dis[i];
            }
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> tc;
        while(tc--) {
            int v; cin >> v; ++v;
            x[i].push_back(v);
            //x[v].push_back(i);
        }
    }
    cin >> tc;
    while(tc--) {
        cin >> n; ++n;
        memset(level, false, sizeof level);
        memset(vis, false, sizeof vis);
        memset(dis, false, sizeof dis);
        mxLevel = 0;
        bfs(n);
        if(level[1] == 0)cout << 0 << endl;
        else cout << mxLevel << " " << day << endl;
    }


    return 0;
}

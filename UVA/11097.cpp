/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1005;
int tc, n, m, st, q;
bool new_line = false;
double dis[sz][sz];
vector < pair < int, int >> x[sz];
pair < double, int > ans[sz];

void djk(int u) {
    priority_queue < pair < ll, pair < int, int >>> pq;
    pq.push({0, {u, 0}});
    dis[u][0] = 0;
    while(!pq.empty()) {
        u = pq.top().S.F;
        int edge = pq.top().S.S;
        double val = -pq.top().F; pq.pop();
        // cout << u << " " << edge << " " << val << endl;
        if(val > dis[u][edge])continue;
        for(auto i : x[u]) {
            double new_val = val + i.S;
            if(edge + 1 <= 1000 && new_val < dis[i.F][edge + 1]) {
                dis[i.F][edge + 1] = new_val;
                pq.push({-new_val, {i.F, edge + 1}});
            }
        }
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // cloud007
    cloud_007;
    cout << fixed << setprecision(4);
    while(cin >> n >> m >> st) {
        for(int i = 0; i <= n; i++) {
            ans[i].F = 1000000000000;
            ans[i].S = -1;
            for(int j = 0; j <= 1000; j++) {
                dis[i][j] = 1000000000000;
            }
        }

        while(m--) {
            int u, v, c; cin >> u >> v >> c;
            x[u].push_back({v, c});
        }

        djk(st);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= 1000; j++) {
                if(dis[i][j] == 1000000000000)continue;
                if(j == 0 && (double)dis[i][j] < ans[i].F) {
                    ans[i].F = (double)dis[i][j];
                    ans[i].S = j;
                } else if(j && dis[i][j] / j < ans[i].F) {
                    ans[i].F = dis[i][j] / j;
                    ans[i].S = j;
                }
            }
        }
        cin >> q;
        while(q--) {
            int x; cin >> x;
            if(ans[x].S == -1)cout << "No Path" << endl;
            else cout << ans[x].F << " " << ans[x].S << endl;
        }
        cout << endl;
        for(int i = 0; i <= n; i++)x[i].clear();
    }


    return 0;
}

/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, m;
map <string, int > encode;
map < int, string > decode;
vector < int > x[N];
int par[N], dis[N];
bool vis[N];

void bfs(int u, int des) {
    queue < int > q;
    q.push(u);
    vis[u] = true;
    dis[u] = 0;
    par[u] = -1;
    while(!q.empty()) {
        u = q.front(); q.pop();
        for(auto i : x[u]) {
            if(vis[i])continue;
            dis[i] = dis[u] + 1;
            par[i] = u;
            vis[i] = true;
            if(i == des)return;
            q.push(i);
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    bool newLine = false;
    cin >> tc;
    while(tc--) {
        if(newLine)cout << endl;
        newLine = true;
        cin >> m >> n;
        int cnt = 0;
        while(m--) {
            string c, d; cin >> c >> d;
            if(!encode[c]) {
                encode[c] = ++cnt;
                decode[cnt] = c;
            }
            if(!encode[d]) {
                encode[d] = ++cnt;
                decode[cnt] = d;
            }
            int u = encode[c], v = encode[d];
            x[u].push_back(v);
            x[v].push_back(u);
        }

        while(n--) {
            string c, d; cin >> c >> d;
            int src = encode[c], des = encode[d];
            memset(vis, false, sizeof vis);
            bfs(src, des);
            string Ans = "";
            while(des != src && des != -1) {
                string now = decode[des];
                Ans += now[0];
                des = par[des];
            }
            string now = decode[des];
            Ans += now[0];
            reverse(Ans.begin(), Ans.end());
            cout << Ans << endl;
        }


        for(int i = 0; i <= cnt; i++) {
            x[i].clear();
        }
        encode.clear(); decode.clear();
    }


    return 0;
}

/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 500 + 5;
int ans = 0, tc, row, col, q, casee = 1, vis[N][N], dis[N][N];
char c[N][N];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= row && ty >= 1 && ty <= col && !vis[tx][ty] && c[tx][ty] != '#');
}

set < pair < int, int >> st;

void dfs(int sx, int sy) {
    vis[sx][sy] = true;
    st.insert({sx, sy});
    if(c[sx][sy] == 'C')++ans;
    for(int i = 0; i < 4; i++) {
        int tx = sx + fx[i], ty = sy + fy[i];
        if(valid(tx, ty)) {
            dfs(tx, ty);
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
        cin >> row >> col >> q;
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
                vis[i][j] = dis[i][j] = false;
            }
        }
        cout << "Case " << casee++ << ":" << endl;
        while(q--) {
            int x, y; cin >> x >> y;
            if(vis[x][y]) {
                cout << dis[x][y] << endl;
                continue;
            }
            ans = 0;
            dfs(x, y);
            for(auto i : st) {
                dis[i.F][i.S] = ans;
            }
            st.clear();
            cout << dis[x][y] << endl;
        }
    }


    return 0;
}

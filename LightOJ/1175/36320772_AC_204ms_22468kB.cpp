/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e3 + 5;
int tc, n, casee = 1, row, col, dis[N][N];
char c[N][N]; bool vis[N][N];
queue < pair < int, int >> fire[2];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= row && ty >= 1 && ty <= col && !vis[tx][ty] && c[tx][ty] == '.');
}

int bfs(int sx, int sy) {
    queue < pair < int, int >> q[2];
    bool type = true;
    vis[sx][sy] = true;
    dis[sx][sy] = 0;
    q[type].push({sx, sy});
    while(!q[type].empty()) {

        while(fire[type].size()) {
            sx = fire[type].front().F, sy = fire[type].front().S;
            fire[type].pop();
            for(int i = 0; i < 4; i++) {
                int tx = sx + fx[i], ty = sy + fy[i];
                if(valid(tx, ty)) {
                    vis[tx][ty] = true;
                    fire[!type].push({tx, ty});
                }
            }
        }

        while(q[type].size()) {
            sx = q[type].front().F, sy = q[type].front().S;
            if(sx == 1 || sx == row || sy == 1 || sy == col)return dis[sx][sy] + 1;
            q[type].pop();
            for(int i = 0; i < 4; i++) {
                int tx = sx + fx[i], ty = sy + fy[i];
                if(valid(tx, ty)) {
                    vis[tx][ty] = true;
                    dis[tx][ty] = dis[sx][sy] + 1;
                    if(tx == 1 || tx == row || ty == 1 || ty == col)return dis[tx][ty] + 1;
                    q[!type].push({tx, ty});
                }
            }
        }

        type = !type;

    }
    return INT_MAX;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> row >> col;
        pair < int, int >jane;
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
                if(c[i][j] == 'F') {
                    fire[1].push({i, j});
                    vis[i][j] = true;
                } else if(c[i][j] == 'J')jane = {i, j};
            }
        }
        memset(vis, false, sizeof vis);
        memset(dis, false, sizeof dis);
        int Ans = bfs(jane.F, jane.S);
        cout << "Case " << casee++ << ": " << (Ans == INT_MAX ? "IMPOSSIBLE" : to_string(Ans)) << endl;

        while(fire[0].size())fire[0].pop();
        while(fire[1].size())fire[1].pop();
    }


    return 0;
}

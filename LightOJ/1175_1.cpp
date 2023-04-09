/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 200 + 5;
int tc, row, col, casee = 1, dis[N][N], Ans = INT_MAX;
char c[N][N];
bool vis[N][N][2];
int fx[] =  {0, 0, 1, -1};
int fy[] = {1, -1, 0, 0};

queue < pair <int, int>> fire[2];

bool valid(int tx, int ty, int type) {
    return (tx >= 1 && ty >= 1 && tx <= row && ty <= col && vis[tx][ty][type] == false && c[tx][ty] == '.');
}

bool outside(int tx, int ty) {
    return (tx <= 0 || ty <= 0 || tx > row || ty > col);
}


int bfs(int sx, int sy, int type) {
    queue < pair < int, int >> q[2];
    q[type].push({sx, sy});
    dis[sx][sy] = 0; vis[sx][sy][0] = true;
    while(!q[0].empty() || !q[1].empty()) {

        while(q[type].size()) {
            sx = q[type].front().F, sy = q[type].front().S; q[type].pop();
            if(vis[sx][sy][1])continue;
            for(int i = 0; i < 4; i++) {
                int tx = sx + fx[i], ty = sy + fy[i];
                if(outside(tx, ty)) {
                    return dis[sx][sy] + 1;
                } else if(valid(tx, ty, 0)) {
                    q[!type].push({tx, ty});
                    vis[tx][ty][0] = true;
                    dis[tx][ty] = dis[sx][sy] + 1;
                }
            }
        }

        while(!fire[type].empty()) {
            sx = fire[type].front().F, sy = fire[type].front().S; fire[type].pop();
            for(int i = 0; i < 4; i++) {
                int tx = sx + fx[i], ty = sy + fy[i];
                if(valid(tx, ty, 1)) {
                    fire[!type].push({tx, ty});
                    vis[tx][ty][1] = true;
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
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> row >> col;

        pair < int, int > jane;

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                dis[i][j] = INT_MAX;
                vis[i][j][0] = vis[i][j][1] = false;
            }
        }

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
                if(c[i][j] == 'F') {
                    vis[i][j][1] = true;
                    fire[0].push({i, j});
                } else if(c[i][j] == 'J')jane = {i, j};
            }
        }

        int Ans = bfs(jane.F, jane.S, 0);

        cout << "Case " << casee++ << ": " << (Ans == INT_MAX ? "IMPOSSIBLE" : to_string(Ans)) << endl;

        while(fire[0].size())fire[0].pop();
        while(fire[1].size())fire[1].pop();

    }


    return 0;
}

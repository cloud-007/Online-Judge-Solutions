/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 20 + 5;
int tc, n, row, col, casee = 1, dis[N][N];
char c[N][N];
bool vis[N][N];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= row && ty >= 1 && ty <= col && !vis[tx][ty] && c[tx][ty] == '.');
}

void bfs(int sx, int sy) {
    queue < pair < int, int >> q;
    vis[sx][sy] = true; dis[sx][sy] = 0;
    q.push({sx, sy});
    while(!q.empty()) {
        sx = q.front().F, sy = q.front().S; q.pop();
        for(int i = 0; i < 4; i++) {
            int tx = sx + fx[i], ty = sy + fy[i];
            if(valid(tx, ty)) {
                dis[tx][ty] = dis[sx][sy] + 1;
                vis[tx][ty] = true;
                q.push({tx, ty});
            }
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
        cin >> row >> col;
        pair < int, int > home, a, b, C;
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
                if(c[i][j] == 'h')home = {i, j};
                else if(c[i][j] == 'a') {
                    a = {i, j};
                    c[i][j] = '.';
                } else if(c[i][j] == 'b') {
                    b = {i, j};
                    c[i][j] = '.';
                } else if(c[i][j] == 'c') {
                    C = {i, j};
                    c[i][j] = '.';
                }
                dis[i][j] = INT_MAX;
                vis[i][j] = false;
            }
        }

        bfs(home.F, home.S);

        cout << "Case " << casee++ << ": " << max({dis[a.F][a.S], dis[b.F][b.S], dis[C.F][C.S]}) << endl;

    }


    return 0;
}

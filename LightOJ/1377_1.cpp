/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 200 + 5;
int tc, n, row, col, casee = 1, a[N];
char c[N][N];
int dis[N][N][2];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && ty >= 1 && tx <= row && ty <= col && c[tx][ty] != '#');
}

void bfs(int sx, int sy, bool type) {
    queue < pair < int, int >> q;
    q.push({sx, sy});
    dis[sx][sy][type] = 0;
    while(q.size()) {
        sx = q.front().F; sy = q.front().S; q.pop();
        for(int i = 0; i < 4; i++) {
            int tx = sx + fx[i];
            int ty = sy + fy[i];
            if(valid(tx, ty) && dis[tx][ty][type] > dis[sx][sy][type] + 1) {
                dis[tx][ty][type] = dis[sx][sy][type] + 1;
                if(c[tx][ty] != '*')q.push({tx, ty});
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
    cin >> tc;
    while(tc--) {
        cin >> row >> col;
        pair < int, int > p, d;
        int totalStar = 0;
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
                if(c[i][j] == 'P') p = {i, j};
                else if(c[i][j] == 'D')d = {i, j};
                else if(c[i][j] == '*')totalStar++;
            }
        }


        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                for(int k = 0; k <= 1; k++) {
                    dis[i][j][k] = INT_MAX;
                }
            }
        }


        bfs(p.F, p.S, true);
        bfs(d.F, d.S, false);
        int Ans = INT_MAX;
        if(dis[d.F][d.S][1] != INT_MAX)Ans = dis[d.F][d.S][1];

        vector < pair < int, pair<int, int>>> dStar, pStar;

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                if(c[i][j] == '*') {
                    if(dis[i][j][1] != INT_MAX)pStar.push_back({dis[i][j][1], {i, j}});
                    if(dis[i][j][0] != INT_MAX)dStar.push_back({dis[i][j][0], {i, j}});
                }
            }
        }

        int Ans1 = INT_MAX;

        for(auto i : pStar) {
            for(auto j : dStar) {
                if(i.S.F == j.S.F && i.S.S == j.S.S && totalStar > 1) {
                    Ans1 = min(Ans1, i.F + j.F + 2);
                } else if(i.S.F != j.S.F || i.S.S != j.S.S) {
                    Ans1 = min(Ans1, i.F + j.F + 1);
                }
            }
        }

        Ans = min(Ans, Ans1);

        cout << "Case " << casee++ << ": " << (Ans == INT_MAX ? "impossible" : to_string(Ans)) << endl;

    }


    return 0;
}

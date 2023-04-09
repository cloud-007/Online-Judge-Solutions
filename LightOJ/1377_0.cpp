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
int tc, row, col, casee = 1, vis[N][N], dis[N][N];
int pToNearestStar, dToNearestStar;
pair < int, int > pIndex, dIndex;
char c[N][N];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && ty >= 1 && tx <= row && ty <= col && !vis[tx][ty] && c[tx][ty] != '#');
}

void bfs(int sx, int sy, int type) {
    vis[sx][sy] = true;
    queue < pair < int, int >> q;
    q.push({sx, sy});
    while(!q.empty()) {
        sx = q.front().F, sy = q.front().S; q.pop();

        for(int i = 0; i < 4; i++) {
            int tx = sx + fx[i], ty = sy + fy[i];
            if(valid(tx, ty)) {
                if(type == 0) {
                    if(c[tx][ty] == '*')continue;
                    dis[tx][ty] = dis[sx][sy] + 1;
                    vis[tx][ty] = true;
                    q.push({tx, ty});
                } else {
                    if(c[tx][ty] == '*') {
                        dis[tx][ty] = dis[sx][sy] + 1;
                        vis[tx][ty] = true;
                        if(type == 1) {
                            if(pToNearestStar == -1) {
                                pToNearestStar = dis[tx][ty];
                                pIndex = {tx, ty};
                            }
                        } else {
                            if(dToNearestStar == -1) {
                                dToNearestStar = dis[tx][ty];
                                dIndex = {tx, ty};
                            }
                        }
                    } else {
                        dis[tx][ty] = dis[sx][sy] + 1;
                        vis[tx][ty] = true;
                        q.push({tx, ty});
                    }
                }
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

        pair < int, int > p, d; int star = 0;

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
                if(c[i][j] == 'P') p = {i, j};
                if(c[i][j] == 'D')d = {i, j};
                if(c[i][j] == '*')star++;
            }
        }

        memset(vis, false, sizeof vis);
        memset(dis, false, sizeof dis);

        pToNearestStar = dToNearestStar = -1;

        bfs(p.F, p.S, 0);

        int Ans = INT_MAX;
        if(dis[d.F][d.S] != 0) {
            Ans = dis[d.F][d.S];
        }

        memset(vis, false, sizeof vis);
        memset(dis, false, sizeof dis);

        bfs(p.F, p.S, 1);

        int sameP = 0, sameQ = 0;

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                if(c[i][j] == '*' && dis[i][j] == pToNearestStar) {
                    sameP++;
                }
            }
        }

        memset(vis, false, sizeof vis);
        memset(dis, false, sizeof dis);

        bfs(d.F, d.S, 2);

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                if(c[i][j] == '*' && dis[i][j] == dToNearestStar) {
                    sameQ++;
                }
            }
        }

        if(~pToNearestStar && ~dToNearestStar && star > 1) {
            ///cout << pIndex.F << " " << pIndex.S << " " << dIndex.F << " " << dIndex.S << endl;
            if(pIndex == dIndex) {
                Ans = min(Ans, pToNearestStar + dToNearestStar + 2 - (sameP > 1 || sameQ > 1));
            } else {
                Ans = min(Ans, pToNearestStar + dToNearestStar + 1);
            }
        }

        cout << "Case " << casee++ << ": ";

        if(Ans == INT_MAX)cout << "impossible" << Endl;
        else cout << Ans << endl;

    }


    return 0;
}

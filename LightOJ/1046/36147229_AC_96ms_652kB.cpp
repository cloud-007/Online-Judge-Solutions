/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 10 + 5;
int tc, row, col, casee = 1, dis[N][N];
char c[N][N];

int fx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int fy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= row && ty >= 1 && ty <= col);
}

void bfs(int sx, int sy) {
    priority_queue < pair < int, pair < int, int >>> pq;
    pq.push({0, {sx, sy}});
    dis[sx][sy] = 0;
    while(!pq.empty()) {
        sx = pq.top().S.F, sy = pq.top().S.S;
        int cost = -pq.top().F; pq.pop();

        for(int i = 0; i < 8; i++) {
            int tx = sx + fx[i], ty = sy + fy[i];
            if(!valid(tx, ty))continue;
            if(dis[tx][ty] > cost + 1) {
                dis[tx][ty] = cost + 1;
                pq.push({-dis[tx][ty], {tx, ty}});
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

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
            }
        }

        int Ans = INT_MAX;

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                for(int k = 1; k <= row; k++) {
                    for(int l = 1; l <= col; l++) {
                        dis[k][l] = INT_MAX;
                    }
                }

                bfs(i, j);

                bool validSolution = true;

                int curMove = 0;

                for(int i = 1; i <= row; i++) {
                    for(int j = 1; j <= col; j++) {
                        if(c[i][j] != '.' && dis[i][j] == INT_MAX) {
                            validSolution = false;
                        } else if(c[i][j] != '.' && dis[i][j] != INT_MAX) {
                            int now = dis[i][j] / (c[i][j] - '0');
                            now += ((dis[i][j] % (c[i][j] - '0')) > 0);
                            curMove += now;
                        }
                    }
                }

                if(validSolution)Ans = min(Ans, curMove);

            }
        }

        cout << "Case " << casee++ << ": " << (Ans == INT_MAX ? -1 : Ans) << endl;

    }


    return 0;
}

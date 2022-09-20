/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 5e2 + 5;
int tc, n, casee = 1, row, col, Ans[N][N], cnt;
char c[N][N];
bool vis[N][N];
vector < pair < int, int >> vec;

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= row && ty >= 1 && ty <= col && !vis[tx][ty] && c[tx][ty] != '#');
}

void dfs(int sx, int sy) {
    vis[sx][sy] = true;
    cnt += (c[sx][sy] == 'C');
    vec.push_back({sx, sy});
    for(int i = 0; i < 4; i++) {
        int tx = sx + fx[i], ty = sy + fy[i];
        if(valid(tx, ty))dfs(tx, ty);
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

        int q; cin >> row >> col >> q;

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
            }
        }

        memset(vis, false, sizeof vis);
        memset(Ans, false, sizeof Ans);

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                if(vis[i][j])continue;
                cnt = 0; vec.clear();
                dfs(i, j);
                for(auto k : vec) {
                    Ans[k.F][k.S] = cnt;
                }
            }
        }

        cout << "Case " << casee++ << ":" << endl;

        while(q--) {
            int x, y; cin >> x  >> y;
            cout << Ans[x][y] << endl;
        }

    }

    return 0;
}

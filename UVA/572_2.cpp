/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e2 + 5;
int tc, n, row, col;
char c[N][N];
bool vis[N][N];

int fx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int fy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= row && ty >= 1 && ty <= col && !vis[tx][ty] && c[tx][ty] == '@');
}

void dfs(int sx, int sy) {
    vis[sx][sy] = true;
    for(int i = 0; i < 8; i++) {
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
    while(cin >> row >> col && (col + row)) {

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
            }
        }

        memset(vis, false, sizeof vis);

        int Ans = 0;

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                if(vis[i][j])continue;
                if(c[i][j] == '@') {
                    dfs(i, j);
                    ++Ans;
                }
            }
        }

        cout << Ans << endl;

    }


    return 0;
}

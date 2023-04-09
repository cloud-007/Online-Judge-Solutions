/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 20 + 5;
int tc, row, col, casee = 1, a[N], Ans;
char c[N][N];
bool vis[N][N];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= row && ty >= 1 && ty <= col && !vis[tx][ty] && c[tx][ty] == '.');
}

void dfs(int sx, int sy) {
    vis[sx][sy] = true; ++Ans;
    for(int i = 0; i < 4; i++) {
        int tx = sx + fx[i];
        int ty = sy + fy[i];
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
        cin >> col >> row;
        pair < int, int > st;
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
                if(c[i][j] == '@')st = {i, j};
            }
        }
        Ans = 0;
        memset(vis, false, sizeof vis);
        dfs(st.F, st.S);

        cout << "Case " << casee++ << ": " << Ans << endl;

    }


    return 0;
}


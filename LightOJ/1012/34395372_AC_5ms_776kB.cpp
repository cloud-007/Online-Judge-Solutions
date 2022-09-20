/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], row, col;
char c[25][25];
bool vis[25][25];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= row && ty >= 1 && ty <= col && !vis[tx][ty] && c[tx][ty] == '.');
}

int dfs(int sx, int sy) {
    vis[sx][sy] = true;
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        int tx = sx + fx[i];
        int ty = sy + fy[i];
        if(!valid(tx, ty))continue;
        ret += 1 + dfs(tx, ty);
    }
    return ret;
}


int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
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

        cout << "Case " << casee++ << ": " << (1 + dfs(st.F, st.S)) << endl;
        memset(vis, false, sizeof vis);
    }


    return 0;
}

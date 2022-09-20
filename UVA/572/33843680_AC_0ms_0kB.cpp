/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 100 + 5;
int tc, n, m, casee = 1, a[N];
char c[N][N];
bool vis[N][N];

int fx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int fy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && ty >= 1 && tx <= n && ty <= m && !vis[tx][ty] && c[tx][ty] == '@');
}

void dfs(int sx, int sy) {
    for(int i = 0; i < 8; i++) {
        int tx = sx + fx[i];
        int ty = sy + fy[i];
        if(valid(tx, ty)) {
            vis[tx][ty] = true;
            dfs(tx, ty);
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    while(cin >> n >> m && (n + m)) {
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++)
                cin >> c[i][j];
        }
        int Ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(c[i][j] == '@' && !vis[i][j]) {
                    vis[i][j] = true;
                    dfs(i, j);
                    ++Ans;
                }
            }
        }
        cout << Ans << endl;
    }


    return 0;
}

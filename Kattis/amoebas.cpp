/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int row, col, cnt = 0, vis[105][105];
char a[105][105];
int fx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int fy[] = {0, -1, 1, 1, -1, 0, 1, -1 };

bool valid(int tx, int ty) {
    if(tx >= 1 && ty >= 1 && tx <= row && ty <= col && a[tx][ty] == '#' && !vis[tx][ty])return true;
    return false;
}

void dfs(int sx, int sy) {
    vis[sx][sy] = 1;
    for(int k = 0; k < 8; k++) {
        int tx = sx + fx[k], ty = sy + fy[k];
        if(valid(tx, ty)) {
            dfs(tx, ty);
        }
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;

    cin >> row >> col;

    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            cin >> a[i][j];
        }
    }

    memset(vis, 0, sizeof vis);

    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            if(a[i][j] == '#' && !vis[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt << endl;


    return 0;
}

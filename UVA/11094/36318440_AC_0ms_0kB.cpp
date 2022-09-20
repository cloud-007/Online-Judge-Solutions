/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 5e2 + 5;
int tc, n, casee = 1, row, col, cnt;
char c[N][N];
bool vis[N][N];
int x, y;
vector < pair < int, int >> vec;

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= row && ty >= 1 && ty <= col && !vis[tx][ty] && c[tx][ty] == c[x][y]);
}

void dfs(int sx, int sy, char ch) {
    vis[sx][sy] = true;
    cnt += (c[sx][sy] == ch);
    vec.push_back({sx, sy});
    for(int i = 0; i < 4; i++) {
        int tx = sx + fx[i], ty = sy + fy[i];
//        if(tx > row)tx = 1;
//        else if(tx < 1)tx = row;
        if(ty > col)ty = 1;
        else if(ty < 1)ty = col;
        if(valid(tx, ty))dfs(tx, ty, ch);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);

    while(cin >> row >> col) {

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                cin >> c[i][j];
            }
        }

        memset(vis, false, sizeof vis);

        cin >> x  >> y;
        ++x, ++y;

        int Ans = 0;

        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= col; j++) {
                if(vis[i][j])continue;
                if(c[i][j] == c[x][y]) {
                    cnt = 0; vec.clear();
                    dfs(i, j, c[x][y]);
                    bool found = false;
                    for(auto k : vec) {
                        if(k.F == x && k.S == y)found = true;
                    }
                    if(!found)Ans = max(Ans, cnt);
                }
            }
        }

        cout << Ans << endl;
    }

    return 0;
}

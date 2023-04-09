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
int tc, n, m, casee = 1, a[N], Ans = 0;
char c[25][25];
bool vis[25][25];

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= n && ty >= 1 && ty <= m && vis[tx][ty] == false && c[tx][ty] == '.');
}

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

void dfs(int sx, int sy) {
    vis[sx][sy] = true; ++Ans;
    for(int i = 0; i < 4; i++) {
        int tx = sx + fx[i] ;
        int ty = sy + fy[i] ;
        if(valid(tx, ty)) {
            dfs(tx, ty);
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
        cin >> n >> m;
        pair < int, int > st;
        swap(n, m);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> c[i][j];
                if(c[i][j] == '@')st = {i,  j};
            }
        }
        Ans = 0;
        dfs(st.F, st.S);
        cout << "Case " << casee++ << ": " << Ans << endl;
        memset(vis, false, sizeof vis);
    }


    return 0;
}

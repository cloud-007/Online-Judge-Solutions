/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, m, cnt, Ans[N][N], cntId[N][N], id;
char c[N][N];
vector <pair<int, int>> vp;
bool vis[N][N];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty]);
}

void dfs(int sx, int sy) {
    vis[sx][sy] = true; ++cnt;
    vp.push_back({sx, sy});
    for(int i = 0; i < 4; i++) {
        int tx = sx + fx[i], ty = sy + fy[i];
        if(!valid(tx, ty))continue;
        dfs(tx, ty);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if(c[i][j] == '*')vis[i][j] = true;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(vis[i][j])continue;
            dfs(i, j); ++id;
            for(auto k : vp) {
                Ans[k.F][k.S] = cnt;
                cntId[k.F][k.S] = id;
            }
            cnt = 0; vp.clear();
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(c[i][j] == '.')cout << c[i][j];
            else {
                cnt = 1;
                map < int, int > mp;
                for(int k = 0; k < 4; k++) {
                    int tx = i + fx[k], ty = j + fy[k];
                    if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && !mp[cntId[tx][ty]]) {
                        cnt += Ans[tx][ty];
                        mp[cntId[tx][ty]] = true;
                    }
                }
                cout << cnt % 10;
            }
        }
        cout << endl;
    }


    return 0;
}

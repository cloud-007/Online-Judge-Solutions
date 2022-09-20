/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, casee = 1, cnt, Ans[N][N];
char c[N][N];
bool vis[N][N][4];
vector < pair < int, int >> vp;


void checkHorizontal(int sx, int sy) {
    ++cnt;
    vp.push_back({sx, sy});
    int i = sx + 1, j = sy;
    while(i <= n && c[i][j] == 'X') {
        vp.push_back({i, j});
        ++i, ++cnt;
    }
    i = sx - 1;
    while(i >= 1 && c[i][j] == 'X') {
        vp.push_back({i, j});
        --i, ++cnt;
    }

    for(auto k : vp) {
        i = k.F, j = k.S;
        vis[i][j][0] = true;
        Ans[i][j] = max(Ans[i][j], cnt);
    }
    vp.clear();
}

void checkVertical(int sx, int sy) {
    ++cnt;
    vp.push_back({sx, sy});
    int i = sx, j = sy + 1;
    while(j <= n && c[i][j] == 'X') {
        vp.push_back({i, j});
        ++j, ++cnt;
    }
    j = sy - 1;
    while(j >= 1 && c[i][j] == 'X') {
        vp.push_back({i, j});
        --j, ++cnt;
    }

    for(auto k : vp) {
        i = k.F, j = k.S;
        vis[i][j][1] = true;
        Ans[i][j] = max(Ans[i][j], cnt);
    }
    vp.clear();
}

void checkLeftDiagonal(int sx, int sy) {
    ++cnt;
    vp.push_back({sx, sy});
    int i = sx + 1, j = sy + 1;
    while(i <= n && j <= n && c[i][j] == 'X') {
        vp.push_back({i, j});
        ++cnt; ++i; ++j;
    }
    i = sx - 1; j = sy - 1;

    while(i >= 1 && j >= 1 && c[i][j] == 'X') {
        vp.push_back({i, j});
        ++cnt; --i; --j;
    }
    for(auto k : vp) {
        i = k.F, j = k.S;
        vis[i][j][2] = true;
        Ans[i][j] = max(Ans[i][j], cnt);
    }
    vp.clear();
}

void checkRightDiagonal(int sx, int sy) {
    cnt++;
    vp.push_back({sx, sy});
    int i = sx + 1, j = sy - 1;
    while(i <= n && j >= 1 && c[i][j] == 'X') {
        vp.push_back({i, j});
        ++cnt; ++i; --j;
    }
    i = sx - 1, j = sy + 1;
    while(i >= 1 && j <= n && c[i][j] == 'X') {
        vp.push_back({i, j});
        ++cnt; --i; ++j;
    }
    for(auto k : vp) {
        i = k.F, j = k.S;
        vis[i][j][3] = true;
        Ans[i][j] = max(Ans[i][j], cnt);
    }
    vp.clear();
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(c[i][j] == '.')continue;
            if(!vis[i][j][0]) {
                cnt = 0;
                checkHorizontal(i, j);
            }
            if(!vis[i][j][1]) {
                cnt = 0;
                checkVertical(i, j);
            }
            if(!vis[i][j][2]) {
                cnt = 0;
                checkLeftDiagonal(i, j);
            }
            if(!vis[i][j][3]) {
                cnt = 0;
                checkRightDiagonal(i, j);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << Ans[i][j] << " ";
        }
        cout << endl;
    }





    return 0;
}

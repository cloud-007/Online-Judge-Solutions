/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 5 + 5;
int tc, n, casee = 1, a[N][N], graph[N][N];
int Ans = 0;

int fx[] = {-1, -1};
int fy[] = {-1, 1};

bool checkCol(int tot, int idx) {
    for(int i = 1; i < tot; i++) {
        if(graph[i][idx])return false;
    }
    return true;
}

bool checkDiagonal(int sx, int sy, int type) {
    int tx = sx + fx[type];
    int ty = sy + fy[type];
    int ret = true;
    if(tx >= 1 && ty >= 1 && tx <= 8 && ty <= 8) {
        if(graph[tx][ty])ret = false;
        else {
            ret &= checkDiagonal(tx, ty, type);
        }
    }
    return ret;
}

void dfs(int idx, int sum) {
    if(idx > 8) {
        Ans = max(Ans, sum);
        return;
    }

    for(int i = 1; i <= 8; i++) {
        if(checkCol(idx, i) && checkDiagonal(idx, i, 0) && checkDiagonal(idx, i, 1)) {
            graph[idx][i] = true;
            dfs(idx + 1, sum + a[idx][i]);
            graph[idx][i] = false;
        }
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
        for(int i = 1; i <= 8; i++) {
            for(int j = 1; j <= 8; j++) {
                cin >> a[i][j];
            }
        }
        memset(graph, false, sizeof graph);
        Ans = 0;
        dfs(1, 0);
        string fin = to_string(Ans);
        while(fin.size() < 5)fin = " " + fin;
        cout << fin << endl;
    }


    return 0;
}

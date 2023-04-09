/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 130 + 5;
int tc, n, casee = 1, a[N];
bool vis[N][N][N];
int dis[N][N][N];
queue < pair < int, pair < int, int >>>q;


char nextChar(char c) {
    ++c;
    if(c > 'z')c = 'a';
    return c;
}

char previousChar(char c) {
    --c;
    if(c < 'a')c = 'z';
    return c;
}

void updateX(char c, char x, char y, char z) {
    if(vis[c][y][z])return;
    vis[c][y][z] = true;
    dis[c][y][z] = dis[x][y][z] + 1;
    q.push({c, {y, z}});
}

void updateY(char c, char x, char y, char z) {
    if(vis[x][c][z])return;
    vis[x][c][z] = true;
    dis[x][c][z] = dis[x][y][z] + 1;
    q.push({x, {c, z}});
}

void updateZ(char c, char x, char y, char z) {
    if(vis[x][y][c])return;
    vis[x][y][c] = true;
    dis[x][y][c] = dis[x][y][z] + 1;
    q.push({x, {y, c}});
}

void bfs(char x, char y, char z) {
    if(vis[x][y][z])return;
    vis[x][y][z] = true;
    dis[x][y][z] = 0;

    while(q.size())q.pop();

    q.push({x, {y, z}});
    while(q.size()) {
        x = q.front().F, y = q.front().S.F, z = q.front().S.S; q.pop();

        char c = nextChar(x);
        updateX(c, x, y, z);
        c = previousChar(x);
        updateX(c, x, y, z);

        c = nextChar(y);
        updateY(c, x, y, z);
        c = previousChar(y);
        updateY(c, x, y, z);

        c = nextChar(z);
        updateZ(c, x, y, z);
        c = previousChar(z);
        updateZ(c, x, y, z);
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
        string st, en;
        cin >> st >> en;

        memset(vis, false, sizeof vis);
        memset(dis, -1, sizeof dis);
        cin >> n;
        while(n--) {
            string x, y, z; cin >> x >> y >> z;
            for(int i = 0; i < x.size(); i++) {
                for(int j = 0; j < y.size(); j++) {
                    for(int k = 0; k < z.size(); k++) {
                        vis[x[i]][y[j]][z[k]] = true;
                    }
                }
            }
        }
        bfs(st[0], st[1], st[2]);

        cout << "Case " << casee++ << ": " << dis[en[0]][en[1]][en[2]] << endl;

    }


    return 0;
}

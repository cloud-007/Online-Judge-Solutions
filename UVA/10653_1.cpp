/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, row, col, casee = 1, a[N];
bool vis[N][N];
pair < int, int > st, des;
int dis[N][N];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 0 && tx < row && ty >= 0 && ty < col && !vis[tx][ty]);
}

void bfs(int sx, int sy) {
    vis[sx][sy] = true;
    dis[sx][sy] = 0;
    queue < pair < int, int >> q;
    q.push({sx, sy});
    while(q.size()) {
        sx = q.front().F, sy = q.front().S; q.pop();
        for(int i = 0; i < 4; i++) {
            int tx = sx + fx[i];
            int ty = sy + fy[i];
            if(valid(tx, ty)) {
                vis[tx][ty] = true;
                dis[tx][ty] = dis[sx][sy] + 1;
                q.push({tx, ty});
            }
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> row >> col && (row || col)) {

        for(int i = 0; i <= row; i++) {
            for(int j = 0; j <= col; j++)
                vis[i][j] = false;
        }

        cin >> tc;
        cin.ignore();
        while(tc--) {
            string s;
            getline(cin, s);
            stringstream ss(s);
            string word;
            int u = -1, v = -1;
            while(ss >> word) {
                if(u == -1)u = stoi(word);
                else if(v == -1) {
                    v = stoi(word);
                } else {
                    v = stoi(word);
                    vis[u][v] = true;
                }
            }

        }
        cin >> st.F >> st.S >> des.F >> des.S;
        bfs(st.F, st.S);
        cout << dis[des.F][des.S] << endl;
    }


    return 0;
}

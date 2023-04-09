/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 20 + 5;
int tc, n, row, col, casee = 1, dis[N][N], k;
char c[N][N], cur;
bool vis[N][N];
pair < int, int > alphabet[100];

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

bool valid(int tx, int ty) {
    return (tx >= 1 && ty >= 1 && tx <= row && ty <= col && !vis[tx][ty] && (c[tx][ty] == '.' || c[tx][ty] == cur + 1));
}

void bfs(int sx, int sy) {
    queue < pair < int, int >> q;
    q.push({sx, sy});
    vis[sx][sy] = true; dis[sx][sy] = 0;
    while(!q.empty()) {
        sx = q.front().F, sy = q.front().S; q.pop();

        for(int i = 0; i < 4; i++) {
            int tx = sx + fx[i], ty = sy + fy[i];
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
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n;

        int k = 0;
        row = col = n;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> c[i][j];
                if(c[i][j] >= 'A' && c[i][j] <= 'Z') {
                    alphabet[c[i][j]] = {i, j};
                    k++;
                }
            }
        }
        --k;
        cur = 'A';

        bool ok = true;

        int Ans = 0;

        while(k--) {

            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    vis[i][j] = false; dis[i][j] = INT_MAX;
                }
            }

            bfs(alphabet[cur].F, alphabet[cur].S);
            c[alphabet[cur].F][alphabet[cur].S] = '.';

            if(vis[alphabet[cur + 1].F][alphabet[cur + 1].S]) {
                Ans += dis[alphabet[cur + 1].F][alphabet[cur + 1].S];
            } else {
                ok = false;
                break;
            }

            ++cur;
        }

        cout << "Case " << casee++ << ": " << (ok ? to_string(Ans) : "Impossible") << endl;

    }



    return 0;
}

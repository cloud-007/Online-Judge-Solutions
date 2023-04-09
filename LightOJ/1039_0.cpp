/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 130 + 5;
int tc, n, casee = 1, vis[N][N][N], dis[N][N][N];
string s, d;

int fx[] = {0, 0, 1, 0, 0, -1};
int fy[] = {0, 1, 0, 0, -1, 0};
int fz[] = {1, 0, 0, -1, 0, 0};

void clear() {
    for(char a = 'a'; a <= 'z'; a++) {
        for(char b = 'a'; b <= 'z'; b++) {
            for(char c = 'a'; c <= 'z'; c++) {
                vis[a][b][c] = dis[a][b][c] = 0;
            }
        }
    }
}

void bfs() {
    queue < tuple < char, char, char>>q;
    q.push(make_tuple(s[0], s[1], s[2]));
    while(!q.empty()) {
        tuple < char, char, char> u = q.front(); q.pop();
        if(get<0>(u) == d[0] && get<1>(u) == d[1] && get<2>(u) == d[2])return;
        for(int i = 0; i < 6; i++) {
            int a = (get<0>(u) - 'a' + fx[i] + 26) % 26 + 'a';
            int b = (get<1>(u) - 'a' + fy[i] + 26) % 26 + 'a';
            int c = (get<2>(u) - 'a' + fz[i] + 26) % 26 + 'a';
            if(vis[a][b][c])continue;
            vis[a][b][c] = true;
            dis[a][b][c] = dis[get<0>(u)][get<1>(u)][get<2>(u)] + 1;
            q.push(make_tuple(a, b, c));
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
        cin >> s >> d >> n;
        for(int i = 1; i <= n; i++) {
            string a, b, c;
            cin >> a >> b >> c;
            for(int j = 0; j < a.size(); j++) {
                for(int k = 0; k < b.size(); k++) {
                    for(int l = 0; l < c.size(); l++) {
                        vis[a[j]][b[k]][c[l]] = true;
                    }
                }
            }
        }

        cout << "Case " << casee++ << ": ";
        if(vis[s[0]][s[1]][s[2]] || vis[d[0]][d[1]][d[2]]) {
            cout << -1 << endl;
        } else if(s == d) {
            cout << 0 << endl;
        } else {
            bfs();
            cout << (vis[d[0]][d[1]][d[2]] ? dis[d[0]][d[1]][d[2]] : -1) << endl;
        }
        clear();
    }


    return 0;
}

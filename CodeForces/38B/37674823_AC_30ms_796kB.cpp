/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];

bool vis[10][10];

int fx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int fy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int getVal(char c) {
    return c - 'a' + 1;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    char c, d; int y1, y2;
    cin >> c >> y1;
    cin >> d >> y2;
    int x1 = getVal(c);
    int x2 = getVal(d);

    vis[x1][y1] = true;
    vis[x2][y2] = true;

    int sx = x1, sy = y1;

    while(sy >= 1)vis[sx][sy] = true, sy--;
    sy = y1;
    while(sy <= 8)vis[sx][sy] = true, sy++;
    sy = y1;
    while(sx >= 1)vis[sx][sy] = true, sx--;
    sx = x1;
    while(sx <= 8)vis[sx][sy] = true, sx++;

    sx = x2, sy = y2;

    for(int i = 0; i < 8; i++) {
        int tx = sx + fx[i];
        int ty = sy + fy[i];
        if(tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8)vis[tx][ty] = true;
    }

    int Ans = 0;

    for(int i = 1; i <= 8; i++) {
        for(int j = 1; j <= 8; j++) {
            if(vis[i][j])continue;
            bool isValid = true;
            for(int k = 0; k < 8; k++) {
                int tx = i + fx[k];
                int ty = j + fy[k];
                if(tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8) {
                    if(tx == x1 && ty == y1)isValid = false;
                    if(tx == x2 && ty == y2)isValid = false;
                }
            }
            Ans += isValid;
        }
    }

    cout << Ans << endl;




    return 0;
}

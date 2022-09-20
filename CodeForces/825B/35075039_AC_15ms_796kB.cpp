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
char c[12][12];

int fx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int fy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool check(int sx, int sy) {
    int cntHorizontal = 0, cntVartical = 0;
    int diagonal1 = 0, diagonal2 = 0;
    int tx = sx, ty = sy;
    while(ty + 1 <= n && c[tx][ty + 1] == 'X')++cntHorizontal, ++ty;
    ty = sy;
    while(ty - 1 >= 1 && c[tx][ty - 1] == 'X')++cntHorizontal, --ty;
    tx = sx, ty = sy;
    while(tx + 1 <= n && c[tx + 1][ty] == 'X')++cntVartical, ++tx;
    tx = sx;
    while(tx - 1 >= 1 && c[tx - 1][ty] == 'X')++cntVartical, --tx;
    tx = sx, ty = sy;
    while(tx + 1 <= n && ty + 1 <= n && c[tx + 1][ty + 1] == 'X')++diagonal1, ++tx, ++ty;
    tx = sx, ty = sy;
    while(tx - 1 >= 1 && ty - 1 >= 1 && c[tx - 1][ty - 1] == 'X')++diagonal1, --tx, --ty;
    tx = sx, ty = sy;
    while(tx - 1 >= 1 && ty + 1 <= n && c[tx - 1][ty + 1] == 'X')++diagonal2, --tx, ++ty;
    tx = sx, ty = sy;
    while(tx + 1 <= n && ty - 1 >= 1 && c[tx + 1][ty - 1] == 'X')++diagonal2, ++tx, --ty;
    return (cntHorizontal >= 4 || cntVartical >= 4 || diagonal1 >= 4 || diagonal2 >= 4);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    n = 10;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(c[i][j] == 'O')continue;
            bool ok = check(i, j);
            if(ok) {
                cout << "YES" << endl;
                exit(0);
            }
        }
    }

    cout << "NO" << endl;


    return 0;
}

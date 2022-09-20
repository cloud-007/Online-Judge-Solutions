/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[16];
bool vis[16][16];

int fx[] = {1, 1, -1, -1, 0, 0, 1, -1};
int fy[] = {-1, 1, 1, -1, 1, -1, 0, 0};

bool valid(int tx, int ty) {
    return (tx >= 1 && ty >= 1 && tx <= 8 && ty <= 8);
}

bool check(int sx, int sy, int idx) {
    int tx = sx + fx[idx];
    int ty = sy + fy[idx];
    bool ret = true;
    if(valid(tx, ty)) {
        if(vis[tx][ty])return ret = false;
        else ret &= check(tx, ty, idx);
    }
    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= 8; i++) {
            cin >> a[i];
            vis[i][a[i]] = true;
        }
        bool ok = true;
        for(int i = 1; i <= 8; i++) {
            for(int j = 0; j < 8; j++) {
                ok &= check(i, a[i], j);
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }


    return 0;
}

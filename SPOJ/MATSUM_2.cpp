/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1050 + 5;
int tc, n, casee = 1, a[N];
ll bit[N][N];

void update(int x, int y, int val) {
    for(; x < N; x += x & -x)
        for(int j = y; j < N; j += j & -j)
            bit[x][j] += val;
}

ll get(int x, int y) {
    ll ans = 0;
    for(; x > 0 ; x -= x & -x)
        for(int j = y ; j > 0 ; j -= j & -j)
            ans += bit[x][j];
    return ans ;
}

ll get(int x1, int y1, int x2, int y2) {
    return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1
            - 1) + get(x1 - 1, y1 - 1) ;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                bit[i][j] = 0;
            }
        }
        while(true) {
            string s; cin >> s;
            if(s == "END")break;
            if(s == "SET") {
                int x, y, val;
                cin >> x >> y >> val;
                ++x; ++y;
                update(x, y, -get(x, y, x, y));
                update(x, y, val);
            } else {
                int x, y, x1, y1; cin >> x >> y >> x1 >> y1;
                ++x; ++y; ++x1; ++y1;
                cout << get(x, y, x1, y1) << endl;
            }
        }
    }


    return 0;
}

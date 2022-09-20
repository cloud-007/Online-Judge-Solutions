/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1030;
int tc, n, a[sz], x, y, val;
ll bit[sz][sz];

void update(int x, int y, int val) {
    for(; x < sz; x += x & -x)
        for(int j = y; j < sz; j += j & -j)
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

string s;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n;
        memset(bit, 0, sizeof bit);
        while(cin >> s && s != "END") {
            if(s == "SET") {
                cin >> x >> y >> val;
                x++, y++;
                ll now = get(x, y, x, y);
                update(x, y, -now);
                update(x, y, val);
            } else {
                int x1, y1;
                cin >> x >> y >> x1 >> y1;
                x++, y++, x1++, y1++;
                cout << get(x, y, x1, y1) << endl;
            }
        }
    }


    return 0;
}

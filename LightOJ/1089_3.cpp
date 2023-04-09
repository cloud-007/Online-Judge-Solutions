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

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int q; cin >> n >> q;
        vector < int > x, y;
        while(n--) {
            int c, d; cin >> c >> d;
            x.push_back(c);
            y.push_back(d);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        cout << "Case " << casee++ << ":" << endl;
        while(q--) {
            int c; cin >> c;
            auto l = upper_bound(x.begin(), x.end(), c) - x.begin();
            auto r = lower_bound(y.begin(), y.end(), c) - y.begin();
            cout << abs(l - r) << endl;
        }
    }


    return 0;
}

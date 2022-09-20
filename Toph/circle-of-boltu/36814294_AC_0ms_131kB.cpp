/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, casee = 1, x[N], y[N];

ll cnt(ll x, ll y) {
    return (y - x) * (y - x);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        ll mx = -1e18;
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> x[i] >> y[i];

        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                ll cur = cnt(y[j], y[i]) + cnt(x[j], x[i]);
                mx = max(mx, cur);
            }
        }

        cout << "Case " << casee++ << ": " << mx << endl;
    }


    return 0;
}

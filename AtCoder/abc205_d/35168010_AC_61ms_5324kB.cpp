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
vector < pair < ll, ll >> vp;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int q; cin >> n >> q;
    ll last = 0;
    while(n--) {
        ll x; cin >> x;
        if(x - last > 1) {
            if(vp.empty())vp.push_back({x - 1, 1});
            else {
                ll diff = (x - last) - 1;
                vp.push_back({vp.back().F + diff, last + 1});
            }
        }
        last = x;
    }

    vp.push_back({1e18 + 2e5, last + 1});

    while(q--) {
        ll k; cin >> k;
        pair < ll, ll > x = {k, 0ll};
        auto cur = lower_bound(vp.begin(), vp.end(), x) - vp.begin();
        // cout << vp[cur].F<<" "<<vp[cur].S<<endl;
        if(cur == 0) {
            cout << vp[cur].S + k - 1 << endl;
        } else {
            ll diff = k - vp[cur - 1].F;
            cout << vp[cur].S + diff - 1 << endl;
        }
    }


    return 0;
}

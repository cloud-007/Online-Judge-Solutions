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

ll findTrailingZeroes(ll n) {
    if(n < 0)return -1;
    ll cnt = 0;
    for(ll i = 5; i <= n; i *= 5)cnt += n / i;
    return cnt;
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
        ll l = 1, r = 1e18, mid = -1, Ans = -1;
        while(l <= r) {
            mid = (l + r) >> 1;
            ll cur = findTrailingZeroes(mid);
            if(cur == n) {
                Ans = mid;
                r = mid - 1;
            } else if(cur < n)l = mid + 1;
            else r = mid - 1;
        }
        cout << "Case " << casee++ << ": " << (~Ans ? to_string(Ans) : "impossible") << endl;
    }


    return 0;
}

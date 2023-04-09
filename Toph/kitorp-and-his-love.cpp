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

ll check(ll n) {
    ll count = 0;
    for(ll i = 5; n / i >= 1; i *= 5)count += n / i;
    return count;
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
        ll l = 1, r = 1e18, Ans = -1;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            ll cur = check(mid);
            if(cur < n) l = mid + 1;
            else if(cur == n) {
                Ans = mid;
                r = mid - 1;
            } else r = mid - 1;
        }
        cout <<"Case "<<casee++<<": "<< (~Ans ? to_string(Ans) : "Go Home! You are drunk!") << endl;
    }


    return 0;
}

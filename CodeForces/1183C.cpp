/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
ll tc, n, k, a, b;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> k >> n >> a >> b;
        ll ans = -1, l = 0, r = k;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if((a * mid) + ((n - mid)*b) < k) {
                l = mid + 1;
                ans = mid;
            } else r = mid - 1;
        }
        cout << min(ans, n) << endl;
    }


    return 0;
}

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

ll check(int mid) {
    ll mx = 0;
    for(int i = 1; i <= n; i++) {
        if(i > 1) {
            int now = a[i], pre = a[i - 1];
            if(now == -1)now = mid;
            if(pre == -1)pre = mid;
            mx = max(mx, (ll) abs(now - pre));
        }
    }
    return mx;
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
        for(int i = 1; i <= n; i++)cin >> a[i];
        int l = 0, r = 1e9, cnt = 100;
        ll Ans = 1e18;
        while(cnt--) {
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;

            if(check(mid1) < check(mid2))r = mid2;
            else l = mid1;
        }
        int id = l;
        while(l <= r) {
            ll cur = check(l);
            if(cur < Ans) {
                Ans = cur; id = l;
            }
            ++l;
        }
        cout << Ans << " " << id << endl;
    }


    return 0;
}

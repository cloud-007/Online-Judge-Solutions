/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, casee = 1, h[N], c[N];

ll check(int mid) {
    ll ret = 0;
    for(int i = 1; i <= n; i++) {
        ret += abs(mid - h[i]) * c[i];
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
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> h[i];
        for(int i = 1; i <= n; i++)cin >> c[i];

        ll l = 1, r = *max_element(h + 1, h + n + 1);
        int cnt = 100;
        while(cnt--) {
            ll mid1 = l + (r - l) / 3;
            ll mid2 = r - (r - l + 1) / 3;

            ll Ans1 = check(mid1);
            ll Ans2 = check(mid2);

            if(Ans1 < Ans2) r = mid2;
            else l = mid1;

        }

        ll Ans = 1e18;
        while(l <= r) {
            Ans = min(Ans, check(l++));
        }

        cout << Ans << endl;

    }


    return 0;
}

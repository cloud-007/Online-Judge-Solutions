/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        int h; cin >> n >> h;
        for(int i = 1; i <= n; i++)cin >> a[i];
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        ll l = 1, r = h, Ans;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            ll sum = mid * a[1] + mid * a[2];
            if(sum >= h) {
                Ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if(a[1] * Ans + (a[2] * (Ans - 1)) >= h)Ans = Ans * 2 - 1;
        else Ans = Ans * 2;
        cout << Ans << endl;
    }


    return 0;
}

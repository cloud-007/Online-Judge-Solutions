/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, x, k, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n  >> x  >> k;
    ll Ans = 0;
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        ll p = (a[i] - 1) / x + k;
        Ans += lower_bound(a, a + n, (p + 1) * x) - lower_bound(a, a + n, max(1ll * a[i], p * x));
    }

    cout << Ans << endl;


    return 0;
}

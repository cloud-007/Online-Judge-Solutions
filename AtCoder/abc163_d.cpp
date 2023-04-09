/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5, mod = 1e9 + 7;
ll n, k, Ans = 1;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> k;

    for(int i = k; i <= n; i++) {
        ll l = (ll)i * (ll)(i - 1) / 2;
        ll r = (n * (n + 1) / 2) - ((n - i) * (n - i + 1) / 2);
        Ans += (r - l) + 1;
        Ans %= mod;
    }

    cout << Ans << endl;


    return 0;
}

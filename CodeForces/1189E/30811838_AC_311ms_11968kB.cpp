/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
ll n, p, k;

ll top4(ll x, ll k) {
    return x % k * x % k * x % k * x % k;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n >> k >> p;
    map < ll, ll > mp;
    ll Ans = 0;
    for(int i = 1; i <= n; i++) {
        ll a; cin >> a;
        ll look = (top4(a, k) - p * a % k + k) % k;
        if(mp.count(look))Ans += mp[look];
        mp[look]++;
    }

    cout << Ans << endl;


    return 0;
}

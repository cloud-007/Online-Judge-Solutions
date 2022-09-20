/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const ll mod = 1000003, sz = 1e6 + 5;
ll tc, n, k, fact[sz], casee = 1;

void init() {
    fact[0] = 1;
    fact[1] = 1;
    fact[2] = 2;
    for(int i = 3; i <= sz; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll bigmod(ll a, ll p, ll m) {
    ll res = 1;
    ll x = a;
    while(p) {
        if(p & 1)res = (res * x) % m;
        x = (x * x) % m;
        p /= 2;
    }
    return res;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    // cloud_007;
    init();
    cin >> tc;
    while(tc--) {
        cin >> n >> k;
        ll val = (fact[n - k] % mod * fact[k] % mod) % mod;
        val = bigmod(val, 1000001, mod) % mod;
        cout << "Case " << casee++ << ": " << (fact[n]*val) % mod << endl;
    }

    return 0;
}



/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5, N = 1e5 + 5;
int tc, n, q, a[sz];
vector<ll>  primes;

void divisor(ll x) {
    int sq = sqrt(x);
    for(int i = 1; i <= sq; i++) {
        if(x % i)continue;
        primes.push_back(i);
        if(i != x / i)primes.push_back(x / i);
    }
}

ll rec(ll x, ll y) {
    if(y == 0)return 0;
    ll g = gcd(x, y), mx = 0;
    for(auto i : primes) {
        ll v = lcm(i, g);
        ll temp = (y / v) * v;
        if(temp == y)temp -= v;
        if(gcd(x, temp) == g)continue;
        mx = max(mx, temp);
    }
    ll dif = y - mx;
    ll moves = dif / g;
    return moves + rec(x, mx);
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    ll x, y; cin >> x >> y;
    divisor(x);
    cout << (rec(x, y)) << endl;

    return 0;
}

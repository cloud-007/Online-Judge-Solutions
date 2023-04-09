/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, casee = 1, a[N];

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
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    ll x, y;
    while(cin >> x >> y >> n) {
        cout << bigmod(x, y, n) << endl;
    }


    return 0;
}

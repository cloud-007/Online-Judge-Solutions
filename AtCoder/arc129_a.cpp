/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll n, l, r;

ll count(ll bit, ll l, ll r) {
    ll mn = (1ll << bit);
    ll mx = (mn * 2ll) - 1;
    mn = max(mn, l);
    mx = min(mx, r);
    if(mn > mx)return 0;
    return mx - mn + 1;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> l >> r;

    ll Ans = 0;

    for(int i = 60; i >= 0; i--) {
        if(n & (1ll << i))Ans += count(i, l, r);
    }

    cout << Ans << endl;


    return 0;
}

/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll a, b, c;

ll calc(ll a, ll b, ll c) {
    ll Ans = 0;
    if(b < a) {
        Ans += a - b; b = a;
    }

    if(c < b) {
        Ans += b - c; c = b;
    }

    ll diff = c - a;
    if(diff & 1)++Ans, ++c, ++diff;
    diff /= 2;
    if(b - a <= diff)Ans += diff - (b - a);
    else {
        ll addValue = b - a;
        Ans += addValue - (c - b);
    }
    return Ans;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    ll Ans = 0, Ans1 = 0;
    cin >> a >> b >> c;
    ll x = a, y = b, z = c;
    Ans = calc(a, b, c);
    Ans = min(Ans, calc(c, b, a));

    cout << Ans << endl;



    return 0;
}

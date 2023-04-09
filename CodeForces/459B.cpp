/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    map < int, int > mp;
    int mn = INT_MAX, mx = 0;
    while(n--) {
        int x; cin >> x;
        mp[x]++;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    cout << mx - mn << " " << (mx != mn ? (ll)mp[mx] * (ll)mp[mn] : (ll)(mp[mx] * (ll)(mp[mx] - 1)) / 2) << endl;


    return 0;
}

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
    ll x, y, z; cin >> x >> y >> z;
    ll mx = min({x, y, z});
    ll Ans = mx + (x - mx) / 3 + (y - mx) / 3 + (z - mx) / 3;
    --mx;
    mx = max(mx, 0ll);
    Ans = max(Ans, mx + (x - mx) / 3 + (y - mx) / 3 + (z - mx) / 3);
    --mx;
    mx = max(mx, 0ll);
    Ans = max(Ans, mx + (x - mx) / 3 + (y - mx) / 3 + (z - mx) / 3);
    --mx;
    mx = max(mx, 0ll);
    Ans = max(Ans, mx + (x - mx) / 3 + (y - mx) / 3 + (z - mx) / 3);
    --mx;
    mx = max(mx, 0ll);
    Ans = max(Ans, mx + (x - mx) / 3 + (y - mx) / 3 + (z - mx) / 3);

    cout << Ans << Endl;


    return 0;
}

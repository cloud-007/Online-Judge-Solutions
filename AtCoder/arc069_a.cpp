/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5, mod = 1e9 + 7;
ll n, m;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m;
    ll y = n * 2, ans = min(n, m / 2);
    m -= min(m, y);
    if(m) {
        ans += (m / 4);
    }

    cout << ans << endl;


    return 0;
}

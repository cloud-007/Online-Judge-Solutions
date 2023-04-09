/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, a[N];
map < ll, bool > mp;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;

    for(ll i = 1 ; i * i * i <= 1e12; i++) {
        ll cnt = i * i * i;
        mp[cnt] = true;
    }
    cin >> tc;
    while(tc--) {
        cin >> n;
        bool ok = false;
        for(ll i = 1; i * i * i <= n; i++) {
            ll now = i * i * i;
            ll lagbe = n - now;
            if(mp[now] && mp[lagbe]) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }


    return 0;
}

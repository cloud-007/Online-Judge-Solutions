/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

ll tc, n, m, k;
map < ll, int > mp;
map < ll, bool> vis;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> m >> n >> k;

        ll ans = 0;

        for(ll i = m; i <= n; i++) {
            int even = 0, odd = 0;
            if(vis[i]) {
                if(mp[i] == k)ans++;
                continue;
            }
            for(int j = 63; j >= 0; j--) {
                if(i & (1ll << j)) {
                    if(j & 1)even++;
                    else odd++;
                }
            }
            vis[i] = true;
            mp[i] = abs(even - odd);
            if(abs(even - odd) == k)ans++;
        }
        cout << ans << endl;
    }


    return 0;
}

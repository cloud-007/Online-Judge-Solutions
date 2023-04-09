/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, h[sz], c[sz];
vector < pair < int, int >> vp;
ll cost[sz];

int main() {
#ifdef cloud007
    freopen("out.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> h[i];
        for(int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        ll Ans = 1e18;
        for(int i = 1; i <= n; i++) {
            ll cur = 0;
            for(int j = 1; j <= n; j++) {
                cur += abs(h[i] - h[j]) * c[j];
            }
            Ans = min(Ans, cur);
        }
        cout << Ans << endl;
    }


    return 0;
}

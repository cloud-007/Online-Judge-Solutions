/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], b[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)cin >> a[i];
    for(int i=1; i<=n; i++)cin >> b[i];

    vector < int > perm;
    for(int i=n; i>=1; i--)perm.push_back(i);

    ll ret = 1e18;

    for(int i=1; i<=50000; i++) {
        random_shuffle(perm.begin(), perm.end());

        ll fri = 0, Ans = 0;

        for(auto u: perm) {
            Ans += b[u];
            ll use = min((ll)a[u], fri);
            ll need = max(0ll, (ll)a[u]-fri);
            fri-=use;
            Ans += need;
            fri += b[u];
        }

        ret = min(ret, Ans);

    }

    cout << ret << endl;


    return 0;
}

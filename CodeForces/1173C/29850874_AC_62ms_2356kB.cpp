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
int tc, n, a[sz], mp[sz], b[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i], mp[a[i]] = 0;
    for(int i = 1; i <= n; i++)cin >> b[i], mp[b[i]] = i;

    int i, j;

    if(mp[1]) {
        for(i = 2; mp[i] == mp[1] + i - 1; i++);
        if(mp[i - 1] == n) {
            for(j = i; j <= n && mp[j] <= j - i; j++);
            if(j > n) {
                cout << n - i + 1 << endl;
                exit(0);
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++)ans = max(ans, mp[i] - i + 1 + n);

    cout << ans << endl;


    return 0;
}

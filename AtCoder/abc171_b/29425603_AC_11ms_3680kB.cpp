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
int tc, n, a[sz], k;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    ll Ans = 0;
    for(int i = 1; i <= k; i++) {
        Ans += a[i];
    }
    cout << Ans << endl;

    return 0;
}

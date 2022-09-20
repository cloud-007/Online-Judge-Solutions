/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int tc, n, a[sz];
ll dp[sz], k, sum = 0, ans = 0;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1, j = 1; j <= n; j++) {
        sum += a[j];
        if(sum >= k) {
            ans += (n - j + 1);
            while(i <= j) {
                sum -= a[i];
                i++;
                if(sum >= k)ans += (n - j + 1);
                else break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

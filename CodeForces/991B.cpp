/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define pi acos(-1.0)

int tc, n, a[105], ans = 0, sum = 0;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i], sum += a[i];
    sort(a + 1, a + n + 1);
    //reverse(a + 1, a + n + 1);

    for(int i = 1; i <= n; i++) {
        if(round((double)sum / n) != 5) {
            sum -= a[i];
            ans++;
            sum += 5;
        }
    }

    cout << ans << endl;

    return 0;
}

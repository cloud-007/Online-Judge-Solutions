/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

int n, k, ans = 0, a[105], mp[105];

int main() {
#ifdef cloud007
    freopen("out.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    while(a[1] < k) {
        ans++;
        for(int i = 1; i <= n; i++) {
            if(a[i] < k) {
                if(!mp[a[i]]) {
                    mp[a[i]] = 1;
                    a[i] += 1;
                }
            } else break;
        }
        memset(mp, 0, sizeof mp);
        sort(a + 1, a + n + 1);
    }
    cout << ans << endl;

    return 0;
}

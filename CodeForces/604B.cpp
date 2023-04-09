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
int n, k, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> k;
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i % 2 == 0 && (k - i / 2 <= n - i))mx = i;
    }
    int ans = 0;
    for(int i = n; i > mx; i--)ans = max(ans, a[i]);
    for(int i = 1; i <= mx; i++, mx--) {
        ans = max(ans, a[i] + a[mx]);
    }
    cout << ans << endl;


    return 0;
}

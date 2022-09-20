/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

double c, l, r, ans = 0;
int tc;

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> c >> tc;
    while(tc--) {
        cin >> l >> r;
        ans += l * r;
    }
    cout << fixed << setprecision(7) << ans*c << endl;

    return 0;
}

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
int tc, n, a[sz];

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    ll i = 1, j = n, x = 0, y = 0;
    bool turn = 1;
    while(i <= j) {
        if(turn)x += a[j--];
        else y += a[i++];
        turn ^= 1;
    }

    ll ans = x * x + y * y;

    cout << ans << endl;


    return 0;
}

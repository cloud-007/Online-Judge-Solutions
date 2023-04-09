/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 21;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];

    ll Ans = 1e18;

    for(int mask = 0; mask < (1 << n) ; mask++) {
        ll x = 0, y = 0;
        for(int j = 0; j < n; j++) {
            if(mask & (1 << j))x += a[j];
            else y += a[j];
        }
        Ans = min(Ans, abs(x - y));
    }

    cout << Ans << endl;


    return 0;
}

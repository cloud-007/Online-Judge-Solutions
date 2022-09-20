/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5, mod = 1e9 + 7;
ll tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    ll sum = 0, one = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i]; sum %= mod;
    }
    ll Ans = 0;
    for(int i = 1; i <= n; i++) {
        sum -= a[i];
        if(sum < 0)sum += mod;
        Ans += a[i] * sum;
        Ans %= mod;
    }
    cout << Ans << endl;


    return 0;
}

/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5, mod = 1e9 + 7;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int k; cin >> n >> k;
        ll Ans = n; --k;
        while(k--) {
            Ans *= n;
            Ans %= mod;
        }
        cout << (Ans + mod) % mod << endl;
    }


    return 0;
}

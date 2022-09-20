/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5, mod = 998244353;
int tc, n, casee = 1, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int zero = 1, one = 1;
    ll Ans = 1;
    cin >> n;
    for(int i = 2; i < n; i++) {
        Ans = zero + one;
        Ans %= mod;
        zero = one;
        one = Ans;
    }
    cout << Ans << endl;


    return 0;
}

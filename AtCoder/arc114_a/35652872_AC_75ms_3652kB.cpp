/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];

vector < int > primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47});

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    ll Ans = 1e18;
    for(int i = 0; i <= (1 << 15); i++) {
        ll ans = 1;
        for(int j = 0; j < 15; j++) {
            if(i & (1 << j)) {
                ans *= primes[j];
            }
        }
        bool found = true;
        for(int j = 1; j <= n; j++) {
            found &= (__gcd(ans, (ll)a[j]) > 1);
        }
        if(found)Ans = min(Ans, ans);
    }

    cout << Ans << endl;


    return 0;
}

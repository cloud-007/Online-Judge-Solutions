/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], pref[N], suff[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i == 1) {
            pref[i] = a[i]; continue;
        }
        pref[i] = __gcd(pref[i - 1], a[i]);
    }

    for(int i = n; i >= 1; i--) {
        if(i == n) {
            suff[i] = a[i]; continue;
        }
        suff[i] = __gcd(suff[i + 1], a[i]);
    }

    int Ans = 1;

    for(int i = 1; i <= n; i++) {
        if(i + 1 <= n && i - 1 >= 1) {
            Ans = max(Ans, __gcd(pref[i - 1], suff[i + 1]));
        } else if(i + 1 <= n) {
            Ans = max(Ans, suff[i + 1]);
        } else if(i - 1 >= 1) {
            Ans = max(Ans, pref[i - 1]);
        }
    }

    cout << Ans << endl;

    return 0;
}

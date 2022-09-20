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

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    ll s, p; cin >> s >> p;
    for(ll i = 1; i <= min((ll)1e6, p); i++) {
        if(p % i == 0) {
            if(i + (p / i) == s) {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;


    return 0;
}

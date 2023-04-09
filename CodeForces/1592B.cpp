/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], b[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        int k; cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            if(i - k < 1 && i + k > n) {
                ok &= a[i] == b[i];
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }


    return 0;
}

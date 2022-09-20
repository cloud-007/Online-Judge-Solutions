/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 35 + 5;

int tc, n, casee = 1, a[N];
ll C[N + 1][N + 1], fact[N];

void initTriangle() {
    C[0][0] = fact[0] = 1;
    for(int n = 1; n < N; ++n) {
        C[n][0] = C[n][n] = 1;
        for(int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        fact[n] = fact[n - 1] * n;
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    initTriangle();

    cin >> tc;
    while(tc--) {
        int k; cin >> n >> k;
        cout << "Case " << casee++ << ": " << C[n][k] * C[n][k] * fact[k] << endl;
    }


    return 0;
}

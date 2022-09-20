/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 35 + 5;
int tc, n, casee = 1, a[N];
ll c[N][N], fact[N];

void initTriangle() {
    c[0][0] = fact[0] = 1;
    for(int i = 1; i < N; i++) {
        c[i][0] = c[i][i] = 1;
        for(int k = 1; k < i; k++) {
            c[i][k] = c[i - 1][k - 1] + c[i - 1][k];
        }
        fact[i] = fact[i - 1] * i;
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    initTriangle();
    cin >> tc;
    while(tc--) {
        int k; cin >> n >> k;
        cout << "Case " << casee++ << ": " << c[n][k] * c[n][k] * fact[k] << endl;
    }


    return 0;
}

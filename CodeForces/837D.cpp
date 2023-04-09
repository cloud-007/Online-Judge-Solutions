/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 6e3 + 5;
int tc, n, k, pw2[N], pw5[N], dp[N][N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n  >> k;
    for(int i = 1; i <= n; ++i) {
        ll x; cin >> x;
        while(x % 2 == 0)x /= 2, pw2[i]++;
        while(x % 5 == 0)x /= 5, pw5[i]++;
    }

    memset(dp, -1, sizeof dp);

    dp[0][0] = 0;

    for(int i = 1; i <= n; ++i) {
        for(int taken = k - 1; taken >= 0; --taken) {
            for(int cnt5 = 0; cnt5 < N; ++cnt5) {
                if(dp[taken][cnt5] >= 0) {
                    dp[taken + 1][cnt5 + pw5[i]] = max(dp[taken + 1][cnt5 + pw5[i]], dp[taken][cnt5] + pw2[i]);
                }
            }
        }
    }

    int Ans = 0;

    for(int i = 0; i < N; i++) {
        Ans = max(Ans, min(dp[k][i], i));
    }

    cout << Ans << endl;


    return 0;
}

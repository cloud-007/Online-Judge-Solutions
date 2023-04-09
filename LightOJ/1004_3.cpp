/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 200 + 5;
int tc, n, casee = 1, a[N][N], dp[N][N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                cin >> a[i][j];
            }
        }
        for(int i = n + 1; i < n * 2; i++) {
            for(int j = 1; j <= (n * 2) - i; j++) {
                cin >> a[i][j];
            }
        }
        dp[1][1] = a[1][1];
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i][j] = a[i][j] + dp[i - 1][j];
                if(j - 1 >= 1)dp[i][j] = max(dp[i][j], a[i][j] + dp[i - 1][j - 1]);
            }
        }
        for(int i = n + 1; i < n * 2; i++) {
            for(int j = 1; j <= (n * 2) - i; j++) {
                dp[i][j] = a[i][j] + dp[i - 1][j];
                if(j + 1 <= (n * 2) - i + 1) {
                    dp[i][j] = max(dp[i][j], a[i][j] + dp[i - 1][j + 1]);
                }
            }
        }
        cout << "Case " << casee++ << ": " << dp[(n * 2) - 1][1] << endl;
    }


    return 0;
}

/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 300 + 5;
int tc, n, casee = 1, a[N][N], b[N][N], dp[N][N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n;

        memset(dp, 0, sizeof dp);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                cin >> a[i][j];
                if(i == 1 && j == 1)dp[i][j] = a[i][j];
                if(i != j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
                } if(j != 1) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
                }
            }
        }

        int id = n + 1;

        for(int i = n - 1; i >= 1; i--) {
            for(int j = 1; j <= i; j++) {
                cin >> b[i][j];
                dp[id][j] = max(dp[id][j], dp[id - 1][j] + b[i][j]);
                dp[id][j] = max(dp[id][j], dp[id - 1][j + 1] + b[i][j]);
            }
            id++;
        }

        cout << "Case " << casee++ << ": " << dp[n * 2 - 1][1] << endl;

    }


    return 0;
}

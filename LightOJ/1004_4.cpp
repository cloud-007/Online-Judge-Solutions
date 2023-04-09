/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 200 + 5;
int tc, n, casee = 1, a[N][N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= 2 * n - 1; i++) {
            if(i <= n) {
                for(int j = 1; j <= i; j++) {
                    cin >> a[i][j];
                    if(i > 1) {
                        a[i][j] = max(a[i][j] + a[i - 1][j], a[i][j] + a[i - 1][j - 1]);
                    }
                }
            } else {
                for(int j = 1; j <= 2 * n - i; j++) {
                    cin >> a[i][j];
                    a[i][j] = max(a[i][j] + a[i - 1][j], a[i][j] + a[i - 1][j + 1]);
                }
            }
        }

        cout << "Case " << casee++ << ": " << a[2 * n - 1][1] << Endl;

        memset(a, false, sizeof a);


    }


    return 0;
}

/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 20 + 1;
int tc, n, casee = 1, a[N][N];
ll dp[N][(1 << N)];

ll rec(int idx, int mask) {
    if(idx >= n)return 1;
    ll &ret = dp[idx][mask];
    if(~ret)return ret;
    ret = 0;
    for(int i = 0; i < n; i++) {
        if(mask & (1 << i))continue;
        if(a[idx][i])ret += rec(idx + 1, mask | (1 << i));
    }
    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<(1<<n);j++)
                dp[i][j] = -1;
        }
        cout << rec(0, 0) << endl;
    }


    return 0;
}

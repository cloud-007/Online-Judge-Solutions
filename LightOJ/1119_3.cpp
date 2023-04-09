/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 12 + 5;
int tc, n, casee = 1, dp[1 << N];
vector < int > v[N];

int rec(int mask) {
    if(mask == (1 << n) - 1)return 0;
    int &ret = dp[mask];
    if(~ret)return ret;
    ret = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(mask & (1 << i))continue;
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(mask & 1 << j)sum += v[i][j];
        }
        sum += v[i][i] + rec(mask | (1 << i));
        ret = min(ret, sum);
    }

    return ret;

}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        memset(dp, -1, sizeof dp);

        for(int i = 0; i < N; i++)v[i].clear();

        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= n; j++) {
                int x; cin >> x;
                v[i].push_back(x);
            }
        }

        cout << "Case " << casee++ << ": " << rec(0) << endl;

    }


    return 0;
}

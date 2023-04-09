/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 105;
int tc, n, w, k, x, y, dp[sz][sz][sz], casee = 1;
vector < pair < int, int >> vp;

int rec(int idx, int pre, int k) {
    if(idx == n)return 0;
    if(~dp[idx][pre][k])return dp[idx][pre][k];
    int &ret = dp[idx][pre][k];
    ret = 0;
    if(pre == 103 && k) {
        ret = max(1 + rec(idx + 1, idx, k - 1), rec(idx + 1, pre, k));
    } else {
        if(vp[idx].F - vp[pre].F <= w) {
            ret = 1 + rec(idx + 1, pre, k);
        } else if(k) {
            ret = max(1 + rec(idx + 1, idx, k - 1), rec(idx + 1, pre, k));
        }
    }
    return dp[idx][pre][k] = ret;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n >> w >> k;
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            vp.push_back({y, x});
        }
        sort(vp.begin(), vp.end());
        memset(dp, -1, sizeof dp);

        cout << "Case " << casee++ << ": " << rec(0, 103, k) << endl;


        vp.clear();
    }


    return 0;
}

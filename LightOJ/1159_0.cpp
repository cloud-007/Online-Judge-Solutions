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
int tc, n, m, k, dp[55][55][55], casee = 1;
string a, b, c;

int rec(int idx_a, int idx_b, int idx_c) {
    if(idx_a >= n || idx_b >= m || idx_c >= k)return 0;
    int &ret = dp[idx_a][idx_b][idx_c];
    if(~ret)return ret;
    ret = 0;
    if(a[idx_a] == b[idx_b] && a[idx_a] == c[idx_c]) {
        ret = 1 + rec(idx_a + 1, idx_b + 1, idx_c + 1);
    } else {
        ret = rec(idx_a + 1, idx_b, idx_c);
        ret = max(ret, rec(idx_a, idx_b + 1, idx_c));
        ret = max(ret, rec(idx_a, idx_b, idx_c + 1));
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
        cin >> a >> b >> c;
        n = a.size(), m = b.size(), k = c.size();
        memset(dp, -1, sizeof dp);
        cout << "Case " << casee++ << ": " << rec(0, 0, 0) << endl;
    }


    return 0;
}

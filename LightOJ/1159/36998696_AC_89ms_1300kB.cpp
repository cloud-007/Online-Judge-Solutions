/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 50 + 5;
int tc, a, b, c, casee = 1, dp[N][N][N];
string x, y, z;

int rec(int i, int j, int k) {
    if(i >= a || j >= b || k >= c)return 0;
    int &ret = dp[i][j][k];
    if(~ret)return ret;
    ret = 0;
    if(x[i] == y[j] && y[j] == z[k])ret += 1 + rec(i + 1, j + 1, k + 1);
    ret = max({ret, rec(i + 1, j, k), rec(i, j + 1, k), rec(i, j, k + 1)});
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
        cin >> x >> y >> z;
        a = x.size(); b = y.size(); c = z.size();
        memset(dp, -1, sizeof dp);
        cout << "Case " << casee++ << ": " << rec(0, 0, 0) << endl;
    }


    return 0;
}

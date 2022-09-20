/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, dp[105][105];
string s;

int rec(int i, int j) {
    if(i >= j)return 0;
    int &ret = dp[i][j];
    if(~ret)return ret;
    ret = 0;
    if(s[i] == s[j])ret += rec(i + 1, j - 1);
    else {
        ret = 1 + min(rec(i + 1, j), rec(i, j - 1));
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
        cin >> s;
        n = s.size(); s = "#" + s;
        memset(dp, -1, sizeof dp);
        cout << "Case " << casee++ << ": " << rec(1, n) << endl;
    }


    return 0;
}

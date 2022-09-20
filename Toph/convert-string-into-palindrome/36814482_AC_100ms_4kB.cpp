/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, casee = 1, a[N], dp[N][N];
string s;

int rec(int l, int r) {
    if(l >= r)return 0;
    int &ret = dp[l][r];
    if(~ret)return ret;
    ret = 0;
    if(s[l] == s[r]) {
        ret = rec(l + 1, r - 1);
    } else {
        ret = 1 + min(rec(l + 1, r), rec(l, r - 1));
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
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < s.size(); j++) {
                dp[i][j] = -1;
            }
        }
        cout << "Case " << casee++ << ": " << rec(0, s.size() - 1) << endl;
    }


    return 0;
}

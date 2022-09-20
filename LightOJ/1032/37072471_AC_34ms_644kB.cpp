/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];
ll dp[33][2][2], dp1[33][2];
string s;

ll rec1(int idx, bool isSmall) {
    if(idx >= n)return 1;
    ll &ret = dp1[idx][isSmall];
    if(~ret)return ret;
    ret = 0;
    if(isSmall) {
        int rem = n - idx;
        ret += (1 << rem);
        return ret;
    }
    if(s[idx] == '1') {
        ret += rec1(idx + 1, isSmall);
        ret += rec1(idx + 1, true);
    } else {
        ret += rec1(idx + 1, isSmall);
    }
    return ret;
}

ll rec(int idx, bool pre, bool isSmall) {
    if(idx >= n)return 0;
    ll &ret = dp[idx][pre][isSmall];
    if(~ret)return ret;
    ret = 0;

    if(s[idx] == '1' || isSmall) {
        if(pre) {
            ret += rec1(idx + 1, isSmall);
        }
        ret += rec(idx + 1, true, isSmall);
        ret += rec(idx + 1, false, true);
    } else {
        ret += rec(idx + 1, false, isSmall);
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
        if(n == 0) {
            cout << "Case " << casee++ << ": " << 0 << endl;
            continue;
        }
        s = "";
        for(int i = 30; i >= 0; i--) {
            if(n & (1 << i))s += "1";
            else s += "0";
        }
        int idx = 0;
        while(s[idx] == '0')++idx;
        s = s.substr(idx, s.size());
        n = s.size();
        memset(dp, -1, sizeof dp);
        memset(dp1, -1, sizeof dp1);
        //cout << s << endl;
        cout << "Case " << casee++ << ": " << rec(0, 0, 0) << endl;
    }


    return 0;
}

/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, casee = 1, a[N];
ll dp[N][100];
string s;

ll rec(int idx, int pre) {
    if(idx >= n)return 0;
    ll &ret = dp[idx][pre];
    if(~ret)return ret;
    ret = 0;
    if(pre == 'N' && s[idx] == 'S') {
        ret += rec(idx + 1, 'S');
    } else if(pre == 'S' && s[idx] == 'U') {
        ret += rec(idx + 1, 'U');
    } else if(pre == 'U' && s[idx] == 'P') {
        ret += rec(idx + 1, 'P');
    } else if(pre == 'P' && s[idx] == 'S') {
        ret++;
    }
    ret += rec(idx + 1, pre);
    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> s;
    memset(dp, -1, sizeof dp);

    ll Ans = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'N')Ans += rec(i, 'N');
    }

    cout << Ans << endl;



    return 0;
}

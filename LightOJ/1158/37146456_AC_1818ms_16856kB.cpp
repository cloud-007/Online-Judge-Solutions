/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 11;
int tc, n, casee = 1, d, freq[11];
ll dp[1 << N][1005], fact[15];
string s;

ll rec(int mask, int mod) {
    if(mask == (1 << n) - 1)return (mod == 0);
    ll &ret = dp[mask][mod];
    if(~ret)return ret;
    ret = 0;

    for(int i = 0; i < n; i++) {
        if(mask & (1 << i))continue;
        ret += rec(mask | (1 << i), ((mod * 10) + s[i] - '0') % d);
    }

    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= 10; i++)fact[i] = fact[i - 1] * i;
    cin >> tc;
    while(tc--) {
        cin >> s >> d;
        for(auto i : s)freq[i - '0']++;
        n = s.size();
        memset(dp, -1, sizeof dp);

        ll Ans = rec(0, 0);

        for(int i = 0; i < 10; i++)if(freq[i])Ans /= fact[freq[i]];

        cout << "Case " << casee++ << ": " << Ans << endl;

        memset(freq, false, sizeof freq);
    }


    return 0;
}

/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 100 + 5;
int tc, n, casee = 1, dp[N][2];
string s[N], t[N];
map < string, int > mp;

bool rec(int idx, int pre) {
    if(idx > n)return true;
    int &ret = dp[idx][pre];
    if(~ret)return ret;
    ret = 0;
    if(mp[s[idx]] || mp[t[idx]])return false;
    mp[s[idx]]++;
    ret |= rec(idx + 1, 0);
    mp[s[idx]]--;
    mp[t[idx]]++;
    ret |= rec(idx + 1, 1);
    mp[t[idx]]--;
    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> s[i] >> t[i];

    memset(dp, -1, sizeof dp);

    cout << (rec(1, 0) ? "Yes" : "No") << endl;


    return 0;
}

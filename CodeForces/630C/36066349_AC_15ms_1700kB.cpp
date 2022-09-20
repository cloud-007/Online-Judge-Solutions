/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, casee = 1, dp[60][60][60];

ll rec(int idx, int seven, int eight) {
    if(idx > n)return 0;
    ll &ret = dp[idx][seven][eight];
    if(~ret)return ret;
    ret = 0;
    ret = 2 + rec(idx + 1, seven + 1, eight) + rec(idx + 1, seven, eight + 1);
    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;

    memset(dp, -1, sizeof dp);
    cout << rec(1, 0, 0) << endl;


    return 0;
}

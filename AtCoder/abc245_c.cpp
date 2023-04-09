/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, k = 1, a[N], dp[N][2], b[N];


bool rec(int idx, int pre, int lastVal) {
    if(idx > n)return true;
    int &ret = dp[idx][pre];
    if(~ret)return ret;
    ret = 0;
    if(abs(lastVal - a[idx]) <= k) {
        ret |= rec(idx + 1, 0, a[idx]);
    } if(abs(lastVal - b[idx]) <= k) {
        ret |= rec(idx + 1, 1, b[idx]);
    }
    return (ret > 0);
}


int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++)cin >> b[i];
    memset(dp, -1, sizeof dp);
    if(rec(2, 0, a[1])) {
        cout << "Yes" << endl;
        exit(0);
    }
    if(rec(2, 1, b[1])) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << Endl;
    }


    return 0;
}

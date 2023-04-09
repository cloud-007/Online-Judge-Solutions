/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 105;
int tc, n, casee = 1, a[N], dp[N][200005];

bool rec(int idx, int sum, int sum1, int id) {
    if(idx > n)return sum == sum1;
    int &ret = dp[idx][sum];
    if(~ret)return ret;
    ret = 0;
    if(idx == id) {
        ret |= rec(idx + 1, sum, sum1, id);
        return ret;
    }
    ret |= rec(idx + 1, sum + a[idx], sum1, id);
    ret |= rec(idx + 1, sum, sum1 + a[idx], id);
    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    memset(dp, -1, sizeof dp);
    if(rec(1, 0, 0, -1) == false) {
        cout << 0 << endl;
        exit(0);
    }
    for(int i = n; i >= 1; i--) {
        memset(dp, -1, sizeof dp);
        if(rec(1, 0, 0, i) == false) {
            cout << 1 << endl;
            cout << i << endl;
            exit(0);
        }
    }


    return 0;
}

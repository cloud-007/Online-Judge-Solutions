/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, a, ans[sz], d[sz], dp[sz];

vector < int > x[sz];

void pre() {
    for(int i = 2; i < sz; i++) {
        for(int j = i; j < sz; j += i)
            x[j].push_back(i);
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    pre();
    cin >> n;
    ans[n] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        for(auto j : x[a])dp[a] = max(dp[a], d[j] + 1);
        for(auto j : x[a])d[j] = dp[a];
        ans[i] = max(ans[i - 1], max(ans[i], dp[a]));
    }
    cout << ans[n] << endl;


    return 0;
}

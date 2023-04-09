/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, a[sz], k, mx_id = 0;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] < 0)mx_id = i;
    }

    if(mx_id == 0) {
        cout << a[k] << endl;
        exit(0);
    }

    int i = 1;
    while(i + k <= mx_id)++i;

    ll Ans = 1e18;

    while(i <= mx_id + 1) {
        if(i + k - 1 <= n) {
            if(i + k - 1 <= mx_id)Ans = min(Ans, (ll)abs(a[i]));
            else if(i == mx_id + 1)Ans = min(Ans, (ll)a[i + k - 1]);
            else {
                ll cur = abs(a[i]) * 2 + a[i + k - 1];
                ll cur1 = abs(a[i]) + 2 * a[i + k - 1];
                Ans = min({Ans, cur, cur1});
            }
        }
        ++i;
    }

    cout << Ans << endl;


    return 0;
}

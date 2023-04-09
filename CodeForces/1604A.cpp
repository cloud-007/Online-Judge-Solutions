/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n;
        ll Ans = -INT_MAX;
        for(int i = 1; i <= n; i++) {
            ll x; cin >> x;
            if(x <= i)continue;
            ll cur = abs(i - abs(x));
            Ans = max(Ans, cur);
        }
        if(Ans == -INT_MAX)Ans = 0 ;
        cout << Ans << endl;
    }


    return 0;
}

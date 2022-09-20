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

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int k; cin >> n >> k;
        ll Ans = 0;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            int cur = x % k;
            if(cur == 0)continue;
            if(x < k)Ans += k - x;
            else if(cur < k - cur)Ans += cur;
            else Ans += (k - cur);
        }
        cout << Ans << endl;
    }


    return 0;
}

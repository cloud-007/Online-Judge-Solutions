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
ll tc, n, t[N], x[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> t[i] >> x[i];

        ll curPosition = 0;
        int Ans = 0;

        for(int i = 1; i <= n; i++) {
            ll curTime = t[i];
            ll duration = abs(x[i] - curPosition);
            if(i == n || t[i] + duration <= t[i + 1])++Ans;
            int r = i;
            for(int j = i + 1; j <= n; j++) {
                if(t[j] < curTime + duration) r = j;
                else break;
            }
            for(int j = i + 1; j <= r; j++) {
                ll l = min(curPosition, x[i]);
                ll r = max(curPosition, x[i]);
                if(x[j] < l || x[j] > r) continue;
                ll timeToReach = abs(curPosition - x[j]);
                if(timeToReach >= t[j] - t[i] && (j == n or timeToReach <= t[j + 1] - t[i])) ++Ans;
            }

            curPosition = x[i];
            i = r;
        }

        cout << Ans << endl;
    }


    return 0;
}

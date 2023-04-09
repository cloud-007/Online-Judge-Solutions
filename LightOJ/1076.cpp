/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, m, casee = 1, a[N], pref[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n >> m;
        int l = 0, r = 0 ;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            pref[i] = pref[i - 1] + x;
            l = max(l, x);
        }
        r = pref[n];
        while(l <= r) {
            int mid = (l + r) / 2;
            int last = 0, cnt = 0;
            for(int j = 1; j <= n; j++) {
                if(pref[j] - pref[last] > mid)++cnt, last = j - 1;
            }
            if(cnt < m)r = mid - 1;
            else l = mid + 1;
        }
        cout << "Case " << casee++ << ": " << l << endl;
    }


    return 0;
}

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
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];
        int one = 0, zero = 0;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            zero += x == 0;
            one += x == 1;
        }
        if(one == n || zero == n) {
            if(is_sorted(a + 1, a + n + 1))cout << "YES" << endl;
            else cout << "NO" << endl;
        } else cout << "YES" << endl;
    }


    return 0;
}

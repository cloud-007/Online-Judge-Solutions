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
ll tc, n, a[N];

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n;
    ll mx = 0, x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    set < ll > st;
    for(ll i = 1; i * i <= min(1000000ll, mx); i++) {
        if(mx % i == 0) {
            st.insert(i);
            st.insert(mx / i);
        }
    }

    for(auto i : st) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            cnt += (a[j] % i == 0);
        }
        if(cnt == n - 1) {
            cout << i << endl;
            return 0;
        }
    }


    return 0;
}

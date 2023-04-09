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
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        int lower = lower_bound(a + 1, a + n + 1, x) - (a);
        int upper = upper_bound(a + 1, a + n + 1, x) - (a);
        if(lower > 1)cout << a[lower - 1] << " ";
        else cout << "X ";
        if(upper > n)cout << "X" << endl;
        else cout << a[upper] << endl;
    }



    return 0;
}

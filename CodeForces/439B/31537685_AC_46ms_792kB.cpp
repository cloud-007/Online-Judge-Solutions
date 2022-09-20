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
    ll x; cin >> n >> x;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);

    ll Ans = a[1] * x;

    for(int i = 2; i <= n; i++) {
        if(x > 1)--x;
        Ans += a[i] * x;
    }

    cout << Ans << endl;

    return 0;
}


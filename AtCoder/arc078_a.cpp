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
    cin >> n;
    ll sum = 0;

    for(int i = 1; i <= n; i++)cin >> a[i], sum += a[i];

    ll newSum = 0, Ans = 1e18;

    for(int i = 1; i < n; i++) {
        newSum += a[i]; sum -= a[i];
        Ans = min(abs(newSum - sum), Ans);
    }

    cout << Ans << endl;


    return 0;
}

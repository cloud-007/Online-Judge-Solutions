/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, d;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n >> d;
    ll Ans = 0, last = -1;
    for(int i = 1; i <= n; i++) {
        ll x; cin >> x;
        if(x > last) {
            last = x;
            continue;
        }
        ll diff = last - x;
        ll add = (diff / d) + (diff % d == 0);
        if(x + add * d <= last)++add;
        Ans += add;
        x += add * d;
        last = x;
    }

    cout << Ans << endl;


    return 0;
}
